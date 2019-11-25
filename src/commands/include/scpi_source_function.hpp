#pragma once
#include <string>

/*
  命令： [:SOURce]:FUNCtion < GENeral | BREakdown>
  用以切换 GENERAL MODE 或 BREAKDOWN VOLT MODE。
  范例 ：输入指令 “FUNC GEN”
  范例说明 ：切换至 GENERAL MODE。
*/
 
    namespace scpi_99::SOURce {
    const char* FUNCtion_GENeral();
    }
    
/*
  命令： [:SOURce]:FUNCtion < GENeral | BREakdown>
  用以切换 GENERAL MODE 或 BREAKDOWN VOLT MODE。
  范例 ：输入指令 “FUNC GEN”
  范例说明 ：切换至 GENERAL MODE。
*/
 
    namespace scpi_99::SOURce {
    const char* FUNCtion_BREakdown();
    }
    
/*
  命令： [:SOURce]:FUNCtion?
  用以查询量测的模式。
  范例 ：输入指令 “FUNC?”
  仪器回覆 “GENERAL”
  范例说明 ：回覆 “GENERAL” 表示目前为 GENERAL MODE。
*/
 
    namespace scpi_99::SOURce {
    const char* FUNCtion_query();
    }
    

