#include<iostream>
#include<string.h>
using namespace std;
template<class T>
class cStack
{
    //class decleration
	struct node
	{
		T data;
		struct node *next;
	};
	struct node *start;
public:
	//functions
	cStack(){start=NULL;}
	void push(T n);
	T pop();
	int is_empty();
	T Show_top();
	void display();
};
template<class T>
void cStack<T>::push(T n)
{
	//decleraring structure variable
	//and giving data for node
	struct node *temp;
	temp=new struct node;
	temp->data=n;
	temp->next=NULL;
	cout<<"\s"<<temp->data;
	if(start==NULL)
	{
		start=temp;
	}
	else
	{
		//attaching node into the list
		//and changing the  start position
		temp->next=start;
		start=temp;
	}
}
template<class T>
T cStack<T>::pop()
{
	//function for pushing the data
	T ch;
	struct node* temp=start;
	if(start==NULL)
	{
		return '\0';
	}
	else
	{
		ch=start->data;
		start=start->next;
		delete temp;
		//returning the top of the stack 
		return ch;
	}
}
template<class T>
int cStack<T>::is_empty()
{
	//function to check if stack is empty or not
	if(start==NULL)
		return 1;
	else
		return 0;
}
template<class T>
T cStack<T>::Show_top()
{
	if(start==NULL)
	{
		cout<<"\n Stack is empty";
		return '\0';
	}
	else
		//function to get the check topof stack
		return start->data;
}
template<class T>
void cStack<T>::display()
{
	//function to display all the contents of stack
	struct node *temp=start;
	if(start==NULL)
		cout<<"\n Stack is empty";
	else
	{
		cout<<"\n STACK IS ";
		while(temp!=NULL)
		{
			cout<<"\n"<<temp->data;
			temp=temp->next;
		}
	}
}
class cExpression
{
	//declering the variables of the class
	char i_string[50],o_string[50];
public:
	//declering the functions of the class
	void getdata();
	int is_operand(char c);
	int is_operator(char ch);
	void infix_postfix();
	void prefix_eva();
	void infix_prefix();
	void postfix_eva();
};
void reverse(char i_string[50]);
void cExpression::postfix_eva()
{
	cStack<int> s1;
	cExpression m1;
	int no,op1,op2,res,ar2[20],flag=0,i,j=0,k;
	char ar1[20];
	for(int i=0;o_string[i]!='\0';i++)
	{
		if(m1.is_operand(o_string[i]))
		{	
			flag=0;
			if(o_string[i]>57)
			{		
				for(k=0;k<j;k++)
				{
					if(ar1[k]==o_string[i])
					{
						s1.push(ar2[k]);
						flag=1;
					}
					
				}
				if(flag==0)
				{
					cout<<"\nEnter the value for operand "<<o_string[i];
					cin>>no;
					ar1[j]=o_string[i];
					ar2[j]=no;
					j++;
					s1.push(no);
				}
				
					
			}
			else
			{
				s1.push(o_string[i]-48);

			}
		}
		else if(m1.is_operator(o_string[i]))
		{
			op2=s1.pop();
			op1=s1.pop();
			switch(o_string[i])
			{
			case '+':
				res=op1+op2;
				s1.push(res);
				break;
			case '-':
				res=op1-op2;
				s1.push(res);
				break;
			case '*':
				res=op1*op2;
				s1.push(res);
				break;
			case '/':
				res=op1/op2;
				s1.push(res);
				break;
			case '^':
				res=op1^op2;
				s1.push(res);
				break;
			case '$':
				res=op1^op2;
				s1.push(res);
				break;
			}

		}
	}
	if(s1.is_empty()!=1)
		cout<<"\n ANswer is   "<<s1.pop()<<"\n";
}

void cExpression::prefix_eva()
{
	//declering the required variables
	cStack<int> s1;
	cExpression m1;
	char ar1[20];
	int ar2[20];
	int no,op1,op2,res,len,j=0,k,flag=0;
	//finding the length of the string
	len=strlen(o_string);
	len--;
	for(int i=len;i>=0;i--)
	{
		//checking for the operand
		if(m1.is_operand(o_string[i]))
		{	flag=0;

			if(o_string[i]>57)
			{		
				for(k=0;k<j;k++)
				{
					//checking if the the value for 
					//operand is already present or not
					if(ar1[k]==o_string[i])
					{
						s1.push(ar2[k]);
						flag=1;
					}
					
				}
				if(flag==0)
				{
					//if operand is not present then taking its value
					cout<<"\nEnter the value for operand "<<o_string[i];
					cin>>no;
					ar1[j]=o_string[i];
					ar2[j]=no;
					j++;
					s1.push(no);
				}
				
					
			}
			else
			{
				//if operand is number then directly pushing it onto the stack
				s1.push(o_string[i]-48);

			}
		}
		else if(m1.is_operator(o_string[i]))
		{
			//poping two operators
			op1=s1.pop();
			op2=s1.pop();
			//checking which operator is present 
			//and performing the operation according to it
			switch(o_string[i])
			{
			case '+':
				res=op1+op2;
				s1.push(res);
				break;
			case '-':
				res=op1-op2;
				s1.push(res);
				break;
			case '*':
				res=op1*op2;
				s1.push(res);
				break;
			case '/':
				res=op1/op2;
				s1.push(res);
				break;
			case '^':
				res=op1^op2;
				s1.push(res);
				break;
			case '$':
				res=op1^op2;
				s1.push(res);
				break;
			}

		}
	}
	//displaying the result of the expression
	if(s1.is_empty()!=1)
		cout<<"\n Answer is   "<<s1.pop()<<"\n";
}

