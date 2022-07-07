#include<bits/stdc++.h>
using namespace std;

int totalHammingDistance(vector<int>& A){
     long res=0;
        for(int i=0; i<32; i++){
            long set=0;
            for(int val=0; val<A.size(); val++){
                if((A[val] & (1<<i))!=0){
                    set++;
                }
            }
            long clear=(A.size()-set);
            long diff=set*clear*2;
            res=(res+diff)%1000000007;
        }
        return (int)res;
}

int main(){

    vector<int> nums ={4,14,2};
    cout<<totalHammingDistance(nums);
    return 0;
}