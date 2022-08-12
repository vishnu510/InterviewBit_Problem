#include<bits/stdc++.h>
using namespace std;

class Graph{
   public:
   map<int,bool> visited;
   map<int,list<int>> adj;

   void addEge(int u,int v);
   void dfs(int v);
   void bfs(int node);

};

void Graph:: addEge(int u,int v){
    adj[u].push_back(v);
}

void Graph::dfs(int node){

    cout<<node<<" ";
    visited[node] = 1;

    for(auto it:adj[node]){
        if(visited[it]==0){
            dfs(it);
        }
    }
}



int main(){
    
    Graph g;
    g.addEge(0,1);
    g.addEge(0,2);
    g.addEge(1, 2);
    g.addEge(2, 0);
    g.addEge(2, 3);
    g.addEge(3, 3);
    g.dfs(0);
    return 0;
}