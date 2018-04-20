#include<iostream>
using namespace std;
struct tree_node
{
	//declaring the structure node
 	char data;
 	struct tree_node *left,*right;
};
class tree
{   
	    //classs variables and functions
    	struct tree_node *root;
    public:
    	tree(){root=NULL;}
    	void create_tree();
    	struct tree_node* create();
		void copy_tree();
    	struct tree_node* copy(struct tree_node* temp);
		void inorder();
    	void preorder();
    	void postorder();
		void display_leaf();
		void leaf(struct tree_node*);
		void display_internal();
		void display_internal(struct tree_node*);
		int height(struct tree_node*);
		void height();
    	void inorder(struct tree_node*);
    	void preorder(struct tree_node*);
    	void postorder(struct tree_node*);
		void destroy();
		void destroy(struct tree_node*);
		int max(int a,int b)
		{
			if(a>b)
				return a;
			else return b;
		}
};

void tree::copy_tree()
{
	//function for copying the tree
	if(root!=NULL)
	{	
		struct tree_node *temp;
		temp=copy(root);
		inorder(temp);
	}
}
struct tree_node* tree::copy(struct tree_node *temp2)
{
	//creating the new node
	tree_node *temp;
	temp=new struct tree_node;
	//making new nodes left and right null
	temp->left=NULL;
	temp->right=NULL;
	temp->data=temp2->data;
	if(temp2->left!=NULL)
		//recursively calling copy function
		temp->left=copy(temp2->left);
	if(temp2->right!=NULL)
		//recursively calling copy function
		temp->right=copy(temp2->right);
	return temp;
}
void tree::destroy()
{
  if(root!=NULL)
  		destroy(root);
}

void tree::destroy(struct tree_node* temp)
{
	//function to destroy the tree
   if(temp!=NULL)
   {
	  //recursively calling destroy function
   	  destroy(temp->left);
	  destroy(temp->right);
   	  delete temp;
   }
   else
   		return;
 }

void tree::height()
{
	//function for calculating the height of tree
	int h;
	h=height(root);
	cout<<"\n Height is "<<h;
}
int tree::height(struct tree_node* temp)
{
	//declaring the required varibles
	int hl,hr;
	if (temp==NULL)
		return 0;
	if((temp->left==NULL) && (temp->right==NULL))
		return 1;
	//recursively calling the function
	hl=height(temp->left);
	hr=height(temp->right);
	return (max(hl,hr)+1);
}
void tree::display_leaf()
{
  if(root!=NULL)
  		leaf(root);
}
void tree::leaf(struct tree_node* temp)
{
	//function to display the leaf nodes
	if(temp!=NULL)
   {
   	  leaf(temp->left);
	  //checking condition for the leaf node
	  if(temp->left==NULL &&temp->right==NULL)
   		cout<<"  "<<temp->data;
   	  leaf(temp->right);
   	  
   }
   else
   	return;
 }


void tree::display_internal()
{
  //function to display the internal nodes
  if(root!=NULL)
  		display_internal(root);
}
void tree::display_internal(struct tree_node* temp)
{
	if(temp!=NULL)
   {
	   
   	  display_internal(temp->left);
	  //condition for the internal nodes
	  if(temp!=root &&(temp->left!=NULL || temp->right!=NULL))
   		cout<<"  "<<temp->data;
   	  display_internal(temp->right);
   	  
   }
   else
   	return;
 }




void tree::postorder()
{
if(root!=NULL)
  	postorder(root);
}

void tree::postorder(struct tree_node* temp)
{
	//postorder  recursive logic 
  if(temp!=NULL)
   {
	postorder(temp->left);
	preorder(temp->right);
	cout<<"  "<<temp->data;
   }
  else
   	return;

}

void tree::preorder()
{
if(root!=NULL)
  		preorder(root);
}

void tree::preorder(struct tree_node* temp)
{
	//preorder  recursive logic
   if(temp!=NULL)
   {
   cout<<"  "<<temp->data;
   preorder(temp->left);
   preorder(temp->right);
   	  
   }
   else
   	return;


}

void tree::inorder()
{
  if(root!=NULL)
  		inorder(root);
}
void tree::inorder(struct tree_node* temp)
{
	//inorder  recursive logic
   if(temp!=NULL)
   {
   	  inorder(temp->left);
   	  cout<<"  "<<temp->data;
   	  inorder(temp->right);
   	  
   }
   else
   	return;
 }

void tree::create_tree()
{
   root=create();
}

struct tree_node* tree::create()
{
   //declaring the requirede variables
  char ch;
  //creating the new node
  struct tree_node *temp;
  temp=new struct tree_node;
  temp->left=NULL;
  temp->right=NULL;
  cout<<"\n Enter the data for the node";
  cin>>temp->data;
     
  		cout<<"\nDo you want to add node at LEFT<Y/N> of  "<<temp->data;
  		cin>>ch;
  		if(ch=='y'|| ch== 'Y')
  		{
			//calling the create function for the left side of node
  			temp->left=create();
  		}
  		cout<<"\n\nDo you want to add node at RIGHT<Y/N> of "<<temp->data;
  		cin>>ch;
  		if(ch=='y'||ch== 'Y')
		{
			//calling the create function for the right side of node
  		    temp->right=create();
  		}
		//returning the newly created node after attaching in the tree
  		return temp;
}

int main()
{
	//declaring the required variables
   tree T;
   int ch,height;
   T.create_tree();
   do
   {
	//giving the menu for the user and asking for the choice
     cout<<"\n1.Inorder \n2.Preorder\n3.Postorder \n4.Display Leaf \n5.Height \n6.Internal_nodes \n7Copy tree";
     cin>>ch;
     switch(ch)
     {
     case 1:
		 //calling the inorder function
   			T.inorder();
   			break;
   	  case 2:
		  //calling the preorder function
   	        T.preorder();
   	        break;
   	  case 3:
		  //calling the postorder function
   	        T.postorder();
   	        break;
	  case 4:
		  //function call to display leaf nodes
			T.display_leaf();
		  break;
	  case 5:
		  //function call for displaying the height of the tree
		  T.height();
			break;
	  case 6:
		  //function call to display internal nodes
		  T.display_internal();
		  break;
	  case 7:
		  cout<<"\nCopied tree is\n";
		  T.copy_tree();
	default:
      		cout<<"\n Enter proper choice";  	            
    }
   
   }while(ch!=0);

   //calling the destroy function 
   T.destroy();
   
   
}
