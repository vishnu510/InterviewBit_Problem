#include<bits/stdc++.h>
using namespace std;

int maxToysPicks(string s,int k){

    int n = s.size();
    int i =0, j=0;
    int ans = INT_MIN;
    if(n==0) return 0;
    unordered_map<char,int> mp;

    while (j < n)
    {
        mp[s[j]]++;
        if(mp.size() < k){
            j++;
        }
        if(mp.size()==k){
            ans = max(ans,j-i+1);
            j++;
        }
        else if(mp.size() > k){
            while (mp.size() > k)
            {
                mp[s[i]]--;
                if(mp[s[i]]==0){
                    mp.erase(s[i]);
                }
                i++;
            }
            j++;
        }
    }
    return ans;
}

int main(){
    
    string s = "abaccaba";
    cout<<maxToysPicks(s,2);
    return 0;
}