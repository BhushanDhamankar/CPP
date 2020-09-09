#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream.h>
struct node
{
	int roll;
	char name[10];
	struct node *next;
};
struct node *head,*newnode,*temp;
void create()
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
}
void display()
{
	temp=head;
	cout<<"Data :\n ";
	while(temp!=0)
	{
		cout<<"["<<temp->name<<" | "<<temp->roll<<"]->";
		temp=temp->next;
	}
	cout<<"[NULL]\n";
}
void modify()
{
	int r,nr,flag=1;
	char n[10];
	cout<<"Enter the roll no to be modified :";
	cin>>r;
	temp=head;
	while(temp!=0)
	{
		if(temp->roll==r)
		{
			cout<<"New Details:\nName:";
			cin>>n;
			cout<<"Roll.no:";
			cin>>nr;
			strcpy(temp->name,n);
			temp->roll=nr;
			cout<<"Data Modified";
			flag=0;
		}
		else
		{
			temp=temp->next;
		}
	}
	if(flag)
	{
		cout<<"Entered Roll.no not found";
	}
}
void search()
{
	int key,r=0;
	char n[10];
	cout<<"\nWhat do you want to search?\n1.Name\n2.Roll\nEnter :";
	cin>>key;
	if(key==1)
	{
		cout<<"Enter the Name: ";
		cin>>n;
	}
	else
	{
		cout<<"Enter the roll no: ";
		cin>>r;
	}
	temp=head;
	while(temp!=0)
	{
		if((strcmp(temp->name,n)==0)||(temp->roll==r))
		{
			cout<<"Data Found\nName:"<<temp->name;
			cout<<"\nRoll.no:"<<temp->roll;
			key=0;
			break;
		}
		else
		{
			temp=temp->next;
		}
	}
	if(key)
	{
		cout<<"Data not Found";
	}
}
int main()
{
	clrscr();
	int ch,ans,flag;
	do
	{
		cout<<"1.Create\n2.Display\n3.Search\n4.Modify";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
			{
				create();
				break;
			}
			case 2:
			{
				display();
				break;
			}
			case 3:
			{
				search();
				break;
			}
			case 4:
			{
				modify();
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

