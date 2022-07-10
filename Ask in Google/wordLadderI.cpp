#include<bits/stdc++.h>
using namespace std;



int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

    if(find(wordList.begin(),wordList.end(),endWord)==wordList.end()){
        return 0;
    }
    set<string> st;
    for(auto i:wordList){
        st.insert(i);
    }
    queue<string> q;
    int ans = 0;
    q.push(beginWord);
    while (!q.empty())
    {
        ans++;
        int n = q.size();
        while(n--){
            string curr = q.front();
            q.pop();
            for(int j=0;j<curr.length();j++){
                string temp = curr;

                for(char i='a';i<='z';i++){
                    temp[j] = i;
                    if(temp==curr){
                        continue;
                    }
                    if(temp==endWord){
                        return ans+1;
                    }
                    if(st.find(temp)!=st.end()){
                        q.push(temp);
                        st.erase(temp);
                    }
                }
            }
        }
    }
    
return 0;
}

int main(){
    
    string beginWord = "hit",endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    cout<<ladderLength(beginWord,endWord,wordList);
    
    return 0;
}