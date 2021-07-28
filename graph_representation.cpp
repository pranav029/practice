#include<iostream>
#include<limits>
using namespace std;
class adjaceny{
    public:
    int dest;
    int weight;
    adjaceny* adj;
    adjaceny(int dest,int weight):dest(dest),weight(weight),adj(nullptr){};
};
class list{
    public:
    adjaceny* head;
};
class Graph{
    public:
    int V,E;
    list* lt;
    bool *flag;
    Graph(int V)
    {
        this->V=V;
        this->E=0;
        lt=new list[V];
        flag=new bool[V];
        for(int i=0;i<V;i++)
         {
             lt[i].head=nullptr;
             flag[i]=false;
         }
    }
};
void addEdge(int src,int dest,int weight,Graph* g)
{
   adjaceny* temp=new adjaceny(dest,weight);
   temp->adj=g->lt[src].head;
   g->lt[src].head=temp;

    g->E++;
//    adjaceny* temp1=new adjaceny(src,weight);
//    temp1->adj=g->lt[dest].head;
//    g->lt[dest].head=temp1;
}
void print(Graph* g)
{
    for(int i=0;i<g->V;i++)
    {
        adjaceny *temp=g->lt[i].head;
        cout<<"Edges connected with "<<i+1<<endl;
        while(temp)
        {
            cout<<temp->dest+1<<" "<<temp->weight<<endl;
            temp=temp->adj;
        }
        cout<<endl;
    }
}
void DFS(Graph* g,int V)
{
    adjaceny* temp=g->lt[V].head;
    g->flag[V]=true;
    cout<<V<<" ";
    while(temp)
    {
      if(!g->flag[temp->dest])DFS(g,temp->dest);
      temp=temp->adj;
    }
}
int min_cost(int *dist,bool *flag,int V)
{
    int min=INT_MAX,ind;
    for(int i=0;i<V;i++)
    {
        if(dist[i]<min && !flag[i])
        {
            min=dist[i];
            ind=i;
        }
    }
    return ind;
}
int* Dijkstras(Graph* g,int src)
{
   int *dist=new int[g->V];
   dist[src]=0;
   for(int i=0;i<g->V;i++)
     if(i!=src)dist[i]=INT_MAX;
   for(int i=0;i<g->V-1;i++)
   {
      int m=min_cost(dist,g->flag,g->V);
      g->flag[m]=true;
      adjaceny* temp=g->lt[m].head;
      while(temp)
      {
          if(dist[m]!=INT_MAX && dist[m]+temp->weight<dist[temp->dest] && !g->flag[temp->dest])
          dist[temp->dest]=dist[m]+temp->weight;
          temp=temp->adj;
      }
   }  
  return dist;
}
void Bellman_ford(Graph* g,int src)
{
   int *dist=new int[g->V];
   dist[src]=0;
   for(int i=0;i<g->V;i++)
     if(i!=src)dist[i]=INT_MAX;
     for(int i=0;i<g->V-2;i++)
     {
         for(int j=0;j<g->V;j++)
         {
            adjaceny* temp=g->lt[j].head;
             while(temp)
             {
                 if(dist[j]!=INT_MAX && dist[j]+temp->weight<dist[temp->dest])
                 dist[temp->dest]=dist[j]+temp->weight;
                 temp=temp->adj;
             }   
         }
     }
     for(int j=0;j<g->V;j++)
         {
            adjaceny* temp=g->lt[j].head;
             while(temp)
             {
                 if(dist[j]!=INT_MAX && dist[j]+temp->weight<dist[temp->dest])
                 {
                     cout<<"Graph contains negative weight cycles:\n";
                     return;
                 }
                 temp=temp->adj;
             }   
         }
         for(int i=0;i<g->V;i++)
         {
             cout<<i<<" "<<dist[i]<<endl;
         }
         return;
}
void test(int *arr)
{
    for(int i=0;i<5;i++)
     cout<<arr[i]<<" ";
}
int main()
{
    int V=5;
    Graph* g=new Graph(V);
    addEdge(0,1,-1,g);
    addEdge(0,2,4,g);
    addEdge(1,2,3,g);
    addEdge(1,3,2,g);
    addEdge(1,4,2,g);
    addEdge(3,2,5,g);
    addEdge(3,1,1,g);
    addEdge(4,3,-3,g);
    print(g);
    // Bellman_ford(g,0);
    int *arr=Dijkstras(g,0);
    for(int i=0;i<V;i++)
     cout<<arr[i]<<" ";
    // DFS(g,2);
    // int *arr=new int[5];
    // for(int i=0;i<5;i++)
    //  arr[i]=i+2;
    //  test(arr+1);
}

