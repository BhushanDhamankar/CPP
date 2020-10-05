#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<iostream.h>
struct node //Node Declaration
{
	int roll;
	char name[10];
	struct node *next,*prev; //Address Pointers
};
struct node *head,*newnode,*temp; //Node Pointer Variables
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
		newnode->prev=0;
		newnode->next=0;
		if(head==0)
		{
			head=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=newnode;
		}
		cout<<"1.New node\n0.Stop\nEnter :";
		cin>>ch;
	}while(ch);
}
void display()  //Display Function
{
	temp=head;
	cout<<"Data :\n ";
	while(temp!=0)
	{
		cout<<"["<<temp->name<<" | "<<temp->roll<<"]<->";
		temp=temp->next;
	}
	cout<<"[NULL]\n";
}
void modify() //Modify function
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
void search() //Search Function
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
void start_insert()  //Start Insert Function
{
	newnode=new node[sizeof(node *)];
	cout<<"New node Details :"<<endl;
	cout<<"Enter the Name:";
	cin>>newnode->name;
	cout<<"Roll.no:";
	cin>>newnode->roll;
	newnode->prev=0;
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
}
void between_insert() //Inbetween Insert Function
{
	int ch,i=1,p;
	newnode=new node[sizeof(node *)];
	newnode->prev=0;
	temp=head;
	cout<<"1.Before Position\n2.After Position\nEnter choice:";
	cin>>ch;
	cout<<"Enter Position:";
	cin>>p;
	cout<<"New node Details :"<<endl;
	cout<<"Enter the Name:";
	cin>>newnode->name;
	cout<<"Roll.no:";
	cin>>newnode->roll;
	while(temp!=0)
	{
		if(p==1)
		{
			if(ch==1)
			{
				newnode->prev=0;
				newnode->next=temp;
				temp->prev=newnode;
				head=newnode;
				break;
			}
		}
		if(p==i)
		{
			if(ch==1)
			{
				temp=temp->prev;
				newnode->next=temp->next;
				newnode->prev=temp;
				(temp->next)->prev=newnode;
				temp->next=newnode;
				break;
			}
			else
			{
				newnode->next=temp->next;
				newnode->prev=temp;
				(temp->next)->prev=newnode;
				temp->next=newnode;
				break;
			}
		}
		temp=temp->next;
		i++;
	}	
}
void last_insert()  //Last Insert Function
{
	temp=head;
	newnode=new node[sizeof(node *)];
	cout<<"New node Details :"<<endl;
	cout<<"Enter the Name:";
	cin>>newnode->name;
	cout<<"Roll.no:";
	cin>>newnode->roll;
	newnode->next=0;
	while(1)
	{
		if(temp->next==0)
		{
			temp->next=newnode;
			newnode->prev=temp;
			break;
		}
		temp=temp->next;
	}
}
void start_delete () //Start Delete Function
{
	temp=head;
	(temp->next)->prev=0;
	head=temp->next;
	delete(temp);
}
void between_delete()  //Inbetween Delete Function
{
	int ch,i=1,p;
	temp=head;
	cout<<"1.Before Position\n2.After Position\nEnter choice:";
	cin>>ch;
	cout<<"Enter Position:";
	cin>>p;
	while(temp!=0)
	{
		if(p==1)
		{
			if(ch==1)
			{
				cout<<"Invalid choice"<<endl;
				cout<<"Node Deletion Error"<<endl;
				break;
			}
		}
		if(p==i)
		{
			if(ch==1)
			{
				temp=temp->prev;
				(temp->prev)->next=temp->next;
				(temp->next)->prev=temp->prev;
				delete(temp);
			}
			else
			{
				temp=temp->next;
				(temp->prev)->next=temp->next;
				(temp->next)->prev=temp->prev;
				delete(temp);
			}
		}
		temp=temp->next;
		i++;	
	}
}
void last_delete()  //Last Delete Function
{
	temp=head;
	while(temp->next!=0){temp=temp->next;}
	(temp->prev)->next=0;
	delete(temp);
	
}
void reverse_print() //Reverse print function
{
	temp=head;
	while(temp->next!=0){temp=temp->next;}
	cout<<"Reversed List:-\n[NULL]";
	while(temp!=head)
	{
		cout<<"<->["<<temp->name<<" | "<<temp->roll<<"]";
		temp=temp->prev;
	}
	cout<<"<->["<<temp->name<<" | "<<temp->roll<<"]";
}
int main()
{
	clrscr();
	int ch,a,ans;
	do
	{
		cout<<"1.Create\t2.Display\n3.Search\t4.Modify\n5.Reverse Print\t6.Insert";
		cout<<"\n7.Delete\tEnter your choice : ";
		cin>>ch;
		if((ch==6)||(ch==7))
		{
			cout<<"1.Start\t2.InBetween\n3.Last\tEnter your choice: ";
			cin>>a;
			if(ch==7)
			{
				ch=a+8;
			}
			else if(ch==6)
			{
				ch=a+5;
			}
			else
			{
				cout<<"Invalid input";
			}
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
				search();
				break;
			}
			case 4:
			{
				modify();
				display();
				break;
			}
			case 5:
			{
				reverse_print();
				break;
			}
			case 6:
			{
				start_insert();
				cout<<"Node Inserted At Start"<<endl;
				display();
				break;
			}
			case 7:
			{
				between_insert();
				cout<<"Node Insertion Successful"<<endl;
				display();
				break;
			}
			case 8:
			{
				last_insert();
				cout<<"Node Inserted At Last"<<endl;
				display();
				break;
			}
			case 9:
			{
				start_delete();
				cout<<"First Node Deleted"<<endl;
				display();
				break;
			}
			case 10:
			{
				between_delete();
				display();
				break;
			}
			case 11:
			{
				last_delete();
				cout<<"Last Node Deleted"<<endl;
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

