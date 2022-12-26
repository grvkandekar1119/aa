#include<iostream>
using namespace std;

class heap
{
 public:
	int h[30];
	int n;
	heap()
	{
          cout<<"\nenter count of nos : ";
          cin>>n;
	  cout<<"\nenter nos : \n";
	  for(int i=1; i<=n; i++)	
	  {
	    cin>>h[i];
          }
	}
        void buildheap(int h[], int n);
        void heapify(int h[], int i, int n);
        void result();
        void print();
};

void heap :: buildheap(int h[], int n)
{
print();
for(int i=n/2; i>=1; i--)
{
  heapify(h,i,n); 
}
}

void heap :: heapify(int h[], int i, int n)
{
int largei=i;
int left=2*i;
int right=2*i+1;

if(left <= n && h[left] > h[i])
{
  largei=left;
}

if(right <= n && h[right] > h[largei])
{
  largei=right;
}

if(largei != i)
{
  int t;
  t=h[i];
  h[i]=h[largei];
  h[largei]=t;
  heapify(h,largei,n);
}
}

void heap :: print()
{
cout<<endl;
for(int i=1; i<=n; i++)	
 {
  cout<<h[i]<<" ";
 }
}

void heap :: result()
{
int size=n;
for(int i=n; i>=2; i--)
{
  int t;
  t=h[i];
  h[i]=h[1];
  h[1]=t;
  size--;
  heapify(h,1,size);
}

cout<<"\n";
print();
cout<<"\nmaximum no is : "<<h[n];
cout<<"\nminimum no is : "<<h[1]<<endl;
}

int main()
{
heap h1;
h1.buildheap(h1.h,h1.n);
h1.print();
h1.result();
return 0;
}




