#include<bits/stdc++.h>
using namespace std;

vector<int> plusOne(vector<int>& A){

    if(A[0]==0 && A.size()>1){

        int c =0;
        while(A[c]==0){
            c++;
        }
        reverse(A.begin(),A.end());
        while (c--)
        {
            A.pop_back();
        }
        
    }
    else{
        reverse(A.begin(),A.end());
    }
    
    vector<int> ans;
    int sum =0,carry =1;
    for(int i=0;i<A.size();i++){
        sum = A[i]+carry;
        ans.push_back(sum%10);
        carry = sum/10;
    }

    if(carry==1){
        ans.push_back(1);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    
    vector<int> A = {1,2,3};
    vector<int> ans = plusOne(A);

    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}