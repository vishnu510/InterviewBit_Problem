#include<bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
    int m = nums1.size() , n = nums2.size();
    if(m>n){
        findMedianSortedArrays(nums2,nums1);
    }
    int left =0, right = m;
    int total = m+n+1;
    while(left<=right){

        int first = left + (right-left)/2;
        int second = total/2-first;

        int l1 = INT_MIN,l2 = INT_MIN;
        int r1 = INT_MAX,r2 = INT_MAX;
        
        if(first>0){
            l1 = nums1[first-1];
        }
        if(second>0){
            l2 = nums2[second-1];
        }
        if(first>=0 && first<m){
            r1 = nums1[first];
        }
        if(second>=0 && second<n){
            r2 = nums2[second];
        }
        if(l1<=r2 && l2<=r1){
            if((m+n)%2==0){
                return (max(l1,l2)+ min(r1,r2))/2.0;
            }
            else{
                return max(l1,l2);
            }
        }
        else if(l1>r2){
            right = first-1;
        }
        else{
            left = first+1;
        }
    }
    return 0;
}

int main(){
    
    vector<int> nums1 ={1,3},nums2 ={2};
    double ans =findMedianSortedArrays(nums1,nums2);
    cout<<ans;
    return 0;
}