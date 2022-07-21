#include<bits/stdc++.h>
using namespace std;

static bool cmp(string a,string b){

    return a+b>b+a;
}

string largestNumber(vector<int>& nums){

    string ans ="";
    vector<string> str;
    for(auto i:nums){
        str.push_back(to_string(i));
    }
    sort(str.begin(),str.end(),cmp);
    if(str[0]=="0"){
        return "0";
    }
    for(auto s:str){
        ans+=s;
    }
    return ans;
}

int main(){

    vector<int> A= {3,30,34,5,9};
    cout<<largestNumber(A);
    return 0;
}