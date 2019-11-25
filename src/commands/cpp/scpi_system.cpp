
    #include <fmt/format.h>
    #include <string>

    #include "../include/scpi_system.hpp"

    /*
    命令： :SYSTem:ERRor[:NEXT]?
    此命令用以读取错误讯息伫列（Error Queue）中之讯息，传回之讯息请查阅第5.5 错
    误讯息。
    范例：输入指令 “SYST:ERR?”
    仪器回覆 “+0,”No error”
    范例说明：回覆 “+0,”No error” 表示没有任何错误讯息在伫列中。
    */
     
    const char* scpi_99::SYSTem::ERRor::NEXT_query() { 
        return ":SYSTem:ERRor:NEXT?";
    }
    
    /*
    命令： :SYSTem:VERSion?
    用以查询此装置所支援的 SCPI 版本。
    范例 ：输入指令 “SYST:VERS?”
    仪器回覆 “1990.0”
    范例说明 ：回覆 “1990.0” 表示此装置所支援 SCPI 版本为 1990.0。
    */
     
    const char* scpi_99::SYSTem::VERSion_query() { 
        return ":SYSTem:VERSion?";
    }
    

    