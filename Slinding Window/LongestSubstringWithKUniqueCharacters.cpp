#include<bits/stdc++.h>
using namespace std;


int largestSubstringUniqueChar(string A ,int k){
    int n = A.size();

    int i =0, j =0;
    unordered_map<char,int> mp;
    int mx = INT_MIN;
    while (j < n)
    {
        mp[A[j]]++;

        if(mp.size() < k){
            j++;
        }
        else if(mp.size()==k){
            mx = max(mx,j-i+1);
            j++;
        }
        else if(mp.size() > k){
            while (mp.size() > k)
            {
                mp[A[i]]--;
                if(mp[A[i]]==0){
                    mp.erase(A[i]);
                }
                i++;
            }
            j++;
        }
    }
    return mx!=INT_MIN?mx:-1;
}

int main(){
    
    string A = "aabacbebebe";
    cout<<largestSubstringUniqueChar(A,3);
    return 0;
}