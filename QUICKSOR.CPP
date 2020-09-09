#include<stdio.h>
#include<conio.h>
#include<iostream.h>
int divide(int a[],int i,int l)
{
	int start=i,end=l;
	int P=a[i];
	int t;
	while(start<end)
	{
		while(a[start]<=P)
		{
			start++;
		}
		while(a[end]>P)
		{
			end--;
		}

		if(start<end)
		{
			t=a[start];
			a[start]=a[end];
			a[end]=t;
		}
	}
	a[i]=a[end];
	a[end]=P;
	return end;
}
void quick(int a[],int i, int l)
{
	int r;
	if(i<l)
	{
		r=divide(a,i,l);
		quick(a,i,r-1);
		quick(a,r+1,l);
	}
}

int main()
{
	clrscr();
	int a[10],n;
	cout<<"Enter the no. of elements: ";
	cin>>n;
	cout<<"Enter the elements of array :\n";
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quick(a,0,n-1);
	cout<<"\nSorted array is: (";
	for(i=0;i<n-1;i++)
	{
		cout<<a[i]<<",";
	}
	cout<<a[n-1]<<")";
	getch();
	return 0;
}