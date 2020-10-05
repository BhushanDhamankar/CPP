#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream.h>
struct node //Node Declaration
{
	int roll;
	char name[10];
	struct node *next; //Next Pointer
};
struct node *head,*newnode,*temp,*trans; //Node Pointer Variables
void create()  //Creating Node
{
	head=0;
	int ch;
	do
	{
		newnode=new node[sizeof(node *)];
		cout<<"Enter the Name : ";
		cin>>newnode->name;
		cout<<"Enter the roll no : ";
		cin>>newnode->roll;
		newnode->next=0;
		if(head==0)
		{
			head=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		cout<<"1.New node\n0.Stop\nEnter :";
		cin>>ch;
	}while(ch);
	temp->next=head;
}
void display()  //Display Function
{
	temp=head;
	cout<<"Data :\n ";
	while(temp->next!=head)
	{
		cout<<"["<<temp->name<<" | "<<temp->roll<<"]->";
		temp=temp->next;
	}
	cout<<"["<<temp->name<<" : "<<temp->roll<<"]->";
	cout<<"[HEAD]\n";
}
void start_insert()  //Start Insert Function
{
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	newnode=new node[sizeof(node *)];
	cout<<"New node Details :"<<endl;
	cout<<"Enter the Name:";
	cin>>newnode->name;
	cout<<"Roll.no:";
	cin>>newnode->roll;
	newnode->next=head;
	head=newnode;
	temp->next=head;
}
void between_insert() //Inbetween Insert Function
{
	int ch,i=2,p;
	newnode=new node[sizeof(node *)];
	temp=head;
	trans=temp->next;
	cout<<"1.Before Position\n2.After Position\nEnter choice:";
	cin>>ch;
	cout<<"Enter Position:";
	cin>>p;
	cout<<"New node Details :"<<endl;
	cout<<"Enter the Name:";
	cin>>newnode->name;
	cout<<"Roll.no:";
	cin>>newnode->roll;
	while(trans!=0)
	{
		if(p==1)
		{
			if(ch==1)
			{
				newnode->next=head;
				head=newnode;
				break;
			}
			else
			{
				temp->next=newnode;
				newnode->next=trans;
				break;
			}
		}
		if(p==i)
		{
			if(ch==2)
			{
				newnode->next=trans->next;
				trans->next=newnode;
				break;
			}
			else
			{
				newnode->next=temp->next;
				temp->next=newnode;
				break;
			}
		}
		trans=trans->next;
		temp=temp->next;
		i++;	
	}	
}
void last_insert()  //Last Insert Function
{
	temp=head;
	while(temp->next!=head)
	{
		temp=temp->next;
	}
	newnode=new node[sizeof(node *)];
	cout<<"New node Details :"<<endl;
	cout<<"Enter the Name:";
	cin>>newnode->name;
	cout<<"Roll.no:";
	cin>>newnode->roll;
	temp->next=newnode;
	temp=newnode;
	temp->next=head;
	
}
int main()
{
	clrscr();
	int ch,a,ans;
	do
	{
		cout<<"1.Create\t2.Display\n3.Insert";
		cin>>ch;
		if(ch==3)
		{
			cout<<"1.Start\t2.InBetween\n3.Last\tEnter your choice: ";
			cin>>a;
			ch=ch+a-1;
		}
		switch(ch)
		{
			case 1:
			{
				create();
				cout<<"List Created"<<endl;
				display();
				break;
			}
			case 2:
			{
				display();
				break;
			}
			case 3:
			{
				start_insert();
				cout<<"Node Inserted At Start"<<endl;
				display();
				break;
			}
			case 4:
			{
				between_insert();
				cout<<"Node Insertion Successful"<<endl;
				display();
				break;
			}
			case 5:
			{
				last_insert();
				cout<<"Node Inserted At Last"<<endl;
				display();
				break;
			}
			default:
			{
				cout<<"Enter the valid choice";
				break;
			}
		};
		cout<<"\nDo you want to continue : ";
		cin>>ans;
	}while(ans);
	getch();
	return 0;
}

