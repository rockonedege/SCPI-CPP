
    #include <fmt/format.h>
    #include <string>

    #include "../include/ieee488_2.hpp"

    /*
    命令： *CLS
    清除状态资料结构，所须动作如下：
    清除标准事件状态暂存器。
    清除状态位元组暂存器，但 MAV 位元（位元 4）外。
    */
     
    const char* ieee488_2::CLS() { 
        return "*CLS";
    }
    
    /*
    命令： *ESE <十进位数值资料>
    用以设定标准事件状态致能暂存器之值，其<十进位数值资料>之值范围在 0～255 之
    间。
    */
     
    auto ieee488_2::ESE(std::uint8_t register_value) -> std::string { 
        using namespace fmt::literals;
        return "*ESE {}"_format(register_value);
    }
    
    /*
    命令： *ESE?
    控制器用来询问装置之标准事件状态致能暂存器之值，输出格式为
    <十进位数值资料>，其值范围在 0～255 之间。
    */
     
    const char* ieee488_2::ESE_query() { 
        return "*ESE?";
    }
    
    /*
    命令： *ESR?
    控制器用来询问装置之标准事件暂存器之值，执行此命令后，标准事件暂存器之值将
    清为 0。
    输出格式为<十进位数值资料>，其值范围在 0～255 之间。
    */
     
    const char* ieee488_2::ESR_query() { 
        return "*ESR?";
    }
    
    /*
    命令： *IDN?
    控制器用来读取装置的基本资料，输出格式为以逗号区隔之 4 个栏位，分别表示：製
    造商、装置型号、序号、韧体版本。
    */
     
    const char* ieee488_2::IDN_query() { 
        return "*IDN?";
    }
    
    /*
    命令： *OPC
    操作完成命令。
    */
     
    const char* ieee488_2::OPC() { 
        return "*OPC";
    }
    
    /*
    命令： *OPC?
    操作完成查询命令。
    输出格式为 ASCII 字元” 1 “。
    */
     
    const char* ieee488_2::OPC_query() { 
        return "*OPC?";
    }
    
    /*
    命令： *PSC 0 | 1
    开机状态清除命令。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
    const char* ieee488_2::PSC_0() { 
        return "*PSC 0";
    }
    
    /*
    命令： *PSC 0 | 1
    开机状态清除命令。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
    const char* ieee488_2::PSC_1() { 
        return "*PSC 1";
    }
    
    /*
    命令： *PSC?
    开机状态清除查询命令。
    输出格式为 ASCII 字元” 1 “或” 0 “。
    */
     
    const char* ieee488_2::PSC_query() { 
        return "*PSC?";
    }
    
    /*
    命令： *RST
    装置重置命令。
    */
     
    const char* ieee488_2::RST() { 
        return "*RST";
    }
    
    /*
    命令： *RCL <十进位数值资料>
    读回命令。
    此命令作用为从记忆体读回装置所储存的状态。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
    const char* ieee488_2::RCL_0() { 
        return "*RCL 0";
    }
    
    /*
    命令： *RCL <十进位数值资料>
    读回命令。
    此命令作用为从记忆体读回装置所储存的状态。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
    const char* ieee488_2::RCL_1() { 
        return "*RCL 1";
    }
    
    /*
    命令： *SAV <十进位数值资料>
    储存命令。
    此命令是用来将装置目前的状态，储存于记忆体。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
    const char* ieee488_2::SAV_0() { 
        return "*SAV 0";
    }
    
    /*
    命令： *SAV <十进位数值资料>
    储存命令。
    此命令是用来将装置目前的状态，储存于记忆体。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
    const char* ieee488_2::SAV_1() { 
        return "*SAV 1";
    }
    
    /*
    命令： *SRE <十进位数值资料>
    用以设定服务要求暂存器之值，其 十进位数值资料>之值范围在 0～255 之间。
    */
     
    auto ieee488_2::SRE(std::uint8_t register_value) -> std::string { 
        using namespace fmt::literals;
        return "*SRE {}"_format(register_value);
    }
    
    /*
    命令： *SRE?
    控制器用来读取服务要求致能暂存器之内含值。
    输出格式为<十进位数值资料>，其值范围在 0～255 之间。
    注
    此命令 bit “6” 恆为零。
    */
     
    const char* ieee488_2::SRE_query() { 
        return "*SRE?";
    }
    
    /*
    命令： *STB?
    控制器用来读取状态位元暂存器之值。
    输出格式为<十进位数值资料>，其值范围在 0～255 之间。
    */
     
    const char* ieee488_2::STB_query() { 
        return "*STB?";
    }
    

    