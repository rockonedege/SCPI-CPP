# -*- coding:utf-8 -*-
from get_cmds import scpi, ieee488_2
from pathlib import Path

# from pprint import pprint as print
import re


def condense(param):
    repl = [('< ', '<'),
            (' >', '>'),
            ('numeric value', 'numeric_value'),
            ('register number', 'register_number'),
            ('start V', 'start_V'),
            ('end V', 'end_V')]
    for r in repl:
        param = param.replace(r[0], r[1])
    return param


def make_decl(param):
    param_decl = param
    repl = [('<numeric_value>', 'double numeric_value'),
            ('<start_V>', 'size_t start_V'),
            ('<end_V>', 'size_t end_V'),
            ('<register_number>', 'size_t register_number'),
            ('<name>', 'std::string name'),
            ('<string data>', 'std::string string_data'),
            (' | KEY', ''),
            ('<十进位数值资料>', 'std::uint8_t register_value')]
    for r in repl:
        param_decl = param_decl.replace(r[0], r[1])

    return param_decl


def make_impl(param_decl):
    param_impl = param_decl
    repl = [('size_t ', ''),
            ('std::string ', ''),
            ('std::uint8_t ', ''),
            ('double ', '')
            ]
    for r in repl:
        param_impl = param_impl.replace(r[0], r[1])
    return param_impl


def make_test_param(param):
    test_input = param
    repl = [('<numeric_value>', '0.002'),
            ('<start_V>', '500'),
            ('<end_V>', '1000'),
            ('<register_number>', '2'),
            ('<name>', '"TEST"'),
            ('<string data>', '"data"'),
            (' | KEY', ''),
            ('<十进位数值资料>', '6')]
    for r in repl:
        test_input = test_input.replace(r[0], r[1])
    return dict(input=test_input)


def make_param_for_multiitems(cmd_only):
    if ':SAFEty:FETCh?' in cmd_only:
        return make_for_FETCh()
    elif ':SAFEty:RESult:AREPort:ITEM' in cmd_only:
        return make_func_for_meterage()
    else:
        pass


def make_for_FETCh():
    test = dict(input='''
                "STEP",
                "MODE",
                "OMETerage",
                "MMETerage",
                "RMETerage",
                "CMETerage",
                "CCMETerage",
                "RELApsed",
                "RLEAve",
                "DELApsed",
                "DLEAve",
                "TELApsed",
                "TLEAve",
                "FELApsed",
                "FLEAve"
    ''')
    return dict(
        test=test,
        decl='''
                bool STEP,
                bool MODE,
                bool OMETerage,
                bool MMETerage,
                bool RMETerage,
                bool CMETerage,
                bool CCMETerage,
                bool RELApsed,
                bool RLEAve,
                bool DELApsed,
                bool DLEAve,
                bool TELApsed,
                bool TLEAve,
                bool FELApsed,
                bool FLEAve
                ''',
        impl='''
                STEP ? " STEP": "",
                MODE ? " MODE": "",
                OMETerage ? " OMETerage": "",
                MMETerage ? " MMETerage": "",
                RMETerage ? " RMETerage": "",
                CMETerage ? " CMETerage": "",
                CCMETerage ? " CCMETerage": "",
                RELApsed ? " RELApsed": "",
                RLEAve ? " RLEAve": "",
                DELApsed ? " DELApsed": "",
                DLEAve ? " DLEAve": "",
                TELApsed ? " TELApsed": "",
                TLEAve ? " TLEAve": "",
                FELApsed ? " FELApsed": "",
                FLEAve ? " FLEAve": ""''',
        placeholder="{}"*15)


