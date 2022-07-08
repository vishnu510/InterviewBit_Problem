#include<bits/stdc++.h>
using namespace std;

void dfs(vector<string>& temp,string A,string end,unordered_set<string> st,vector<vector<string>>& sol){
    if(A==end){
        sol.push_back(temp);
        return;
    }
    for(int i=0;i<A.size();i++){
        for(int j=0;j<26;j++){
            int tempp = A[i]-'a';
            A[i] = j+'a';
            if(st.find(A)!=st.end()){
                temp.push_back(A);
                st.erase(A);
                dfs(temp,A,end,st,sol);
                temp.pop_back();
            }
            A[i] = tempp+'a';
        }
    }
}

vector<vector<string>> findLadders(string start, string end, vector<string>& dict) {

    unordered_set<string> st;
    for(int i=0;i<dict.size();i++){
        st.insert(dict[i]);
    }
    vector<string> temp;
    st.erase(start);
    temp.push_back(start);
    vector<vector<string>> ans,sol;
    dfs(temp,start,end,st,sol);
    int minSize = INT_MAX;
    for(int i=0;i<sol.size();i++){
        if(minSize>sol[i].size()){
            minSize = sol[i].size();
        }
    }
    for(int i=0;i<sol.size();i++){
        if(minSize==sol[i].size()){
            ans.push_back(sol[i]);
        }
    }
 return ans;
}

int main(){
    
    string beginWord = "hit",endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    vector<vector<string>> ans = findLadders(beginWord,endWord,wordList);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            cout<<""<<ans[i][j];
        }
        cout<<" ";
    }
    return 0;
}