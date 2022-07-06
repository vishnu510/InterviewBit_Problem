#include<bits/stdc++.h>
using namespace std;

vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
    int i=0,j=0;
    vector<int> ans;
    while(i<nums1.size() && j<nums2.size()){
        if(nums1[i]<nums2[j])i++;
        else if(nums1[i]>nums2[j])j++;
        else{
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main(){
    
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> ans = intersection(nums1,nums2);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}