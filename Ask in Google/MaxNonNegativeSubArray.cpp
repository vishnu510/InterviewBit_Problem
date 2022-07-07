#include<bits/stdc++.h>
using namespace std;

vector<int> maxNonNegSubArr(vector<int>& A){
    int start =0,end=-1,st =0;
    long sum = 0;
    long ans =INT_MIN;
    if(A[0]==0){
        ans =0;
    }
    for(int i=0;i<A.size();i++){
        sum+=A[i];
        if(sum>ans){
            ans = sum;
            start = st;
            end = i;
        }
        else if((ans==sum) && (end-start)<(i-st)){
            start =st;
            end = i;
        }
        else{
            sum = 0;
            st = i+1;
        }
    }
    vector<int> result;
    for(int i=start;i<=end;i++){
        result.push_back(A[i]);
    }
return result;
}


int main(){
    
    vector<int> A ={1, 2, 5, -7, 2, 3};
    vector<int> ans  = maxNonNegSubArr(A);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;

}