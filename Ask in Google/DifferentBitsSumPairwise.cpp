#include<bits/stdc++.h>
using namespace std;

# define  ll long long int

ll cntBits(vector<int>&A){
    ll ans=0;
    vector<ll> a1(32,0);
    vector<ll> a2(32,0);
    int n = A.size();
    for(int i=0;i<n;i++){
        for(int j=0;j<32;j++){
            if(A[i]&(1<<j)){
                a1[j]++;
            }
            else{
                a2[j]++;
            }
        }
    }
    for(int i=0;i<32;i++){
        ans+=((a1[i]%1000000007)*(a2[i]%1000000007))%1000000007;
    }
    return (2*ans)%1000000007;
}

int main(){

    vector<int> A = {1, 3, 5};
    cout<<cntBits(A);
    return 0;
}