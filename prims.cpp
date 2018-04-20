#include<iostream>
#include<string>
using namespace std;

class node
{
public:
    int vertex,endv;
    float cost;
    node *next;
    node()
    {
        cost=0.0;
        next=NULL;
    }
};

class prims
{

    node* city[30];
    string name[30];
    int n;
    float min_cost;
    int tree[20][2];
    int visited[30];
    int source;
	public:
    prims()
    {
        min_cost=0.0;
    }
    void read();
    void add(int vi,int vj,float e_cost);
    void prim();
    void display();
};
void prims::read()
{
    int u,v,i;
    float c;
	char ch;
    string input;
    cout<<"\nEnter the no. of cities in graph ";
    cin>>n;
    for(i=0;i<n;i++)
    {
        city[i]=NULL;
    }
    for(i=0;i<n;i++)
    {
        cout<<"\nEnter the name of city  "<<i+1<<" ";
        cin>>name[i];
    }

        int num;
      
      do  {
            cout<<"\n\nEnter first the city ";
            cin>>input;
            for(i=0;i<n;i++)
            {
                if(name[i]==input)
                u=i;
            }

            cout<<"\n\nEnter the next city ";
            cin>>input;
            for(i=0;i<n;i++)
            {
                if(name[i]==input)
                    v=i;
            }

            cout<<"\nEnter the cost ";
            cin>>c;
            add(u,v,c);
            add(v,u,c);

		   cout<<"\Do u want to add more edges<y/n> ";
           cin>>ch;
       

        }while(ch=='Y' || ch=='y');
        cout<<"\nEnter the head node ";
        cin>>input;
        for(i=0;i<n;i++)
        {
            if(name[i]==input)
                source=i;
        }

        for(i=0;i<n;i++)
            visited[i]=0;

        visited[source]=1;

}
void prims::add(int vi,int vj,float e_cost)
{
    node* p,*node1;
    node1=new node;
    node1->vertex=vi;
    node1->endv=vj;
    node1->cost=e_cost;
    node1->next=NULL;
    
    if(city[vi]==NULL)
    {
        city[vi]=node1;
    }
    else
    {
        p=city[vi];
        while(p->next!=NULL)
        {
            p=p->next;
        }
        p->next=node1;
    }

}

void prims::display()
{
    int i=0;
    cout<<"\nMinimum cost of tree is  "<<min_cost;
    cout<<"\n\nPreferred connections :";
    for(i=0; tree[i][0]!= -1 ;i++)
    {
        cout<<"\n "<<name[tree[i][0]]<<" -> "<<name[tree[i][1]];
    }
}

void prims::prim()
{
    int min_value=999,u,v,no_of_edges=0,i,cnt=0,flag;
    node *p;
    min_cost=0.0;
    while(no_of_edges < n)
    {
        flag=0;
        for(i=0;i<n;i++)
        {
            if(visited[i])
            {
                p=city[i];
                while(p!=NULL)
                {
                    if(p->cost < min_value && visited[p->endv]!=1)
                    {
                    	u=p->vertex;
                        v=p->endv;
                        min_value=p->cost;
                        flag=1;
                    }
                    p=p->next;
                }
            }
        }
        if(flag==1)
        {
            min_cost+=min_value;
            tree[cnt][0]=u;
            tree[cnt++][1]=v;
            visited[v]=1;
            min_value=999;
        }

        no_of_edges++;
    }
    tree[cnt][0]=-1;

}

int main()
{
    prims centre;
    centre.read();
    centre.prim();
    centre.display();
    return 0;
}
