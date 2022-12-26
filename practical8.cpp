#include<iostream>
using namespace std;

class OBST
{
public:

       int n;
       //cout<<"\nenter n = ";
      // cin>>n;
      
       int key[10];
       int p[10];
       int q[10];
 int w[10][10], c[10][10], r[10][10];
       OBST()
     {
       n=3;
       cout<<"\nkeys = ";
       for(int i=0;i<=n;i++) 
       {
         key[i]=i;
         cout<<i<<" ";
       }
       for(int i=0;i<n;i++) 
       {  
         cout<<"\nenter prabability p"<<i+1<<" ";
         cin>>p[i];
         //p[i]=p;
       }
       for(int i=0;i<=n;i++) 
       {  
         //int q;
         cout<<"\nenter prabability q"<<i<<" ";
         cin>>q[i];
         //q[i]=q;
       }
    }
       void create();
       int findmincost(int,int);

};

int OBST :: findmincost(int i, int j)
{
int cost;
int k,m,min=9999;
for(m=i+1; m<=j; m++)
{
cost = c[i][m-1] + c[m][j];
if(cost<min)
{
  min =cost;
  k=m;
}
}
return k;
}

void OBST :: create()
{
int n=3;


for(int i=0; i<=n; i++)
{
  w[i][i]=q[i];
  c[i][i]=0;
  r[i][i]=0;
}

for(int i=0; i<n; i++)
{
  int j=i+1;
  w[i][j]=p[j] + q[j] + w[i][j-1];
  c[i][j]=w[i][j] + c[i][j-1] + c[j][j];
  r[i][i]=j;
}

for(int g=2; g<=n; g++)
{
  for(int i=0; i<n; i++)
 {
  int k;
  int j=i+g;
  w[i][j]=p[j] + q[j] + w[i][j-1];
  k=findmincost(i,j);
  c[i][j]=w[i][j] + c[i][k-1] + c[k][j];
  r[i][j]=k;
 }
}
}

int main()
{
OBST o1;
o1.create();
return 0;
}




