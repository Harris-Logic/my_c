//
// Created by Logic on 2023/1/11.
//
#include "Myloger.h"
#include "iostream"

string /*&*/func(const char *pstr)
{
    string msg=string(__FILE__)+string(":")
            +string(__FUNCTION__ )+string(":")
            +string(std::to_string(__LINE__))+string(":")
            +string(pstr);
    return msg;//局部对象 &不能返回局部对象的引用，去掉&
}
void test0(){
    //第一步，完成单例模式的写法
    Mylogger *log = Mylogger::getInstance();

    log->info("The log is info message");
    log->error("The log is error message");
    log->debug("The log is fatal message");
    log->info("The log is crit message");
}

void test()
{
//    Mylogger::getInstance()
//    ->warn(prefix("warn test message"));
//    Mylogger::getInstance()
//            ->error(prefix("error test message"));
//    ->warn(func("warn test message").c_str());
    logWarn("warn test");
    logError("error test");
    logInfo("info test");
    logDebug("debug test");

//    Mylogger::getInstance()->warn(func("warn test message"));//堆对象
}
void test2()
{//字符串替换 两个字符串拼接
    cout<<__FILE__<<"   "
    <<__FUNCTION__ <<"   "
    <<__LINE__<<endl;
}
int main(int argc, char* argv[])
{
    test();
    return 0;
}
//string int2string(int v)
//{
//    ostringstream oss;
//    oss<<v;
//    return oss.str();
//}
//void test1()
//{
//    printf("hello,world\n");
//    //第二步，像使用printf一样
//    //只要求能输出纯字符串信息即可，不需要做到格式化输出
//    LogInfo("The log is info message");
//    LogError("The log is error message");
//    LogWarn("The log is warn message");
//    LogDebug("The log is debug message");
//}

//    PatternLayout *ppl = new PatternLayout();
////    "%d日%n"
////    "[%p]优先级%n"
////    "%c categories名字%n"
////    "字符串message:%m%n"
//    ppl->setConversionPattern("%d"
//                              "[%p]"
//                              "%c"
//                              "%m %n");
//    OstreamAppender *poa=new OstreamAppender("testostream"
//            ,&cout);//终端
//    //文件
//    RollingFileAppender *prfa=new RollingFileAppender("Rolling"
//            ,"wd.log",5*1024
//            ,3);
//    poa->setLayout(ppl);
////    Category &root= Category::getRoot();
////赋予categories 名字
//    Category &root= Category::getRoot().getInstance("Mycat ");
//
//
//    FileAppender *pfa= new FileAppender("Fileappender1"
//            ,"wd.log");
//    prfa->setLayout(ppl);
//    root.addAppender(poa);
//
//    root.addAppender(prfa);//见cmake-build-debug里的wd.log
//    //过滤器Priority.hh>
//    root.setPriority(Priority::DEBUG);
//#if 0
//    class LOG4CPP_EXPORT Priority {
//        public:
//
//		static const int MESSAGE_SIZE; // = 8;
//
//        /**
//         * Predefined Levels of Priorities. These correspond to the
//         * priority levels used by syslog(3).
//         **/
//        typedef enum {EMERG  = 0,
//		      FATAL  = 0,
//                      ALERT  = 100,
//                      CRIT   = 200,
//                      ERROR  = 300,
//                      WARN   = 400,
//                      NOTICE = 500,
//                      INFO   = 600,
//                      DEBUG  = 700,
//                      NOTSET = 800
//        } PriorityLevel;
//#endif
//    size_t i = 0;
//    while (i < 100) {
//        root.emerg("this is an emerg message");
//        root.fatal("this is fatal message");
//        root.alert("this is an a message");
//        root.crit("this is an cr message");
//        root.error("this is an er message");
//        root.warn("this is an wa message");
//        root.info("this is an in message");
//        root.debug("this is an de message");
//    }
//#if 0
//    printf();
//    extern int printf (const char *__restrict __format, ...);
//    //...指可变参数，参数个数不确定 类型不确定。
//#endif
//    //空间回收
//    log4cpp::Category::shutdown();
//    //poa pfa的patterlayout回收了两次
//    //每个appender对应一个layout，不要共用

//    log4cpp::OstreamAppender* osAppender =
//            new log4cpp::OstreamAppender("osAppender",&cout);
//    osAppender->setLayout(new log4cpp::BasicLayout());
//
//    log4cpp::Category& root = log4cpp::Category::getRoot();
//    root.addAppender(osAppender);
//    root.setPriority(log4cpp::Priority::DEBUG);
//
//    root.error("Hello log4cpp in a Error Message!");
//    root.warn("Hello log4cpp in a Warning Message!");
//
//    log4cpp::Category::shutdown();