def make_func_for_meterage():
    test = dict(input='''
            "OMETerage",
            "MMETerage",
            "RMETerage",
            "CMETerage",
            "CCMETerage",
            "RELApsed",
            "DELApsed",
            "TELApsed",
            "FELApsed",
            "STATe"
            ''')
    return dict(

        test=test,
        decl='''
            bool OMETerage,
            bool MMETerage,
            bool RMETerage,
            bool CMETerage,
            bool CCMETerage,
            bool RELApsed,
            bool DELApsed,
            bool TELApsed,
            bool FELApsed,
            bool STATe''',
                impl='''
            OMETerage ? " OMETerage": "",
            MMETerage ? " MMETerage": "",
            RMETerage ? " RMETerage": "",
            CMETerage ? " CMETerage": "",
            CCMETerage ? " CCMETerage": "",
            RELApsed ? " RELApsed": "",
            DELApsed ? " DELApsed": "",
            TELApsed ? " TELApsed": "",
            FELApsed ? " FELApsed": "",
            STATe ? " STATe": ""''',
                placeholder="{}"*10)

def make_empty_param():
    return dict(decl='', impl='', test=dict(input=''))

def make_para(param):

    param = condense(param)
    param_decl = make_decl(param)
    param_impl = make_impl(param_decl)
    test = make_test_param(param)

    return dict(decl=param_decl,
                impl=param_impl,
                test=test,
                placeholder=" {}"*(param_decl.count(',') + 1))


def make_para_for_step(param, has_m):

    param = condense(param)
    param_decl = make_decl(param)
    param_impl = make_impl(param_decl)
    test = make_test_param(param)

    decl = 'size_t n, size_t m' if has_m else 'size_t n'
    impl = 'n, m' if has_m else 'n'
    test_input = '1, 3' if has_m else '1'

    placeholder = ''

    if param_decl:
        decl += f', {param_decl}'
        impl += f', {param_impl}'
        placeholder = " {}"*(param_decl.count(',') + 1)

    test['input'] = f"{test_input}, {test['input']}" if test['input'] else test_input



    return dict(decl=decl,
                impl=impl, 
                test=test, 
                placeholder=placeholder)


def make_func(cmd):
    cmd = f'ieee488_2:{cmd[1:]}' if cmd.startswith('*') else f'scpi_99{cmd}'
    ns = cmd.replace('<', '').replace(
        '>', '').replace('?', '_query').split(':')
    return dict(ns=ns[:-1], ns_str='::'.join(ns[:-1]), name=ns[-1])



def make_for_step(cmd_only, param, one):
    def _on_off():
        cc = []
        for c in ['ON', 'OFF']:
            cc.append(dict(one, meta=dict(
                cmd=(cmd_only + f' {c}').replace(
                    '<n>', ' {}').replace('<m>', ' {}'),
                func=make_func(cmd_only + f'_{c}'),
                param=make_para_for_step('', '<m>' in cmd_only)
            )))
        return cc

    def _min_max_now():
        cc = []
        for c in ['MAXimum', 'MINimum', 'NOW']:
            cc.append(dict(one, meta=dict(
                cmd=(cmd_only + f' {c}').replace(
                    '<n>', ' {}').replace('<m>', ' {}'),
                func=make_func(cmd_only + f'_{c}'),
                param=make_para_for_step('', '<m>' in cmd_only)
            )))
        return cc

    def default():
        return [dict(one, meta=dict(
            cmd=cmd_only.replace('<n>', ' {}').replace('<m>', ' {}'),
            func=make_func(cmd_only),
            param=make_para_for_step(param, '<m>' in cmd_only)
        ))]

    map = {'ON|OFF': _on_off,
           '<boolean> | ON | OFF': _on_off,
           '<MAXimum|MINimum|NOW>': _min_max_now}
    return map.get(param, default)()


def make_for_ieee488(cmd_only, param, one):

    if cmd_only in ['*RCL', '*SAV']:
        param = '0 | 1'

    def default():
        return [dict(one, meta=dict(
            cmd=cmd_only,
            func=make_func(cmd_only),
            param=make_para(param)

        ))]

    def _0_1():
        cc = []
        for c in ['0', '1']:
            cc.append(dict(one, meta=dict(
                cmd=cmd_only + f' {c}',
                func=make_func(cmd_only + f'_{c}'),
                param=make_empty_param()
            )))
        return cc

    map = {'0 | 1': _0_1}
    return map.get(param, default)()


