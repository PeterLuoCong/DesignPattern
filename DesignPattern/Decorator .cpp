#include<iostream>
using  namespace  std;

class Component
{
public:
	virtual ~Component()
	{

	}
	virtual void configuration() = 0;
};

class Car : public Component
{
public:
	void configuration()override
	{
		cout << "A Car" << endl;
	}
};

class DecoratorCar : public Component
{
public:
	DecoratorCar(Component* car) :m_pCar(car)
	{

	}
	void configuration()override
	{
		m_pCar->configuration();
	}

private:
	Component* m_pCar;
};

class DecoratorLED : public DecoratorCar
{
public:
	DecoratorLED(Component* car) :DecoratorCar(car)
	{

	}
	void configuration()override
	{
		DecoratorCar::configuration();
		addLED();
	}

private:
	void addLED()
	{
		cout << "Install LED" << endl;
	}
};

class DecoratorPC : public DecoratorCar
{
public:
	DecoratorPC(Component* car) : DecoratorCar(car)
	{

	}
	void configuration()override
	{
		DecoratorCar::configuration();
		addPC();
	}

private:
	void addPC()
	{
		cout << "Install PC" << endl;
	}
};

class DecoratorEPB : public DecoratorCar
{
public:
	DecoratorEPB(Component* car) : DecoratorCar(car)
	{

	}
	void configuration()override
	{
		DecoratorCar::configuration();
		addEPB();
	}

private:
	void addEPB()
	{
		cout << "Install EPB" << endl;
	}
};
int  main(void)
{
	Car* car = new Car;
	DecoratorLED* ledCar = new DecoratorLED(car);
	DecoratorPC* pcCar = new DecoratorPC(ledCar);
	DecoratorEPB* epbCar = new DecoratorEPB(pcCar);

	epbCar->configuration();

	delete epbCar;
	epbCar = nullptr;

	delete pcCar;
	pcCar = nullptr;

	delete ledCar;
	ledCar = nullptr;

	delete car;
	car = nullptr;

	return 0;
}