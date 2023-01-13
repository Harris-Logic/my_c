#include <iostream>

using std::cout;
using std::endl;
class AutoRelease;

class Singleton
{
    friend class AutoRelease;
public:
    static Singleton *getInstance()
    {
        if(nullptr == _pInstance)
        {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }

    static void destroy()//不能放Singleton里(会无穷递归stackoverflow)，放另一个类 里。另一个类销毁时，顺便销毁这个类。
    {
        if(_pInstance)//_pInstance != nullptr
        {
            delete _pInstance;
            _pInstance = nullptr;
        }
    }
private:
    Singleton()
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

Singleton *Singleton::_pInstance = nullptr;//静态数据成员的初始化
class AutoRelease
{
public:
    AutoRelease()
    {cout<<"AutoRelease()"<<endl;}
    ~AutoRelease()
    {//拿下 冲突解决，绕过语法限制
        cout<<"~AutoRelease()"<<endl;
        if(Singleton::_pInstance)//_pInstance != nullptr
        {
            delete Singleton::_pInstance;
            Singleton::_pInstance = nullptr;
        }
    }
};
int main(int argc, char **argv)
{
    Singleton *ps1 = Singleton::getInstance();//创建堆对象
    Singleton *ps2 = Singleton::getInstance();
    cout << "ps1 = " << ps1 << endl;
    cout << "ps2 = " << ps2 << endl;

//    AutoRelease ar;
    AutoRelease();//这里有个临时对象？
//    Singleton::destroy();//对象销毁时， 自动调用析构函数
//    Singleton::destroy();
//    delete &ps1;
    return 0;
}