int priority(char ch)
{
    int p;
	//deciding the priority according to the 
	//presedencce of the operator
	switch(ch)
	{
	case '+':
		p=1;
		break;
    case '-':
		p= 1;
		break;
	case '*':
		p= 2;
		break;
	case '/':
		p= 2;
		break;
	case '^':
		p= 3;
		break;
	case '$':
		p= 3;
		break;
	case '(':
		p=0;
		break;

	}
	return p;
}



void cExpression::getdata()
{
	//declering the required variables
	int i,counter,cnt1=0,cnt2=0,res,flag=0,len;
	do{
			flag=0;
			cnt1=0;
			cnt2=0;
			//taking the string
   			cout<<"\n Enter the infix Expression ";
   			cin>>i_string;
			counter=0;
   			for(i=0;i_string[i]!='\0';i++)
   			{
				//checking the codition for opening and closing bracket
      			if(i_string[i]=='(')
					counter++;
      			if(i_string[i]==')')
					counter--;
				//checking the condition for the operator and the operand
				if(is_operand(i_string[i]))
					cnt1++;
				if(is_operator(i_string[i]))
					cnt2++;
   			}
			res=cnt1-cnt2;
			if(res!=1)
				flag=1;
			len=strlen(i_string);
		len--;
		if(is_operator(i_string[0]) || is_operator(i_string[len]))
			flag=1;
  		if((counter!=0) ||flag==1)
			cout<<"\n Enter proper Expression";
		
	   }while((counter!=0)|| flag==1);


}
/*void cExpression::infix_postfix()
{
	//declaring the required variables
	int i,j=0;
	char ch,c,d,e;
	cStack<char> sk;
	for(i=0;i_string[i]!='\0';i++)
	{
		//if it is operand pushing it into output string
		if(is_operand(i_string[i]))
		{
			o_string[j++]=i_string[i];
		}
		//if it is opening bracket pushing it onto stack
		else if(i_string[i]=='(')
		{
			sk.push(i_string[i]);
		}
		//poping data until opening bracket is encountered
		else if(i_string[i]==')')
		{
			while((ch=sk.pop())!='(')
			{		
			o_string[j++]=ch;
			if(sk.is_empty())
				break;
			}
				
		}
		//if it is operator
		else if(is_operator(i_string[i]))
		{
			//if stack is empty pushing it onto stack
			if(sk.is_empty())
				sk.push(i_string[i]);
			//pushing it at its proper position
			else if((priority(sk.Show_top()))<(priority(i_string[i])))
				sk.push(i_string[i]);
			else 
			{
					if((sk.is_empty())==0)
					{
						//finding the proper position for the incoming operator
						while((sk.is_empty())!=1 && (priority(sk.Show_top()))>=(priority(i_string[i])))
						{
							e=sk.pop();
							o_string[j++]=e;
						}
					}
					sk.push(i_string[i]);
			}
		}
	}
if((sk.is_empty())!=1)
{	
	//copying the remaining operators into output string
	while(sk.is_empty()!=1)
	{
		d=sk.pop();
		o_string[j++]=d;
			
	}
}
   //displaying the output string
	o_string[j]='\0';
	cout<<"\n"<<o_string;
}*/

void cExpression::infix_postfix()
{
	cStack<char> s;
	int i,j=0;
	char ch;
	for(i=0;i_string[i]!='\0';i++)
	{
		if(is_operand(i_string[i]))
			o_string[j++]=i_string[i];
		if(i_string[i]=='(')
			s.push(i_string[i]);
		//cout<<"aas  "<<start->data;
		if(i_string[i]==')')
			while(ch=s.pop()!='(')
				o_string[j++]=s.pop();
		else if(is_operator(i_string[i]))
		{
			if(s.is_empty())
				s.push(i_string[i]);
			else if(priority(s.Show_top())<priority(i_string[i]))
				s.push(i_string[i]);
			else
			{
				while(s.is_empty()!=1 &&priority(s.Show_top())>=priority(i_string[i]))
					o_string[j++]=s.pop();
				s.push(i_string[i]);
			}
		}
	}
	while(s.is_empty()!=1)
	{
		
		o_string[j++]=s.pop();
			
	}

   //displaying the output string
	o_string[j]='\0';
	cout<<"\n"<<o_string;


}

