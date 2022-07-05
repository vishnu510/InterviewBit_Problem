#include<bits/stdc++.h>
using namespace std;

vector<int> order(vector<int> &nums1, vector<int> &nums2){
    int n = nums1.size();
    vector<pair<int,int>> people;
    for(int i=0;i<n;i++){
        people.push_back({nums1[i],nums2[i]});
    }
    sort(people.begin(),people.end());
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++){
        int count =0;

        int target = people[i].second;
        int j=0;
        while(j<n && count<=target){
            if(ans[j]==-1){
                count++;
            }
            j++;
        }
        ans[j-1] = people[i].first;
    }
    return ans;
}

int main(){
   
   vector<int> Heights ={5,3,2,6,1,4};
   vector<int> inFront ={0,1,2,0,3,2};
   vector<int> ans = order(Heights,inFront);
   for(auto i:ans){
    cout<<i<<" ";
   }
    return 0;
}