#include<iostream>
using  namespace  std;

class Clone
{
public:
	virtual Clone* clone() = 0;
	virtual void show() = 0;
};

class Sheep : public Clone
{
public:
	Sheep(int id, string name) : m_id(id), m_name(name)
	{
		cout << "Sheep id address:" << &m_id << endl;
		cout << "Sheep name address:" << &m_name << endl;
	}
	~Sheep()
	{

	}

	Sheep(const Sheep& obj)
	{
		this->m_id = obj.m_id;
		this->m_name = obj.m_name;
		cout << "sheep(const sheep& obj) id address:" << &m_id << endl;
		cout << "sheep(const sheep& obj) name address:" << &m_name << endl;
	}
	Clone* clone()override
	{
		return new Sheep(*this);
	}
	void show()
	{
		cout << "id : " << m_id << endl;
		cout << "name : " << m_name.data() << endl;
	}
	void setid(int id)
	{
		m_id = id;
	}
private:
	int m_id;
	string m_name;
};

int main_Prototype(void)
{
	Clone* s1 = new Sheep(1, "abs");
	//s1->show();
	Clone* s2 = s1->clone();
	cout << s1 << endl << s2 << endl;
	//s2->show();

	s2->show();
	Sheep* s3 = dynamic_cast<Sheep*>(s2);
	s3->setid(9);
	s2->show();
	s3->setid(11);
	s2->show();
	s1->show();

	cout << s2 << endl << s3 << endl;
	return 0;
}