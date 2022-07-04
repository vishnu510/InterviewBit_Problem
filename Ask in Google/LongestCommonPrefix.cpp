#include<bits/stdc++.h>
using namespace std;

int findLen(vector<string> &A,int n){
    int min_ = A[0].size();
    for(int i=0;i<n;i++){
        if(min_>A[i].size()){
            min_ = A[i].size();        }
    }
    return min_;
}

string longestCommonPrefix(vector<string> &A){
    int n = A.size();
    int len = findLen(A,n);
    string ans =  "";
    for(int i=0;i<len;i++){
        char curr = A[i][0];
        for(int j=0;j<n;j++){
            if(curr!=A[j][i]){
                return ans;
            }
        }
        ans+=curr;
    }
    return ans;
}

int main(){

    vector<string> strs = {"abcdefgh", "aefghijk", "abcefgh"};
    cout<<longestCommonPrefix(strs);
    return 0;
}