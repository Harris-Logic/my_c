#include <iostream>
#include <pthread.h>
#include "stdlib.h"

using std::cout;
using std::endl;

//单例模式4
//pthread_once多线程中，第一次推开门的人。前一个参数固定下来即可 <pthread.h>
class Singleton
{
//    friend class AutoRelease;
public:
    static Singleton *getInstance()
    {
//        对‘pthread_once’未定义的引用: -lpthread
//        cmakelists.txt里加target_link_libraries(_M pthread)#相当于 -lpthread
        pthread_once(&_once,init);//error: invalid use
        // of non-static member function ‘void Singleton::init()’
        //静态成员不能访问非静态成员函数 的意思
        return _pInstance;
    }
    static void init()
    {
        _pInstance = new Singleton();
        atexit(destroy);
    }

    static void destroy()//不能放Singleton里(会无穷递归stackoverflow)，放另一个类 里。另一个类销毁时，顺便销毁这个类。
    {
        cout<<"void destroy()"<<endl;
        if(_pInstance)//_pInstance != nullptr
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
private:
    Singleton()
    /*:_pInstance(nullptr)Member initializer '_pInstance' does not name a non-static data member or base class*/
    {
        cout << "Singleton()" << endl;
    }
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }
private:
    static pthread_once_t _once;
    static Singleton *_pInstance;
};
Singleton *Singleton::_pInstance = Singleton::getInstance();//饿汉模式
pthread_once_t Singleton::_once = PTHREAD_ONCE_INIT;
//Singleton *Singleton::_pInstance = nullptr;//饱汉模式 懒汉模式

int main(int argc, char **argv)
{
    Singleton *ps1 = Singleton::getInstance();//多线程pv操作
    Singleton *ps2 = Singleton::getInstance();
    Singleton *ps3 = Singleton::getInstance();
    cout << "ps1 = " << ps1 << endl;
    cout << "ps2 = " << ps2 << endl;
    cout << "ps3 = " << ps3 << endl;
    //不再需要下面这些手动释放。
//    Singleton::AutoRelease ar;//'AutoRelease' is a private member of 'Singleton'
//    AutoRelease();//这里有个临时对象？
//    Singleton::destroy();//对象销毁时， 自动调用析构函数
//    Singleton::destroy();
//    delete &ps1;
    return 0;
}

