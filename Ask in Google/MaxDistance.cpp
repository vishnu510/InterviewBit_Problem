#include<bits/stdc++.h>
using namespace std;

int maxDistance(vector<int> & num){
    int result =-1;
    int n = num.size();
    vector<int> arr1(n),arr2(n);
    arr1[0] = num[0];
    arr2[n-1] = num[n-1];
    for(int i=1;i<n;i++){
        arr1[i] = min(arr1[i-1],num[i]);
    }
    for(int i=n-2;i>=0;i--){
        arr2[i] = max(arr2[i+1],num[i]);
    }
    int i=0,j=0;

    while (i<n && j<n)
    {
        if(arr1[i]<=arr2[j]){
            result = max(result,j-i);
            j++;
        }
        else{
            i++;
        }
    }
    return result;

}

int main(){

    vector<int> nums = {3, 5, 4, 2};
    cout<<maxDistance(nums);
    return 0;
}