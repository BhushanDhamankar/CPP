#include<string.h>
#include<iostream.h>
#include<conio.h>
struct queue //Node Declaration
{
	int roll;
	char name[10];
	struct queue *next; //Next Pointer
};
struct queue *front=0,*newqueue,*temp,*rear=0; //Node Pointer Variables
void create()  //Creating Node
{
	front=0;
	int ch;
	do
	{
		newqueue=new queue[sizeof(queue *)];
		cout<<"Enter the Name : ";
		cin>>newqueue->name;
		cout<<"Enter the roll no : ";
		cin>>newqueue->roll;
		newqueue->next=0;
		if(front==0)
		{
			front=newqueue;
			temp=newqueue;
		}
		else
		{
			temp->next=newqueue;
			temp=newqueue;
		}
		rear=temp;
		cout<<"1.New node\n0.Stop\nEnter :";
		cin>>ch;
	}while(ch);
}
void display()  //Display Function
{
	temp=front;
	cout<<"Data :\n ";
	while(temp!=0)
	{
		cout<<"["<<temp->name<<" | "<<temp->roll<<"]->";
		temp=temp->next;
	}
	cout<<"[NULL]\n";
}
void enqueue()  //Last Insert Function
{
	temp=front;
	newqueue=new queue[sizeof(queue *)];
	cout<<"Enter the Name : ";
	cin>>newqueue->name;
	cout<<"Enter the roll no : ";
	cin>>newqueue->roll;
	newqueue->next=0;
	while(1)
	{
		if(temp->next==0)
		{
			temp->next=newqueue;
			break;
		}
		temp=temp->next;
	}
	rear=newqueue;
}
void dequeue() //Start Delete Function
{
	if(front==0)
	{
		cout<<"Queue is empty"<<endl;
	}
	else
	{
		temp=front;
		front=temp->next;
		delete(temp);
		cout<<"Node Removed"<<endl;
	}
}
void getfront()
{
	cout<<"\nFront Node : "<<endl;
	cout<<"\tName :"<<front->name<<endl;
	cout<<"\tRoll no :"<<front->roll<<endl;
}
void getrear()
{
	cout<<"\nRear Node : "<<endl;
	cout<<"\tName :"<<rear->name<<endl;
	cout<<"\tRoll no :"<<rear->roll<<endl;
}
void getsize()
{
	int count=1;
	temp=front;
	while(temp->next!=0)
	{
		count++;
		temp=temp->next;
	}
	cout<<"\n\tSize of Queue is : "<<count<<endl;
}
int isempty()
{
	if(front==0)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int ch,a,ans,emp;
	clrscr();
	do
	{
		cout<<"\n1.Create Queue\t2.Display Queue\n3.Add Node\t4.Remove Node\n5.getfront()\t6.getrear()\n7.isempty()\t8.getsize()";
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
				enqueue();
				cout<<"Node Added"<<endl;
				break;
			}
			case 4:
			{
				dequeue();
				break;
			}
			case 5:
			{
				getfront();
				break;
			}
			case 6:
			{
				getrear();
				break;
			}
			case 7:
			{
				emp=isempty();
				if(emp==1)
				{
					cout<<"Queue is empty"<<endl;
				}
				else
				{
					cout<<"Queue is not empty"<<endl;
				}
				break;
			}
			case 8:
			{
				getsize();
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

