#include<iostream>
#include<list>
#include<memory>
using  namespace  std;

class View;

class DataModel
{
public:
	virtual ~DataModel()
	{

	}

	virtual void addView(View* view) = 0;
	virtual void removeView(View* view) = 0;
	virtual void notify() = 0;
};

class View
{
public:
	virtual ~View()
	{
		cout << "~View()" << endl;
	}

	virtual void update() = 0;
	virtual void setViewName(const string& str) = 0;
	virtual const string& name() = 0;
};

class IntDataModel : public DataModel
{
public:
	~IntDataModel()
	{
		m_pViewList.clear();
	}

	virtual void addView(View* pView)override
	{
		shared_ptr<View> temp(pView);
		auto iter = find(m_pViewList.begin(), m_pViewList.end(), temp);
		if (iter == m_pViewList.end())
		{
			m_pViewList.push_front(temp);
		}
		else
		{
			cout << "View already exists" << endl;
		}
	}
	virtual void removeView(View* pView)override
	{
		auto iter = m_pViewList.begin();
		for (; iter != m_pViewList.end(); ++iter)
		{
			if ((*iter).get() == pView)
			{
				m_pViewList.erase(iter);
				return;
			}
		}
	}

	virtual void notify()override
	{
		auto iter = m_pViewList.begin();
		for (; iter != m_pViewList.end(); iter++)
		{
			(iter->get())->update();
		}
	}

private:
	list<shared_ptr<View>> m_pViewList;
};

class TableView : public View
{
public:
	TableView() :m_name("unknow")
	{

	}
	TableView(const string& name) :m_name(name)
	{

	}
	~TableView()
	{
		cout << "~TableView(): " << m_name.data() << endl;
	}

	void setViewName(const string& name)
	{
		m_name = name;
	}
	const string& name()
	{
		return m_name;
	}

	void update()
	{
		cout << m_name.data() << " update" << endl;
	}
private:
	string m_name;
};
int  main(void)
{
	View* v1 = new TableView("TableView1");
	View* v2 = new TableView("TableView2");
	View* v3 = new TableView("TableView3");
	View* v4 = new TableView("TableView4");

	IntDataModel* model = new IntDataModel();
	model->addView(v1);
	model->addView(v2);
	model->addView(v3);
	model->addView(v4);

	model->notify();
	model->removeView(v1);
	model->notify();

	delete model;
	model = nullptr;
	return 0;
}