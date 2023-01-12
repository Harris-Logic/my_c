cmake_minimum_required(VERSION 3.10.2)

set(CMAKE_CXX_STANDARD 14)

include_directories(/usr/local/include/log4cpp)
link_directories("/usr/local/include/log4cpp")
ADD_EXECUTABLE(_M  zuoyelog4fengzhuang.cpp Myloger.cpp)
#相当于 -lpthread -llog4cpp 必须分开写！
target_link_libraries(_M log4cpp)#相当于 -llog4cpp
target_link_libraries(_M pthread)#相当于 -lpthread

ADD_COMPILE_OPTIONS(-fno-elide-constructors)

#错误的#ADD_COMPILE_OPTIONS(-llog4cpp -lpthread)
#target_include_directories(_M
#        PUBLIC
#        /usr/local/include/)
#ADD_EXECUTABLE(_M zuoyeholybable_dic.cpp ihead.h)