#include<stdio.h>
#include<conio.h>
#include<iostream.h>
class Student
{
protected :
	char name[10];
	int roll;
public :
	void getinfo();
};
class Sport : public virtual Student
{
protected :
	float smarks;
public :
	void getsmarks();
};
class Academics : public virtual Student
{
protected :
	float amarks;
public :
	void getamarks();
};
class Result : public Sport , public Academics
{
public :
	void showresult();
};
void Student::getinfo()
{
	cout<<"Enter the name of student :";
	cin>>name;
	cout<<"Enter the roll no :";
	cin>>roll;
}
void Sport::getsmarks()
{
	cout<<"Enter the marks scored in Sports field :";
	cin>>smarks;
}
void Academics::getamarks()
{
	cout<<"Enter the marks scored in Academics :";
	cin>>amarks;
}
void Result::showresult()
{
	cout<<"Name : "<<name<<endl;
	cout<<"Roll no: "<<roll<<endl;
	cout<<"Academics : "<<amarks<<"%"<<endl;
	cout<<"Sports : "<<smarks<<"%"<<endl;
}
int main()
{
	clrscr();
	int n;
	Result s[10];
	cout<<"Enter the no. of Students: ";
	cin>>n;
	cout<<"ENTER DATA:-"<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<"Student "<<i+1<<endl;
		s[i].getinfo();
		s[i].getsmarks();
		s[i].getamarks();
	}
	cout<<"RESULT:-"<<endl;
	for(i=0;i<n;i++)
	{
		s[i].showresult();
	}
	getch();
	return 0;
}