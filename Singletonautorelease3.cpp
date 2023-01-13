#include <iostream>

using std::cout;
using std::endl;

//单例模式3，atexit()+饿汉模式 多线程安全问题解决
class Singleton
{
//    friend class AutoRelease;
public:
    static Singleton *getInstance()
    {
        //存在多线程不安全 的问题
        if(nullptr == _pInstance)
        {
            _pInstance = new Singleton();
            atexit(destroy);
        }
//        atexit(destroy);
        return _pInstance;
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
    static Singleton *_pInstance;
};
Singleton *Singleton::_pInstance = Singleton::getInstance();//饿汉模式
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

