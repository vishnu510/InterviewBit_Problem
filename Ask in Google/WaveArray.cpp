#include<bits/stdc++.h>
using namespace std;

void waveArraySort(vector<int> & A){
    int n = A.size();
    for(int i=0;i<n;i+=2){
        if(i>0 && A[i-1]>A[i]){
            swap(A[i],A[i-1]);
        }
        if(i<n && A[i]<A[i+1]){
            swap(A[i],A[i+1]);
        }
    }
    return;
}

int main(){
   
    vector<int> A = {10, 90, 49, 2, 1, 5, 23};
     waveArraySort(A);
    for(auto it:A){
        cout<<it<<" ";
    }
    return 0;
}