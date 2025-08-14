#include <iostream>
#include <string>
#include <vector>

using namespace std;

//����������,���ڶ���õ���ʼ���󡢵õ���һ�������ж��Ƿ񵽽�β����ǰ����ȳ��󷽷���ͳһ�ӿ�
class Iterator
{
public:
    Iterator() {};
    virtual ~Iterator() {};
    virtual string First() = 0;
    virtual string Next() = 0;
    virtual string CurrentItem() = 0;
    virtual bool IsDone() = 0;
};

//�ۼ�������
class Aggregate
{
public:
    virtual int Count() = 0;
    virtual void Push(const string& strValue) = 0;
    virtual string Pop(const int nIndex) = 0;
    virtual Iterator* CreateIterator() = 0;
};

//����������࣬�̳�Iterator ʵ�ֿ�ʼ����һ�����Ƿ��β����ǰ����ȷ���
class ConcreteIterator : public Iterator
{
public:
    ConcreteIterator(Aggregate* pAggregate) :m_nCurrent(0), Iterator()
    {
        m_Aggregate = pAggregate;
    }
    string First()
    {
        return m_Aggregate->Pop(0);
    }
    string Next()
    {
        string strRet;
        m_nCurrent++;
        if (m_nCurrent < m_Aggregate->Count())
        {
            strRet = m_Aggregate->Pop(m_nCurrent);
        }
        return strRet;
    }
    string CurrentItem()
    {
        return m_Aggregate->Pop(m_nCurrent);
    }
    bool IsDone()
    {
        return ((m_nCurrent >= m_Aggregate->Count()) ? true : false);
    }
private:
    Aggregate* m_Aggregate;
    int m_nCurrent;
};

//����ۼ��� �̳�
class ConcreteAggregate : public Aggregate
{
public:
    ConcreteAggregate() :m_pIterator(NULL)
    {
        m_vecItems.clear();
    }
    ~ConcreteAggregate()
    {
        if (NULL != m_pIterator)
        {
            delete m_pIterator;
            m_pIterator = NULL;
        }
    }
    Iterator* CreateIterator()
    {
        if (NULL == m_pIterator)
        {
            m_pIterator = new ConcreteIterator(this);
        }
        return m_pIterator;
    }
    int Count()
    {
        return m_vecItems.size();
    }
    void Push(const string& strValue)
    {
        m_vecItems.push_back(strValue);
    }
    string Pop(const int nIndex)
    {
        string strRet;
        if (nIndex < Count())
        {
            strRet = m_vecItems[nIndex];
        }
        return strRet;
    }
private:
    vector<string> m_vecItems;
    Iterator* m_pIterator;


};
int main_Iterator()
{
    ConcreteAggregate* pName = NULL;
    pName = new ConcreteAggregate();
    if (NULL != pName)
    {
        pName->Push("hello");
        pName->Push("world");
        pName->Push("ShenZhen");
    }
    Iterator* iter = NULL;
    iter = pName->CreateIterator();
    if (NULL != iter)
    {
        string strItem = iter->First();
        while (!iter->IsDone())
        {
            cout << iter->CurrentItem() << " is ok" << endl;
            iter->Next();
        }
    }
    system("pause");

    return 0;
}
