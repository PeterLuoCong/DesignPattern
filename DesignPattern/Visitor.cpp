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
		cout << "���˵ĸ������۸ø����Ǻܳɹ�" << endl;
	}

	void getWomanResult(Woman* woman) override
	{
		cout << "Ů�˵ĸ������۸ø����Ǻܳɹ�" << endl;
	}
};

class Fail :public Action
{
public:
	void getManResult(Man* man) override
	{
		cout << "���˵ĸ������۸ø�����ʧ��" << endl;
	}

	void getWomanResult(Woman* woman) override
	{
		cout << "Ů�˵ĸ������۸ø�����ʧ��" << endl;
	}
};

class Person
{
public:
	//�ṩһ�������÷����߿��Է���
	virtual void accept(Action* action) = 0;
};

//�������õ���˫���ɣ��������ڿͻ��˳����У��������״̬��Ϊ�������ݽ�Man�У���һ�η��ɣ�
//Ȼ����Man�е�����Ϊ�����ġ����巽���� getManResultͬʱ���Լ���Ϊ����������ɵڶ��η���
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

//���ݽṹ������ܶ��ˣ�Man��Woman������װ����ĳһ�����۵�������
class ObjectStructure
{
public:
	//��ӵ�list
	void attach(Person* p)
	{
		persons.push_back(p);
	}
	//�Ƴ�
	void detach(Person* p)
	{
		persons.remove(p);
		delete p;
		p = nullptr;
	}

	//��ʾ�������
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

int main_Visitor(int argc, char* argv[])
{
	//����ObjectStructure�����Դ����ܶ����ͬ��ObjectStructure������ͬ���ۣ�Ȼ���ͬ�����۵��˷ŵ�һ��ObjectStructure�У�
	ObjectStructure* objectStructure = new ObjectStructure;
	objectStructure->attach(new Man);
	objectStructure->attach(new Woman);

	//������ֻ�óɹ�
	Success* success = new Success;
	objectStructure->display(success);
	cout << "=======================" << endl;
	//�������ʧ����
	Fail* fail = new Fail;
	objectStructure->display(fail);
	return 0;
}

