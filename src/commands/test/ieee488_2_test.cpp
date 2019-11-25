
    /*
    命令： *CLS
    清除状态资料结构，所须动作如下：
    清除标准事件状态暂存器。
    清除状态位元组暂存器，但 MAV 位元（位元 4）外。
    */
     
BOOST_AUTO_TEST_CASE(_CLS)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*CLS)", CLS());
}
    /*
    命令： *ESE <十进位数值资料>
    用以设定标准事件状态致能暂存器之值，其<十进位数值资料>之值范围在 0～255 之
    间。
    */
     
BOOST_AUTO_TEST_CASE(_ESE)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*ESE 6)", ESE(6));
}
    /*
    命令： *ESE?
    控制器用来询问装置之标准事件状态致能暂存器之值，输出格式为
    <十进位数值资料>，其值范围在 0～255 之间。
    */
     
BOOST_AUTO_TEST_CASE(_ESE_)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*ESE?)", ESE_query());
}
    /*
    命令： *ESR?
    控制器用来询问装置之标准事件暂存器之值，执行此命令后，标准事件暂存器之值将
    清为 0。
    输出格式为<十进位数值资料>，其值范围在 0～255 之间。
    */
     
BOOST_AUTO_TEST_CASE(_ESR_)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*ESR?)", ESR_query());
}
    /*
    命令： *IDN?
    控制器用来读取装置的基本资料，输出格式为以逗号区隔之 4 个栏位，分别表示：製
    造商、装置型号、序号、韧体版本。
    */
     
BOOST_AUTO_TEST_CASE(_IDN_)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*IDN?)", IDN_query());
}
    /*
    命令： *OPC
    操作完成命令。
    */
     
BOOST_AUTO_TEST_CASE(_OPC)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*OPC)", OPC());
}
    /*
    命令： *OPC?
    操作完成查询命令。
    输出格式为 ASCII 字元” 1 “。
    */
     
BOOST_AUTO_TEST_CASE(_OPC_)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*OPC?)", OPC_query());
}
    /*
    命令： *PSC 0 | 1
    开机状态清除命令。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
BOOST_AUTO_TEST_CASE(_PSC_0)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*PSC 0)", PSC_0());
}
    /*
    命令： *PSC 0 | 1
    开机状态清除命令。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
BOOST_AUTO_TEST_CASE(_PSC_1)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*PSC 1)", PSC_1());
}
    /*
    命令： *PSC?
    开机状态清除查询命令。
    输出格式为 ASCII 字元” 1 “或” 0 “。
    */
     
BOOST_AUTO_TEST_CASE(_PSC_)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*PSC?)", PSC_query());
}
    /*
    命令： *RST
    装置重置命令。
    */
     
BOOST_AUTO_TEST_CASE(_RST)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*RST)", RST());
}
    /*
    命令： *RCL <十进位数值资料>
    读回命令。
    此命令作用为从记忆体读回装置所储存的状态。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
BOOST_AUTO_TEST_CASE(_RCL_0)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*RCL 0)", RCL_0());
}
    /*
    命令： *RCL <十进位数值资料>
    读回命令。
    此命令作用为从记忆体读回装置所储存的状态。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
BOOST_AUTO_TEST_CASE(_RCL_1)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*RCL 1)", RCL_1());
}
    /*
    命令： *SAV <十进位数值资料>
    储存命令。
    此命令是用来将装置目前的状态，储存于记忆体。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
BOOST_AUTO_TEST_CASE(_SAV_0)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*SAV 0)", SAV_0());
}
    /*
    命令： *SAV <十进位数值资料>
    储存命令。
    此命令是用来将装置目前的状态，储存于记忆体。
    注
    此命令参数值非” 0 “即” 1 “。
    */
     
BOOST_AUTO_TEST_CASE(_SAV_1)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*SAV 1)", SAV_1());
}
    /*
    命令： *SRE <十进位数值资料>
    用以设定服务要求暂存器之值，其 十进位数值资料>之值范围在 0～255 之间。
    */
     
BOOST_AUTO_TEST_CASE(_SRE)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*SRE 6)", SRE(6));
}
    /*
    命令： *SRE?
    控制器用来读取服务要求致能暂存器之内含值。
    输出格式为<十进位数值资料>，其值范围在 0～255 之间。
    注
    此命令 bit “6” 恆为零。
    */
     
BOOST_AUTO_TEST_CASE(_SRE_)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*SRE?)", SRE_query());
}
    /*
    命令： *STB?
    控制器用来读取状态位元暂存器之值。
    输出格式为<十进位数值资料>，其值范围在 0～255 之间。
    */
     
BOOST_AUTO_TEST_CASE(_STB_)
{
  using namespace ieee488_2;
  BOOST_CHECK_EQUAL(R"(*STB?)", STB_query());
}


    