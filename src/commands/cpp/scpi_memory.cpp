
    #include <fmt/format.h>
    #include <string>

    #include "../include/scpi_memory.hpp"

    /*
    命令： :MEMory:DELete[:NAME] < name >
    此命令用以删除主机记忆体内的 <name> 所指之参数资料。< name > 为字元资料。
    范例 ：输入指令 “MEM:DEL “123”
    范例说明 ：表示删除主机记忆体的名称为“123”的参数资料。
    */
     
    auto scpi_99::MEMory::DELete::NAME(std::string name) -> std::string { 
        using namespace fmt::literals;
        return ":MEMory:DELete:NAME {}"_format(name);
    }
    
    /*
    命令： :MEMory:DELete:LOCAtion < register number >
    此命令用以删除主机记忆体内的 < register number > 所指之参数资料。< register number > 为整数资料。
    范例 ：输入指令 “MEM:DEL:LOCA 1”
    范例说明 ：表示删除主机记忆体的第一组参数资料。
    */
     
    auto scpi_99::MEMory::DELete::LOCAtion(size_t register_number) -> std::string { 
        using namespace fmt::literals;
        return ":MEMory:DELete:LOCAtion {}"_format(register_number);
    }
    
    /*
    命令： :MEMory:STATe:DEFine < name >, < register number >
    此命令可设定 <register number > 所指记忆体之名称。
    范例 ：输入指令 “MEM:STAT:DEF TEST,1”
    范例说明 ：表示设定主机记忆体内的第一组记忆体的参数资料名称 TEST。
    */
     
    auto scpi_99::MEMory::STATe::DEFine(std::string name, size_t register_number) -> std::string { 
        using namespace fmt::literals;
        return ":MEMory:STATe:DEFine {} {}"_format(name, register_number);
    }
    
    /*
    命令： :MEMory:STATe:DEFine? < name >
    此命令可询问 < name > 所指记忆体之 < register number >。
    范例 ：输入指令 “MEM:STAT:DEF? TEST”
    仪器回覆 “1”
    范例说明 ：回覆 “1” 表示名称为 TEST 的参数资料的位置在第一组。
    */
     
    auto scpi_99::MEMory::STATe::DEFine_query(std::string name) -> std::string { 
        using namespace fmt::literals;
        return ":MEMory:STATe:DEFine? {}"_format(name);
    }
    
    /*
    命令： :MEMory:FREE:STATe?
    此命令用以查询主机记忆体中剩馀的 PRESET 参数数量。
    范例 ：输入指令 “MEM:FREE:STAT?”
    仪器回覆 “97,3”
    范例说明 ：回覆 “97,3” 表示剩馀可设定的参数资料组数为 97 组，巳使用 3 组。
    */
     
    const char* scpi_99::MEMory::FREE::STATe_query() { 
        return ":MEMory:FREE:STATe?";
    }
    
    /*
    命令： :MEMory:FREE:STEP?
    此命令用以查询主机记忆体中剩馀的 STEP 数。
    范例 ：输入指令 “MEM:FREE:STEP?”
    仪器回覆 “497,3”
    范例说明 ：回覆 “497,3” 表示剩馀可设定的 STEP 为 497 个，巳使用 3 个 STEP。
    */
     
    const char* scpi_99::MEMory::FREE::STEP_query() { 
        return ":MEMory:FREE:STEP?";
    }
    
    /*
    命令： :MEMory:NSTates?
    此命令用以查询主机 *SAV / *RCL 命令可使用参数之最大值加 1。
    范例 ：输入指令 “MEM:NST?”
    仪器回覆 “101”
    范例说明 ：回覆 “101” 表示主机记忆体的储存容量为 100 组(101-1)。
    */
     
    const char* scpi_99::MEMory::NSTates_query() { 
        return ":MEMory:NSTates?";
    }
    

    