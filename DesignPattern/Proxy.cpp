#include<iostream>
using  namespace  std;

class Girl
{
public:
	Girl(string name = "Girl") :m_Name(name)
	{
		cout << "Girl Construct" << endl;
	}
	Girl(const Girl& girl)
	{
		cout << "const Girl& girl" << endl;
	}
	string getName()
	{
		return m_Name;
	}
	~Girl()
	{
		cout << "~Girl()" << endl;
	}
private:
	
	string m_Name;
};

class Profession
{
public:
	Profession()
	{
		cout << "Profession" << endl;
	}
	virtual ~Profession()
	{
		cout << "~Profession()" << endl;
	}
	virtual void profess() = 0;
};

class YoungMan : Profession
{
public:
	YoungMan(const Girl& girl) :m_girl(girl)
	{
		cout << "YoungMan" << endl;
	}
	void profess()
	{
		cout << "Young man Love " << m_girl.getName().data() << endl;
	}
	~YoungMan()
	{
		cout << "~YoungMan()" << endl;
	}
private:
	Girl m_girl;
};

class ManProxy : public Profession
{
public:
	ManProxy(const Girl& girl) :m_pMan(new YoungMan(girl))
	{
		cout << "ManProxy()" << endl;
	}
	~ManProxy()
	{
		cout << "~ManProxy()" << endl;
		delete m_pMan;
		m_pMan = nullptr;
	}
	void profess()
	{
		m_pMan->profess();
	}
private:
	YoungMan* m_pMan;
};

class PointTest1
{
public:
	PointTest1()
	{
		cout << "PointTest1()" << endl;
	}
	~PointTest1()
	{
		cout << "~PointTest1()" << endl;
	}
};

class PointTest2
{
public:
	PointTest2()
	{
		cout << "PointTest2()" << endl;
	}
	~PointTest2()
	{
		cout << "~PointTest2()" << endl;
	}

};
int  main_Proxy1(void)
{
	Girl girl("Princess");
	ManProxy* p_Proxy = new ManProxy(girl);
	p_Proxy->profess();

	delete p_Proxy;
	p_Proxy = nullptr;
	/*PointTest1 pt1;
	PointTest2 pt2;*/

	return 0;
}