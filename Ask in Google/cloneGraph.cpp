#include<bits/stdc++.h>
using namespace std;

 struct UndirectedGraphNode {
     int label;
     vector<UndirectedGraphNode *> neighbors;
     UndirectedGraphNode(int x) : label(x) {};
 };

UndirectedGraphNode * cloneGraph(UndirectedGraphNode *node) {
    map<UndirectedGraphNode*,UndirectedGraphNode*> mp;
    queue<UndirectedGraphNode*> q;
    q.push(node);
    UndirectedGraphNode* clone = new UndirectedGraphNode(node->label);
    clone->label = node->label;
    mp[node] = clone;
    while(!q.empty()){
        UndirectedGraphNode* u = q.front();
        q.pop();
        vector<UndirectedGraphNode*> v = u->neighbors;
        int n = v.size();
        for(int i=0;i<n;i++){
            if(mp[v[i]]==nullptr){
                clone = new UndirectedGraphNode(node->label);
                clone->label = v[i]->label;
                mp[v[i]] = clone;
                q.push(v[i]);
            }
            mp[u]->neighbors.push_back(mp[v[i]]);
        }
    }
    return mp[node];
}

int main(){

    return 0;
}