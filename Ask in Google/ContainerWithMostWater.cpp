#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<int>& height){
    int left =0,right =height.size()-1;
    int result =0;
    while(left<right){

        int lh = height[left];
        int rh = height[right];
        result = max(result,(right-left)*min(lh,rh));
        if(lh<rh){
            left++;
        }
        else
        right--;
    }
    return result;
}

int main(){


    vector<int> height = {2,3,4,5,18,17,6};
    cout<<maxArea(height);
    return 0;
}