#include<iostream>
#include<string.h>
using namespace std;
struct pat
{
	char name[30],disease[30];
     int pri,id;
     
};
struct node
{
	 struct pat *data;
     struct node *next; 
  
};


class patient
{
  struct node *front,*rear;
  public:
	  patient()
	  {
		front=NULL;
		rear=NULL;
	  }
	  void getdata();
      void remove();
    
};
void display(struct node *temp);
void patient::getdata()
{
 
  struct node *temp1,*temp2,*temp3;
  temp1=new struct node;
  temp1->data=new struct pat;
  temp1->next=NULL;
  static int temp=1;
  int ch;
  temp1->data->id=temp;
  temp++;
   cout<<"\n Enter the name of the patient";
   cin.ignore();
   cin.getline(temp1->data->name,sizeof(temp1->data->name));
   cout<<"\n Select the disease\n 1.serious accident \n 2.Heart attack\
		 \n 3.brain damage \n 4.Hand Fracture \n 5.TB\
		 \n 6.Cancer \n7.Cold\n 8.fever\n9 headache";
   cout<<"\n Enter your choice\n";
   cin>>ch;
   switch(ch)
   {
    case 1:
     	strcpy(temp1->data->disease,"serious accident");
     	temp1->data->pri=1;
     	break;
     case 2:
     	strcpy(temp1->data->disease,"Heart attack");
     	temp1->data->pri=1;
    	 break;
     case 3:
     	strcpy(temp1->data->disease,"brain damage");
     	temp1->data->pri=1;
     	break;
     case 4:
        strcpy(temp1->data->disease,"Hand Fracture");
     	temp1->data->pri=2;
     	break;
     case 5:
        strcpy(temp1->data->disease,"TB");
     	temp1->data->pri=2;
     	break;
     case 6:
        strcpy(temp1->data->disease,"Cancer");
     	temp1->data->pri=2;
     	break;
     case 7:
        strcpy(temp1->data->disease,"Cold");
     	temp1->data->pri=3;
     	break;
     case 8:
     	strcpy(temp1->data->disease,"fever");
     	temp1->data->pri=3;
     	break;
     case 9:
        strcpy(temp1->data->disease,"Headache");
     	temp1->data->pri=3;
     	break;
    default:
        cout<<"\n Enter proper choice";
   }
  
  if(front==NULL)
   front=rear=temp1;
   else
   {
	   rear->next=temp1;
	   rear=temp1;
	   for(temp2=front;temp2->next!=NULL;temp2=temp2->next)
		{
			for(temp3=front;temp3->next!=NULL;temp3=temp3->next)
				if(temp3->data->pri>temp3->next->data->pri)
				{
					struct pat* temp4=temp3->data;
					temp3->data=temp3->next->data;
					temp3->next->data=temp4;
				}

		}
			

		
   }
}
 void display(struct node *temp)
    {
    
     cout<<"\n********************\n";
     cout<<"\n NAME:-"<<temp->data->name;
     cout<<"\n ID:- "<<temp->data->id;
     cout<<"\n Disease is:-  "<<temp->data->disease;
     cout<<"\n priority:-  "<<temp->data->pri;
     cout<<"\n********************\n\n";
     
   }
  void patient::remove()
    {
      struct node *temp2=front;
      if(front==NULL)
      {
      	cout<<"\n Error!!!!!";
      }
      else if(front==rear)
      {
          display(front);
          front=rear=NULL;
          
      }
      else
      {
        display(front);
        front=front->next;
        delete temp2;
      }
    }
    
    
   
   int main()
   {
   int n;
   patient p;
   do
   {
     cout<<"\n1.Input data\n2.Remove\n Enter your choice ";
     cin>>n;
     switch(n)
     {
       case 1:	
     	p.getdata();
     	break;
     	case 2:
     	p.remove();
     	break;
     }
    }while(n!=5) ;
     return 0;
   }
