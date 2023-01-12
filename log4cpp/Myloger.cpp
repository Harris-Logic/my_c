//
// Created by Logic on 2023/1/12.
//

#include "Myloger.h"
Mylogger *Mylogger::_pIstc = nullptr;
Mylogger *Mylogger::getInstance()//单例模式
{
    if(nullptr == _pIstc)
    {
        _pIstc = new Mylogger();
    }
    return _pIstc;
}
void Mylogger::destroy() {
    if(nullptr == _pIstc)
    {
    }
    else
    {
        delete  _pIstc;
        _pIstc = nullptr;
    }
}

Mylogger::Mylogger()
:_mycat(Category::getRoot().getInstance("myCat"))
{
    cout<<"myloger()"<<endl;
    PatternLayout *ppl1 = new PatternLayout();
    ppl1->setConversionPattern("%d %c [%%p] %m%n");
    PatternLayout *ppl2 = new PatternLayout();
    ppl2->setConversionPattern("%d %c [%%p] %m%n");
    //日志目的地
    OstreamAppender *poa=new OstreamAppender("Ostreamap",&cout);
    poa->setLayout(ppl1);
    FileAppender *pfa = new FileAppender("Fielap","wd.txt");
    pfa->setLayout(ppl2);

    //过滤器
    _mycat.setPriority(Priority::DEBUG);
    _mycat.addAppender(poa);
    _mycat.addAppender(pfa);
}

Mylogger::~Mylogger()
{
    cout<<"执行"<<"析构函数"<<std::endl;
    Category::shutdown();
}
void Mylogger::warn(const char *msg)
{
    _mycat.warn(msg);
}
void Mylogger::error(const char *msg)
{
    _mycat.error(msg);
}
void Mylogger::debug(const char *msg)
{
    _mycat.debug(msg);
}
void Mylogger::info(const char *msg)
{
    _mycat.info(msg);
}

//void Mylogger::warn(const char *msg) {
//    PatternLayout *ppl = new PatternLayout();
////    ppl->setConversionPattern("%m%n");
//    OstreamAppender *poa = new OstreamAppender("testostream"
//            ,&cout);
////    RollingFileAppender *prfa=new RollingFileAppender("RollingFileAppender"
////            ,"wd.log",5*1024,3);
//    poa->setLayout(ppl);
////    prfa->setLayout(ppl);
//    Category &root = Category::getRoot().getInstance("WARN");
//    root.addAppender(poa);
////    root.addAppender(prfa);
//    root.setPriority(Priority::WARN);
//    root.warn(msg);
////    log4cpp::Category::shutdown();
//}
//void Mylogger::error(const char *msg){
//    PatternLayout *ppl = new PatternLayout();
////    ppl->setConversionPattern("%m%n");
//    OstreamAppender *poa = new OstreamAppender("testostream"
//            ,&cout);
////    RollingFileAppender *prfa=new RollingFileAppender("RollingFileAppender"
////            ,"wd.log",5*1024,3);
//    poa->setLayout(ppl);
////    prfa->setLayout(ppl);
//    Category &root = Category::getRoot().getInstance("ERROR");
//    root.addAppender(poa);
////    root.addAppender(prfa);
//    root.setPriority(Priority::ERROR);
//    root.error(msg);
////    log4cpp::Category::shutdown();
//}
//void Mylogger::debug(const char *msg){
//    PatternLayout *ppl = new PatternLayout();
//    ppl->setConversionPattern("%m%n");
//    OstreamAppender *poa = new OstreamAppender("testostream"
//            ,&cout);
////    RollingFileAppender *prfa=new RollingFileAppender("RollingFileAppender"
////            ,"wd.log",5*1024,3);
//    poa->setLayout(ppl);
////    prfa->setLayout(ppl);
//    Category &root = Category::getRoot().getInstance("DEBUG");
//    root.addAppender(poa);
////    root.addAppender(prfa);
//    root.setPriority(Priority::DEBUG);
//    root.warn(msg);
////    log4cpp::Category::shutdown();
//}
//void Mylogger::info(const char *msg){
//    PatternLayout *ppl = new PatternLayout();
//    ppl->setConversionPattern("%m%n");
//    OstreamAppender *poa = new OstreamAppender("testostream"
//            ,&cout);
////    RollingFileAppender *prfa=new RollingFileAppender("RollingFileAppender"
////            ,"wd.log",5*1024,3);
//    poa->setLayout(ppl);
////    prfa->setLayout(ppl);
//    Category &root = Category::getRoot().getInstance("INFO");
//    root.addAppender(poa);
////    root.addAppender(prfa);
//    root.setPriority(Priority::INFO);
//    root.warn(msg);
////    log4cpp::Category::shutdown();
//}
//void Mylogger::fatal(const char *msg){
//    PatternLayout *ppl = new PatternLayout();
////    ppl->setConversionPattern("%m%n");
//    OstreamAppender *poa = new OstreamAppender("testostream"
//            ,&cout);
////    RollingFileAppender *prfa=new RollingFileAppender("RollingFileAppender"
////            ,"wd.log",5*1024,3);
//    poa->setLayout(ppl);
////    prfa->setLayout(ppl);
//    Category &root = Category::getRoot().getInstance("FATAL");
//    root.addAppender(poa);
////    root.addAppender(prfa);
//    root.setPriority(Priority::FATAL);
//    root.warn(msg);
////    log4cpp::Category::shutdown();
//}
//void Mylogger::crit(const char *msg){
//    PatternLayout *ppl = new PatternLayout();
//    ppl->setConversionPattern("%m%n");
//    OstreamAppender *poa = new OstreamAppender("testostream"
//            ,&cout);
////    RollingFileAppender *prfa=new RollingFileAppender("RollingFileAppender"
////            ,"wd.log",5*1024,3);
//    poa->setLayout(ppl);
////    prfa->setLayout(ppl);
//    Category &root = Category::getRoot().getInstance("CRIT");
//    root.addAppender(poa);
////    root.addAppender(prfa);
//    root.setPriority(Priority::CRIT);
//    root.warn(msg);
////    log4cpp::Category::shutdown();
//}