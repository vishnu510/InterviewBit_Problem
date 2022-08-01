#include<bits/stdc++.h>
using namespace std;

string insetNextLine(int n){

    string ans;
    for(int i=0;i<n;i++){
        ans+="\t";
    }
    return ans;
}

vector<string> prettyJSON(string A){

    if(A=="") return {};

    vector<string> ans;
    string word ="";
    int tab =0;

    for(auto c:A){

        if(c=='{' || c=='['){

            if(word!="") ans.push_back(insetNextLine(tab)+word);
            ans.push_back(insetNextLine(tab) + c);
            ++tab;
            word ="";
        }
        else if(c=='}' || c==']'){
            if(word!="") ans.push_back(insetNextLine(tab) + word);
            --tab;
            word = c;
        }

        else if(c==','){
            word+=c;
            ans.push_back(insetNextLine(tab)+ word);
            word = "";
        }
        else{
            word+=c;
        }
    }
    if(word!="") ans.push_back(word);
    return ans;
}

int main(){
    
    string A = "bare""}}}";
    vector<string> ans = prettyJSON(A);

    for(auto word:ans){
        cout<<word<<" ";
    }
    return 0;
}