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
 /*class queue
 {
    	struct queue *head;
    public:
    	void add()
    
 };*/
 
class BST
{
  tree_node *root;
  public:
  BST()	
  {root=NULL;}
  void create();
  void inorder(struct tree_node*);
  void inorder();
  int search(int n);
  void insert();
  void delete_node(int key);
  tree_node* inorder_successor(tree_node * ptr);
  void BFT();
};

void BST::BFT()
{
 queue q1;
 
}

tree_node* BST::inorder_successor(tree_node * ptr)
{
  ptr=ptr->right;
  while(ptr->left!=NULL)
  	ptr=ptr->left;
  return ptr;
}


void BST::delete_node(int key)
{

 tree_node *parent,*ptr=root,*ptr1;

 int flag=0,val;
 while(ptr!=NULL && flag==0)
 {
   if(ptr->data==key)
   	flag=1;
   else if(ptr->data>key)
   {
      parent=ptr;
      ptr=ptr->left;
 
   }
   else
   {
   	parent=ptr;
   	ptr=ptr->right;
   }
   
 }
 if(flag==0)
 {
   cout<<"\n Data not found";
   return;
 }  
 if(ptr->left==NULL && ptr->right==NULL)
  {
    if(parent->left==ptr)
      	parent->left=NULL;
    else
    	parent->right=NULL;
    delete ptr;
  }
  else if(ptr->left==NULL)
  {
     if(parent->left==ptr)
      parent->left=ptr->right;
     else
       parent->right=ptr->right;
      delete ptr;
  }
  else if(ptr->right==NULL)
  {
     if(parent->left==ptr)
      parent->left=ptr->left;
     else
       parent->right=ptr->left;
       delete ptr;
  }
  else if(ptr->left!=NULL && ptr->right!=NULL)
  {
    ptr1=inorder_successor(ptr);
    val=ptr1->data;
    delete_node(val);
    ptr->data=val;
  }

}

void BST::inorder()
{
	cout<<"\n";
	if(root!=NULL)
	   inorder(root);
}
void BST::inorder(struct tree_node* temp)
{
	if(temp!=NULL)
   	{
   	  inorder(temp->left);
   	  cout<<" "<<temp->data;
   	  inorder(temp->right);
   	  
   	}
   return;
}

void BST::insert()
{

  
  int flag=0;
  char ch;
  tree_node *pwalk,*parent;
  tree_node *temp;
  temp=new tree_node;
  temp->left=NULL;
  temp->right=NULL;
  cout<<"\nEnter the data for the node ";
  cin>>temp->data;
  
  	if(root==NULL)
  	{
  		root=temp;
  		//flag=1;
  	}
  	else
  	{
       		pwalk=root;
       		while(pwalk!=NULL)
       		{
                    parent=pwalk;
         	   if(temp->data<pwalk->data)
         	    	pwalk=pwalk->left;
         	   else if(temp->data>pwalk->data)
         	   	pwalk=pwalk->right;
         	   else if(temp->data==pwalk->data)
         	   {
         	   	cout<<"Data cannot be inserted";
         	   	flag=1;
         	   	delete temp;
         	   	//break;
         	   	
         	   }
       		}
       	
       		if(flag==0)
       		{
       			if(temp->data<parent->data)
       				parent->left=temp;
       			else 
       				parent->right=temp;
       			
       		
       		}
       	}   
  
}


int BST::search(int key)
{
   tree_node *temp=root;
   
   if(temp!=NULL)
   {
         while(temp!=NULL)
         {
           if(temp->data==key)
           {
           	return 1;
           }
           else if (temp->data>key)
                temp=temp->left;
           else 
           	temp=temp->right;
         }
     return 0;
   }
      

}


void BST::create()
{
  char ch;
  
 do{
        insert();
 	 
	
  	cout<<"\n Do you want to continue<y/n>";
    	cin>>ch;
   }while(ch=='y' ||ch=='Y');
}

int main()
{

int res,ch;
 BST s;
 s.create();
 int key;
 
 do{
    	cout<<"\n1.Display \n2.Search \n3.Delete";
 	cin>>ch;
 	switch(ch)
 	{
 		case 1:
 			s.inorder();
 			break;
 		case 2:
 			cout<<"\n Enter the key to be searched";
   			cin>>key;
 			res=s.search(key);
 			if(res==1)
 			    cout<<"\nData found";
 			else 
 			    cout<<"\n Data not found";
 			break;
 		case 3:
 			cout<<"\n Enter the key to be Deleted";
   			cin>>key;
 			s.delete_node(key);
 			break;
 		
 		
 	}
   }while(ch!=0);
}
