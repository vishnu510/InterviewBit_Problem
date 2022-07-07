#include<bits/stdc++.h>
using namespace std;

int maxMinSUm(vector<int> & A){
    int n = A.size();
    sort(A.begin(),A.end());
    return A[0]+A[n-1];
}

int main(){
   
    vector<int> A = {-2, 1, -4, 5, 3};
    cout<<maxMinSUm(A);
    return 0;
}