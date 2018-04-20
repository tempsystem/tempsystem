#include<iostream>
#include<string.h>
using namespace std;
struct tree_node
{
	//declaring tree node structure
	char data;
	struct tree_node *left,*right;
};

struct node_Stack
{
	//declaring node for stack
	struct tree_node *data1;
	struct node_Stack *next;
};


class stack
{
	
	node_Stack *start;
public:
	stack(){start=NULL;}
	void push(struct tree_node*);
	struct tree_node* pop();
	int is_empty();
};


int stack::is_empty()
{
	//function to check if stack is empty or not
	if(start==NULL)
		return 1;
	else
		return 0;
}

struct tree_node* stack::pop()
{
	//poping the data from the stack
	node_Stack *temp=start;
	tree_node *temp2;
	if(start!=NULL)
	{
		 start=start->next;
		 temp2=temp->data1;
		 //deleting the poped node
		 delete temp;
		 //returning the poped data
		 return temp2;
	}
	
	
}
void stack::push(tree_node *temp)
{
	//creating the new node for the stack
	node_Stack *temp2;
	temp2=new node_Stack;
	
	temp2->data1=temp;
	temp2->next=NULL;
	//putting that node onto the stack
	if(start==NULL)
	{
		start=temp2;
	}
	else
	{
		temp2->next=start;
		start=temp2;
	}
}
class expression
{
	//decalring the class variables
	char string1[30];
	struct tree_node *root;
public:
	expression(){root=NULL;}
	void create();
	void accept();
	int is_operator(char);
	int is_operand(char);
	void rec_inorder();
	void non_inorder();
	void non_preorder();
	void non_postorder();
    void rec_preorder();
    void rec_postorder();
    void rec_inorder(struct tree_node*);
    void rec_preorder(struct tree_node*);
    void rec_postorder(struct tree_node*);
	void destroy(struct tree_node*);
	void destroy();


};


void expression::destroy()
{
	//calling destroy function 
  if(root!=NULL)
  		destroy(root);
}

void expression::destroy(struct tree_node* temp)
{
   if(temp!=NULL)
   {
	  //calling destroy function recursively
   	  destroy(temp->left);
	  destroy(temp->right);
   	  delete temp;
   	  
   	  
   }
   else
   		return;
 }

void expression::rec_inorder()
{
	//calling the recursive inorder function
	cout<<"\n";
	if(root!=NULL)
		rec_inorder(root);
}
void expression::rec_preorder()
{
	//calling the recursive preorder function
	cout<<"\n";
if(root!=NULL)
  		rec_preorder(root);
}
void expression::rec_postorder()
{
	//calling the recursive postorder function
	cout<<"\n";
if(root!=NULL)
  		rec_postorder(root);
}

void expression::rec_postorder(struct tree_node* temp)
{
	//calling the recursive postorder function recursively
  if(temp!=NULL)
   {
   rec_postorder(temp->left);
   rec_postorder(temp->right);
   cout<<""<<temp->data;
   
   }
   	return;

}
void expression::rec_preorder(struct tree_node* temp)
{
   if(temp!=NULL)
   {
   cout<<""<<temp->data;
   //calling the recursive pretorder function recursively
   rec_preorder(temp->left);
   rec_preorder(temp->right);
   	  
   }
   	return;


}

void expression::non_inorder()
{
	//declaring the required variable
	struct tree_node *temp=root;
	stack s;
	//conditions for the functions
	while((s.is_empty())!=1 || temp!=NULL)
	{
		while(temp!=NULL)
		{
			//pushing node on stack
			s.push(temp);
			temp=temp->left;
		}	
		if(temp==NULL)
		{
			//poping the data and printing it
			temp=s.pop();
			cout<<""<<temp->data;
			temp=temp->right;	
		}
		
	}
}

void expression::non_preorder()
{
	tree_node *temp=root;
	stack s;
	if(root!=NULL)
		//pushing the node onto the stack
		s.push(root);
	while((s.is_empty())!=1)
	{
		//poping the node from stack
		temp=s.pop();
		//processing the node
		cout<<""<<temp->data;
		if(temp->right!=NULL)
			//pushing the right child of node on stack
			s.push(temp->right);
		if(temp->left!=NULL)
			//pushing the left child of npode on stack
			s.push(temp->left);
	}
}

