#include<iostream>
using namespace std;
const int MAX=10;
template<class T>

class set
{
    public:
    T a[MAX];
    int n;
    set()
    {
        n=-1;
    }
    void input(int num);
    bool insert(T);
    bool remove(T);
    int contains(T);
    void print();
    int size();
    set unionS(set,set);
    set inter(set,set);
    set diff(set,set);
    bool subset(set);
};

template<class T>
void set<T>::input(int num)
{
    T element;
    for(int i=0;i<num;i++)
    {
        cout<<"\n Element :"<<endl;
        cin>>element;
        insert(element);
    }
}
template<class T>
bool set<T>::insert(T element)
{
    if(n>=MAX-1)
    {
        cout<<"\n Set is full:"<<endl;
        return 0;
    }
    a[++n]=element;
    return 1;
}

template<class T>
void set<T>::print()
{
     for(int i=0;i<=n;i++)
     {
          cout<<"    "<<a[i];
     }
}

template<class T>
bool set<T>::remove(T element)
{
    if(n==-1)
    {
        cout<<"\n Cannot performed deletion operation:"<<endl;
        return 0;
    }
    for(int i=0;i<=n;i++)
    {
        if(a[i]==element)
        {
            for(int j=i;j<n;j++)
            {
                a[j]=a[j+1];
            }
            return 1;
        }
     
    }
    return 0;
}
template<class T>
int set<T>::contains(T element)
{
    for(int i=0;i<=n;i++)
    {
        if(a[i]==element)
        {
            return 1;
        }
    }
    return 0;
}
template<class T>
int set<T>::size()
{
    return n+1;    
}

template<class T>
set<T> set<T> ::unionS(set<T> s1, set<T> s2 )
{
    set<T> s3;
    
    int flag=0;
    int i=0;

    for(i=0;i<=s1.n;i++)
    {
        s3.insert(s1.a[i]);
    }
   
    for(int j=0;j<=s2.n;j++)
    {
        flag=0;
        for(i=0;i<=s1.n;i++)
        {
            if(s1.a[i]==s2.a[j])
            {
                flag=1;
              
            }
        }
        
        if(flag==0)
        {
            s3.insert(s2.a[j]);
        }
    }
    
    
    return s3;
}
template<class T>
set<T> set<T>::inter(set<T> s1, set<T> s2)
{
    set<T>s3;
    
    int flag=0;
    int i=0;
    for(i=0;i<=s1.n;i++)
    {
        for(int j=0;j<=s2.n;j++)
        {
            if(s1.a[i]==s2.a[j])
            {
                s3.insert(s1.a[i]);
                break;
            }
        }
    }
    return s3;
}

template<class T>
set<T> set<T>::diff(set<T> s1 ,set<T> s2)
{
    set<T> s3;
    
    int flag=1;
    int i=0;
    for(i=0;i<=s1.n;i++)
    {
        for(int j=0;j<=s2.n;j++)
        {
            if(s1.a[i]==s2.a[j])
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            s3.insert(s1.a[i]);
        }
    }
    return s3;
}

template<class T>
bool set<T>::subset(set<T> s2)
{
    int count=0;
    int size=s2.size();
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=s2.n;j++)
        {
            if(a[i]==s2.a[j])
            {
                count++;
                break;
            }
        }
    }
    if(count==size)
    {
        return 1;
    }
        return 0;
}

int main()
{
    set<int>s1,s2,s3;
    int element,ch;
    cout<<"\nEnter number of elements in SET1:";
    cin>>element;//element is used for taking size
    s1.input(element);
    s1.print();
    cout<<"\nEnter number of elements in SET2:";
    cin>>element;//element is used for taking size
    s2.input(element);
    s2.print();
    while(1)
    {
         cout<<"\n 1.Insert elements of set 1"<<endl;
         cout<<"\n 2. Remove :"<<endl;
         cout<<"\n 3. Contains"<<endl;
         cout<<"\n 4. Size"<<endl;
         cout<<"\n 5. Union "<<endl;
         cout<<"\n 6. Intersection"<<endl;
         cout<<"\n 7. Difference"<<endl;
         cout<<"\n 8. check if Subset"<<endl;
         cout<<"\n Enter your choice:"<<endl;
         cin>>ch;
         switch(ch)
         {
             case 1: 
                  cout<<"Enter elements of set s1:"<<endl;
                  cin>>element;
                  if(s1.insert(element))
                  {
                      cout<<element<<" inserted";
                  }
                  else
                  {
                      cout<<"Insertion Failed";
                  }
                  s1.print();
                  break;        
             case 2:
                    cout<<"Enter element you want to remove:"<<endl;
                    cin>>element;
                    if(s1.remove(element)) 
                    {
                        cout<<element<<"Deleted"<<endl;
                    }
                    else
                    {
                        cout<<"Deletion failed"<<endl;
                    }
                    s1.print();
                    break;
              case 3:
                     cout<<"Enter element you want to check"<<endl;
                     cin>>element;
                     if(s1.contains(element))
                     {
                         cout<<"\n element is present "<<endl;
                     }
                     else
                     {
                         cout<<"\n Element is not present"<<endl;
                     }
                     break;
              case 4:
                     cout<<"\n Size of set 1:"<<s1.size();
                     cout<<"\n Size of set 2:"<<s2.size();
                     break;
              case 5:
                     s3=s2.unionS(s1,s2);
                     cout<<"\n elements of set s1 :"<<endl;
                     s1.print();
                     cout<<"\n elements of set s2 :"<<endl;
                     s2.print();
                     cout<<"\nUnion of set 1 and set 2:"<<endl;
                     s3.print();
                     break;
              case 6:
                     s3=s1.inter(s1,s2);
                     cout<<"\n elements of set s1 :"<<endl;
                     s1.print();
                     cout<<"\n elements of set s2 :"<<endl;
                     s2.print();
                     cout<<"\nIntersection set 1 and set 2:"<<endl;
                     s3.print();
                     break;
              case 7:
                     s3=s1.diff(s1,s2);
                     cout<<"\n elements of set s1 :"<<endl;
                     s1.print();
                     cout<<"\n elements of set s2 :"<<endl;
                     s2.print();
                     cout<<"\ndifference of set 1 and set 2:"<<endl;
                     s3.print();
                     break;
              case 8:
                      if(s1.subset(s2))
                      {
                          cout<<"\n s2 is subset of s1"<<endl;
                      }
                      else
                      {
                          cout<<"\n Not subset"<<endl;
                      }
                      break;
         }
    }
    
    
    
}