def common(cmd_only, param, one):

    cc = []

    def _get_off():
        cc = []
        for c in ['GET', 'OFF']:
            cc.append(dict(one, meta=dict(
                cmd=cmd_only + f' {c}',
                func=make_func(cmd_only + f'_{c}'),
                param=make_empty_param()
            )))
        return cc

    def _get():
        return [dict(one, meta=dict(
                cmd=cmd_only + f' GET',
                func=make_func(cmd_only + f'_GET'),

                param=make_empty_param()
                ))]

    def _bool_on_off():
        cc = []
        for c in ['ON', 'OFF']:
            cc.append(dict(one, meta=dict(
                cmd=cmd_only + f' {c}',
                func=make_func(cmd_only + f'_{c}'),

                param=make_empty_param()
            )))
        return cc

    def _min_max():
        cc = []
        for c in ['MAXimum', 'MINimum', 'NOW']:
            cc.append(dict(one, meta=dict(
                cmd=cmd_only + f' {c}',
                func=make_func(cmd_only + f'_{c}'),

                param=make_empty_param()
            )))
        return cc

    def _general_breakdown():
        cc = []
        for c in ['GENeral', 'BREakdown']:
            cc.append(dict(one, meta=dict(
                cmd=cmd_only + f' {c}',
                func=make_func(cmd_only + f'_{c}'),
                param=make_empty_param()
            )))
        return cc

    def _multi_item():

        return [dict(one, meta=dict(
            cmd=cmd_only,
            func=make_func(cmd_only),
            param=make_param_for_multiitems(cmd_only)
        ))]

    def default():
        return [dict(one, meta=dict(
            cmd=cmd_only,
            func=make_func(cmd_only),
            param=make_para(param)

        ))]

    map = {'GET': _get,
           'GET | OFF':     _get_off,
           'ON|OFF':     _bool_on_off,
           '<boolean> | ON | OFF':     _bool_on_off,
           '<MAXimum|MINimum|NOW>':     _min_max,
           '<GENeral | BREakdown>':     _general_breakdown,
           '[ <item> ] [ , <item> ]':     _multi_item}
    return map.get(param, default)()


def scpi_preprocess():

    cc = []

    for one in scpi() + ieee488_2():
        cmd = one['cmd']
        cmd_only, space, param = cmd.partition(' ')

        cmd_only = re.sub(r'[\]\[]', '', cmd_only)

        param = param.replace('< ', '<').replace(
            ' >', '>')

        if '<n>' in cmd_only:
            cc += make_for_step(cmd_only, param, one)

        elif cmd_only.startswith('*'):
            cc += make_for_ieee488(cmd_only, param, one)

        else:
            cc += common(cmd_only, param, one)

    Path('~msbuild/scpi_cmds_raw.txt').write_text(
        '\n'.join([c['cmd'] for c in cc]), encoding='utf-8')
    Path('~msbuild/scpi_cmds.txt').write_text(
        '\n'.join([c['meta']['cmd'] for c in cc]), encoding='utf-8')
    return cc


def run():
    from source_maker import SourceMaker
    names = []

    for prefix in [
        '*',
        ':MEMory',
        ':SYSTem',
        ':SOURce:FUNCtion',
        ':SOURce:SAFEty'

    ]:
        filename = 'scpi_' + \
            prefix[1:].replace(':', '_').lower(
            ) if prefix != '*' else 'ieee488_2'

        cmds = [c for c in scpi_preprocess() if c['meta']
                ['cmd'].startswith(prefix)]

        SourceMaker(cmds, filename)

        names.append(f'#include "{filename}.hpp"')

    scpi_hpp = Path(__file__).absolute().parent.parent / \
        f'src/commands/include/commands.hpp'
    scpi_hpp.write_text('\n'.join(['#pragma once'] + names), encoding='utf-8')


if __name__ == "__main__":
    run()
    print('done')
