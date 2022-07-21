#include<bits/stdc++.h>
using namespace std;


int maxSumSubArr(vector<int> & A){

    int sum =0,maxSum = INT_MIN;

    for(int i=0;i<A.size();i++){

        sum+=A[i];
        if(sum<A[i]){
            sum = A[i];
        }

        maxSum = max(maxSum,sum);
    }
    return maxSum;
}

int main(){
    
    vector<int> A ={-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout<<maxSumSubArr(A);
    return 0;
}