#include<bits/stdc++.h>
using namespace std;

bool validRange(string str){
    if(stoi(str)>255 || stoi(str)<0) return false;

    if(str.size() > 1 && str[0]=='0') return 0;

    return true;
}

void getIp(string A, int idx, string ip,int ipPos,vector<string> & ans){

    if(idx ==A.size() && ipPos==5){

        ip = ip.substr(0,ip.size()-1);
        ans.push_back(ip);
        return;
    }
    if(idx >= A.size()) return;

    if(idx < A.size() && ipPos > 4) return;

    string str = A.substr(idx,1);
    if(validRange(str)){
        getIp(A,idx+1,ip+str+".",ipPos+1,ans);
    }
    str = A.substr(idx,2);
    if(validRange(str)){
        getIp(A,idx+2,ip+str+".",ipPos+1,ans);
    }
    str = A.substr(idx,3);
    if(validRange(str)){
        getIp(A,idx+3,ip+str+".",ipPos+1,ans);
    }
}

vector<string> restoreIpAddresses(string A){
    vector<string> ans;
    getIp(A,0,"",1,ans);
    return ans;
}

int main(){
    
    string A = "25525511135";
    vector<string> ans = restoreIpAddresses(A);

    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}