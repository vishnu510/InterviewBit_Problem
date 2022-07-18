#include<bits/stdc++.h>
using namespace std;

class Trie{
    public:
     unordered_map<char,Trie*> children;
     bool isEnd = false;

     void insert(string word){
        Trie * node = this;
        for(char c:word){
            if(node->children.find(c)==node->children.end()){
                node->children[c] = new Trie();
            }
            node = node->children[c];
        }
        node->isEnd = true;
     }

     bool search(string word){
        Trie* node = this;
        for(char c:word){
            if(node->children.find(c)==node->children.end()){
                return false;
            }
            node = node->children[c];
        }
        return node->isEnd;
     }

};


bool wordBreak(string s, vector<string>& wordDict){

     Trie trie;
        for(string word : wordDict)
            trie.insert(word);
        
        vector<bool> dp(s.size()+1, false);
        dp[0]=true;
        
        for(int len=1; len<=s.size(); len++){
            for(int i=0; i<len; i++){
                if(dp[i] && trie.search(s.substr(i, len-i)))
                    dp[len]=true;
            }
        }
        return dp[s.size()];
}

int main(){


    string s = "myinterviewtrainer";
    vector<string> wordDict = {"trainer", "my", "interview"};
    cout<<wordBreak(s,wordDict);
    return 0;
}