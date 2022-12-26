#include<iostream>
#include<string>
#include <cstring>

using namespace std;

struct rec
{
    string name;
    long int tel;
    int num;

};

class Hash
{
    public:
    rec dir[10];
    int max=10;
    int num;
    Hash()
    {
        for(int i=0;i<max;i++)
        {
            dir[i].name="None";
            dir[i].tel=0;
            dir[i].num=0;
           
        }
    }
    void insert();
    void display();
    void search();
    void linear();
    void quad();
};

void Hash::insert()
{
    string nm;
    char ch;
    int sum;
    int add;
    int i;
    cout<<"Enter name :"<<endl;
    cin>>nm;
    sum=0;
    for(int i=0;nm[i]!='\0';i++)
    {
        sum=sum+int (nm[i]);
    }
    cout<<"Sum is:"<<sum<<endl;
    add=sum%10;        
}

void Hash::display()
{
    for(int i=0;i<max;i++)
    {
        cout<<i<<"  "<<"Name:"<<dir[i].name<<"   "<<"Telephone number:"<<dir[i].tel<<"     "<<"comparisons :"          <<dir[i].num<<endl;
    }
}

void Hash::search()
{
    string nm;
    int sum;
    int add;
    cout<<"\nEnter key do you want to search:"<<endl;
    cin>>nm;
    sum=0;
    for(int i=0;nm[i]!='\0';i++)
    {
        sum=sum+int(nm[i]);
    }
    cout<<"SUM IS"<<sum<<endl;
    add=sum%max;
    
    while(dir[add].name!=nm)
    {
        add=add+1;
    }
    
    cout<<"ADDRESS is:"<<add<<endl;
    
    cout<<"Telephone number is:  "<<dir[add].tel<<endl;
    while(dir[add].tel==0)
    {
        cout<<"\n Record not found:"<<endl;
    }
}

//LINEAR PROBING
void Hash::linear()
{
  
    string nm,name;
    char ch;
    int sum;
    int add;
    int i;
    do
    {
            cout<<"Enter name :"<<endl;
            cin>>nm;
            sum=0;
            for(int i=0;nm[i]!='\0';i++)
            {
                sum=sum+int (nm[i]);
            }
            cout<<"Sum is:"<<sum<<endl;
            add=sum%10;
            cout<<"ADDRESS is:"<<add<<endl;
            int count=0;
            while(dir[add].name!="None")
            {
                add=add+1;
                count++;
            }
            num=count;
            dir[add].name=nm;
            cout<<"enter telephone number:"<<endl;
            cin>>dir[add].tel;
            cout<<"TEL"<<dir[add].tel<<endl;
            cout<<"\nNumber of comparisons are:"<<num;
            dir[add].num=count;
            cout<<"\nDO you want to continue y or n? ";
            cin>>ch;
    }while(ch=='y');
}

void Hash::quad()
{
    
    string nm,name;
    char ch;
    int sum;
    int add;
    int i;
    do
    {
            cout<<"Enter name :"<<endl;
            cin>>nm;
            sum=0;
            for(int i=0;nm[i]!='\0';i++)
            {
                sum=sum+int (nm[i]);
            }
            cout<<"Sum is:"<<sum<<endl;
            add=sum%10;
            cout<<"ADDRESS is:"<<add<<endl;
            int i=1;
            int count=0;
            while(dir[add].name!="None")
            {
                    add=(sum+i*i)%max;
                    i++;
                    count++;
            }
            num=count;
            dir[add].name=nm;
            cout<<"enter telephone number:"<<endl;
            cin>>dir[add].tel;
            cout<<"TEL"<<dir[add].tel<<endl;
            cout<<"\nNumber of comparisons are:"<<num;
            dir[add].num=count;
            cout<<"\nDO you want to continue y or n? ";
            cin>>ch;
    }while(ch=='y');
}

int main()
{
    Hash t,h;
    Hash s;
    int ch;
    //t.insert();
   while(1)
    {
        cout<<"\n 1.create telephone directory:"<<endl;
        cout<<"\n 2.Apply linear probing:"<<endl;
        cout<<"\n 3.Display:"<<endl;
        cout<<"\n 4.Search:"<<endl;
        cout<<"\n 5.Apply quadratic probing:"<<endl;
        cout<<"\n 6.Display:"<<endl;
        cout<<"\n 7.Search:"<<endl;
        cout<<"\n 8.Exit"<<endl;
        cout<<"\n Enter your choice:"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                    t.insert();
                    break;
            case 2:
                   t.linear();
                    break;
            case 3:
                    t.display();
                    break;
            case 4:
                    t.search();
                    break;
            case 5:
                    s.quad();
                    break;
            case 6:
                   s.display();
                   break;
            case 7:
                   s.search();
                   break;
            case 8:
                    exit(0);       
        }
    }
    return 0;
}
