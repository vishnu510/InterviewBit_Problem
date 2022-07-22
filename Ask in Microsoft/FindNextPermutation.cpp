#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int> &A){

    int idx = -1;

    for(int i=A.size()-1;i>0;i--){

        if(A[i]>A[i-1]){
            idx = i-1;
            break;
        }
    }

    if(idx<0){
        reverse(A.begin(),A.end());
    }

    for(int i=A.size()-1;i>=0;i--){

        if(A[i]>A[idx]){
            swap(A[i],A[idx]);

        }
        reverse(A.begin()+idx+1,A.end());
        break;;
    }
    return A;
}

int main(){
    
    vector<int> A ={1,2,3};
    vector<int> ans = nextPermutation(A);

    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}