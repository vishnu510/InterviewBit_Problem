#include<bits/stdc++.h>
using namespace std;

int firstMissingNum(vector<int> &A){

    vector<int> seq(A.size(),-1);

    for(int i=0;i<A.size();i++){

        if(A[i]>=0 && A[i]<=A.size()){
            seq[A[i]-1] = 1;
        }
    }
    for(int i=0;i<seq.size();i++){
        if(seq[i]==-1){
            return i+1;
        }
    }
    return A.size()+1;
}

int main(){
     
    vector<int> A = {1,2,0};
    cout<<firstMissingNum(A);
    return 0;
}