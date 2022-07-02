#include<bits/stdc++.h>
using namespace std;

int singleNumber(const vector<int> & A){
    int ans =0,k;
    for(int i=0;i<32;i++){
        k=0;
        for(int j=0;j<A.size();j++){
            if(A[j]&(1<<i)){
                k++;
            }
        }
        ans = ans + ((k%3)*(1<<i));
    }
    return ans;
}

int main(){

    vector<int> A = {1, 2, 4, 3, 3, 2, 2, 3, 1, 1};
    cout<<singleNumber(A);
    return 0;
}