#include<bits/stdc++.h>
using namespace std;

vector<int>  MaxOfWindowK(vector<int>& nums,int k){

    int n = nums.size();
    vector<int> ans;
    if(k>n){
        ans.push_back(*max_element(nums.begin(),nums.end()));
        return ans;
    }

    int i =0, j=0;
    deque<int> q;

    while (j < n)
    {
        while (!q.empty() && q.back() < nums[j])
        {
            q.pop_back();
        }
        q.push_back(nums[j]);
        
        if(j-i+1 < k){
            j++;
        }
        else{

            ans.push_back(q.front());

            if(nums[i]==q.front()){
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

    vector<int> ans = MaxOfWindowK(nums,3);

    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}