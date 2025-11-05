#include<iostream>
using  namespace  std;

typedef enum
{
	Tank_Type_56,
	Tank_Type_96,
	Tank_Type_Num
}Tank_Type;

class Tank
{
public:
	virtual const string& type() = 0;
};

class Tank_56 : public Tank
{
public:
	Tank_56(): m_strType("Tank_56")
	{

	}

	const string& type()override
	{
		cout << m_strType.data() << endl;
		return m_strType;
	}
private:
	string m_strType;
};

class Tank_96 : public Tank
{
public:
	Tank_96() :m_strType("Tank_96")
	{

	}

	const string& type()override
	{
		cout << m_strType.data() << endl;
		return m_strType;
	}
private:
	string m_strType;
};

//class Tank_Factory
//{
//public:
//	Tank* CreateTank(Tank_Type type)
//	{
//		switch (type)
//		{
//		case Tank_Type_56:
//			return new Tank_56();
//		case Tank_Type_96:
//			return new Tank_96();
//		default: return nullptr;
//		}
//	}
//};
//int  main(void)
//{
//	Tank_Factory* factory = new Tank_Factory();
//	Tank * tank56 = factory->CreateTank(Tank_Type_56);
//	tank56->type();
//
//	Tank* tank96 = factory->CreateTank(Tank_Type_96);
//	tank96->type();
//
//	delete factory;
//	factory = nullptr;
//	delete tank56;
//	tank56 = nullptr;
//	delete tank96;
//	tank96 = nullptr;
//	return 0;
//}

class TankFactory
{
public:
	virtual Tank* CreateTank() = 0;
};

class Tank56Factory : TankFactory
{
public:
	Tank* CreateTank()
	{
		return new Tank_56();
	}
};

class Tank96Factory : TankFactory
{
public:
	Tank* CreateTank()
	{
		return new Tank_96();
	}
};

int  main_Factory1_(void)
{
	Tank56Factory* factory56 = new Tank56Factory();
	Tank* Tank56 = factory56->CreateTank();
	const string& str1 = Tank56->type();
	//cout << str1 << endl;

	Tank96Factory* factory96 = new Tank96Factory();
	Tank* Tank96 = factory96->CreateTank();
	string* str2 = const_cast<string*>(&Tank96->type());
	*str2 = "KL";
	cout << *str2 << endl;
	cout << Tank96->type() << endl;

	delete factory56;
	factory56 = nullptr;

	delete factory96;
	factory96 = nullptr;

	delete Tank56;
	Tank56 = nullptr;

	delete Tank96;
	Tank96 = nullptr;
	return 0;
}