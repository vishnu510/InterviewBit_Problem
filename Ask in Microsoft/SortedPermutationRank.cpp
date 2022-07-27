#include<bits/stdc++.h>
using namespace std;

int fact(int n){
    if(n==0 || n==1) return 1;
    return (n*fact(n-1))%1000003;
}

int findRank(string A){
    
    int count =1;
    for(int i=0;i<A.size()-1;i++){

        int c=0;

        for(int j=i+1;j<A.size();j++){

            if(A[i]>A[j]) c++;
        }

        if(c){
            int a = fact(A.size()-i-1)%1000003;

            count = (count+ (a*c)%(1000003))%1000003;
        }
    }
    return count;
}

int main(){
    
    string A= "acb";
    cout<<findRank(A);
    return 0;
}