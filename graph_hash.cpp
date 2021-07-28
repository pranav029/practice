//Graph implementation

#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void create_edge(unordered_map<int,vector<int>> &ver,int src,int dest)
{
    ver[src].push_back(dest);
}
void print(unordered_map<int,vector<int>> ver)
{
    unordered_map<int,vector<int>>::iterator it;
    for(it=ver.begin();it!=ver.end();it++)
      {
          cout<<"Vertices with "<<it->first<<" :\n";
          for(int i=0;i<it->second.size();i++)
           cout<<it->second[i]<<" ";
          cout<<endl;
      }
}
unordered_map<int,bool> visited;
void DFS(unordered_map<int,vector<int>> ver,int key)
{
    if(visited.find(key)!=visited.end())return;
    cout<<key<<" ";
    visited[key]=true;
    for(int i=0;i<ver[key].size();i++)
    {
        if(visited.find(ver[key][i])==visited.end())DFS(ver,ver[key][i]);
    }
}
int main()
{
    unordered_map<int,vector<int>> ver;
    create_edge(ver,5,2);
    create_edge(ver,5,0);
    create_edge(ver,2,3);
    create_edge(ver,3,1);
    create_edge(ver,4,0);
    create_edge(ver,4,1);
    print(ver);
    cout<<endl<<endl;
    unordered_map<int,vector<int>>::iterator it;
    //loop to traverse in case of disconnected graph
    for(it=ver.begin();it!=ver.end();it++)
    DFS(ver,it->first);

    return 0;
}
