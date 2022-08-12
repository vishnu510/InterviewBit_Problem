#include<bits/stdc++.h>
using namespace std;


class Graph{

    int V;
    vector<list<int>> adj;
    public:

    Graph(int v);
    void addEdge(int u,int v);
    void bfs(int s);
};

Graph::Graph(int V){
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u,int v){
    adj[u].push_back(v);
}

void Graph::bfs(int s){

    vector<bool> visited;
    visited.resize(V,false);
    queue<int> q;
    visited[s] = true;
    q.push(s);
    while (!q.empty())
    {
        int curr = q.front();
        q.pop();
        cout<<curr<<" ";
        for(auto it:adj[curr]){
            if(visited[it]==false){
                visited[it] = true;
                q.push(it);
            }
        }
    }
    
}

int main(){

    Graph g(4);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    g.bfs(0);
    return 0;
}