void expression::non_postorder()
{
	tree_node *p,*q;
	stack s;
	p=q=root;
	while(p!=NULL)
	{
  	   while(p->left!=NULL)
	  {
 		s.push(p);
		p=p->left;
 	  }
		while(p!=NULL && (p->right==NULL || p->right==q))
		{
 			cout<<""<<p->data;
			q=p;
			if((s.is_empty())==1)
				return;
			p=s.pop();	
		}
		s.push(p);
		p=p->right;
	}
}

void expression::rec_inorder(struct tree_node *temp)
{
	if(temp!=NULL)
   {
	   //recursive inoder function
   	  rec_inorder(temp->left);
   	  cout<<""<<temp->data;
   	  rec_inorder(temp->right);
   	  
   }



}


void expression::create()
{
	//declaring the required variables
	int i,len;
	stack s;
	len=strlen(string1);
	len--;
	for(i=len;i>=0;i--)
	{
		if(is_operand(string1[i]))
		{
			//creating the new node
			struct tree_node *temp;
			temp=new struct tree_node;
			temp->left=NULL;
			temp->right=NULL;
			temp->data=string1[i];
			//pushing new node on stack
			s.push(temp);
			

		}
		else if(is_operator(string1[i]))
		{
			struct tree_node *temp;
			temp=new struct tree_node;
			//poping two nodes from stack
			temp->left=s.pop();
			temp->right=s.pop();
			temp->data=string1[i];
			//pushing node back on stack
			s.push(temp);
		}
	}

	root=s.pop();
}


void expression::accept()
{
	//declaring required variables
	int i,len,cnt1=0,flag,cnt2=0;
	do{
		flag=0;
		cout<<"\nEnter the PREFIX expression";
		cin>>string1;
		for(i=0;string1[i]!='\0';i++)
		{
			if(is_operand(string1[i]))
				//incrementing operand counter
				cnt1++;
			else if(is_operator(string1[i]))
				//incrementing the operator counter
				cnt2++;
			//checking if any opening or closing bracket is present in expreesion
			if(string1[i]=='(' || string1[i]==')')
				flag=1;
		}
		//checking the last char is operand or not
		len=strlen(string1);
		len--;
		if(is_operator(string1[len])|| is_operator(string1[len-1]))
			flag=1;
		if(cnt1<=cnt2 || flag==1)
				cout<<"\nEnter valid expression";

	}while(cnt1<=cnt2 || flag==1);

}
int expression:: is_operator(char ch)
{
	//functin for identifying oprator
	if(ch=='+' || ch=='-' || ch=='*'|| ch=='/'|| ch=='^'|| ch=='$')
		return 1;
	else 
		return 0;
}
int expression::is_operand(char ch)
{
	//functin for identifying operand
	if((ch>='A' && ch<='Z')||(ch>='a' &&ch<='z')||(ch>='1' &&ch<='9'))
		return 1;
	else 
		return 0;
}




int main()
{
	//declaring the required variable
	int ch,ch2;
	expression s1;
	s1.accept();
	s1.create();
	do{
		//giving menu for user
		cout<<"\n1.Inorder\n2.Postorder\n3.Preorder";
		cin>>ch;
		switch(ch)
		{
		case 1:
			//calling recursive or nonrecursive func according to choice
			cout<<"\n1.Recursive\n2.Non-Recursive";
			cin>>ch2;
			if(ch2==1)
				s1.rec_inorder();
			else
				s1.non_inorder();
			break;
		case 2:
			//calling recursive or nonrecursive func according to choice
			cout<<"\n1.Recursive\n2.Non-Recursive";
			cin>>ch2;
			if(ch2==1)
				s1.rec_postorder();
			else
			if(ch==2)
				s1.non_postorder();
			break;
		case 3:
			//calling recursive or nonrecursive func according to choice
			cout<<"\n1.Recursive\n2.Non-Recursive";
			cin>>ch2;
			if(ch2==1)
				s1.rec_preorder();
			else
				s1.non_preorder();
			break;
		case 4:
			cout<<"Exit Sucessfull";
			break;
		default:
			cout<<"\nEnter proper choice";
		}
	  }while(ch!=0);
	
	s1.destroy();
}
