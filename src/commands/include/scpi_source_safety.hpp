#pragma once
#include <string>

/*
  命令： [:SOURce]:SAFEty:FETCh? [ < item > ] [ , < item > ]
  此命令可询问主机此时量测结果，< item > 为字元资料，意义如下：
  | 字元资料   | 回传资料                                                                                                          |
  |------------|-------------------------------------------------------------------------------------------------------------------|
  | STEP       | 目前之 STEP 序号                                                                                                  |
  | MODE       | 目前之 MODE                                                                                                       |
  | OMETerage  | 目前之输出值                                                                                                      |
  | MMETerage  | 目前之量测值                                                                                                      |
  | RMETerage  | AC MODE 目前之 Real Current 量测值(仅适用于 19056)                                                                |
  | CMETerage  | 目前之 Corona 量测值(当无 Corona 时，无法使用此参数)                                                              |
  | CCMETerage | AC MODE、DC MODE 目前之 HFCC 的 C 量测值                                                                          |
  | RELApsed   | 目前 RAMP 已执行之时间                                                                                            |
  | RLEAve     | 目前 RAMP 还剩馀之时间                                                                                            |
  | DELApsed   | 目前 DWELL 已执行之时间(仅适用于 19057、19057-20)                                                                 |
  | DLEAve     | 目前 DWELL 还剩馀之时间(仅适用于 19057、19057-20)                                                                 |
  | TELApsed   | 目前 TEST 已执行之时间;当设定 Test Time 为 CONT.时，Test Time 大于 999sec 时，回应 9.9000001E+37                  |
  | TLEAve     | 目前 TEST 还剩馀之时间;当设定 Test Time 为有限时间时，回应剩馀时间当设定 Test Time 为 CONT.时，回应 9.9000001E+37 |
  | FELApsed   | 目前 Fall Time 已执行 之时间                                                                                      |
  | FLEAve     | 目前 Fall Time 还剩馀之时间                                                                                       |
  范例 ：输入指令 “SAFE:FETC?”STEP,MODE,OMET
  仪器回覆 “1,AC,+5.000000E+02”
  范例说明：回覆 “1,AC,+5.000000E+02” 表示主机此时 STEP 和 MODE 及输
  出值的结果为 STEP1, AC MODE, 0.500kV。
*/
 
    namespace scpi_99::SOURce::SAFEty {
    auto FETCh_query(
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
                ) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STARt[:ONCE]
  此命令用以启动测试。
  范例：输入指令 “SAFE:STAR”
  范例说明：表示啓 动主机测试。
*/
 
    namespace scpi_99::SOURce::SAFEty::STARt {
    const char* ONCE();
    }
    
/*
  命令： [:SOURce]:SAFEty:STARt:OFFSet GET | OFF
  当参数为 GET 时为抓取归零值，当参数为 OFF 时为关闭归零动作。
  范例：输入指令 “SAFE:STAR OFFS GET”
  范例说明：表示啓 动主机抓取归零值的功能。
*/
 
    namespace scpi_99::SOURce::SAFEty::STARt {
    const char* OFFSet_GET();
    }
    
/*
  命令： [:SOURce]:SAFEty:STARt:OFFSet GET | OFF
  当参数为 GET 时为抓取归零值，当参数为 OFF 时为关闭归零动作。
  范例：输入指令 “SAFE:STAR OFFS GET”
  范例说明：表示啓 动主机抓取归零值的功能。
*/
 
    namespace scpi_99::SOURce::SAFEty::STARt {
    const char* OFFSet_OFF();
    }
    
/*
  命令： [:SOURce]:SAFEty:STARt:OFFSet?
  用以询问是否有做归零动作。
  范例：输入指令 “SAFE:STAR OFFS?”
  仪器回覆 “0”
  范例说明：回覆 “0” 表示主机没有做归零动作。
*/
 
    namespace scpi_99::SOURce::SAFEty::STARt {
    const char* OFFSet_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:STARt:CSTandard GET
  此命令用以启动短开路侦测模式的 GET Cs 功能。
  范例：输入指令 “SAFE:STAR:CST GET”
  范例说明：表示启动短开路侦测模式的 GET Cs 功能。
*/
 
    namespace scpi_99::SOURce::SAFEty::STARt {
    const char* CSTandard_GET();
    }
    
/*
  命令： [:SOURce]:SAFEty:STOP
  此命令用以停止测试。
  范例：输入指令 “SAFE:STOP”
  范例说明：表示停止主机测试。
*/
 
    namespace scpi_99::SOURce::SAFEty {
    const char* STOP();
    }
    
/*
  命令： [:SOURce]:SAFEty:STATus?
  此命令用以询问目前装置的执行状态，传回字元资料 RUNNING|STOPPED。
  范例：输入指令 “SAFE:STAT?”
  仪器回覆 “RUNNING”
  范例说明：回覆 “RUNNING”表示主机目前正在进行测试中。
*/
 
    namespace scpi_99::SOURce::SAFEty {
    const char* STATus_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:SNUMber?
  此命令用以查询工作记忆体中已设定多少个 STEP。
  范例 ：输入指令 “SAFE:SNUM?”
  仪器回覆 “+2”
  范例说明：回覆 “+2” 表示主机工作记忆体中已设定 2 个 STEP。
*/
 
    namespace scpi_99::SOURce::SAFEty {
    const char* SNUMber_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:ALL:OMETerage?
  询问所有 STEP 的 OUTPUT METER 读值。
  范例：输入指令 “SAFE:RES:ALL:OMET?”
  仪器回覆 “5.100000E+01”
  范例说明 ：回覆 “5.100000E+01” 表示查询 OUTPUT METER 的结果为 0.051kV。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::ALL {
    const char* OMETerage_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:ALL:RMETerage?
  在 GENERAL MODE 下，询问所有 STEP 的 REAL CURRENT METER 读值。
  (仅适用于 19056)。
  范例：输入指令 “SAFE:RES:ALL:RMET?”
  仪器回覆 “7.000000E-05”
  范例说明 ：回覆 “7.000000E-05” 表示查询 REAL CURRENT METER 的结果为
  0.07mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::ALL {
    const char* RMETerage_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:ALL:CMETerage?
  在 GENERAL MODE 下，询问所有 STEP 的 CORONA METER 读值。
  范例：输入指令 “SAFE:RES:ALL:CMET?”
  仪器回覆 “1.200000E+01”
  范例说明 ：回覆 “1.200000E+01” 表示查询 CORONA METER 的结果为 12。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::ALL {
    const char* CMETerage_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:ALL:CCMETerage?
  在 GENERAL MODE 下，询问所有 STEP 的 HFCC 的 C 读值。
  范例：输入指令 “SAFE:RES:ALL:CCMET?”
  仪器回覆 “1.000000E-11”
  范例说明：回覆 “1.000000E-11” 表示查询 HFCC 的 C 量测的结果为 10pF。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::ALL {
    const char* CCMETerage_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:ALL:MMETerage[:NORMal]?
  询问所有 STEP 的 MEASURE METER 读值。
  范例：输入指令 “SAFE:RES:ALL:MMET?”
  仪器回覆 “7.000000E-05”
  范例说明 ：回覆 “7.000000E-05” 表示查询 MEASURE METER 的结果为 0.07mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::ALL::MMETerage {
    const char* NORMal_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:ALL:MODE?
  询问所有 STEP 的 MODE，将传回字元资料 AC|DC|IR|PA|OSC。
  范例：输入指令 “SAFE:RES:ALL:MODE?”
  仪器回覆 “DC”。
  范例说明：回覆 “DC” 表示其 MODE 设定为 DC MODE。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::ALL {
    const char* MODE_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:ALL:TIME[:ELAPsed]:RAMP?
  询问所有 STEP 电压上升之时间。
  范例：输入指令 “SAFE:RES:ALL:TIME:RAMP?”
  仪器回覆 “1.000000E+00”
  范例说明 ：回覆 “1.000000E+00” 表示测试的 ramp 的时间为 1 秒。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::ALL::TIME::ELAPsed {
    const char* RAMP_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:ALL:TIME[:ELAPsed][:TEST]?
  询问所有 STEP 之测试时间。
  范例：输入指令 “SAFE:RES:ALL:TIME?”
  仪器回覆 “3.000000E+00”
  范例说明 ：回覆 “3.000000E+00” 表示其测试所需时间的结果为 3 秒。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::ALL::TIME::ELAPsed {
    const char* TEST_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:ALL:TIME[:ELAPsed]:DWELl?
  询问所有 STEP 其测试的 dwell 时间。(仅适用于 19057 与 19057-20)。
  范例：输入指令 “SAFE:RES:ALL:TIME:DWEL?”
  仪器回覆 “2.500000E+00”
  范例说明：回覆 “2.500000E+00” 表示其测试的 dwell 的时间为 2.5 秒。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::ALL::TIME::ELAPsed {
    const char* DWELl_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:ALL:TIME[:ELAPsed]:FALL?
  询问所有 STEP 其测试的 fall 时间。
  范例：输入指令 “SAFE:RES:ALL:TIME:FALL?”
  仪器回覆 “1.000000E+00”
  范例说明：回覆 “1.000000E+00” 表示其测试的 fall 的时间为 1.0 秒。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::ALL::TIME::ELAPsed {
    const char* FALL_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:ALL[:JUDGment]?
  询问所有判读结果，传回格式:First Step Result, Second Step, Result, ..., Last
  Step Result。Code 表示意义如下表：
  测试结果代码一览表
  Mode
  Code
  STOP
  USER STOP
  CAN NOT TEST
  TESTING
  PASS
  HIGH FAIL
  LOW FAIL
  ARC FAIL
  HIGH FAIL
  CHECK FAIL
  OUTPUT A/D
  OVER
  METER A/D OVER
  REAL HIGH FAIL
  CORONA FAIL
  SHORT FAIL
  OPEN FAIL
  GFI FAIL
  HVCC OPEN FAIL
  HFCC SHORT
  FAIL
  AC
  DC
  IR
  OSC
  ALL
  HEX DEC HEX DEC HEX DEC HEX DEC HEX
  DEC
  70
  112
  71
  113
  72
  114
  73
  115
  74
  116
  21
  33 31 49
  41
  65
  22
  34 32 50
  42
  66
  23
  35 33 51
  24
  36 34 52
  64 100
  35 53
  26
  38
  36
  54
  46
  70
  66
  102
  27
  2A
  2B
  39
  42
  43
  37
  55
  47
  71
  67
  103
  77
  61
  62
  6D
  97
  98
  109
  2D
  2E
  45
  46
  3D
  3E
  61
  62
  2F
  47
  3F
  63
  4D
  范例：输入指令 “SAFE:RES:ALL?”
  仪器回覆 “116”
  范例说明：回覆 “116” 表示判读的结果为 PASS。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::ALL {
    const char* JUDGment_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:COMPleted?
  询问装置是否完成所有设定值之执行动作，传回 1 或 0。
  范例 ：输入指令 “SAFE:RES:COMP?”
  仪器回覆 “1”
  范例说明 ：回覆 “1” 表示已完成所有设定值之执行动作。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult {
    const char* COMPleted_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult[:LAST][:JUDGment]?
  在 GENERAL MODE 下，询问最后一个 STEP 的判读结果代码。
  范例 ：输入指令 “SAFE:RES:LAST?”
  仪器回覆 “116”
  范例说明 ：表示主机最后一个 STEP 的判读结果为 PASS。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::LAST {
    const char* JUDGment_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:AREPort < boolean > | ON | OFF
  设定是否自动回报测试结果 (仅适用于 RS232 介面)。
  范例
  ：输入指令 “SAFE:RES:AREP ON”
  范例说明 ：表示设定主机测试完成后自动回覆测试结果。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult {
    const char* AREPort_ON();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:AREPort < boolean > | ON | OFF
  设定是否自动回报测试结果 (仅适用于 RS232 介面)。
  范例
  ：输入指令 “SAFE:RES:AREP ON”
  范例说明 ：表示设定主机测试完成后自动回覆测试结果。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult {
    const char* AREPort_OFF();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:AREPort?
  询问装置是否自动回报测试结果，传回 1 或 0 (仅适用于 RS232 介面)。
  范例
  ：输入指令 “SAFE:RES:AREP?”
  仪器回覆 “1”
  范例说明 ：回覆 “1” 表示主机测试完成后会自动回覆测试结果。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult {
    const char* AREPort_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:AREPort:ITEM [ < item > ] [ , < item > ]
  设定自动回报测试资料，< item > 为字元资料，意义如下：
  | 字元资料   |   | 回传资料                                                                                  |
  |------------|---|-------------------------------------------------------------------------------------------|
  | MODE       |   | 量测 MODE                                                                                 |
  | OMETerage  |   | 输出值                                                                                    |
  | MMETerage  |   | 量测值                                                                                    |
  | RMETerage  |   | Real Current 量测值(仅适用于 19056)。                                                     |
  | CMETerage  |   | Corona 量测值(当无 Corona 时，无法使用此参数)                                             |
  | CCMETerage |   | HFCC 的 C 量测值                                                                          |
  | RELApsed   |   | RAMP 已执行之时间                                                                         |
  | DELApsed   |   | DWELL 已执行之时间(仅适用于 19057 与 19057-20)                                            |
  | TELApsed   |   | TEST 已执行之时间;当设定 Test Time 为 CONT.时，Test Time 大于 999sec 时回应 9.9000001E+37 |
  | FELApsed   |   | Fall Time 已执行的时间                                                                    |
  | STATe      |   | 测试结果代码                                                                              |
  回报资料顺序
  MODE, OMETerage, MMETerage ,CMETerage, RMETerage, CCMETerage,
  RELApsed, DELApsed, TELApsed, FELApsed, STATe
  范例：1. 输入指令 “SAFE:RES:AREP ON＂，设定启动自动回报
  2. 输入指令“SAFE:RES:AREP:ITEM STAT,MODE,OMET＂，设定要回
  报的资料假设测试为 AC MODE，则回应如下
  AC,+5.200000E+01,116
  范例说明 ：当测试完成后，会依照所要回报的资料设定回报资料
  注
  参数设定无需照顺序，但资料会依照先后顺序回报。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::AREPort {
    auto ITEM(
            bool OMETerage,
            bool MMETerage,
            bool RMETerage,
            bool CMETerage,
            bool CCMETerage,
            bool RELApsed,
            bool DELApsed,
            bool TELApsed,
            bool FELApsed,
            bool STATe) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:AREPort:ITEM?
  询问装置自动回报测试的资料种类，传回资料回报种类。
  (仅适用于 RS232 介面)。
  范例
  ：输入指令 “SAFE:RES:AREP:ITEM?”
  仪器回覆 “MODE,OMET,STAT”
  范例说明 ：回应表示目前自动回报的资料有”量测 MODE”,” 输出值”,” 测试结果代码”。
  SOURce:SAFEty:RESult:ASAVe < boolean > | ON | OFF
  此命令设定用以设定自动回报功能是否保存至下次开机。
  (仅适用于 RS232 介面)
  范例
  ：输入指令 “SOUR:SAFE:RES:ASAV ON”
  范例说明 ：当设定 ON 时，在下次开机后，仍有自动回报功能。
  SOURce:SAFEty:RESult:ASAVe?
  询问装置是否自动回报功能保留至下次开机。
  范例
  ：输入指令 “SOUR:SAFE:RES:ASAV?”
  范例说明 ：回应 1，表示自动回报功能的设定保留至下次开机。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::AREPort {
    const char* ITEM_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:BREakdown[:JUDGment]?
  在 BREAK DOWN VOLT MODE 下，询问判读结果代码。
  范例：输入指令 “SAFE:RES:BRE?”
  仪器回覆 “116”
  范例说明 ：表示主机的判读结果为 PASS。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::BREakdown {
    const char* JUDGment_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:BREakdown:MMETerage?
  在 BREAK DOWN VOLT MODE 下，询问 MEASURE METER 读值。
  范例：输入指令 “SAFE:RES:BRE:MMET?”
  仪器回覆 “7.000000E-05”
  范例说明 ：回覆 “7.000000E-05” 表示查询 MEASURE METER 的结果为 0.07mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::BREakdown {
    const char* MMETerage_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:BREakdown:OMETerage?
  在 BREAK DOWN VOLT MODE 下，询问 OUTPUT METER 读值。
  范例：输入指令 “SAFE:RES:BRE:OMET?”
  仪器回覆 “5.100000E+01”
  范例说明 ：回覆 “5.100000E+01” 表示查询 OUTPUT METER 的结果为 0.051kV。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::BREakdown {
    const char* OMETerage_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:BREakdown:CMETerage? 
  (适用于型号 19055-C)
  在 BREAK DOWN VOLT MODE 下，询问 CORONA METER 读值。
  范例：输入指令 “SAFE:RES:BRE:CMET?”
  仪器回覆 “1.200000E+01”
  范例说明 ：回覆 “1.200000E+01” 表示查询 CORONA METER 的结果为 12。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::BREakdown {
    const char* CMETerage_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:BREakdown:MODE?
  在 BREAK DOWN VOLT MODE 下，此命令用以询问选择的 MODE，将传回字元资
  料为 AC 或 DC。
  范例 ：输入指令 “SAFE:RES:BRE:MODE?”
  仪器回覆 “DC”
  范例说明 ：回覆 “DC” 表示其 MODE 为 DC MODE。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::BREakdown {
    const char* MODE_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:BREakdown:STEP?
  在 BREAK DOWN VOLT MODE 下，此命令用以询问已执行的 STEP 数。
  范例 ：输入指令 “SAFE:RES:BRE:STEP?”
  仪器回覆 “2”
  范例说明 ：回覆 “2” 表示已执行 2 个 STEP。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::BREakdown {
    const char* STEP_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:BREakdown:TIME[:ELAPsed][:TEST]?
  在 BREAK DOWN VOLT MODE 下，询问该 STEP 已执行的测试时间。
  范例 ：输入指令 “SAFE:RES:BRE:TIME?”
  仪器回覆 “3.000000E+00”
  范例说明 ：回覆 “3.000000E+00” 表示该 STEP 已测试的时间为 3 秒。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::BREakdown::TIME::ELAPsed {
    const char* TEST_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:BREakdown:TIME[:ELAPsed]:DWELl?
  在 BREAK DOWN VOLT MODE 下，询问该 STEP 已执行的 dwell 时间。
  (仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:RES:BRE:TIME:DWEL?”
  仪器回覆 “3.000000E+00”
  范例说明 ：回覆 “3.000000E+00” 表示该 STEP 已测试的 dwell 时间为 3 秒。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::BREakdown::TIME::ELAPsed {
    const char* DWELl_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:BREakdown:TIME[:ELAPsed]:RAMP?
  在 BREAK DOWN VOLT MODE 下，询问该 STEP 已执行的 ramp 时间。
  范例 ：输入指令 “SAFE:RES:BRE:TIME:RAMP?”
  仪器回覆 “3.000000E+00”
  范例说明 ：回覆 “3.000000E+00” 表示该 STEP 已测试的 ramp 时间为 3 秒。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::BREakdown::TIME::ELAPsed {
    const char* RAMP_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:RESult:BREakdown:WVoltage?
  在 BREAK DOWN VOLT MODE 下，当发生 FAIL 状况时，此命令可传回发生 FAIL
  之前的电压值；当测试为 PASS 时，该命令回传 9.910000E+37。
  范例 ：输入指令 “SAFE:RES:BRE:WV?”
  仪器回覆 “7.500000E+01”
  范例说明 ：回覆 “7.500000E+01” 表示发生 FAIL 之前的电压值为 75V。
*/
 
    namespace scpi_99::SOURce::SAFEty::RESult::BREakdown {
    const char* WVoltage_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DELete
  在 GENERAL MODE 下，此命令将移除<n>代表的 STEP，而此<n>后面的 STEP 将
  往前递补。
  范例 ：输入指令 “SAFE:STEP 1:DEL”
  范例说明 ：表示清除主机工作记忆体中 STEP 1 的设定值。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn {
    auto DELete(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:SET?
  在 GENERAL MODE 下，此命令用以询问选择的 STEP 中所有设定值。
  范例 ：输入指令 SAFE:STEP 1:SET?
  仪器回覆
  范例说明 ：表示主机工作记忆体中 SETP 设定值为 STEP1, AC,
  VOLT:5.000kV,HIGH:0.600mA, LOW:0.007mA, Real Limit:0.008mA,
  ARC:8.0mA, Corona:33, ,HFCC C:26pF,HFCC OPEN:50%,HFCC SHORT:300%
  TIME:3.0s, RAMP:1.0s, FALL:2.0s。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn {
    auto SET_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:MODE?
  在 GENERAL MODE 下，此命令用以询问选择的 STEP 中的 MODE。
  将传回字元资料为 AC, DC, IR, PA 或 OSC。
  范例 ：输入指令 “SAFEty:STEP1:MODE?”
  仪器回覆 “DC”
  范例说明：回覆 “DC” 表示其 MODE 为 DC MODE。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn {
    auto MODE_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC[:LEVel] < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其交流耐压测试时所需
  的电压值，单位为伏特(V)。(仅适用于 19056)
  设定范围 ：100~10000。
  范例 ：输入指令 “SAFE:STEP 2:AC 3000”
  范例说明 ：表示设定主机 STEP 2 其交流耐压测试时所需的电压值为 3000V。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC {
    auto LEVel(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC[:LEVel]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其交流耐压测试时所需
  的电压值。(仅适用于 19056)
  范例 ：输入指令 “SAFE:STEP 2:AC?”
  仪器回覆 “3.000000E+03”
  范例说明 ：回覆 “3.000000E+03” 表示主机 STEP 2 其交流耐压测试时所需的
  电压值为 3000V。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC {
    auto LEVel_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit[:HIGH] < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其交流耐压漏电电流上
  限值，单位为安培(A)。(仅适用于 19056)
  设定范围 ： 0.000001~0.02。
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM 0.01”
  范例说明 ：表示设定主机 STEP 2 其交流耐压漏电电流上限值为 10mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto HIGH(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit[:HIGH]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其交流耐压漏电电流上
  限值。(仅适用于 19056)
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM?”
  仪器回覆 “1.000000E-02”
  范例说明 ：回覆 “1.000000E-02” 表示主机 STEP 2 其交流耐压漏电电流上限值为10mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto HIGH_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:LOW < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其交流耐压
  漏电电流下限值。(仅适用于 19056)
  设定范围 ：0=OFF,0.000001~0.02 (漏电流的下限值≦设定的上限值)。
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:LOW 0.00001”
  范例说明 ：表示设定主机 STEP 2 其交流耐压漏电电流下限值为 0.01mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto LOW(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:LOW?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其交流耐压漏电电流下
  限值，单位为安培(A)。(仅适用于 19056)
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:LOW?”
  仪器回覆 “1.000000E-05”
  范例说明 ：回覆 “1.000000E-05” 表示主机 STEP 2 其交流耐压漏电电流下限值为
  0.01mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto LOW_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:REAL < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其交流耐压漏电流 Real Current 上限值。(仅适用于 19056)
  设定范围 ：0=OFF,0.000001~0.02 (Real Current 上限值≦设定的上限值)。
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:REAL 0.00001”
  范例说明：表示设定主机 STEP 2 其交流耐压漏电流 Real Current 上限值为 0.01mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto REAL(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:REAL?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其交流耐压漏电流 Real
  Current 上限值，单位为安培(A)。(仅适用于 19056)
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:REAL?”
  仪器回覆 “1.000000E-05”
  范例说明 ：回覆 “1.000000E-05” 表示主机 STEP 2 其交流耐压漏电流 Real Current
  上限值为 0.01mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto REAL_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:ARC[:LEVel] < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其 ARC 检测值，单位为
  安培 (A)。(仅适用于 19056)
  设定范围 ：0 或 0.001~0.02，0 为设定 OFF。
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:ARC 0.004”
  范例说明 ：表示设定主机 STEP 2 其 ARC 检测值为 4mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit::ARC {
    auto LEVel(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:ARC[:LEVel]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其 ARC 检测值。
  (仅适用于 19056)
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:ARC?”
  仪器回覆 “4.000000E-03”
  范例说明 ：回覆 “4.000000E-03” 表示主机 STEP 2 其 ARC 检测值为 4.0mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit::ARC {
    auto LEVel_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:CORona < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其交流耐压漏电流 Corona
  上限值。(仅适用于 19056，且有 CORONA 功能)
  设定范围 ：0=OFF, 0.1-99.9
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:COR 20.2”
  范例说明：表示设定主机 STEP 2 其交流耐压漏电流 Corona 上限值为 20.2。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto CORona(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:CORona? 
  (适用于型号 19055-C)
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其交流耐压漏电流 Corona
  上限值。(仅适用于 19056，且有 CORONA 功能)
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:COR?”
  仪器回覆 “+2.020000E+01”
  范例说明 ：回覆 “+2.020000E+01” 表示主机 STEP 2 其交流耐压漏电流 Corona 上
  限值为 20.2。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto CORona_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:HVCC < boolean > | ON | OFF
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其交流耐压的 HVCC 值。
  (仅适用于 19056)
  范例 ：输入指令 “SAFE:STEP 2:AC:HVCC ON”
  范例说明：表示设定主机 STEP 2 其交流耐压的 HVCC 值为 ON。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC {
    auto HVCC_ON(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:HVCC < boolean > | ON | OFF
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其交流耐压的 HVCC 值。
  (仅适用于 19056)
  范例 ：输入指令 “SAFE:STEP 2:AC:HVCC ON”
  范例说明：表示设定主机 STEP 2 其交流耐压的 HVCC 值为 ON。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC {
    auto HVCC_OFF(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:HVCC?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其交流耐压的 HVCC 值。
  (仅适用于 19056)
  范例 ：输入指令 “SAFE:STEP 2:AC:HVCC?”
  仪器回覆 “1”
  范例说明：回覆 “1”，表示主机 STEP 2 其交流耐压的 HVCC 值为 ON。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC {
    auto HVCC_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:OPEN < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其交流耐压漏电流 HFCC
  的 OPEN 上限值。
  设定范围：10%-100%
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:OPEN 0.2”
  范例说明：表示设定主机 STEP 2 其交流耐压漏电流 HFCC 的 OPEN 上限值为 20%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto OPEN(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:OPEN?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其交流耐压漏电流 HFCC
  的 OPEN 上限值。
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:OPEN?”
  仪器回覆 “+2.000000E-01”
  范例说明 ：回覆 “+2.000000E-01” 表示主机 STEP 2 其交流耐压漏电流 OPEN 上限
  值为 20%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto OPEN_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:SHORt < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其交流耐压 HFCC 的 SHORT 上限值。
  设定范围：当 Cs 为 40 pF(含)以下，其设定为 0(即 OFF)、100%-500%；当 C s 大
  于 41pF(含)以上，只能设定 0(即 OFF)
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:SHOR 3”
  范例说明 ：表示设定主机 STEP 2 其交流耐压 HFCC 的 SHORT 上限值为 300%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto SHORt(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:LIMit:SHORt?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其交流耐压漏电流 HFCC
  的 SHORT 上限值。
  范例 ：输入指令 “SAFE:STEP 2:AC:LIM:SHOR?”
  仪器回覆 “+3.000000E+00”
  范例说明 ：回覆 “+3.000000E+00” 表示主机 STEP 2 其交流耐压漏电流 SHORT 上
  限值为 300%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::LIMit {
    auto SHORt_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:CSTandard < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其交流耐压漏电流 HFCC
  的 C 值。
  设定范围：0=OFF,1-100pF
  范例 ：输入指令 “SAFE:STEP 2:AC:CST 20E-12”
  范例说明 ：表示设定主机 STEP 2 其交流耐压漏电流 HFCC 的 C 值为 20pF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC {
    auto CSTandard(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:CSTandard?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其交流耐压 HFCC 的 C
  值。
  范例 ：输入指令 “SAFE:STEP 2:AC:CST?”
  仪器回覆 “+2.000000E-11”
  范例说明 ：回覆 “+2.000000E-11” 表示主机 STEP 2 其交流耐压 HFCC 的 C 值为 20pF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC {
    auto CSTandard_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:CURRent:OFFSet[:NORmal] <numeric value>
  在 GENERAL MODE 下，此命令用以设定 AC 的 Offset 值。单位为安培(A)。
  设定范围 ：(仅适用于 19056)
  High Limit 设定介于 0.001~2.999mA 时，其 OFFSET 设定范围(0.000000~0.002999)
  High Limit 设定介于 3~20.00mA 之间时，其 OFFSET 设定范围
  (0.00000~0.02000)
  范例：输入指令 “SAFE:STEP 1:AC:CURR:OFFS 0.005”
  范例说明：表示设定主机 STEP 1 AC Offset 为 5mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::CURRent::OFFSet {
    auto NORmal(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:CURRent:OFFSet[:NORmal]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其 Offset 值。
  (仅适用于 19056)
  范例：输入指令 “SAFE:STEP 1:AC:CURR:OFFS?
  仪器回覆 “5.000000E-03”
  范例说明 ：回覆 “5.000000E-03” 表示主机 STEP1 其 Offset 值为 5mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::CURRent::OFFSet {
    auto NORmal_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:CURRent:OFFSet:REAL <numeric value>
  在 GENERAL MODE 下，此命令用以设定 AC 的 Real Current 的 Offset 值。单位为
  安培(A)。(仅适用于 19056)
  设定范围 ：
  High Limit 设定介于 0.001~2.999mA 时，其 Real Current 的 OFFSET 设定范围
  (0.000000~0.002999)
  High Limit 设定介于 3~20.00mA 时，其 Real Current 的 OFFSET 设定范围
  (0.00000~0.02000)
  范例：输入指令 “SAFE:STEP 1:AC:CURR:OFFS:REAL 0.005”
  范例说明 ：表示设定主机 STEP 1 AC Real Current 的 Offset 为 5mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::CURRent::OFFSet {
    auto REAL(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:CURRent:OFFSet:REAL?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其 Real Current 的 Offset
  值。(仅适用于 19056)
  范例：输入指令 “SAFE:STEP 1:AC:CURR:OFFS:REAL?
  仪器回覆 “5.000000E-03”
  范例说明 ：回覆 “5.000000E-03” 表示主机 STEP1 其 Real Current 的 Offset 值为 5mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::CURRent::OFFSet {
    auto REAL_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:HFCC:OFFSet <numeric value>
  在 GENERAL MODE 下，此命令用以设定 AC 的 HFCC 的 C 值的 Offset 值。单位为
  法拉(F)。
  设定范围 ：0~100pF
  范例：输入指令 “SAFE:STEP 1:AC:HFCC:OFFS 20E-12”
  范例说明 ：表示设定主机 STEP 1 AC HFCC 的 C 的 Offset 为 20pF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::HFCC {
    auto OFFSet(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:HFCC:OFFSet?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其 HFCC 的 C 值的 Offset
  值。
  范例：输入指令 “SAFE:STEP 1:AC:HFCC:OFFS?
  仪器回覆 “+2.000000E-11”
  范例说明 ：回覆 “+2.000000E-11” 表示主机 STEP1 其 HFCC 的 C 的 Offset 值为 20pF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::HFCC {
    auto OFFSet_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:TIME:RAMP < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其测试上升至设定电压
  所需时间，单位为秒 (s)。(仅适用于 19056)
  设定范围 ：0 或 0.1~999.0，0 为设定 OFF。
  范例：输入指令 “SAFE:STEP 2:AC:TIME:RAMP 5”
  范例说明：表示设定主机 STEP 2 其测试上升至设定电压所需时间为 5.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::TIME {
    auto RAMP(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:TIME:RAMP?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其测试上升至设定电压
  所需时间。(仅适用于 19056)
  范例：输入指令 “SAFE:STEP 2:AC:TIME:RAMP?”
  仪器回覆 “5.000000E+00”
  范例说明 ：回覆 “5.000000E+00” 表示主机 STEP 2 测试上升至设定电压所需时间
  为 5.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::TIME {
    auto RAMP_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:TIME[:TEST] < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其测试所需时间。
  设定范围 ：0 或 0.3~999.0，0 为设定 CONTINUE。
  (仅适用于 19056)
  范例：输入指令 “SAFE:STEP 2:AC:TIME 10”
  范例说明 ：表示设定主机 STEP 2 其测试所需时间为 10.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::TIME {
    auto TEST(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:TIME[:TEST]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其测试所需时间。
  (仅适用于 19056)
  范例：输入指令 “SAFE:STEP 2:AC:TIME?”
  仪器回覆 “1.000000E+01”
  范例说明 ：回覆 “1.000000E+01” 表示主机 STEP 2 其测试所需时间为 5 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::TIME {
    auto TEST_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:TIME:FALL < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其设定之电压值下降到 0
  所需时间，单位为秒(s)。(仅适用于 19056)
  设定范围 ：0 或 0.1~999.0，0 为设定 OFF。
  范例：输入指令 “SAFE:STEP 2:AC:TIME:FALL 3”
  范例说明 ：表示设定主机 STEP 2 其设定之电压值下降到 0 所需时间为 3.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::TIME {
    auto FALL(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:AC:TIME:FALL?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其设定之电压值下降到 0
  所需时间。(仅适用于 19056)
  范例：输入指令 “SAFE:STEP 2:AC:TIME:FALL?”
  仪器回覆 “3.000000E+00”
  范例说明 ：回覆 “3.000000E+00” 表示主机 STEP 2 其设定之电压值下降到 0 所需
  时间为 3.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::AC::TIME {
    auto FALL_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC[:LEVel] < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其直流耐压测试时所需
  的电压值，单位为伏特(V)。(仅适用于 19057 与 19057-20)
  设定范围 ：19057 时，范围 100~12000
  19057-20 时，范围 100~20000
  范例：输入指令 “SAFE:STEP 3:DC 4000”
  范例说明 ：表示设定主机 STEP 3 其直流耐压测试时所需的电压值为 4000V。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC {
    auto LEVel(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC[:LEVel]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其直流耐压测试时所需
  的电压值。(仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:STEP 3:DC?”
  仪器回覆 “4.000000E+03”
  范例说明 ：回覆 “4.000000E+03” 表示主机 STEP 3 其直流耐压测试时的电压值为 4000V。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC {
    auto LEVel_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce:]SAFEty:STEP<n>:DC:LIMit[:HIGH] < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其直流耐压漏电电流上
  限值，单位为安培(A)。(仅适用于 19057 与 19057-20)
  设定范围：19057 时，范围 0.0000001~0.01
  19057 时，范围 0.0000001~0.005
  范例：输入指令 “SAFE:STEP 3:DC:LIM 0.002999”
  范例说明 ：表示设定主机 STEP 3 其直流耐压漏电电流上限值为 2.999mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit {
    auto HIGH(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce:]SAFEty:STEP<n>:DC:LIMit[:HIGH]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其直流耐压漏电电流上
  限值。(仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:STEP 3:DC:LIM?”
  仪器回覆 “2.999000E-03”
  范例说明 ：回覆 “2.999000E-03” 表示主机 STEP 3 其直流耐压漏电电流上限值为 2.999mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit {
    auto HIGH_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce:]SAFEty:STEP<n>:DC:LIMit:LOW < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其直流耐压漏电电流下
  限值，单位为安培(A)。(仅适用于 19057 与 19057-20)
  设定范围：19057 时，范围 0 或 0.0000001~0.01，0 为设定 OFF
  19057-20 时，范围 0 或 0.0000001~0.005，0 为设定 OFF (漏电流的下
  限值≦设定的上限值)
  范例：输入指令 “SAFE:STEP 3:DC:LIM:LOW 0.000001”
  范例说明 ：表示设定主机 STEP 3 其直流耐压漏电电流下限值为 0.001mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit {
    auto LOW(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce:]SAFEty:STEP<n>:DC:LIMit:LOW?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其直流耐压漏电电流下
  限值。(仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:STEP 3:DC:LIM:LOW?”
  仪器回覆 “1.000000E-06”
  范例说明 ：回覆 “1.000000E-06” 表示主机 STEP 3 其直流耐压漏电电流的下限值
  为 0.001mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit {
    auto LOW_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:LIMit:ARC[:LEVel] < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其 ARC 检测值，单位为
  安培(A)。(仅适用于 19057 与 19057-20)
  设定范围 ：0 或 0.001~0.01，0 为设定 OFF。
  范例：输入指令 “SAFE:STEP 3:DC:LIM:ARC 0.0025”
  范例说明：表示设定主机 STEP 3 其 ARC 检测值为 2.5mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit::ARC {
    auto LEVel(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:LIMit:ARC[:LEVel]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其 ARC 检测值。
  (仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:STEP 3:DC:LIM:ARC?”
  仪器回覆 “2.500000E-03”
  范例说明 ：回覆 “2.500000E-03” 表示主机 STEP 3 其 ARC 检测值为 2.5mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit::ARC {
    auto LEVel_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:LIMit:CORona < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其直流耐压 Corona 上限
  值。(仅适用于 19057 与 19057-20，且有 CORONA 功能)
  设定范围 ：0=OFF, 0.1-99.9
  范例 ：输入指令 “SAFE:STEP 2:DC:LIM:COR 20.2”
  范例说明：表示设定主机 STEP 2 其直流耐压 Corona 上限值为 20.2。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit {
    auto CORona(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:LIMit:CORona?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其直流耐压 Corona 上限
  值。(仅适用于 19057 与 19057-20，且有 CORONA 功能)
  范例 ：输入指令 “SAFE:STEP 2:DC:LIM:COR?”
  仪器回覆 “+2.020000E+01”
  范例说明 ：回覆 “+2.020000E+01” 表示主机 STEP 2 其直流耐压 Corona 上限值为 20.2。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit {
    auto CORona_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:HVCC < boolean > | ON | OFF
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其直流耐压的 HVCC 值。
  (仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:STEP 2:DC:HVCC ON”
  范例说明：表示设定主机 STEP 2 其直流耐压的 HVCC 值为 ON。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC {
    auto HVCC_ON(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:HVCC < boolean > | ON | OFF
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其直流耐压的 HVCC 值。
  (仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:STEP 2:DC:HVCC ON”
  范例说明：表示设定主机 STEP 2 其直流耐压的 HVCC 值为 ON。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC {
    auto HVCC_OFF(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:HVCC?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其直流耐压的 HVCC 值。
  (仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:STEP 2:DC:HVCC?”
  仪器回覆 “1”
  范例说明：回覆 “1”，表示主机 STEP 2 其直流耐压的 HVCC 值为 ON。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC {
    auto HVCC_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:LIMit:OPEN < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其直流耐压漏电流 HFCC
  的 OPEN 上限值。
  设定范围：10%-100%
  范例：输入指令 “SAFE:STEP 2:DC:LIM:OPEN 0.2”
  范例说明：表示设定主机 STEP 2 其直流耐压漏电流 HFCC 的 OPEN 上限值为 20%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit {
    auto OPEN(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:LIMit:OPEN?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其直流耐压 HFCC 的 OPEN 上限值。
  范例：输入指令 “SAFE:STEP 2:DC:LIM:OPEN?”
  仪器回覆 “+2.000000E-01”
  范例说明 ：回覆 “+2.000000E-01” 表示主机 STEP 2 其直流耐压 OPEN 上限值为 20%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit {
    auto OPEN_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:LIMit:SHORt < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其直流耐压 HFCC 的 SHORT 上限值。
  设定范围：当 Cs 为 40 pF(含)以下，其设定为 0(即 OFF)、100%-500%；当 C s 大
  于 41pF(含)以上，只能设定 0(即 OFF)
  范例 ：输入指令 “SAFE:STEP 2:DC:LIM:SHOR 3”
  范例说明 ：表示设定主机 STEP 2 其直流耐压 HFCC 的 SHORT 上限值为 300%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit {
    auto SHORt(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:LIMit:SHOR?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其直流耐压 HFCC 的
  SHORT 上限值。
  范例 ：输入指令 “SAFE:STEP 2:DC:LIM:OPEN?”
  仪器回覆 “+3.000000E+00”
  范例说明 ：回覆 “+3.000000E+00” 表示主机 STEP 2 其直流耐压 HFCC 的 SHORT
  上限值为 300%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::LIMit {
    auto SHOR_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:CSTandard < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其直流耐压 HFCC 的 C 值。
  设定范围 ：0=OFF,1-100pF
  范例：输入指令 “SAFE:STEP 2:DC:CST 20E-12”
  范例说明 ：表示设定主机 STEP 2 其直流耐压 HFCC 的 C 值为 20pF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC {
    auto CSTandard(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:CSTandard?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其直流耐压 HFCC 的 C
  值。
  范例 ：输入指令 “SAFE:STEP 2:DC:CST?”
  仪器回覆 “+2.000000E-11”
  范例说明 ：回覆 “+2.000000E-11” 表示主机 STEP 2 其直流耐压 HFCC 的 C 值为 20pF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC {
    auto CSTandard_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:CURRent:OFFSet <numeric value>
  在 GENERAL MODE 下，此命令用以设定 DC 的 Offset 值，单位为安培 (A)。
  (仅适用于 19057 与 19057-20)
  设定范围 ：
  High Limit 设定介于 0.1uA~299.9uA 时，其 OFFSET 设定范围
  (0.0000000~0.0002999)
  High Limit 设定介于 0.3mA~2.999mA 之间时，其 OFFSET 设定范围
  (0.000000~0.002999)
  当 19057 时，High Limit 设定介于 3mA~10mA 之间时，其 OFFSET 设定
  范围 (0.000000~0.01000)
  当 19057-20 时，High Limit 设定介于 3mA~5mA 之间时，其 OFFSET 设
  定范围 (0.000000~0.00500)
  范例：输入指令 “SAFE:STEP 1:DC:CURR:OFFS 0.005
  范例说明 ：表示设定主机 STEP 1 DC Offset 为 5mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::CURRent {
    auto OFFSet(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:CURRent:OFFSet?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其 Offset 值。
  (仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:STEP 1:DC:CURR:OFFS?
  仪器回覆 “5.000000E-03”
  范例说明 ：回覆 “5.000000E-03” 表示主机 STEP1 其 Offset 值为 5mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::CURRent {
    auto OFFSet_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:HFCC:OFFSet <numeric value>
  在 GENERAL MODE 下，此命令用以设定 DC 的 HFCC C 值的 Offset 值，单位为
  法拉(F)。
  设定范围 ：0~100pF
  范例：输入指令 “SAFE:STEP 1:DC:HFCC:OFFS 20E-12”
  范例说明 ：表示设定主机 STEP 1 DC HFCC C 值的 Offset 为 20pF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::HFCC {
    auto OFFSet(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:HFCC:OFFSet?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其 HFCC 的 C 的 Offset
  值。
  范例 ：输入指令 “SAFE:STEP 1:DC:HFCC:OFFS?
  仪器回覆 “+2.000000E-11”
  范例说明 ：回覆 “+2.000000E-11” 表示主机 STEP1 其 HFCC 的 C 的 Offset 值为
  20pF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::HFCC {
    auto OFFSet_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:TIME:DWELl < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其 DWELL TIME 所需时
  间，单位为秒(s)。(仅适用于 19057 与 19057-20)
  设定范围 ：0 或 0.1~999.0，0 为设定 OFF
  范例：输入指令 “SAFE:STEP 3:DC:TIME:DWEL 2.5”
  范例说明 ：表示设定主机 STEP 3 其 DWELL 所需时间为 2.5sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::TIME {
    auto DWELl(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:TIME:DWELl?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其 DWELL TIME 所需时
  间。(仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:STEP 3:DC:TIME:DWEL?”
  仪器回覆 “2.500000E+00”
  范例说明 ：回覆 “2.500000E+00” 表示主机 STEP 3 其 DWELL 的时间设定为
  2.5 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::TIME {
    auto DWELl_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:TIME:RAMP < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其测试上升至设定电压
  所需时间，单位为秒(s)。(仅适用于 19057 与 19057-20)
  设定范围 ：0 或 0.1~999.0，0 为设定 OFF
  范例：输入指令 “SAFE:STEP 3:DC:TIME:RAMP 2”
  范例说明 ：表示设定主机 STEP 3 其测试上升至设定电压所需时间为 2.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::TIME {
    auto RAMP(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:TIME:RAMP?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其测试上升至设定电压
  所需时间。(仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:STEP 3:DC:TIME:RAMP?”
  仪器回覆 “2.000000E+00”
  范例说明 ：回覆 “2.000000E+00” 表示主机 STEP 3 测试上升至设定电压所需的时
  间设定为 2.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::TIME {
    auto RAMP_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:TIME[:TEST] < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其测试所需时间，单位
  为秒(s)。(仅适用于 19057 与 19057-20)
  设定范围 ：0 或 0.3~999.0，0 为设定 CONTINUE
  范例：输入指令 “SAFE:STEP 3:DC:TIME 1”
  范例说明 ：表示设定主机 STEP 3 其测试所需时间为 1.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::TIME {
    auto TEST(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:TIME[:TEST]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其测试所需时间。
  (仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:STEP 3:DC:TIME?”
  仪器回覆 “1.000000E+00”
  范例说明 ：回覆 “1.000000E+00” 表示主机 STEP 3 其测试所需的时间设定为
  1 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::TIME {
    auto TEST_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:TIME:FALL < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其设定之电压值下降到 0
  所需时间，单位为秒(s)。(仅适用于 19057 与 19057-20)
  设定范围 ：0 或 0.1~999.0，0 为设定 OFF。
  范例：输入指令 “SAFE:STEP 3:DC:TIME:FALL 3”
  范例说明 ：表示设定主机 STEP 3 其设定之电压值下降到 0 所需时间为 3.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::TIME {
    auto FALL(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:DC:TIME:FALL?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其设定之电压值下降到 0
  所需时间。(仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:STEP 3:DC:TIME:FALL?”
  仪器回覆 “3.000000E+00”
  范例说明 ：回覆 “3.000000E+00” 表示主机 STEP 3 其设定之电压值下降到 0 所需
  时间为 3.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::DC::TIME {
    auto FALL_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR[:LEVel] < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其绝缘电阻测试时所需
  的电压值，单位为伏特(V)。(仅适用于 19057 与 19057-20)
  设定范围 ：100~5000
  范例 ：输入指令 “SAFE:STEP 4:IR 1000”
  范例说明 ：表示设定主机 STEP 4 绝缘电阻测试时所需的电压值为 1000V。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR {
    auto LEVel(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR[:LEVel]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其绝缘电阻测试时所需
  的电压值。(仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:STEP 4:IR?”
  仪器回覆 “1.000000E+03”
  范例说明 ：回覆 “1.000000E+03” 表示主机 STEP 4 其绝缘电阻测试时所需的电压
  值设定为 1000V。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR {
    auto LEVel_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:LIMit:HIGH < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其绝缘电阻上限值，单
  位为欧姆(ohm)。(仅适用于 19057 与 19057-20)
  设定范围 ：0~50000000000，0 为设定 OFF。
  范例 ：输入指令 “SAFE:STEP 4:IR:LIM:HIGH 50000000000”
  范例说明 ：表示设定主机 STEP 4 其绝缘电阻上限值为 50GΩ。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::LIMit {
    auto HIGH(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:LIMit:HIGH?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其绝缘电阻上限值。
  (仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:STEP 4:IR:LIM:HIGH?”
  仪器回覆 “5.000000E+10”
  范例说明 ：回覆 “5.000000E+10” 表示主机 STEP 4 其绝缘电阻的上限值为 50GΩ。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::LIMit {
    auto HIGH_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:LIMit[:LOW] < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其绝缘电阻下限值，单
  位为欧姆 (ohm)。(仅适用于 19057 与 19057-20)
  设定范围 ：100000~50000000000 (绝缘电阻的下限值≦设定的上限值)
  范例 ：输入指令 “SAFE:STEP 4:IR:LIM 100000”
  范例说明 ：表示设定主机 STEP 4 其绝缘电阻下限值为 0.1MΩ。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::LIMit {
    auto LOW(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:LIMit[:LOW]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其绝缘电阻下限值。
  (仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:STEP 4:IR:LIM?”
  仪器回覆 “1.000000E+05”
  范例说明 ：回覆 “1.000000E+05” 表示主机 STEP 4 其绝缘电阻的下限值设定为
  0.1MΩ。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::LIMit {
    auto LOW_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:TIME:RAMP < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其测试上升至设定电压
  所需时间，单位为秒(s)。(仅适用于 19057 与 19057-20)
  设定范围 ：0 或 0.1~999.0，0 为设定 OFF。
  范例 ：输入指令 “SAFE:STEP 4:IR:TIME:RAMP 0.5”
  范例说明 ：表示设定主机 STEP 4 其测试上升至设定电压所需时间为 0.5 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::TIME {
    auto RAMP(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:TIME:RAMP?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其测试上升至设定电压
  所需时间。(仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:STEP 4:IR:TIME:RAMP?”
  仪器回覆 “5.000000E-01”
  范例说明 ：回覆 “5.000000E-01” 表示主机 STEP 4 其测试上升至设定电压的所需
  时间为 0.5 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::TIME {
    auto RAMP_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:TIME[:TEST] < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其测试所需时间，单位
  为秒(s)。(仅适用于 19057 与 19057-20)
  设定范围 ：0 或 0.3~999.0，0 为设定 CONTINUE
  范例 ：输入指令 “SAFE:STEP 4:IR:TIME 1”
  范例说明 ：表示设定主机 STEP 4 其测试所需时间为 1.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::TIME {
    auto TEST(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:TIME[:TEST]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其测试所需时间。
  (仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:STEP 4:IR:TIME?”
  仪器回覆 “1.000000E+00”
  范例说明 ：回覆 “1.000000E+00” 表示主机 STEP 4 其测试所需的时间为 1sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::TIME {
    auto TEST_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:TIME:FALL < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其设定之电压值下降到 0
  所需时间，单位为秒(s)。(仅适用于 19057 与 19057-20)
  设定范围 ：0 或 0.1~999.0，0 为设定 OFF
  范例 ：输入指令 “SAFE:STEP 4:IR:TIME:FALL 3”
  范例说明 ：表示设定主机 STEP 4 其设定之电压值下降到 0 所需时间为 3.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::TIME {
    auto FALL(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:TIME:FALL?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其设定之电压值下降到 0
  所需时间。(仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:STEP 4:IR:TIME:FALL?”
  仪器回覆 “3.000000E+00”
  范例说明 ：回覆 “3.000000E+00” 表示主机 STEP 4 其设定之电压值下降到 0 所需
  时间为 3.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::TIME {
    auto FALL_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:RANGe:UPPer < numeric value >
  在 GENERAL MODE 下，此命令根据使用者所输入的电流值，来选取高于该电流所
  能量测的档位，单位为安培(A)。(仅适用于 19057 与 19057-20)
  设定范围 ：0~0.01
  范例 ：输入指令 “SAFE:STEP 4:IR:RANG 0.0003”
  范例说明 ：表示设定主机 STEP 4 IR 量测的电流值为 300uA，所以此时被选取高于
  该电流所能量测的 IR 档位为 3mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::RANGe {
    auto UPPer(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:RANGe:UPPer?
  在 GENERAL MODE 下，此命令询问所设定的档位。(仅适用于 19057 与 19057-20)
  范例 ：输入指令“SAFE:STEP 4:IR:RANG:UPP?”
  仪器回覆 “3.000000E-03”
  范例说明 ：回覆 “3.000000E-03” 表示主机 STEP 4 其设定的档位为 3mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::RANGe {
    auto UPPer_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:RANGe:LOWer < numeric value >
  在 GENERAL MODE 下，此命令根据使用者所输入的电流值，来选取低于该电流所
  能量测的档位，单位为安培(A)。(仅适用于 19057 与 19057-20)
  设定范围 ：0~0.01
  范例 ：输入指令 “SAFE:STEP 4:IR:RANG:LOW 0.0003”
  范例说明 ：表示设定主机 STEP 4 IR 量测的电流值为 300uA，所以此时被选取低于
  该电流所能量测的 IR 档位为 300uA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::RANGe {
    auto LOWer(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:RANGe:LOWer?
  在 GENERAL MODE 下，此命令询问所设定的档位。(仅适用于 19057 与 19057-20)
  范例 ：输入指令“SAFE:STEP 4:IR:RANG:LOW?”
  仪器回覆 “3.000000E-04”
  范例说明 ：回覆 “3.000000E-04” 表示主机 STEP 4 其设定的档位为 300uA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::RANGe {
    auto LOWer_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:RANGe:AUTO < boolean > | ON | OFF
  在 GENERAL MODE 下，此命令设定 IR 档位是否切至 AUTO。
  (仅适用于 19057 与 19057-20)
  参数 ON 或 1 表设定 AUTO
  参数 OFF 或 0 表关闭 AUTO
  注
  当未设定 AUTO，下达 OFF 参数时，会维持原先的设定档位；当原先设定为
  AUTO 时，下达 OFF 参数时，则会设定成 10mA 档。
  范例 ：输入指令 “SAFE:STEP 4:IR:RANG:AUTO ON”
  范例说明 ：表示设定主机 STEP 4 IR 量测的电流档位为 AUTO。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::RANGe {
    auto AUTO_ON(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:RANGe:AUTO < boolean > | ON | OFF
  在 GENERAL MODE 下，此命令设定 IR 档位是否切至 AUTO。
  (仅适用于 19057 与 19057-20)
  参数 ON 或 1 表设定 AUTO
  参数 OFF 或 0 表关闭 AUTO
  注
  当未设定 AUTO，下达 OFF 参数时，会维持原先的设定档位；当原先设定为
  AUTO 时，下达 OFF 参数时，则会设定成 10mA 档。
  范例 ：输入指令 “SAFE:STEP 4:IR:RANG:AUTO ON”
  范例说明 ：表示设定主机 STEP 4 IR 量测的电流档位为 AUTO。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::RANGe {
    auto AUTO_OFF(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:IR:RANGe:AUTO?
  在 GENERAL MODE 下，此命令询问 IR 档位是否设切换为 AUTO。
  (仅适用于 19057 与 19057-20)
  回覆 1 表示设定为 AUTO 状态
  回覆 0 表示设定为关闭 AUTO 状态
  范例 ：输入指令“SAFE:STEP 4:IR:AUTO?”
  仪器回覆 “1”
  范例说明 ：回覆 “1” 表示主机 STEP 4 设定的档位为 AUTO。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::IR::RANGe {
    auto AUTO_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:PAuse:MESSage <string data>
  在 GENERAL MODE 下，此命令用以设定 PAUSE mode 的讯息提示字串。
  范例：输入指令 “SAFE:STEP 5:PA:MESS CHROMA”
  范例说明 ：表示设定主机 STEP 5 其 message 的字串为 CHROMA。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::PAuse {
    auto MESSage(size_t n, std::string string_data) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:PAuse:MESSage?
  在 GENERAL MODE 下，此命令用以查询所设定的 message 的字串。
  范例 ：输入指令 “SAFE:STEP 5:PA:MESS?”
  仪器回覆 “CHROMA”
  范例说明 ：回覆 “CHROMA”表示主机 STEP 5 其 message 的字串为“CHROMA”。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::PAuse {
    auto MESSage_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:PAuse:TIME[:TEST] <numeric_value>
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其 PA mode 测试所需时
  间。
  设定范围 ：0 或 0.3~999.0，0 为设定 OFF
  范例：输入指令 “SAFE:STEP 5:PA:TIME 5”
  范例说明 ：表示设定主机 STEP 5 其测试所需时间为 5.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::PAuse::TIME {
    auto TEST(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:PAuse:TIME[:TEST]?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其 PA mode 测试所需时
  间。
  范例：输入指令 “SAFE:STEP 5:PA:TIME ?”
  仪器回覆 “5.000000E+00”
  范例说明：回覆 “5.000000E+00” 表示主机 STEP 5 其测试的所需时间设定为
  5.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::PAuse::TIME {
    auto TEST_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:OSC:LIMit:OPEN < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其短开路侦测时开路判
  断所设定的百分比。(仅适用于 19056)
  设定范围 ：0.1~1.0
  范例：输入指令 “SAFE:STEP 6:OSC:LIM:OPEN 0.3”
  范例说明 ：表示设定主机 STEP 6 其短开路侦测时开路判断的百分比为 30%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::OSC::LIMit {
    auto OPEN(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:OSC:LIMit:OPEN?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其短开路侦测时开路判
  断所设定的百分比。(仅适用于 19056)
  范例 ：输入指令 “SAFE:STEP 6:OSC:LIM:OPEN?”
  仪器回覆 “3.000000E-01”
  范例说明 ：回覆 “3.000000E-01” 表示主机 STEP 6 其短开路侦测时开路判断
  的百分比为 30%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::OSC::LIMit {
    auto OPEN_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:OSC:LIMit:SHORt < numeric value >
  在 GENERAL MODE 下，此命令用以设定所选择的 STEP，其短开路侦测时短路判
  断所设定的百分比。(仅适用于 19056)
  设定范围 ：0 或 1~5，0 为设定 OFF
  范例：输入指令 “SAFE:STEP 6:OSC:LIM:SHOR 3”
  范例说明 ：表示设定主机 STEP 6 其短开路侦测时短路判断的百分比为 300%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::OSC::LIMit {
    auto SHORt(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:OSC:LIMit:SHORt?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其短开路侦测时短路判
  断所设定的百分比。(仅适用于 19056)
  范例 ：输入指令 “SAFE:STEP 6:OSC:LIM:SHOR?”
  仪器回覆 “3.000000E+00”
  范例说明 ：回覆 “3.000000E+00” 表示主机 STEP 6 其短开路侦测时短路判断的百
  分比为 300%。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::OSC::LIMit {
    auto SHORt_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:OSC:CRANge? <MAXimum|MINimum|NOW>
  在 GENERAL MODE 下，此命令用以询问档位可设定的最大值、最小值及目前工作
  的档位。(仅适用于 19056)
  范例：输入指令 “SAFE:STEP 6:OSC:CRAN? NOW”
  仪器回覆 “1”
  范例说明 ：回覆 “1” 表示主机 STEP 6 OSC 档位目前在 1。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::OSC {
    auto CRANge_query_MAXimum(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:OSC:CRANge? <MAXimum|MINimum|NOW>
  在 GENERAL MODE 下，此命令用以询问档位可设定的最大值、最小值及目前工作
  的档位。(仅适用于 19056)
  范例：输入指令 “SAFE:STEP 6:OSC:CRAN? NOW”
  仪器回覆 “1”
  范例说明 ：回覆 “1” 表示主机 STEP 6 OSC 档位目前在 1。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::OSC {
    auto CRANge_query_MINimum(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:OSC:CRANge? <MAXimum|MINimum|NOW>
  在 GENERAL MODE 下，此命令用以询问档位可设定的最大值、最小值及目前工作
  的档位。(仅适用于 19056)
  范例：输入指令 “SAFE:STEP 6:OSC:CRAN? NOW”
  仪器回覆 “1”
  范例说明 ：回覆 “1” 表示主机 STEP 6 OSC 档位目前在 1。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::OSC {
    auto CRANge_query_NOW(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:OSC:CURRent<m>:OFFSet <numeric value>
  在 GENERAL MODE 下，此命令用以设定 OSC 的电流档位及 Offset 值。
  设定范围：m:RANGE NUMBER(只能输入 1), numeric value= Cs 值，单位为 F。
  范围：0~999.9nF。(仅适用于 19056)
  范例：输入指令 “SAFE:STEP1:OSC:CURR 1:OFFS 0.00000001”
  范例说明 ：表示设定主机 STEP 1 OSC，电流档位为 1，Offset 值为 10nF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::OSC::CURRentm {
    auto OFFSet(size_t n, size_t m, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:OSC:CURRent<m>:OFFSet?
  在 GENERAL MODE 下，此命令用以询问所选择的 STEP，其 Offset 值。
  设定范围：m:RANGE NUMBER(只能输入 1)。(仅适用于 19056)
  范例：输入指令 “SAFE:STEP 1:OSC:CURR 1:OFFS?
  仪器回覆 “1.0000000E-10”
  范例说明 ：回覆 “1.0000000E-10” 表示主机 STEP1 其 Offset 值为 100pF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::OSC::CURRentm {
    auto OFFSet_query(size_t n, size_t m) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:OSC:CSTandard <numeric value>
  在 GENERAL MODE 下，此命令用以设定 OSC 的标准电容值。
  设定范围：0.1-10.0nF，单位为 F。(仅适用于 19056)
  范例：输入指令 “SOUR:SAFE:STEP 1:OSC:CST 0.000000009”
  范例说明 ：表示设定主机 STEP 1 OSC，标准电容值(Cs)为 9nF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::OSC {
    auto CSTandard(size_t n, double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:STEP<n>:OSC:CSTandard?
  在 GENERAL MODE 下，此命令用以询问 OSC 的标准电容值。(仅适用于 19056)
  范例：输入指令 “SOUR:SAFE:STEP 1:OSC:CST?”
  仪器回覆 “+9.000000E-09”
  范例说明 ：回覆 “+9.000000E-09” 表示标准电容值(Cs)为 9nF。
*/
 
    namespace scpi_99::SOURce::SAFEty::STEPn::OSC {
    auto CSTandard_query(size_t n) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:TIME:PASS < numeric value >
  用以设定 PASS 时蜂鸣器(BUZZER)响声持续时间，单位为秒 (s)。
  设定范围 ：0.2~99.9.
  范例 ：输入指令 “SAFE:PRES:TIME:PASS 3”
  范例说明 ：表示设定主机 PASS 时蜂鸣器(BUZZER)响声持续时间为 3 秒。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::TIME {
    auto PASS(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:TIME:PASS?
  用以询问 PASS 时蜂鸣器(BUZZER)响声输出持续时间。
  范例 ：输入指令 “SAFE:PRES:TIME:PASS?”
  仪器回覆 “3.000000E+00”
  范例说明 ：回覆 “3.000000E+00” 表示 PASS 时蜂鸣器(BUZZER)响声输出持续时
  间为 3 秒。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::TIME {
    const char* PASS_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:TIME:STEP < numeric value > | KEY
  该设定使用在 GENERAL MODE ，用以设定 STEP 之间的间隔时间或再下一次启动
  命令开始执行下一个 STEP。单位为秒(s)。
  设定范围 ：KEY 或 0.1~99.9
  范例 ：输入指令 “SAFE:PRES:TIME:STEP 0.5”
  范例说明 ：表示设定主机 STEP 之间的间隔时间为 0.5 秒。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::TIME {
    auto STEP(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:TIME:STEP?
  用以询问 STEP 之间的间隔设定，传回值为 KEY 或单位为秒之数值。
  范例 ：输入指令 “SAFE:PRES:TIME:PASS?”
  仪器回覆 “5.000000E-01”
  范例说明 ：回覆 “5.000000E-01” 表示 STEP 之间的间隔时间为 0.5 秒。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::TIME {
    const char* STEP_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:AC:FREQuency < numeric value >
  该设定使用在 GENERAL MODE 与 BREAKDOWN MODE，使用在用以设定交流耐
  压测试时输出电压之频率，单位为赫兹(Hz)。(仅适用于 19056)
  设定范围 ：50~60
  范例：输入指令 “SAFE:PRES:AC:FREQ 60”
  范例说明 ：表示设定主机交流耐压测试时输出电压之频率为 60Hz。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::AC {
    auto FREQuency(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:AC:FREQuency?
  用以查询交流耐压测试时输出电压之频率。(仅适用于 19056)
  范例 ：输入指令 “SAFE:PRES:AC:FREQ?”
  仪器回覆 “6.000000E+01”
  范例说明 ：回覆 “6.000000E+01” 表示交流耐压测试时输出电压之频率为 60Hz。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::AC {
    const char* FREQuency_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:WRANge[:AUTO] < boolean > | ON | OFF
  该设定使用在 GENERAL MODE，用以设定耐压自动换档功能是否开启。
  范例 ：输入指令 “SAFE:PRES:WRAN ON”
  范例说明 ：表示设定主机耐压自动换档功能开启。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::WRANge {
    const char* AUTO_ON();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:WRANge[:AUTO] < boolean > | ON | OFF
  该设定使用在 GENERAL MODE，用以设定耐压自动换档功能是否开启。
  范例 ：输入指令 “SAFE:PRES:WRAN ON”
  范例说明 ：表示设定主机耐压自动换档功能开启。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::WRANge {
    const char* AUTO_OFF();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:WRANge[:AUTO]?
  用以查询耐压自动换档功能是否开启，传回 1 或 0。
  范例 ：输入指令 “SAFE:PRES:WARN?”
  仪器回覆 “1”
  范例说明 ：回覆 “1” 表示主机耐压自动换档功能开启。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::WRANge {
    const char* AUTO_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:AGC[:SOFTware] < boolean > | ON | OFF
  该设定使用在 GENERAL MODE，用以设定软体 AGC 是否开启。
  范例：输入指令 “SAFE:PRES:AGC ON”
  范例说明 ：表示设定主机软体 AGC 开启。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::AGC {
    const char* SOFTware_ON();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:AGC[:SOFTware] < boolean > | ON | OFF
  该设定使用在 GENERAL MODE，用以设定软体 AGC 是否开启。
  范例：输入指令 “SAFE:PRES:AGC ON”
  范例说明 ：表示设定主机软体 AGC 开启。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::AGC {
    const char* SOFTware_OFF();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:AGC[:SOFTware]?
  用以查询软体 AGC 是否开启。
  范例 ：输入指令 “SAFE:PRES:AGC?”
  仪器回覆 “1”
  范例说明 ：回覆 “1” 表示主机软体 AGC 开启。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet::AGC {
    const char* SOFTware_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:RJUDgmnet < boolean > | ON | OFF
  该设定使用在 GENERAL MODE，用以设定 Ramp Judg.是否开启。
  范例：输入指令 “SAFE:PRES:RJUD ON” (仅适用于 19057 与 19057-20)
  范例说明 ：表示设定主机 Ramp Judg.开启。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet {
    const char* RJUDgmnet_ON();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:RJUDgmnet < boolean > | ON | OFF
  该设定使用在 GENERAL MODE，用以设定 Ramp Judg.是否开启。
  范例：输入指令 “SAFE:PRES:RJUD ON” (仅适用于 19057 与 19057-20)
  范例说明 ：表示设定主机 Ramp Judg.开启。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet {
    const char* RJUDgmnet_OFF();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:RJUDgment?
  用以查询 Ramp Judg.是否开启。(仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:PRES:RJUD?”
  仪器回覆 “1”
  范例说明 ：回覆 “1” 表示主机 Ramp Judg.开启。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet {
    const char* RJUDgment_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:GFI ON|OFF
  该设定使用在 GENERAL MODE 与 BREAKDOWN MODE，用以 GFI 的设定。
  (仅适用于 19056)
  范例：输入指令 “SAFE:PRES:GFI ON”
  范例说明 ：表示设定 GFI ON。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet {
    const char* GFI_ON();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:GFI ON|OFF
  该设定使用在 GENERAL MODE 与 BREAKDOWN MODE，用以 GFI 的设定。
  (仅适用于 19056)
  范例：输入指令 “SAFE:PRES:GFI ON”
  范例说明 ：表示设定 GFI ON。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet {
    const char* GFI_OFF();
    }
    
/*
  命令： [:SOURce]:SAFEty:PRESet:GFI?
  用以询问 GFI 的设定。(仅适用于 19056)
  范例 ：输入指令 “SAFE:PRES:GFI?”
  仪器回覆 “ON”
  范例说明 ：表示 GFI ON。
*/
 
    namespace scpi_99::SOURce::SAFEty::PRESet {
    const char* GFI_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:MODE?
  在 BREAKDOWN MODE 下，此命令用以询问目前是设定何种模式
  范例 ：输入指令 “SAFE:BRE:MODE?”
  仪器回覆 “AC”
  范例说明 ：表示 AC MODE。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown {
    const char* MODE_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC[:LEVel] < start V >,<end V>
  在 BREAKDOWN MODE 下，此命令用以设定 AC MODE 的起点电压值与终点电压，
  单位为伏特(V)。(仅适用于 19056)
  设定范围：起点电压:100V~终点电压。
  终点电压:起点电压~10000V。
  范例 ：输入指令 “SAFE:BRE:AC 500,1000”
  范例说明 ：表示设定主机 AC MODE 的起点电压 500V 值与终点电压 1000V。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC {
    auto LEVel(size_t start_V,size_t end_V) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC[:LEVel]?
  在 BREAKDOWN MODE 下，此命令用以询问 AC MODE 的起点电压值与终点电压，
  单位为伏特(V)。(仅适用于 19056)
  范例 ：输入指令 “SAFE:BRE:AC?”
  仪器回覆：“+5.000000E+02,+1.000000E+03”
  范例说明 ：表示 AC MODE 的起点电压 500V 值与终点电压 1000V。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC {
    const char* LEVel_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:LIMit[:HIGH] < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定 AC MODE 的漏电电流上限值，单位
  为安培(A)。(仅适用于 19056)
  设定范围 ：0.000001~0.02。
  范例 ：输入指令 “SAFE:BRE:AC:LIM 0.01”
  范例说明 ：表示设定主机 AC MODE 的漏电电流上限值为 10mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC::LIMit {
    auto HIGH(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:LIMit[:HIGH]?
  在 BREAKDOWN MODE 下，此命令用以询问 AC MODE 的漏电电流上限值。
  (仅适用于 19056)
  范例 ：输入指令 “SAFE:BRE:AC:LIM?”
  仪器回覆 “1.000000E-02”
  范例说明 ：回覆 “1.000000E-02” 表示主机 AC MODE 的漏电电流上限值为 10mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC::LIMit {
    const char* HIGH_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:LIMit:LOW < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定 AC MODE 的漏电电流下限值。
  (仅适用于 19056)
  设定范围 ：0:OFF 或 0.000001~0.02 (漏电流的下限值 ≦ 设定的上限值)。
  范例 ：输入指令 “SAFE:BRE:AC:LIM:LOW 0.00001”
  范例说明 ：表示设定主机 AC MODE 的漏电电流下限值为 0.01mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC::LIMit {
    auto LOW(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:LIMit:LOW?
  在 BREAKDOWN MODE 下，此命令用以询问 AC MODE 的漏电电流下限值，单位
  为安培(A)。(仅适用于 19056)
  范例：输入指令 “SAFE:BRE:AC:LIM:LOW?”
  范例说明 ：回覆 “1.000000E-05” 表示主机 AC MODE 的漏电电流下限值为0.01mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC::LIMit {
    const char* LOW_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:LIMit:ARC[:LEVel] < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定 AC MODE 的 ARC 检测值，单位为
  安培(A)。(仅适用于 19056)
  设定范围 ：0 或 0.001~0.02，0 为设定 OFF。
  范例 ：输入指令 “SAFE:BRE:AC:LIM:ARC 0.004”
  范例说明 ：表示设定主机 AC MODE 的 ARC 检测值为 4mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC::LIMit::ARC {
    auto LEVel(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:LIMit:ARC[:LEVel]?
  在 BREAKDOWN MODE 下，此命令用以询问 AC MODE 的 ARC 检测值。
  (仅适用于 19056)
  范例 ：输入指令 “SAFE:BRE:AC:LIM:ARC?”
  仪器回覆 “4.000000E-03”
  范例说明 ：回覆 “4.000000E-03” 表示主机 AC MODE 的 ARC 检测值为 4.0mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC::LIMit::ARC {
    const char* LEVel_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:LIMit:CORona < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定 AC MODE 的 Corona 上限值。
  (仅适用于 19056，且有 CORONA 功能)
  设定范围 ：0=OFF,0.1-99.9
  范例 ：输入指令 “SAFE:BRE:AC:LIM:COR 20.2”
  范例说明 ：表示设定主机 AC MODE 的 Corona 上限值为 20.2。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC::LIMit {
    auto CORona(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdiwn:AC:LIMit:CORona?
  在 BREAKDOWN MODE 下，此命令用以询问 AC MODE 的 Corona 上限值。
  (仅适用于 19056，且有 CORONA 功能)
  范例 ：输入指令 “SAFE:BRE:AC:LIM:COR?”
  仪器回覆 “+2.020000E+01”
  范例说明 ：回覆 “+2.020000E+01” 表示主机 AC MODE 的 Corona 上限值为 20.2。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdiwn::AC::LIMit {
    const char* CORona_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:TIME[:TEST] < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定每个 STEP，其测试所需时间，单位
  为秒 (s)。(仅适用于 19056)
  设定范围 ：0.3~999.0。
  范例 ：输入指令 “SAFE:BRE:AC:TIME 10”
  范例说明 ：表示设定主机在每个 STEP 测试所需时间为 10.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC::TIME {
    auto TEST(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:TIME[:TEST]?
  在 BREAKDOWN MODE 下，此命令用以询问每个 STEP 的测试所需时间。
  (仅适用于 19056)
  范例 ：输入指令 “SAFE:BRE:AC:TIME?”
  仪器回覆 “1.000000E+01”
  范例说明 ：回覆 “1.000000E+01” 表示主机每个 STEP 测试所需时间为 5 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC::TIME {
    const char* TEST_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:TIME:RAMP < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定每个 STEP，其测试上升至设定电压
  所需时间，单位为秒 (s)。(仅适用于 19056)
  设定范围 ：0 或 0.1~999.0，0 为设定 OFF。
  范例 ：输入指令 “SAFE:BRE:AC:TIME:RAMP 10”
  范例说明 ：表示设定主机在每个 STEP 测试上升至设定电压所需时间 10.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC::TIME {
    auto RAMP(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:TIME:RAMP?
  在 BREAKDOWN MODE 下，此命令用以询问每个 STEP 的测试上升至设定电压所
  需时间。(仅适用于 19056)
  范例 ：输入指令 “SAFE:BRE:AC:TIME:RAMP?”
  仪器回覆 “1.000000E+01”
  范例说明 ：回覆 “1.000000E+01” 表示主机每个 STEP 测试上升至设定电压所需时
  间为 5 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC::TIME {
    const char* RAMP_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:CONTinue < boolean > | ON | OFF
  在 BREAKDOWN MODE 下，此命令用以设定在测试到最后一个 STEP 时，是否要
  连续输出不停止。(仅适用于 19056)
  范例：输入指令 “SAFE:BRE:AC:CONT ON”
  范例说明 ：表示设定测试到最后一个 STEP 时，连续输出不停止。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC {
    const char* CONTinue_ON();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:CONTinue < boolean > | ON | OFF
  在 BREAKDOWN MODE 下，此命令用以设定在测试到最后一个 STEP 时，是否要
  连续输出不停止。(仅适用于 19056)
  范例：输入指令 “SAFE:BRE:AC:CONT ON”
  范例说明 ：表示设定测试到最后一个 STEP 时，连续输出不停止。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC {
    const char* CONTinue_OFF();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:CONTinue?
  在 BREAKDOWN MODE 下，此命令用以询问在测试到最后一个 STEP 时，是否要
  连续输出不停止。(仅适用于 19056)
  范例：输入指令 “SAFE:BRE:AC:CONT?”
  仪器回覆 “1”
  范例说明 ：表示当测试到最后一个 STEP 时，会连续输出不停止。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC {
    const char* CONTinue_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:STEP < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定所需测试多少个 STEP。
  设定范围：2~999。(仅适用于 19056)
  范例：输入指令 “SAFE:BRE:AC:STEP 10”
  范例说明 ：表示设定主机测试 10 个 STEP。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC {
    auto STEP(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:AC:STEP?
  在 BREAKDOWN MODE 下，此命令用以询问测试多少个 STEP。(仅适用于 19056)
  范例 ：输入指令 “SAFE:BRE:AC:STEP?”
  仪器回覆 “10”
  范例说明 ：回覆 “10” 表示主机测试 10 个 STEP。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::AC {
    const char* STEP_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC[:LEVel] < start V >,<end V>
  在 BREAKDOWN MODE 下，此命令用以设定 DC MODE 的起点电压值与终点电压，
  单位为伏特(V)。(仅适用于 19057 与 19057-20)
  设定范围 ：起点电压:100V~终点电压。
  终点电压:19057 时，起点电压~12000V。
  19057-20 时，起点电压~20000V。
  范例：输入指令 “SAFE:BRE:DC 500,1000”
  范例说明 ：设定主机 AC MODE 的起点电压 500V 值与终点电压 1000V。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC {
    auto LEVel(size_t start_V,size_t end_V) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC[:LEVel]?
  在 BREAKDOWN MODE 下，此命令用以询问 DC MODE 的起点电压值与终点电压，
  单位为伏特(V)。(仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:BRE:DC?”
  仪器回覆：“+5.000000E+02,+1.000000E+03”
  范例说明：表示 DC MODE 的起点电压 500V 值与终点电压 1000V。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC {
    const char* LEVel_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:LIMit[:HIGH] < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定 DC MODE 的漏电电流上限值，单位
  为安培(A)。(仅适用于 19057 与 19057-20)
  设定范围 ：19057 时，范围 0.00000001~0.01。
  19057-20 时，范围 0.00000001~0.005。
  范例：输入指令 “SAFE:BRE:DC:LIM 0.01”
  范例说明：表示设定主机 DC MODE 的漏电电流上限值为 10mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::LIMit {
    auto HIGH(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:LIMit[:HIGH]?
  在 BREAKDOWN MODE 下，此命令用以询问 DC MODE 的漏电电流上限值。
  (仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:BRE:DC:LIM?”
  仪器回覆 “1.000000E-02”
  范例说明 ：回覆 “1.000000E-02” 表示主机 DC MODE 的漏电电流上限值为 10mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::LIMit {
    const char* HIGH_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:LIMit:LOW < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定 DC MODE 的漏电电流下限值。
  (仅适用于 19057 与 19057-20)
  设定范围 ：19057 时，0:OFF 或 0.0000001~0.01
  19057-20 时，0:OFF 或 0.0000001~0.005
  (漏电流的下限值 ≦ 设定的上限值)
  范例 ：输入指令 “SAFE:BRE:DC:LIM:LOW 0.00001”
  范例说明 ：表示设定主机 DC MODE 的漏电电流下限值为 0.01mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::LIMit {
    auto LOW(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:LIMit:LOW?
  在 BREAKDOWN MODE 下，此命令用以询问 DC MODE 的漏电电流下限值，单位
  为安培(A)。(仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:BRE:DC:LIM:LOW?”
  仪器回覆 “1.000000E-05”
  范例说明 ：回覆 “1.000000E-05” 表示主机 DC MODE 的漏电电流下限值为
  0.01mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::LIMit {
    const char* LOW_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:LIMit:ARC[:LEVel] < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定 DC MODE 的 ARC 检测值，单位为
  安培(A)。(仅适用于 19057 与 19057-20)
  设定范围：0 或 0.001~0.01，0 为设定 OFF。
  范例 ：输入指令 “SAFE:BRE:DC:LIM:ARC 0.004”
  范例说明 ：表示设定主机 DC MODE 的 ARC 检测值为 4mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::LIMit::ARC {
    auto LEVel(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:LIMit:ARC[:LEVel]?
  在 BREAKDOWN MODE 下，此命令用以询问 DC MODE 的 ARC 检测值。
  (仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:BRE:DC:LIM:ARC?”
  仪器回覆 “4.000000E-03”
  范例说明 ：回覆 “4.000000E-03” 表示主机 DC MODE 的 ARC 检测值为 4.0mA。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::LIMit::ARC {
    const char* LEVel_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:LIMit:CORona < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定 DC MODE 的 Corona 上限值。
  (仅适用于 19057 与 19057-20，且有 CORONA 功能)
  设定范围 ：0=OFF,0.1-99.9
  范例 ：输入指令 “SAFE:BRE:DC:LIM:COR 20.2”
  范例说明 ：表示设定主机 DC MODE 的 Corona 上限值为 20.2。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::LIMit {
    auto CORona(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdiwn:DC:LIMit:CORona?
  在 BREAKDOWN MODE 下，此命令用以询问 DC MODE 的 Corona 上限值。
  (仅适用于 19057 与 19057-20，且有 CORONA 功能)
  范例 ：输入指令 “SAFE:BRE:DC:LIM:COR?”
  仪器回覆 “+2.020000E+01”
  范例说明 ：回覆 “+2.020000E+01” 表示主机 DC MODE 的 Corona 上限值为 20.2。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdiwn::DC::LIMit {
    const char* CORona_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:TIME[:TEST] < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定每个 STEP，其测试所需时间，单位
  为秒(s)。(仅适用于 19057 与 19057-20)
  设定范围 ：0.3~999.0
  范例 ：输入指令 “SAFE:BRE:DC:TIME 10”
  范例说明 ：表示设定主机在每个 STEP 测试所需时间为 10.0sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::TIME {
    auto TEST(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:TIME[:TEST]?
  在 BREAKDOWN MODE 下，此命令用以询问 STEP 的测试所需时间。
  范例 ：输入指令 “SAFE:BRE:DC:TIME?”
  仪器回覆 “1.000000E+01”
  范例说明 ：回覆 “1.000000E+01” 表示主机每个 STEP 测试所需时间为 5sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::TIME {
    const char* TEST_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:TIME:DWELl < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定每个 STEP 的 dwell 时间，单位为秒(s)。
  (仅适用于 19057 与 19057-20)
  设定范围 ：0 或 0.1~999.0，0 表示没有 dwell time。
  范例 ：输入指令 “SAFE:BRE:DC:TIME:DWEL 10”
  范例说明 ：表示设定主机在每个 STEP 的 dwell 时间为 10.0sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::TIME {
    auto DWELl(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:TIME:DWELl?
  在 BREAKDOWN MODE 下，此命令用以询问 STEP 的 dwell 时间。
  (仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:BRE:DC:TIME:DWEL?”
  仪器回覆 “1.000000E+01”
  范例说明 ：回覆 “1.000000E+01” 表示主机每个 STEP 的 dwell 时间为 5sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::TIME {
    const char* DWELl_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:TIME:RAMP < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定每个 STEP，其测试上升至设定电压
  所需时间，单位为秒 (s)。(仅适用于 19057 与 19057-20)
  设定范围 ：0 或 0.1~999.0，0 为设定 OFF。
  范例 ：输入指令 “SAFE:BRE:DC:TIME:RAMP 10”
  范例说明 ：表示设定主机在每个 STEP 测试上升至设定电压所需时间 10.0 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::TIME {
    auto RAMP(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:TIME:RAMP?
  在 BREAKDOWN MODE 下，此命令用以询问每个 STEP 的测试上升至设定电压所
  需时间。(仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:BRE:DC:TIME:RAMP?”
  仪器回覆 “1.000000E+01”
  范例说明 ：回覆 “1.000000E+01” 表示主机每个 STEP 测试上升至设定电压所需时
  间为 5 sec。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC::TIME {
    const char* RAMP_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:CONTinue < boolean > | ON | OFF
  在 BREAKDOWN MODE 下，此命令用以设定在测试到最后一个 STEP 时,是否要连
  续输出不停止。(仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:BRE:DC:CONT ON”
  范例说明 ：表示设定测试到最后一个 STEP 时，连续输出不停止。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC {
    const char* CONTinue_ON();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:CONTinue < boolean > | ON | OFF
  在 BREAKDOWN MODE 下，此命令用以设定在测试到最后一个 STEP 时,是否要连
  续输出不停止。(仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:BRE:DC:CONT ON”
  范例说明 ：表示设定测试到最后一个 STEP 时，连续输出不停止。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC {
    const char* CONTinue_OFF();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:CONTinue?
  在 BREAKDOWN MODE 下，此命令用以询问在测试到最后一个 STEP 时,是否要连
  续输出不停止。(仅适用于 19057 与 19057-20)
  范例：输入指令 “SAFE:BRE:DC:CONT?”
  仪器回覆 “1”
  范例说明 ：表示当测试到最后一个 STEP 时，会连续输出不停止。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC {
    const char* CONTinue_query();
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:STEP < numeric value >
  在 BREAKDOWN MODE 下，此命令用以设定所需测试多少个 STEP。
  (仅适用于 19057 与 19057-20)
  设定范围 ：2~999。
  范例 ：输入指令 “SAFE:BRE:DC:STEP 10”
  范例说明 ：表示设定主机测试 10 个 STEP。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC {
    auto STEP(double numeric_value) -> std::string;
    }
    
/*
  命令： [:SOURce]:SAFEty:BREakdown:DC:STEP?
  在 BREAKDOWN MODE 下，此命令用以询问测试多少个 STEP。
  (仅适用于 19057 与 19057-20)
  范例 ：输入指令 “SAFE:BRE:DC:STEP?”
  仪器回覆 “10”
  范例说明 ：回覆 “10” 表示主机测试 10 个 STEP。
  TRIGger:SOURce:EXTernal:STATe < boolean > | ON | OFF
  该设定使用在 GENERAL MODE 与 BREAKDOWN MODE，用以设定在 remote 状
  态下是否会挡 START KEY。
  当参数为 1 时，remote 状态时不会挡 START KEY
  当参数为 0 时，remote 状态时会挡 START KEY
  范例 ：输入指令 “TRIG:SOUR:EXT:STAT 0”
  范例说明 ：表示设定主机在 remote 状态下会挡 START KEY。
  TRIGger:SOURce:EXTernal:STATe?
  该设定使用在 GENERAL MODE 与 BREAKDOWN MODE，用以查询 remote 状态
  下是否会挡 START KEY。
  范例 ：输入指令 “TRIG:SOUR:EXT:STAT?”
  仪器回覆 “0”
  范例说明：回覆 “0” 表示主机在 remote 状态下会挡 START KEY。
*/
 
    namespace scpi_99::SOURce::SAFEty::BREakdown::DC {
    const char* STEP_query();
    }
    

