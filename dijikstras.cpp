#include<iostream>
#include<string.h>
using namespace std;
class DIJIKS
{
   	int nodes,sp,ep;
   	int **cost,distance[40],found[30],prev[10];
	char cities[20][30];
   public:
   		DIJIKS(); 
        void create();
        void algo(); 
        int chose();
        void minimum_path(int dest); 
};
int search(char city[][30],char temp[30],int total)
{
	for(int i=0;i<total;i++)
	{
       	   int res=strcmp(temp,city[i]);
	   if(res==0)
	   return i;
	}
	return -1;
}
DIJIKS::DIJIKS()
{
  for(int i=0;i<30;i++)
  {
    found[i]=0;
  }
}
void DIJIKS::create()
{
   char ch,ch1;
   int a,b,flag;
   char temp[30];
   cout<<"\n Enter the number of the cities for the graph";
   cin>>nodes;
   cout<<"\nEnter the "<<nodes<<"  cities";
   {
	   for(int i=0;i<nodes;i++)
		   cin>>cities[i];
   }
   //allocating memory for cost array
   cost=new int*[nodes];
   for(int i=0;i<nodes;i++)
		*(cost+i)=new int[nodes];
   //initilizing weights of all the cities
	for(int i=0;i<nodes;i++)
   	{
       		for(int j=0;j<nodes;j++)
			cost[i][j]=9999;
   	}
	cout<<"\n Do you want directed graph (Y/N)";
	cin>>ch1;
	if(ch1=='Y' || ch1=='y')
		flag=0;
	else flag=1;
   do
   {
	   do{
			cout<<"\nEnter the starting city  ";
			cin>>temp;
			a=search(cities,temp,nodes);
	     }while(a==-1);
	   do{
			cout<<"\nEnter the ending city  ";
			cin>>temp;
			b=search(cities,temp,nodes);
	     }while(b==-1);
	   cout<<"\nEnter the weight for that edge "<<cities[a]<<"->"<<cities[b]<<"  ";
	   cin>>cost[a][b];
	   if(flag==1)
		   cost[b][a]=cost[a][b];
	   
	   cout<<"\nDo you want to continue(y/n)  ";
	   cin>>ch;
   }while(ch=='Y' ||ch=='y');
   do
   {
		cout<<"\n Enter the source city   ";
		cin>>temp;
		sp=search(cities,temp,nodes);
   }while(sp==-1);


}

 

void DIJIKS::algo()
{
   char ch,flag,temp[30];
   for(int i=0;i<nodes;i++)
   {
   		distance[i]=cost[sp][i];
   		prev[i]=sp;
   }
   found[sp]=1;
   distance[sp]=0;


   for(int i=0;i<=nodes-2;i++)
   {
     int u=chose();
     found[u]=1;
     for(int w=0;w<nodes;w++)
     {
       if(!found[w])
       {
         if(distance[u]+cost[u][w]<distance[w])
         {
            distance[w]=distance[u]+cost[u][w];
            prev[w]=u;
         }
       }
     }
   }
   
   
   for(int i=0;i<nodes;i++)
   {
      cout<<"\n Shortest path from "<<cities[sp]<<" ->  "<<cities[i]<<"  is   ";
      cout<<distance[i]<<"  ";
   }
   
   
   cout<<"\n Do you want to display all path(Y/N)";
      cin>>ch;
      if(ch=='y' || ch=='Y')
      {
    	for(int i=0;i<nodes;i++)
   		{
			flag=0;
      		if((distance[i]!=9999)&&i!=sp)
        		minimum_path(i);
        
      		else if((distance[i]==9999))
        		cout<<"\n Path does not exist";
     
   		}
   	}
   	else
   	{
   	
   		do
   		{
			cout<<"\n Enter the destination city   ";
			cin>>temp;
			ep=search(cities,temp,nodes);
   		}while(ep==-1);
   			minimum_path(ep);
   	}
   	
 }

void DIJIKS::minimum_path(int dest)
{

   cout<<"\n\n";
   int path[20],i=0;
   path[i++]=dest;
   while(dest!=sp)
   {
      path[i++]=prev[dest];
      dest=prev[dest];
   }
   for(int j=i-1;j>=1;j--)
   {
		cout<<cities[path[j]]<<"->";
   }
   cout<<cities[path[0]];
   


}

int DIJIKS::chose()
{
  int min=99999;
  int minimum_pos= -1;
  for(int i=0;i<nodes;i++)
  {
  	if(distance[i]< min && !found[i])
  	{
  		min=distance[i];
  		minimum_pos=i;
  	}
  	
  }
  return minimum_pos;
}
int main()
{
	DIJIKS s1;
	s1.create();
	s1.algo();
}