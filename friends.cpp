#include<iostream>
#include<queue>
#include<string.h>
using namespace std;

class username
{

	 public:
 		  char name[40];
          int dd,mm,yy;
          int no_of_comments;
          username* next;
		  username()
           {
                next=NULL;
           }
           void read();
           void display();
};

void username::read()
{ 
  cout<<"Enter Name:";
  cin>>name;
  int flag=0;

  do
  {
	cout<<"Year of birth(only yy):";
	cin>>yy;

  }while(yy<0);

  do
  {
	cout<<"Month of birth(only mm):";
	cin>>mm;
  }while(mm>12);
  
  do
  {
	cout<<"Date of birth(only dd):";
	cin>>dd;
	flag=0;
	if(mm==2 && dd>28)
		flag=1;
	if(mm%2==0 && dd>30)
		flag=1;
	if(mm%2==1 && dd>31)
		flag=1;
	if(yy%4==0 && dd==29)
		flag=0;

		
  }while(flag==1);

  
  cout<<"Enter the no of comments:";
  cin>>no_of_comments;
 
}

void username::display()
{ cout<<"\n*************************************";
  cout<<"\nName:"<<name;
  cout<<"\nDOB:"<<dd<<"/"<<mm<<"/"<<yy;
  cout<<"\nNo of comments:"<<no_of_comments;
  cout<<"\n*************************************\n\n";
}
class friendsbook
{
   username *users[50];
   int max_user;
   public:
          friendsbook();
          void add_user();
          void add_friend();
		  void max_friends();
          void display();
		  int search(char name1[30]);
		  void show_friends();
		  void Max_comments();
		  void Birth_days();
		  void Birth_days(int, int,int []);
		  int search(int i,username *temp)
		  {
			  username *temp2;
			  int flag;
			  for(temp2=users[i];temp2!=NULL;temp2=temp2->next)
			  {
				  flag=strcmp(temp2->name,temp->name);
				  if(flag==0)
					return -1;
			  }
			  return 1;
		  }
};
/*void friendsbook::Max_comments()
{
	int visited[20],i,month,res,max=0,index;
	queue<username*> q;
	username *temp,*temp2;
	for(i=0;i<20;i++)
	{
		visited[i]=0;
	}
	q.push(users[0]);
	visited[0]=1;
	while(!q.empty())
	{
		temp=q.front();
		res=search(temp->name);
		for(temp2=users[res];temp2->next!=NULL;temp2=temp2->next)
		{
			res=search(temp2->next->name);
			if(visited[res]!=1)
			{
				q.push(temp2->next);
				visited[res]=1;
			}
		}
		if(max<temp->no_of_comments)
		{
			max=temp->no_of_comments;
			index=search(temp->name);
		}
		q.pop();
	}
	cout<<"\n "<<users[index]->name<<"  has MAXIMUM comments ="<<users[index]->no_of_comments;
}*/
void friendsbook::Max_comments()//bfs
{
	int visited[20],res,max=0,index;
	queue<username*> q;
	username* temp,*temp2;
	for(int i=0;i<20;i++)
	  visited[i]=0;
	q.push(users[0]);
	while(!q.empty())
	{
		temp=q.front();
		res=search(temp->name);
		visited[res]=1;
		for(temp2=users[res]->next;temp2!=NULL;temp2=temp2->next)
		{
			res=search(temp2->name);
			if(!visited[res])
			{
				visited[res]=1;
				q.push(temp2);
			}
		}
		if(max<temp->no_of_comments)
		{
			max=temp->no_of_comments;
			index=search(temp->name);
		}
		q.pop();

	}
	cout<<"\n has max comments"<<users[index]->name;

}
void friendsbook::Birth_days()
{
	int visited[20],i,month,res;
	for(i=0;i<20;i++)
	{
		visited[i]=0;
	}
	cout<<"\n Enter the current month ";
	cin>>month;
	Birth_days(0,month,visited);
}
void friendsbook::Birth_days(int key,int month,int visited[])
{
	visited[key]=1;
	username* start=users[key],*temp;
	if(users[key]->mm==month)
		cout<<"\n Has biorthday in thos mionth  "<<users[key]->name;
	for(temp=start->next;temp!=NULL;temp=temp->next)
	{
		int res=search(temp->name);
			if(!visited[res])
			{
				Birth_days(res,month,visited);
			}
	}

}
/*void friendsbook::Birth_days(int key,int month,int visited[])
{
	username *temp,*start=users[key];
	visited[key]=1;
	int res;
	if(users[key]->mm==month)
				cout<<"\n  "<<users[key]->name<<"  has birthday in this month";

	for(temp=start->next;temp!=NULL;temp=temp->next)
	{
		res=search(temp->name);
		
		if(!visited[res])
		{
			Birth_days(res,month,visited);
		}
	}
}*/
void friendsbook::max_friends()
{
	int i,cnt=0,max=0,index;
	username *temp;
	for(i=0;i<max_user;i++)
	{
		cnt=0;
		temp=users[i];
		while(temp->next!=NULL)
		{
			cnt++;
			temp=temp->next;
			
		}
		if(cnt>max)
		{
			index=i;
			max=cnt;
		}
	}
	cout<<"\n  "<< users[index]->name<<"   has Maximum friends  and friends are  "<<max;
}
void friendsbook::show_friends()
{
  username *temp1,*temp2;
  int i;
  cout<<"\n";
  for(i=0;i<max_user;i++)
     {
       temp1=users[i];
       for(temp2=temp1;temp2!=NULL;temp2=temp2->next)
         {
           cout<<temp2->name<<"->";
         }
	   cout<<"\n";
     }
}
int friendsbook::search(char nam[30])
{
	int flag,i;
	for( i=0;i<max_user;i++)
	{
		flag=strcmp(users[i]->name,nam);
		if(flag==0)
			return i;
	}
	return -1;
}
void friendsbook::add_friend()
{
	if(max_user>=2)
	{
		username *temp1,*temp2,*temp3;
		char name1[30],name2[30];
		int flag1,flag2,res,flag=0;
		do
		{
			cout<<"\n Enter whose friend do you want to add  ";
			cin>>name1;
			flag1=search(name1);
			
		}while(flag1<0);
		do
		{
			cout<<"\n Enter whom  do you want to add as a friend of  "<<name1<<"  ";
			cin>>name2;
			flag2=search(name2);
		}while(flag2<0);


		res=search(flag1,users[flag2]);
		if(res==-1)
		{
				cout<<"\nalready friends ";
				flag=1;

		}
				if(flag==0){
			temp1=new username;
			temp1->next=NULL;
			strcpy(temp1->name,users[flag1]->name);
			temp1->dd=users[flag1]->dd;
			temp1->mm=users[flag1]->mm;
			temp1->yy=users[flag1]->yy;
			temp1->no_of_comments=users[flag2]->no_of_comments;

			temp2=new username;
			temp2->next=NULL;
			strcpy(temp2->name,users[flag2]->name);
			temp2->dd=users[flag2]->dd;
			temp2->mm=users[flag2]->mm;
			temp2->yy=users[flag2]->yy;
			temp2->no_of_comments=users[flag2]->no_of_comments;
		
		
			temp3=users[flag1];
			while(temp3->next!=NULL)
				temp3=temp3->next;
			temp3->next=temp2;
		
			temp3=users[flag2];
			while(temp3->next!=NULL)
				temp3=temp3->next;
			temp3->next=temp1;
		}
	}
	else
		cout<<"\n Not possible";
}
friendsbook::friendsbook()
{
   int i;
   for(i=0;i<50;i++)
	users[i]=NULL;
   max_user=0;
            
}

void friendsbook::add_user()
{
  if(max_user<50)
     {
       users[max_user]=new username;
       users[max_user++]->read();
     }
}

void friendsbook::display()
{
  
  int i;
  for(i=0;i<max_user;i++)
		users[i]->display();
}

int main()
{
  friendsbook f;
  int ch;
  
  do
  {
	cout<<"\n 1.Add user \n 2.Display \n 3.Add frnd \n 4.Display friends \n 5.birth days \n 6.Max comments ";
    cin>>ch;
	switch(ch)
	{
	case 1:
		f.add_user();
		break;
	case 2:
		f.display();
		break;
	case 3:
		f.add_friend();
		break;
	case 4:
		f.show_friends();
		break;
	case 5:
		f.Birth_days();
		break;
	case 6:
		f.Max_comments();
		break;
	case 7:
		f.max_friends();
	}
	  
  }while(ch!=0);
}
