
    #include <fmt/format.h>
    #include <string>

    #include "../include/scpi_source_function.hpp"

    /*
    命令： [:SOURce]:FUNCtion < GENeral | BREakdown>
    用以切换 GENERAL MODE 或 BREAKDOWN VOLT MODE。
    范例 ：输入指令 “FUNC GEN”
    范例说明 ：切换至 GENERAL MODE。
    */
     
    const char* scpi_99::SOURce::FUNCtion_GENeral() { 
        return ":SOURce:FUNCtion GENeral";
    }
    
    /*
    命令： [:SOURce]:FUNCtion < GENeral | BREakdown>
    用以切换 GENERAL MODE 或 BREAKDOWN VOLT MODE。
    范例 ：输入指令 “FUNC GEN”
    范例说明 ：切换至 GENERAL MODE。
    */
     
    const char* scpi_99::SOURce::FUNCtion_BREakdown() { 
        return ":SOURce:FUNCtion BREakdown";
    }
    
    /*
    命令： [:SOURce]:FUNCtion?
    用以查询量测的模式。
    范例 ：输入指令 “FUNC?”
    仪器回覆 “GENERAL”
    范例说明 ：回覆 “GENERAL” 表示目前为 GENERAL MODE。
    */
     
    const char* scpi_99::SOURce::FUNCtion_query() { 
        return ":SOURce:FUNCtion?";
    }
    

    