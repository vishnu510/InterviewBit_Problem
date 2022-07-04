#include<bits/stdc++.h>
using namespace std;

string multiply(string s1,string s2){
    vector<int> digit(s1.size()+s2.size(),0);
    for(int i=s1.size()-1;i>=0;--i){
        for(int j=s2.size()-1;j>=0;--j){
            int mult = (s1[i]-'0')*(s2[j]-'0');
            int sum = mult + digit[i+j+1];
            digit[i+j+1] = sum%10;
            digit[i+j]+=sum/10;
        }
    }
    string ans ="";
    for(auto it:digit){
        if(ans.size()||it){
            ans.append(to_string(it));
        }
    }
    if(ans.size()==0){
        ans = "0";
    }
    return ans;
}

int main(){
    
    string s1 = "123", s2="456";
    cout<<multiply(s1,s2);
    return 0;
}