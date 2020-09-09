#include<stdio.h>
#include<conio.h>
#include<iostream.h>
void bubble(int a[],int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
				a[i]=a[i]+a[j];
				a[j]=a[i]-a[j];
				a[i]=a[i]-a[j];
			}
		}
	}
	cout<<"\nBubble sorted array:\n";
	for(i=0;i<n;i++)
	{
		cout<<a[i]<<endl;
	}
}
void binaryR(int a[],int l,int r,int x)
{
	if(l<=r)
	{
		int mid=(l+r)/2;
		if(a[mid]==x)
		{
			cout<<"Element found at index position : "<<mid;
		}
		else if(x>a[mid])
		{
			binaryR(a,l=mid+1,r,x);
		}
		else
		{
			binaryR(a,l,r=mid-1,x);
		}
	}
	else
	{
		cout<<"element not found";
	}
}
void linear(int a[],int n,int x)
{
	int f=1;
	for(int i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			f=0;
			cout<<"\nThe Element "<<x<<" is at index position:"<<i;
			break;
		}
	}
	if(f)
	{
		cout<<"\nElement not found";
	}
	
}
void binary(int a[],int n,int x)
{
	int start=0,end=n-1,mid,f=1;
		do
	{
		mid=(start+end)/2;
		if(a[mid]==x)
		{
			cout<<"\nElement "<<x<<" found at index position:"<<mid;
			f=0;
			break;
		}
		else if(a[mid]>x)
		{
			end=mid-1;
		}
		else
		{
			start=mid+1;
		}
	}while(start<=end);
	if(f)
	{
	cout<<"\nElement not found";
	}
}
int main()
{
	clrscr();
	int a[20];
	int n,i,ch,ans,x;
	do
	{
		cout<<"Enter the number of elements:";
		cin>>n;
		cout<<"Enter the elements:\n";
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cout<<"\n1.Linear Search\n2.Binary Search\nEnter your choice:";
		cin>>ch;
		if(ch==2)
		{
			cout<<"\n\n1.Binary Search Normal\n2.Binary Search using Reccursion \nEnter your choice:";
			cin>>ch;
			ch++;
		}	
		cout<<"Enter the element you want to search:";
		cin>>x;
		switch(ch)
		{
			case 1:
			{
				linear(a,n,x);
				break;
			}
			case 2:
			{
				bubble(a,n);
				binary(a,n,x);
				break;
			}
			case 3:
			{
				bubble(a,n);
				binaryR(a,0,n-1,x);
				break;
			}
			
		};
		cout<<"\nDo you want to continue 1 for (YES) 0 for (NO):";
		cin>>ans;
	}while(ans);
	
	getch();
	return 0;
}
