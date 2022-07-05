#include<bits/stdc++.h>
using namespace std;

int LongestSequence(vector<int> & nums){
    if(nums.size()==0) return 0;
    sort(nums.begin(),nums.end());
    int longest =0,currLongest =1;
    for(int i=1;i<nums.size();i++){
        if(nums[i]==nums[i-1]) continue;
        else if(nums[i]==nums[i-1]+1) currLongest++;
        else{
            longest =max(longest,currLongest);
            currLongest =1;
        }
        
    }
    return max(longest,currLongest);
}

int main(){
    vector<int> nums ={100,4,200,1,3,2};
    cout<<LongestSequence(nums);
    return 0;
}