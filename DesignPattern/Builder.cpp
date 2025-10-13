#include<iostream>
#include<string>
using  namespace  std;

class Order
{
public:
	void setFood(const string& food)
	{
		m_Food = food;
	}
	string& food()
	{
		cout << m_Food << endl;
		return m_Food;
	}
	void setDrink(const string& drink)
	{
		m_Drink = drink;
	}
	string& drink()
	{
		cout << m_Drink << endl;
		return m_Drink;
	}
private:
	string m_Food;
	string m_Drink;
};

class OrderBuilder
{
public:
	virtual ~OrderBuilder()
	{
		cout << "~OrderBuilder()" << endl;
	}
	virtual void setOrderFood() = 0;
	virtual void setOrderDrink() = 0;
	virtual Order* getOrder() = 0;
};

class VagetarionOrderBuilder: public OrderBuilder
{
public:
	VagetarionOrderBuilder()
	{
		m_pOrder = new Order;
	}
	~VagetarionOrderBuilder()
	{
		cout << "~VagetarionOrderBuilder()" << endl;
		delete m_pOrder;
		m_pOrder = nullptr;
	}
	void setOrderFood()override
	{
		m_pOrder->setFood("vagetable salad");
	}
	void setOrderDrink()override
	{
		m_pOrder->setDrink("water");
	}
	Order* getOrder()override
	{
		return m_pOrder;
	}
private:
	Order* m_pOrder;
};

class MeatOrderBuilder : public OrderBuilder
{
public:
	MeatOrderBuilder()
	{
		m_pOrder = new Order;
	}
	~MeatOrderBuilder()
	{
		cout << "~MeatOrderBuilder()" << endl;
		delete m_pOrder;
		m_pOrder = nullptr;
	}
	void setOrderFood()override
	{
		m_pOrder->setFood("beef");
	}
	void setOrderDrink()override
	{
		m_pOrder->setDrink("beer");
	}
	Order* getOrder()
	{
		return m_pOrder;
	}

private:
	Order* m_pOrder;
};

class Director
{
public:
	Director(OrderBuilder* OrderBuilder) :m_pOrderBuilder(OrderBuilder)
	{

	}
	void Construct()
	{
		m_pOrderBuilder->setOrderFood();
		m_pOrderBuilder->setOrderDrink();
	}

private:
	OrderBuilder* m_pOrderBuilder;
};

int  main_OrderBuilder(void)
{
	MeatOrderBuilder* m_OrderBuilder = new MeatOrderBuilder();
	Director* director = new Director(m_OrderBuilder);
	director->Construct();
	Order* order = m_OrderBuilder->getOrder();
	order->food();
	order->drink();

	delete m_OrderBuilder;
	m_OrderBuilder = nullptr;

	delete director;
	director = nullptr;

	//VagetarionOrderBuilder* m_OrderBuilder = new VagetarionOrderBuilder();
	//Director* director = new Director(m_OrderBuilder);
	//director->Construct();
	//Order* order = m_OrderBuilder->getOrder();
	//order->food();
	//order->drink();

	//delete m_OrderBuilder;
	//m_OrderBuilder = nullptr;

	//delete director;
	//director = nullptr;

	//int* p = new int;
	//delete p;
	//p = nullptr;
	//delete p;
	//p = nullptr;
	//delete p;
	//p = nullptr;
	return 0;
}