//
// Created by Logic on 2023/1/12.
//

#ifndef DEPLOYMENT_MYLOGER_H
#define DEPLOYMENT_MYLOGER_H
#include <iostream>
#include "string"
#include "ostream"
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/SimpleLayout.hh>
#include "log4cpp/OstreamAppender.hh"
#include "log4cpp/Category.hh"
#include <log4cpp/Priority.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/PatternLayout.hh>
#include <log4cpp/FileAppender.hh>
#include <log4cpp/RollingFileAppender.hh>

#define prefix(msg) (string(__FILE__)+string(":")\
+string(__FUNCTION__ )+string(":")\
+string(std::to_string(__LINE__))+string(":")\
+string(msg)).c_str()
#define logWarn(msg) Mylogger::getInstance()->warn(prefix(msg))
#define logError(msg) Mylogger::getInstance()->error(prefix(msg))
#define logInfo(msg) Mylogger::getInstance()->info(prefix(msg))
#define logDebug(msg) Mylogger::getInstance()->debug(prefix(msg))
using std::cout;
using std::endl;
using std::string;
using std::ostringstream;
using namespace log4cpp;//引出 命名空间

class Mylogger{
public:
//    Mylogger(const char *name)
//    :_Name(name){}
//
    static Mylogger *getInstance();//单例模式

    static void destroy();

    void warn(const char *msg);
    void error(const char *msg);
    void debug(const char *msg);
    void info(const char *msg);
//    void fatal(const char *msg);
//    void crit(const char *msg);

private:
    Mylogger(/*const char *name*/);
    ~Mylogger();
private:
    static Mylogger *_pIstc;
    Category &_mycat;

};


#endif //DEPLOYMENT_MYLOGER_H
