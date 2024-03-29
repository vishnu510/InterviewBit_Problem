#include<bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s){

    int n = s.size();
    int i =0, j=0;
    int ans = INT_MIN;
    if(n==0) return 0;
    unordered_map<char,int> mp;

    while (j < n)
    {
        mp[s[j]]++;
        if(mp.size()==j-i+1){
            ans = max(ans,j-i+1);
            j++;
        }
        else if(mp.size() < j-i+1){
            while (mp.size() < j-i+1)
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
    
    string s = "";
    cout<<lengthOfLongestSubstring(s);
    return 0;
}