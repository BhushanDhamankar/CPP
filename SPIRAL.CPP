#include<stdio.h>
#include<conio.h>
#include<iostream.h>
int main()
{
	int r,c,e,i=0,j=0,k=0,num=0;
	cout<<"enter r&c";
	cin>>r>>c;
	e=(r*c);
	int a[5][5];
	while(num<=e)
	{
//********************************************************Right
		for(j;j<c-k;j++)
		{
			a[i][j]=num;
			num++;
		}
		i++;
		j--;
//********************************************************Down
		for(i;i<r-k;i++)
		{
			a[i][j]=num;
			num++;
		}
		j--;
		i--;
//********************************************************Left
		for(j;j>=0+k;j--)
		{
			a[i][j]=num;
			num++;
		}
		i--;
		k++;
//********************************************************Up
		for(i;i>=0+k;i--)
		{
			a[i][j]=num;
			num++;
		}
		j++;
	};
	for(int p=0;p<r;p++)
	{
		for(int q=0;q<c;q++)
		{
			cout<<a[p][q]<<"\t";
		}
	cout<<"\n";
	}
	getch();
	return 0;
};