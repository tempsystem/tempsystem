#include<iostream>
using namespace std;

struct tree_node
	{
		int data;	  
		struct tree_node *left,*right;
	};

struct queue
	{
		struct tree_node *data1;
		struct queue *front,*rear;
	};
class BST
	{
		struct tree_node *root;

		public:
				BST(){root=NULL;}
				void create();
				void insert();
				void inorder();
				void inorder(struct tree_node *);
	};

void BST::create()
	{
		int flag=0;
		//tree_node *pwalk,*parent;
		
		struct tree_node* temp2;
		temp2=new struct tree_node;
		temp2->left=NULL;
		temp2->right=NULL;
		cout<<"\nenter data";
		cin>>temp2->data;
		
		if(root==NULL)
		{
			root=temp2;
		}	
			cout<<"\nadd left";
			cin>>ch;

			if(ch=='y')
			{
			temp2->left=create();			
			}
			cout<<"\nadd right";
			cin>>ch;

			if(ch=='y')
			{
			temp2->right=create();			
			}
		return temp;


	}
void BST::inorder()
	{
		cout<<"\n";
		if(root!=NULL)
		inorder(root);
	}

void BST::inorder(struct tree_node *temp1)
	{
		if(temp1!=NULL)
		{
			inorder(temp1->left);
			cout<<" "<<temp1->data;
			cout<<"*";
			inorder(temp1->right);
		}
	}


void BST::create()
	{
		char ch;
		do
		{
			insert();
			
			cout<<"\ndo you want continue";
			cin>>ch;
		}while(ch=='y');
	}


int main()
{

int res,ch;
 BST s;
 s.create();
 s.inorder();
}
	
				














