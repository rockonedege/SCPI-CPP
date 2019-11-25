from pathlib import Path

# from pprint import pprint as print
import pystache
import re


class SourceMaker:
    hpp_template = '''#pragma once
#include <string>

{{#commands}}
/*
  命令： {{{cmd}}}
{{#comments}}
  {{{.}}}
{{/comments}}
*/
{{{declaration}}}
{{/commands}}

'''

    cpp_template = '''
    #include <fmt/format.h>
    #include <string>

    #include "../include/{{suffix}}.hpp"

    {{#commands}}
    /*
    命令： {{{cmd}}}
    {{#comments}}
    {{{.}}}
    {{/comments}}
    */
    {{{declaration}}}
    {{/commands}}

    '''

    test_template = '''
    {{#commands}}
    /*
    命令： {{{cmd}}}
    {{#comments}}
    {{{.}}}
    {{/comments}}
    */
    {{{declaration}}}
    {{/commands}}


    '''

    src_root = Path(__file__).absolute().parent.parent

    def __init__(self, commands, filename):
        hpp = [dict(c, declaration=self._make_cmd_declaration(c['meta']))
               for c in commands]
        self.make_hpp(hpp, filename)

        cpp = [dict(c, declaration=self._make_cmd_implementation(c['meta']))
               for c in commands]
        self.make_cpp(cpp, filename)

        test = [dict(c, declaration=self._make_cmd_test(c['meta']))
                for c in commands]
        self.make_test(test, filename)

    def make_hpp(self, commands, suffix):

        s = pystache.render(SourceMaker.hpp_template, dict(commands=commands))

        hpp = SourceMaker.src_root / f'src/commands/include/{suffix}.hpp'
        hpp.write_text(s, encoding='utf-8')

    def make_cpp(self, commands, suffix):

        s = pystache.render(SourceMaker.cpp_template, dict(
            commands=commands, suffix=suffix))

        cpp = SourceMaker.src_root / f'src/commands/cpp/{suffix}.cpp'
        cpp.write_text(s, encoding='utf-8')

    def make_test(self, commands, suffix):

        s = pystache.render(SourceMaker.test_template, dict(
            commands=commands, suffix=suffix))

        test = SourceMaker.src_root / f'src/commands/test/{suffix}_test.cpp'
        test.write_text(s, encoding='utf-8')

    def _make_cmd_implementation(self, command_meta):

        param = command_meta['param']

        templ_cpp = ''' 
    const char* {{func.ns_str}}::{{func.name}}() { 
        return "{{{cmd}}}";
    }
    '''

        templ_cpp_para = ''' 
    auto {{func.ns_str}}::{{func.name}}({{{param.decl}}}) -> std::string { 
        using namespace fmt::literals;
        return "{{{cmd}}}{{param.placeholder}}"_format({{{param.impl}}});
    }
    '''

        return pystache.render(templ_cpp_para if param['decl'] else templ_cpp, dict(
            func=command_meta['func'],
            param=param,
            cmd=command_meta['cmd']))

    def _make_cmd_declaration(self, command_meta):

        param = command_meta['param']

        templ_hpp = ''' 
    namespace {{func.ns_str}} {
    const char* {{{func.name}}}();
    }
    '''

        templ_hpp_para = ''' 
    namespace {{func.ns_str}} {
    auto {{{func.name}}}({{{param.decl}}}) -> std::string;
    }
    '''

        return pystache.render(templ_hpp_para if param['decl'] else templ_hpp, dict(
            func=command_meta['func'],
            param=param,
            cmd=command_meta['cmd']))

    def _make_cmd_test(self, command_meta):
        import re

        param = command_meta['param']

        expected = command_meta['cmd']
        test_output =  param['test']['input'].replace('"','')
        test_output = re.sub(r'[,\s]+', ' ', test_output)
        
        repl = expected.count('{}')
        test_output_ele = test_output.split(' ', repl)

        expected = expected.format(*test_output_ele[0:repl])
        expected  = f'{expected} {" ".join(test_output_ele[repl:])}' 
        expected = re.sub(r'\s+', ' ', expected).strip()


        templ_test = ''' 
BOOST_AUTO_TEST_CASE({{test_name}})
{
  using namespace {{func.ns_str}};
  BOOST_CHECK_EQUAL(R"({{{cmd}}})", {{{func.name}}}());
}'''

        templ_test_para = ''' 
BOOST_AUTO_TEST_CASE({{test_name}})
{
  using namespace {{func.ns_str}};
  BOOST_CHECK_EQUAL(R"({{{expected}}})", {{{func.name}}}({{{param.test.input}}}));
}'''

        # templ_test_para = ''

        return pystache.render(templ_test_para if param['decl'] else templ_test, dict(
            func=command_meta['func'],
            param=param,
            cmd=command_meta['cmd'],
            expected=expected,
            test_output=test_output,
            test_name=re.sub('[^\w]+', '_', f'{command_meta["cmd"]}')))
