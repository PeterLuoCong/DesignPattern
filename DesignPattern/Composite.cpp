#include<iostream>
#include<list>
#include<memory>

using  namespace  std;

class Company
{
public:
	Company(const string& name) :m_name(name)
	{

	}
	virtual ~Company()
	{
		cout << "~Company()" << endl;
	}
	virtual void add(Company*) = 0;
	virtual void remove(const string&) = 0;
	virtual void display(int depth) = 0;
	virtual const string& name()
	{
		return m_name;
	}
	
protected:
	string m_name;
};

class HeadCompany : public Company
{
public:
	HeadCompany(const string& name) :Company(name)
	{

	}
	virtual ~HeadCompany()
	{
		cout << "~HeadCompany()" << endl;
	}

	void add(Company* company)override
	{
		shared_ptr<Company> temp(company);
		m_companyList.push_back(temp);
	}
	void remove(const string& strName)override
	{
		list<shared_ptr<Company>>::iterator iter = m_companyList.begin();
		for (; iter != m_companyList.end();iter++)
		{
			if ((*iter)->name() == strName)
			{
				m_companyList.erase(iter);
				return;
			}
		}
	}

	void display(int depth)
	{
		for (int i = 0; i < depth; ++i)
		{
			cout << "-";
		}
		cout << this->name().data() << endl;
		list<shared_ptr<Company>>::iterator iter= m_companyList.begin();
		for (; iter != m_companyList.end(); ++iter)
		{
			iter->get()->display(depth + 1);
		}
	}


private:
	list<shared_ptr<Company>> m_companyList;
};

class ResearchCompany : public Company
{
public:
	ResearchCompany(const string& name) :Company(name)
	{

	}

	virtual ~ResearchCompany()
	{
		cout << "~ResearchCompany()" << endl;
	}

	void add(Company* company)override
	{

	}
	void remove(const string&)
	{

	}

	void display(int depth)
	{
		for (int i = 0; i < depth; ++i)
		{
			cout << "-";
		}
		cout << m_name.data() << endl;
	}
};

class SalesCompany : public Company
{
public:
	SalesCompany(const string& name) :Company(name)
	{

	}

	virtual ~SalesCompany()
	{
		cout << "~SalesCompany()" << endl;
	}

	void add(Company* company)override
	{

	}
	void remove(const string&)
	{

	}

	void display(int depth)
	{
		for (int i = 0; i < depth; ++i)
		{
			cout << "-";
		}
		cout << m_name.data() << endl;
	}
};


class FinanceCompany : public Company
{
public:
	FinanceCompany(const string& name) :Company(name)
	{
		
	}

	virtual ~FinanceCompany()
	{
		cout << "~FinanceCompany()" << endl;
	}

	void add(Company* company)override
	{

	}
	void remove(const string&)
	{

	}

	void display(int depth)
	{
		for (int i = 0; i < depth; ++i)
		{
			cout << "-";
		}
		cout << m_name.data() << endl;
	}
};
int  main_Composite(void)
{
	HeadCompany* headRoot = new HeadCompany("Head Root Company");

	HeadCompany* childRoot1 = new HeadCompany("Child Company A");
	ResearchCompany* r1 = new ResearchCompany("Research Company A");
	SalesCompany* s1 = new SalesCompany("Sales Company A");
	SalesCompany* s2 = new SalesCompany("Sales Company B");
	FinanceCompany* f1 = new FinanceCompany("FinanceCompany A");
	
	childRoot1->add(r1);
	childRoot1->add(s1);
	childRoot1->add(s2);
	childRoot1->add(f1);

	HeadCompany* childRoot2 = new HeadCompany("Child Company B");
	ResearchCompany* r2 = new ResearchCompany("Research Company B");
	SalesCompany* s3 = new SalesCompany("Sales Company C");
	SalesCompany* s4 = new SalesCompany("Sales Company D");
	FinanceCompany* f2 = new FinanceCompany("FinanceCompany B");

	childRoot2->add(r2);
	childRoot2->add(s3);
	childRoot2->add(s4);
	childRoot2->add(f2);

	headRoot->add(childRoot1);
	headRoot->add(childRoot2);
	headRoot->display(1);

	cout << "\n***************\n" << endl;

	childRoot1->remove("Sales Company B");
	headRoot->display(1);

	cout << "\n***************\n" << endl;

	delete headRoot;
	headRoot = nullptr;
	return 0;
}