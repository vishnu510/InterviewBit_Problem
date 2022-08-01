#include<bits/stdc++.h>
using namespace std;

string countandsay(int n,string s="1"){

    if(n==1) return s;

    string ans = "";

    int i=0,j,len = s.size();

    while(i<len){

        j =i;

        while(i<len && s[i]==s[j]) i++;
        ans+=to_string(i-j)+s[j];
    }
    return countandsay(n-1,ans);
}

string countAndSay(int n){

    return countandsay(n);
}

int main(){

    cout<<"'"<<countAndSay(3)<<"'";
    return 0;
}