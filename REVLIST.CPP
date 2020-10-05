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
struct node *head,*newnode,*temp,*prev;
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
void reverse()
	{

		
		Node* current = head;
		Node* prev = NULL, * next = NULL;

		while (current != NULL) {
		
			next = current->next;

			
			current->next = prev;

			
			prev = current;
			current = next;
		}
		head = prev;
	}

	

int main()
{
	clrscr();
	int ch,ans,flag;
	create();
	reverse();
	display();
	getch();
	return 0;
}
