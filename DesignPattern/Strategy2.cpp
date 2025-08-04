#include<iostream>
#include<functional>
using namespace  std;

void adcHurt(void)
{
	cout << "adcHurt" << endl;
}

void apcHurt(void)
{
	cout << "apcHurt" << endl;
}

class Soldier1
{
public:
	typedef void(*Function)(void);
	Soldier1(Function fun) :m_fun(fun)
	{

	}
	void attack()
	{
		m_fun();
	}
private:
	Function m_fun;
};

class Mage1
{
public:
	typedef std::function<void(void)> Function;
	Mage1(Function fun) :m_fun(fun)
	{

	}
	void attack()
	{
		m_fun();
	}
private:
	Function m_fun;
};
int  main_Strategy2(void)
{
	Soldier1 s(adcHurt);
	Soldier1 s1(apcHurt);
	s.attack();
	s1.attack();
	Mage1 m(adcHurt);
	m.attack();
	Mage1 m1(apcHurt);
	m1.attack();

	return 0;
}