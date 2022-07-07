#include<bits/stdc++.h>
using namespace std;

vector<int> searchRange(vector<int>& A, int B){
    vector<int> ans = {-1, -1};
int n= A.size();

int i =0;
int j =n-1;
int k = -1;
while(i<=j){
int mid = (i+j)/2;
if(A[mid] == B){
k= mid;
break;
}else if(A[mid] > B){
j = mid-1;
}
else{
i = mid+1;
}
}
if(k==-1){
return ans;
}

i=k;
j=k;
while(i>=0 and A[i]== B){
i--;
}
while(j<n and A[j]==B){
j++;
}

ans[0] = i+1;
ans[1] = j-1;

return ans;
}

int main(){

    vector<int> nums = {5,7,7,8,8,10};
    vector<int> ans = searchRange(nums,8);
    for(auto it:ans){
        cout<<it<<" ";
    }
    return 0;
}