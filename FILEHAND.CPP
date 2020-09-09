#include<iostream.h>
#include<conio.h>
#include<fstream.h>
class student
{
private:
	char name[10];
	char marks[5];
	char roll[5];
public:
	void getdata();
	void showdata();
};
void student::getdata()
{	cout<<"\nEnter the Name of Student:-";
	cin>>name;
	cout<<"\nEnter the roll no. of the student:-";
	cin>>roll;
	cout<<"\nEnter the marks of the student:-";
	cin>>marks;
};
void student::showdata()
{
	cout<<"\nName of Student:-"<<name;
	cout<<"\nRoll no. Student:-"<<roll;
	cout<<"\nMarks:-"<<marks;
};
void Display(char fname[],int n,student s[])
{
	ifstream fi;
	fi.open(fname);
	for(int i=0;i<n;i++)
	{
		fi.read((char *)&s[i],sizeof(s[i]));
		s[i].showdata();
	}
	fi.close();
};
int Add(char fname[],int n,student s[])
{
	int m;
	cout<<"how many records you want to add:-";
	cin>>m;
	fstream fo;
	fo.open(fname,ios::out|ios::in|ios::ate);
	for(int i=n;i<n+m;i++)
	{
		s[i].getdata();
		fo.write((char *)&s[i],sizeof(s[i]));
	}
	fo.close();
	n=n+m;
	return n;
};
void Modify(char fname[],int n,student s[])
{
	int m;
	cout<<"Enter the index of the student you want to modify:-";
	cin>>m;
	s[m].getdata();
	ofstream fo;
	fo.open(fname);
	for(int i=0;i<n;i++)
	{
		fo.write((char *)&s[i],sizeof(s[i]));
	}
	fo.close();
};
void Delete(char fname[],int n,student s[])
{
	int m;
	cout<<"Enter the Index of the student record you want to delete:-";
	cin>>m;
	ofstream fo;
	fo.open(fname);
	for(int i=0;i<n;i++)
	{
		if(i!=m)
		{
			fo.write((char *)&s[i],sizeof(s[i]));
		}
	}
	fo.close();
};
void Search(char fname[],int n,student s[])
{
	int m;
	cout<<"Enter the index of the student you want to search:-";
	cin>>m;
	ifstream fi;
	fi.open(fname);
	for(int i=0;i<n;i++)
	{
		fi.read((char *)&s[i],sizeof(s[i]));
		if((m>=0)&&(m<n))
		{
			cout<<"Record Found";
			s[i].showdata();
			break;
		}
	}
	fi.close();
};
int main()
{
	clrscr();
	int  n,ch,ans;
	char fname[20];
	cout<<"Enter the no. of students:-";
	cin>>n;
	student s[10];
	ofstream fo;
	cout<<"\nEnter the name of File:-";
	cin>>fname;
	fo.open(fname);
	for(int i=0;i<n;i++)
	{
		s[i].getdata();
		fo.write((char *)&s[i],sizeof(s[i]));
	}
	fo.close();
	do
	{
		cout<<"\nEnter the File Operation to be Performed..";
		cout<<"\n1.Display\n2.Add Records\n3.Search Record\n4.Modify Record\n5.Delete Record";
		cout<<"\nEnter your choice:-";
		cin>>ch;
		switch(ch)
		{
			case(1):
			{
				Display(fname,n,s);
				break;
			};
			case(2):
			{
				n=Add(fname,n,s);
				break;
			};
			case(3):
			{
				Search(fname,n,s);
				break;
			};
			case(4):
			{
				Modify(fname,n,s);
				break;
			};
			case(5):
			{
				Delete(fname,n,s);
				n--;
				break;
			};
			default:
			{
				cout<<"\nInvalid Choice";
				break;
			};
		};
		cout<<"\nDo you want to continue";
		cout<<"\nEnter 1. for Yes 0. for NO:-";
		cin>>ans;
	}while(ans);
	getch();
	return 0;
}