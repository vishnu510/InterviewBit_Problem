#include<bits/stdc++.h>
using namespace std;

vector<int>  findFistNegative(vector<int>& nums,int k){

    int i=0, j =0;
    deque<int> q;
    vector<int> ans;
    while(j<nums.size()){

        if(nums[j]<0) q.push_back(nums[j]);
        if(j-i+1<k) j++;
        else{

            if(q.empty()) ans.push_back(0);
            else{
                ans.push_back(q.front());
            }
            if(nums[i]==q.front()) {
            q.pop_front();
            }
            i++;
            j++;
        }
        
    }
    return ans;
}

int main(){

    vector<int> nums = {1,-4,-2,8,6,-2,5};

    vector<int> ans = findFistNegative(nums,3);

    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}