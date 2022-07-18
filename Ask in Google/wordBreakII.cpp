#include<bits/stdc++.h>
using namespace std;

vector<string> ans;

class Trie{
    public:
    unordered_map<char,Trie*> children;
    bool isEnd = false;

};

    void insert(string& word,Trie* root){
        Trie* curr = root;
        for(char c:word){
            if(curr->children.find(c)==curr->children.end()){
                curr->children[c] = new Trie();
            }
            curr  =curr->children[c];
        }
        curr->isEnd = true;
    }

    bool search(string word,Trie* root){
        Trie* curr = root;
        for(char c:word){
            if(curr->children.find(c)==curr->children.end()){
                return false;
            }
            curr  =curr->children[c];
        }
        return curr->isEnd;
    }
void dfs(string &s,int idx,string currstr,Trie* root){

    if(idx==s.size()){
        ans.push_back(currstr.substr(0,0+currstr.size()-1));
        return;
    }
    string str ="";
    for(int i=idx;i<s.size();++i){
        str.push_back(s[i]);
        if(search(str,root)){
            dfs(s,i+1,currstr+str+" ",root);
        }
    }
}

vector<string> wordBreak(string s, vector<string>& wordDict){
    
    Trie* root = new Trie();
    for(auto word:wordDict){
        insert(word,root);
    }
    dfs(s,0,"",root);
    return ans;
}

int main(){

    string s = "catsanddog";
    vector<string> wordDict = {"cat","cats","and","sand","dog"};

    vector<string> ans = wordBreak(s,wordDict);

    for(int i=0;i<ans.size();i++){
        cout<<"["<<ans[i]<<"]"<<" ";
    }
    return 0;
}