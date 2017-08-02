###########################################################
#                                                         #
#          Observer Design Pattern Ecample                #
#                                                         #
###########################################################

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class AbstractObserver
{
 public: 
  virtual void updateValue(int value) = 0;
    
};

class ConcreteAObserver: public AbstractObserver
{
public:
    ConcreteAObserver() {}
   ~ConcreteAObserver() {}
   
   void updateValue(int value)
   {
     std::cout  << " I am Concrete A Observer update  " << value << std::endl; 
   }
};

class ConcreteBObserver: public AbstractObserver
{
public:
    ConcreteBObserver(){}
   ~ConcreteBObserver(){}
   
   void updateValue(int value)
   {
     cout  << " I am Concrete B Observer update  " << value << endl; 
   }
   
};

class ObserverSubject
{
 public:
    ObserverSubject() : m_value(2) 
    {
    }
   ~ObserverSubject() {}
   
   void setValue(int val)
   {
     m_value = val;  
     
     for(size_t i=0; i<m_ObserverList.size(); i++)
           m_ObserverList[i]->updateValue(m_value);
   }
 
 bool attachObserver(AbstractObserver *objObserver)
 {
    for(size_t k=0; k<m_ObserverList.size(); k++)
     {
        if(objObserver == m_ObserverList[k])
             return false;
     }
     m_ObserverList.push_back(objObserver); 
     objObserver->updateValue(m_value);
     return true;
 }
 
private:
   int m_value;
   vector<AbstractObserver*> m_ObserverList;
};

int main()
{
  ObserverSubject object;
  ConcreteAObserver obsA;

  object.attachObserver(&obsA);
  object.setValue(5);
  
  ConcreteBObserver obsB;
  object.attachObserver(&obsB);
}
