#include<iostream>
using namespace std;

class edge
{
   public:
      int vertex,next;
      float cost;
      void read();
};

void edge::read()
{
    do{
            cout<<"\nEnter the current vertex ";
            cin>>vertex;
            cout<<"\nEnter the next vertex ";
            cin>>next;
            cout<<"\nEnter the cost of edge ";
            cin>>cost;
    }while(vertex<0 || next<0 || cost<0);

}

class graph
{
  
      edge e[30];
      edge t[30];
      int component[30];
      int n;
public:
      graph()
      {
      	n=0;
      }
      void accept();
      void sorting();
      void comp_union(int comp_no1,int comp_no2);
      float kruskal();
      void edge_disp();
};

void graph::accept()
{
    char ch;
  do{
     	 e[n++].read();
     	 cout<<"\n\nDo you want to continue<y/n> ";
     	 cin>>ch;

     }while(ch=='y'||ch=='Y');

     int i;
     for(i=0;i<n;i++)
     {
         component[i]=i;
     }


}

void graph::sorting()
{
    float key;
    edge record;
    int j;
    for(int i=0;i<n;i++)
    {
        key=e[i].cost;
        record=e[i];
        for(j=i-1;j>0 && key<e[j].cost;j--)
        {
            e[j+1]=e[j];
        }
        e[j+1]=record;

    }
}


void graph::comp_union(int comp_no1,int comp_no2)
{
    for(int i=0;i<n;i++)
    {
        if(component[i]==comp_no2)
            component[i]=comp_no1;
    }
}
float  graph::kruskal()
{
    int i=0,cnt=0;
    float min_cost=0.0;

    sorting();
	while(i < n-1)
    {

        int j=component[e[i].vertex];
        int k=component[e[i].next];
        if(j!=k)
        {
            t[cnt++]=e[i];
            min_cost+=e[i].cost;
            comp_union(j,k);
		}
        i++;
    }
    t[cnt].cost= -1;

   if(i!=n-1)
    {
        cout<<"\nNo spanning tree.\n";
        return 0;
    }
    
    else
        return min_cost;
}

void graph::edge_disp()
{
    for(int i=0;t[i].cost!= -1;i++)
    {
        cout<<"\n"<<t[i].vertex<<" -> "<<t[i].next<<endl;
    }
}

int main()
{
    graph obj;
    float minimum_cost;
    obj.accept();
    minimum_cost=obj.kruskal();
    cout<<"\nCost of Minimum Spanning Tree= "<<minimum_cost;
    cout<<"\nEdges included in MST: ";
    obj.edge_disp();
	return 0;
}
