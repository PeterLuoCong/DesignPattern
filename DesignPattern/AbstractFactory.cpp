#include<iostream>
using  namespace   std;

class Coat
{
public:
	virtual const string& color() = 0;
};

class BlackCoat : public Coat
{
public:
	BlackCoat() :Coat(),m_Color("BlackCoat")
	{

	}
	const string& color()
	{
		cout << m_Color << endl;
		return m_Color;
	}
private:
	string m_Color;
};

class WhiteCoat : public Coat
{
public:
	WhiteCoat() :Coat(), m_Color("WhiteCoat")
	{

	}
	const string& color()
	{
		cout << m_Color << endl;
		return m_Color;
	}
private:
	string m_Color;
};

class Pants
{
public:
	virtual const string & color() = 0;
};

class BlackPants : public Pants
{
public:
	BlackPants() :Pants(), m_Color("BlackPants")
	{

	}
	const string& color()override
	{
		cout << m_Color << endl;
		return m_Color;
	}
private:
	string m_Color;
};

class WhitePants : public Pants
{
public:
	WhitePants() :Pants(), m_Color("WhitePants")
	{

	}
	const string& color()override
	{
		cout << m_Color << endl;
		return m_Color;
	}
private:
	string m_Color;
};

class Factory
{
public:
	virtual Coat* CreateCoat() = 0;
	virtual Pants* CreatePants() = 0;
};

class BlackFactory : Factory
{
public:
	Coat* CreateCoat()override
	{
		return new BlackCoat();
	}

	Pants* CreatePants()override
	{
		return new BlackPants();
	}
};

class WhiteFactory : Factory
{
public:
	Coat* CreateCoat()override
	{
		return new WhiteCoat();
	}

	Pants* CreatePants()override
	{
		return new WhitePants();
	}
};

int  main_AbstractFac(void)
{
	BlackFactory* blackfactory = new BlackFactory();
	BlackCoat* blackcoat = dynamic_cast<BlackCoat*>(blackfactory->CreateCoat());
	BlackPants* blackpants = dynamic_cast<BlackPants*>(blackfactory->CreatePants());
	string str1 = blackcoat->color();
	string str2 = blackpants->color();
	cout << endl << endl;
	cout << str1 << endl << str2 << endl;
	
	WhiteFactory* whitefactory = new WhiteFactory();
	Coat* whitecoat = dynamic_cast<WhiteCoat*>(whitefactory->CreateCoat());
	Pants* whitepants = dynamic_cast<WhitePants*>(whitefactory->CreatePants());
	string str3 = whitecoat->color();
	string str4 = whitepants->color();
	cout << endl << endl;
	cout << str3 << endl << str4 << endl;
	return 0;
}

