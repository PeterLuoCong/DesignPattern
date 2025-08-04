#include<iostream>
using  namespace  std;

class Mediator;

class Businessman
{
public:
	Businessman()
	{

	}
	Businessman(Mediator* m)
	{
		m_pMediator = m;
	}
	virtual ~Businessman()
	{

	}
	virtual void setMediator(Mediator* m)
	{
		m_pMediator = m;
	}

	virtual void sendMessage(const string& s) = 0;
	virtual void getMessage(const string& s) = 0;
protected:
	Mediator* m_pMediator;
};

class Mediator
{
public:
	virtual ~Mediator()
	{

	}
	virtual void setBuyer(Businessman* buyer) = 0;
	virtual void setSeller(Businessman* seller) = 0;
	virtual void send(const string& message, Businessman* man) = 0;

};

class Buyer : public Businessman
{
public:
	Buyer()
	{

	}
	Buyer(Mediator* p_Mediator):Businessman(p_Mediator)
	{

	}
	virtual void sendMessage(const string& message)override
	{
		m_pMediator->send(message, this);
	}

	virtual void getMessage(const string& message)override
	{
		cout << message.data() << endl;
	}
};

class Seller : public Businessman
{
public:
	Seller()
	{

	}
	Seller(Mediator* p_Mediator) :Businessman(p_Mediator)
	{

	}
	virtual void sendMessage(const string& message)override
	{
		m_pMediator->send(message, this);
	}

	virtual void getMessage(const string& message)override
	{
		cout << message.data() << endl;
	}
};

class HouseMediator : public Mediator
{
public:
	void setBuyer(Businessman* man)override
	{
		m_Buyer = man;
	}
	void setSeller(Businessman* man)override
	{
		m_Seller = man;
	}

	void send(const string& message, Businessman* man)override
	{
		if (man == m_Buyer)
		{
			m_Seller->getMessage(message);
		}
		else
		{
			m_Buyer->getMessage(message);
		}
	}
private:
	Businessman* m_Buyer;
	Businessman* m_Seller;
};
int  main554311(void)
{
	HouseMediator* mediator = new HouseMediator();
	Buyer* buyer = new Buyer(mediator);
	Seller* seller = new Seller(mediator);
	mediator->setBuyer(buyer);
	mediator->setSeller(seller);

	buyer->sendMessage("Sell not to sell?");
	seller->sendMessage("of course selling");

	delete buyer;
	buyer = nullptr;

	delete seller;
	seller = nullptr;

	delete mediator;
	mediator = nullptr;
	return 0;
}