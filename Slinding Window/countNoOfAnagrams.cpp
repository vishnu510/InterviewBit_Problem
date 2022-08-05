#include<bits/stdc++.h>
using namespace std;

int countAnagrams(string  A,string B){

    int windSize = B.size();
    int n = A.size();
    int ans  =0;

    unordered_map<char,int> mp;
    for(auto i:B){
        mp[i]++;
    }
    int count = mp.size();
    int i =0, j= 0;

    while (j<n)
    {
        mp[A[j]]--;
        if(mp[A[j]]==0){
            count--;
        }
        if(j-i+1<windSize){
            j++;
        }
        else if(j-i+1==windSize){

            if(count==0){
                ans++;
            }
            mp[A[i]]++;
            if(mp[A[i]]==1){
                count++;
            }
            i++;
            j++;
        }
    }
    return ans;
}


int main(){
    
    string A = "forxxorfxdofr",B = "for";

    cout<<countAnagrams(A,B);

    return 0;
}