
    /*
    命令： [:SOURce]:FUNCtion < GENeral | BREakdown>
    用以切换 GENERAL MODE 或 BREAKDOWN VOLT MODE。
    范例 ：输入指令 “FUNC GEN”
    范例说明 ：切换至 GENERAL MODE。
    */
     
BOOST_AUTO_TEST_CASE(_SOURce_FUNCtion_GENeral)
{
  using namespace scpi_99::SOURce;
  BOOST_CHECK_EQUAL(R"(:SOURce:FUNCtion GENeral)", FUNCtion_GENeral());
}
    /*
    命令： [:SOURce]:FUNCtion < GENeral | BREakdown>
    用以切换 GENERAL MODE 或 BREAKDOWN VOLT MODE。
    范例 ：输入指令 “FUNC GEN”
    范例说明 ：切换至 GENERAL MODE。
    */
     
BOOST_AUTO_TEST_CASE(_SOURce_FUNCtion_BREakdown)
{
  using namespace scpi_99::SOURce;
  BOOST_CHECK_EQUAL(R"(:SOURce:FUNCtion BREakdown)", FUNCtion_BREakdown());
}
    /*
    命令： [:SOURce]:FUNCtion?
    用以查询量测的模式。
    范例 ：输入指令 “FUNC?”
    仪器回覆 “GENERAL”
    范例说明 ：回覆 “GENERAL” 表示目前为 GENERAL MODE。
    */
     
BOOST_AUTO_TEST_CASE(_SOURce_FUNCtion_)
{
  using namespace scpi_99::SOURce;
  BOOST_CHECK_EQUAL(R"(:SOURce:FUNCtion?)", FUNCtion_query());
}


    