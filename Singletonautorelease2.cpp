#include <iostream>

using std::cout;
using std::endl;
//最优秀的解决方案
//单例模式2，自动释放，内部类+静态数据成员 解决问题
class Singleton
{
//    friend class AutoRelease;
public:
    static Singleton *getInstance()
    {
        if(nullptr == _pInstance)
        {
            _pInstance = new Singleton();
        }
        return _pInstance;
    }
//    static void destroy()//不能放Singleton里(会无穷递归stackoverflow)，放另一个类 里。另一个类销毁时，顺便销毁这个类。
//    {
//        if(_pInstance)//_pInstance != nullptr
//        {
//            delete _pInstance;
//            _pInstance = nullptr;
//        }
//    }
private:
    Singleton()
    /*:_pInstance(nullptr)Member initializer '_pInstance' does not name a non-static data member or base class*/
    {
        cout << "Singleton()" << endl;
//        AutoRelease ar;//生命周期在构造函数完了后 就结束了
    }
    ~Singleton()
    {
        cout << "~Singleton()" << endl;
    }

    class AutoRelease
    {
    public:
        AutoRelease()
        {cout<<"AutoRelease()"<<endl;}
        ~AutoRelease()
        {//拿下 冲突解决，绕过语法限制
            cout<<"~AutoRelease()"<<endl;
            if(/*Singleton::*/_pInstance)//_pInstance != nullptr
            {
                delete _pInstance;
                _pInstance = nullptr;
            }
        }
    };
private:
    static Singleton *_pInstance;
    static AutoRelease _ar;//_ar不能作为Sing一部分。_ar要放在全局区静态区
//    AutoRelease _ar;//死锁，因为～Sing()不执行，_ar不销毁。_ar不销毁，
};
Singleton::AutoRelease  Singleton::_ar;
Singleton               *Singleton::_pInstance = nullptr;//静态数据成员的初始化

int main(int argc, char **argv)
{
    Singleton *ps1 = Singleton::getInstance();//创建堆对象
    Singleton *ps2 = Singleton::getInstance();
    cout << "ps1 = " << ps1 << endl;
    cout << "ps2 = " << ps2 << endl;
    //不再需要下面这些手动释放。
//    Singleton::AutoRelease ar;//'AutoRelease' is a private member of 'Singleton'
//    AutoRelease();//这里有个临时对象？
//    Singleton::destroy();//对象销毁时， 自动调用析构函数
//    Singleton::destroy();
//    delete &ps1;
    return 0;
}

