#include<bits/stdc++.h>
using namespace std;

vector<int> flips(string A){

    int sum =0,maxSum =0,right=0,left =0;

    bool flag = false;
    vector<int> ans(2);
    for(int i=0;i<A.size();i++){
        int val = A[i]=='0'?1:-1;
        sum = max(sum+val,val);
        if(val==1) flag = true;

        if(maxSum < sum){
            maxSum = sum;
            right = i;
            ans[0] = left+1;
            ans[1] = right+1;
        }
        if(sum < 0){
            sum =0;
            left = i+1;
        }
    }
    if(!flag) return {};
    return ans;
}

int main(){
    
    string str = "010";
    vector<int> ans = flips(str);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}