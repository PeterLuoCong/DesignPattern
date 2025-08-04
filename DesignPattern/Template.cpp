#include<iostream>
using  namespace  std;

class Computer1
{
public:
	void product()
	{
		InstallCpu();
		InstallRam();
		InstallGraphicsCard();

		cout << endl;
	}
	virtual ~Computer1()
	{
		cout << "Computer Destructor" << endl;
	}

public:
	virtual void InstallCpu()
	{

	}
	virtual void InstallRam()
	{

	}
	virtual void InstallGraphicsCard()
	{

	}
};

class ComputerA : public Computer1
{ 
protected:
	void InstallCpu()override
	{
		cout << "ComputerA install Inter core5" << endl;
	}
	void InstallRam()override
	{
		cout << "ComputerA install 2G ram" << endl;
	}
	void InstallGraphicsCard()override
	{
		cout << "ComputerA install Gtx940 GraphicsCard" << endl;
	}
public:
	~ComputerA()
	{
		cout << "Computer A Destructor" << endl;
	}
};

class ComputerB : public Computer1
{
protected:
	void InstallCpu()override
	{
		cout << "ComputerB install Inter core7" << endl;
	}
	void InstallRam()override
	{
		cout << "ComputerB install 4G ram" << endl;
	}
	void InstallGraphicsCard()override
	{
		cout << "ComputerB install Gtx960 GraphicsCard" << endl;
	}
};


class ComputerC : public Computer1
{
protected:
	void InstallCpu()override
	{
		cout << "ComputerC install Inter core9" << endl;
	}
	void InstallRam()override
	{
		cout << "ComputerC install 6G ram" << endl;
	}
	void InstallGraphicsCard()override
	{
		cout << "ComputerC install Gtx1080 GraphicsCard" << endl;
	}
};

int  main_Computer(void)
{
	
	Computer1* p1 = new ComputerA();
	p1->product();

	ComputerB* p2 = new ComputerB();
	p2->product();

	ComputerC* p3 = new ComputerC();
	p3->product();

	delete p3;
	p3 = nullptr;

	delete p2;
	p2 = nullptr;

	delete p1;
	p1 = nullptr;

	return 0;
}