void cExpression::infix_prefix()
{
	cStack<char> s;
	int i,j=0;
	char ch;
	reverse(i_string);

	for(i=0;i_string[i]!='\0';i++)
	{
		if(is_operand(i_string[i]))
			o_string[j++]=i_string[i];
		if(i_string[i]=='(')
			s.push(i_string[i]);
		if(i_string[i]==')')
			while(ch=s.pop()!='(')
				o_string[j++]=s.pop();
		else if(is_operator(i_string[i]))
		{
			if(s.is_empty())
				s.push(i_string[i]);
			else if(priority(s.Show_top())<priority(i_string[i]))
				s.push(i_string[i]);
			else
			{
				while(s.is_empty()!=1 &&priority(s.Show_top())>priority(i_string[i]))
					o_string[j++]=s.pop();
				s.push(i_string[i]);
			}
		}
	}
	while(s.is_empty()!=1)
	{
		
		o_string[j++]=s.pop();;
			
	}

   //displaying the output string
	o_string[j]='\0';
	reverse(o_string);
	cout<<"\n"<<o_string;


}

/*void cExpression::infix_prefix()
{
	//declaring the required variables
	int i,j=0;
	char ch,c,d,e;
	cStack<char> sk;
	//reversing the givem string
	reverse(i_string);
	for(i=0;i_string[i]!='\0';i++)
	{
		//if it is operand copying it in output string
		if(is_operand(i_string[i]))
		{
			o_string[j++]=i_string[i];
		}
		//if it is opening bracket pushing it onto stack
		else if(i_string[i]=='(')
		{
			sk.push(i_string[i]);
		}
		//poping data until opening bracket is encountered
		else if(i_string[i]==')')
		{
			while((ch=sk.pop())!='(')
			{	o_string[j++]=ch;
				if(sk.is_empty())
					break;
			}
		}
		else if(is_operator(i_string[i]))
		{
			//if stack is empty pushing it onto stack
			if(sk.is_empty())
				sk.push(i_string[i]);
			//pushing it onto stack if priority is greater
			else if((priority(sk.Show_top()))<(priority(i_string[i])))
				sk.push(i_string[i]);
			else 
			{
					if((sk.is_empty())==0)
					{
						//finding the proper position for the incoming operator
						while((sk.is_empty())!=1 && (priority(sk.Show_top()))>(priority(i_string[i])))
						{
							e=sk.pop();
							if(e=='(')
								continue;
							else
								o_string[j++]=e;
						}
					}
					//pushing onto the stack
					sk.push(i_string[i]);
				}
			}
		}
if((sk.is_empty())!=1)
{	
	//copying the remaining operators into output string
	while(sk.is_empty()!=1)
	{
        d=sk.pop();
		o_string[j++]=d;
			
	}
	//o_string[j++]=sk.pop();
}
	o_string[j]='\0';
	reverse(o_string);
	//displaying the output string
	cout<<"\n"<<o_string;
}
*/
int cExpression:: is_operator(char ch)
{
	//function fot deciding the operator
	if(ch=='+' || ch=='-' || ch=='*'|| ch=='/'|| ch=='^'|| ch=='$')
		return 1;
	else 
		return 0;
}
int cExpression::is_operand(char ch)
{
	//function fot deciding the operand
	if((ch>='A' && ch<='Z')||(ch>='a' &&ch<='z')||(ch>='1' &&ch<='9'))
		return 1;
	else 
		return 0;
}


void reverse(char i_string[50])
{
	//declaring the required variables
	char ch;
	char temp[50];
	cExpression sd;
	int i,len,j=0;
	//finding the len of string
	len=strlen(i_string);
	len--;
	for(i=len;i>=0;i--)
	{
		//reverse logic
	  if(i_string[len-j]==')')
		  i_string[len-j]='(';
	  else if (i_string[len-j]=='(')
		  i_string[len-j]=')';
	  temp[j]=i_string[len-j];
	  j++;
	 
	}
	temp[j]='\0';
	strcpy(i_string,temp); 
}
int main()
{
	//declaring the required variables
	int ch,flag=0;
	cExpression as;
	do
	{
		//giving the menu
		cout<<"\n 1.Prefix Conversion \n 2.Prefix Eva \n 3.Postfix Conversion \n4 .Postfix Eva";
		cout<<"\n Enter your choice";
		cin>>ch;
		switch(ch)
		{
		case 1:
			//calling getdata and infix to prefix conversion func
			as.getdata();
			as.infix_prefix();
			flag=1;
			break;
		case 2:
			//calling the evaluation func
			if(flag==1)
				as.prefix_eva();
			else
				cout<<"\n Convert the expression into prefix first";
			break;
		case 3:
			//calling getdata and infix to postfix conversion func
			as.getdata();
			as.infix_postfix();
			flag=2;
			break;
		case 4:
			//calling the evaluation func
			if(flag==2)
				as.postfix_eva();
			else
				cout<<"\n Convert the expression into postfix first";
			
			break;
		default:
			cout<<"\n Enter proper choice";
	
		}
	}while(ch!=0);
	
}
