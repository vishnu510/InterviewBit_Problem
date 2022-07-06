#include<bits/stdc++.h>
using namespace std;
int intersection(vector<int>& A, vector<int>& B,vector<int>& C){
    int i=0,j=0,k=0;
    int mini = INT_MAX;
    while(i<A.size() && j<B.size() && k<C.size()){
        int n1 =A[i],n2=B[j],n3=C[k];
        int diff = max(n1,max(n2,n3)) - min(n1,min(n2,n3));
        if(diff<mini){
            mini = diff;
        }
        if(A[i]<=B[j] && A[i]<=C[k]){
            i++;
        }
        if(B[j]<=A[i] && B[j]<=C[k]){
            j++;
        }
        else{
            k++;
        }
    }
    return mini;
}

int main(){
    
    vector<int> nums1 = {1,4,10};
    vector<int> nums2 = {2,15,20};
    vector<int> nums3 = {10,12};
    cout<<intersection(nums1,nums2,nums3);
    return 0;
}