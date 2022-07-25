#include<bits/stdc++.h>
using namespace std;

vector<int> findUnsortedSubarray(vector<int>& A){
    
    if(is_sorted(A.begin(),A.end()))
    return vector<int> {-1};
    int len = A.size();
    vector<int> copy = A;
    vector<int> ans;
    int i,j;
    sort(copy.begin(),copy.end());
    for(i=0,j=0;i<len,j<len;i++,j++){
        
        if(A[i]!=copy[j]){
            ans.push_back(i);
            break;
        }
    }
    for(i=len-1,j=len-1;i>=0,j>=0;i--,j--){
        
        if(A[i]!=copy[j]){
            ans.push_back(i);
            break;
        }
    }
    return ans;
    
}

int main(){

    vector<int> A = {2,6,4,8,10,9,15};
    vector<int> ans = findUnsortedSubarray(A);
    for(auto x:ans){
        cout<<x<<" ";
    }
    return 0;
}