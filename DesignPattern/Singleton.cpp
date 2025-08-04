// DesignPattern.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<mutex>
#include<atomic>
using  namespace  std;

//饿汉式：线程安全，注意一定要在合适的地方去delete它
class Singleton
{
public:
    static Singleton* getInstance();
private:
    Singleton() {}                                    //构造函数私有
    Singleton(const Singleton&) = delete;            //明确拒绝
    Singleton& operator=(const Singleton&) = delete ; //明确拒绝
    static Singleton* m_pSingleton;
};

Singleton* Singleton::m_pSingleton = new Singleton();

Singleton* Singleton::getInstance()
{
    return m_pSingleton;
}
//线程不安全
class Singleton1
{
public:
    static Singleton1& getInstance();
private:
    Singleton1() {}
    Singleton1(const Singleton1&) = delete;  //明确拒绝
    Singleton1& operator=(const Singleton1&) = delete; //明确拒绝
};

Singleton1& Singleton1::getInstance()
{
    static Singleton1 singleton;
    return singleton;
}

std::mutex mt;

class Singleton2
{
public:
    static Singleton2* getInstance();
private:
    Singleton2() {}                                    //构造函数私有
    Singleton2(const Singleton2&) = delete;            //明确拒绝
    Singleton2& operator=(const Singleton2&) = delete; //明确拒绝

    static Singleton2* m_pSingleton2;

};
Singleton2* Singleton2::m_pSingleton2 = NULL;

Singleton2* Singleton2::getInstance()
{
    if (m_pSingleton2 == NULL)
    {
        mt.lock();
        if (m_pSingleton2 == NULL)
        {
            m_pSingleton2 = new Singleton2();
        }
        mt.unlock();
    }
    return m_pSingleton2;
}


/*
* 关键代码：构造函数是私有的，不能通过赋值运算，拷贝构造等方式实例化对象。
*/
//懒汉式一般实现：非线程安全，getInstance返回的实例指针需要delete
class Singleton3
{
public:
    static Singleton3* getInstance();
    ~Singleton3() {}
private:
    Singleton3() {}                                        //构造函数私有
    Singleton3(const Singleton3& obj) = delete;            //明确拒绝
    Singleton3& operator=(const Singleton3& obj) = delete; //明确拒绝

    static Singleton3* m_pSingleton3;
};

Singleton3* Singleton3::m_pSingleton3 = NULL;
Singleton3* Singleton3::getInstance()
{
    if (m_pSingleton3 == NULL)
    {
        m_pSingleton3 = new Singleton3;
    }
    return m_pSingleton3;
}

class Singleton4
{
private:
    static Singleton4* m_pSingleton4;
    Singleton4()
    {

    }

    Singleton4(const Singleton4& obj) = delete;

    Singleton4& operator=(const Singleton4& obj) = delete;

public:

    static Singleton4* getInstance();

};

Singleton4* Singleton4::m_pSingleton4 = nullptr;

Singleton4* Singleton4::getInstance()
{
    if (m_pSingleton4 == nullptr)
    {
        m_pSingleton4 = new Singleton4();
    }
    return m_pSingleton4;
}


int main_Singleton()
{
   /* Singleton* instance = Singleton::getInstance();
    Singleton* instance2 = instance->getInstance();
    cout << reinterpret_cast<void*>(instance) << endl;
    cout << reinterpret_cast<void*>(instance2) << endl;*/

    Singleton1& instance = Singleton1::getInstance();
    Singleton1& instance2 = Singleton1::getInstance();
    cout << reinterpret_cast<void*>(&instance) << endl;
    cout << reinterpret_cast<void*>(&instance2) << endl;

  /*  Singleton3* instance = Singleton3::getInstance();
    Singleton3* instance1 = instance->getInstance();
    cout << reinterpret_cast<void*>(instance) << endl;
    cout << reinterpret_cast<void*>(instance1) << endl;*/


    //Singleton4* instance = Singleton4::getInstance();
    //Singleton4* instance1 = instance->getInstance();
    //cout << reinterpret_cast<void*>(instance) << endl;
    //cout << reinterpret_cast<void*>(instance1) << endl;


   // Singleton2*  instance = Singleton2::getInstance();
   // //Singleton2* instance2 = instance.getInstance();
   //cout << reinterpret_cast<void*>(&instance) << endl;
   ////cout << reinterpret_cast<void*>(&instance2) << endl;
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
