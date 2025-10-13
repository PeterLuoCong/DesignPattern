#include <iostream>
#include <list>

class Man;
class Woman;
using namespace std;

class Action
{
public:
	virtual void getManResult(Man* man) = 0;
	virtual void getWomanResult(Woman* woman) = 0;

private:
};

class Success :public Action
{
public:
	void getManResult(Man* man) override
	{
		cout << "男人的给的评价该歌手是很成功" << endl;
	}

	void getWomanResult(Woman* woman) override
	{
		cout << "女人的给的评价该歌手是很成功" << endl;
	}
};

class Fail :public Action
{
public:
	void getManResult(Man* man) override
	{
		cout << "男人的给的评价该歌手是失败" << endl;
	}

	void getWomanResult(Woman* woman) override
	{
		cout << "女人的给的评价该歌手是失败" << endl;
	}
};

class Person
{
public:
	//提供一个方法让访问者可以访问
	virtual void accept(Action* action) = 0;
};

//这里用用到了双分派，即首先在客户端程序中，将具体的状态作为参数传递进Man中（第一次分派）
//然后在Man中调用作为参数的“具体方法” getManResult同时将自己作为参数传入完成第二次分派
class Man :public Person
{
public:
	void accept(Action* action) override
	{
		action->getManResult(this);
	}
};

class Woman : public Person
{
public:
	void accept(Action* action) override
	{
		action->getWomanResult(this);
	}
};

//数据结构，管理很多人（Man、Woman）用来装符合某一个评价的所有人
class ObjectStructure
{
public:
	//添加到list
	void attach(Person* p)
	{
		persons.push_back(p);
	}
	//移除
	void detach(Person* p)
	{
		persons.remove(p);
		delete p;
		p = nullptr;
	}

	//显示测评情况
	void display(Action* action)
	{
		for (auto value : persons)
		{
			value->accept(action);
		}
	}
private:
	list<Person*> persons;
};

int main_Visitor1(int argc, char* argv[])
{
	//创建ObjectStructure（可以创建很多个不同的ObjectStructure来代表不同评价，然后把同样评价的人放到一个ObjectStructure中）
	ObjectStructure* objectStructure = new ObjectStructure;
	objectStructure->attach(new Man);
	objectStructure->attach(new Woman);

	//假如歌手获得成功
	Success* success = new Success;
	objectStructure->display(success);
	cout << "=======================" << endl;
	//假如歌手失败了
	Fail* fail = new Fail;
	objectStructure->display(fail);
	return 0;
}

