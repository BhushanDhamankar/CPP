#include<iostream>
#include<string>
using namespace std;
struct stack
{
	struct stack *next;
	char item;
};
struct stack *top=0,*newstack,*temp;
string postfix="";
void push(char x)
{
	newstack=new stack[sizeof(stack *)];
	newstack->item=x;
	newstack->next=top;
	top=newstack;
}
void pop()
{
	if(top==0)
	{
		cout<<"Stack is empty"<<endl;
	}
	else
	{
		temp=top;
		top=top->next;
		delete(temp);
	}
}
int precedence(char x)
{
	if(x=='^')
	{		
		return 3; 
    }
	else if((x=='*')||(x=='/'))
	{		
		return 2; 
    }
	else if((x=='+')||(x=='-'))
	{		
		return 1; 
    }
	else
	{
		return -1;
	}
}
void infixToPostfix(string infix)
{
	for(int i=0;i<infix.length();i++)
	{
		if(infix[i]=='(')
		{
			push('(');
		}
		else if(((infix[i]>='a') && (infix[i]<='z')) || ((infix[i]>='A') && (infix[i]<='Z')))
		{
			postfix=postfix+infix[i];
		}
		else if(infix[i]==')')
		{
			while((top->item!='(') && (top!=0))
			{
				postfix=postfix+top->item;
				pop();
			}
			if(top->item=='(')
			{
				pop();
			}
		}
		else if((infix[i]=='+')||(infix[i]=='-')||(infix[i]=='/')||(infix[i]=='*')||(infix[i]=='^'))
		{
			if(top==0)
			{
				push(infix[i]);
			}
			else
			{
				if(precedence(infix[i])>precedence(top->item))
				{
					push(infix[i]);
				}
				else if((precedence(infix[i])==precedence(top->item))&&(infix[i]=='^'))
				{
					push(infix[i]);
				}
				else
				{
				while((top!=0)&&( precedence(infix[i])<=precedence(top->item)))
				{
					postfix=postfix+top->item;
					pop();
				}
				push(infix[i]);
				}
			}
		}
	}
	while(top!=0)
	{
		postfix=postfix+top->item;
		pop();
	}
	cout<<"\tPostfix Expression : "<<postfix<<endl;
}
int main()
{
	int ch,ans;
	string infix;
	do
	{
		cout<<"\t*****MENU*****"<<endl;
		cout<<"1.Infix to Postfix Conversion\n2.Postfix Evaluation\n\tEnter Your Choice : ";
		cin>>ch;
		if(ch==1)
		{
			cout<<"Enter the Expression : ";
			cin>>infix;
			infixToPostfix(infix);
		}
		else if(ch==2)
		{
		
		}
		else
		{
			cout<<"\n\tInvalid choice"<<endl;
		}
		string infix="";
		cout<<"\tDo you want to continue ?\n\tYES-->1\n\tNO-->0\nEnter your choice : "<<endl;
		cin>>ans;
	}while(ans);
	return 0;
}

