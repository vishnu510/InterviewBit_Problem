#include<bits/stdc++.h>
using namespace std;

vector<int> addOnePlus(vector<int> &digit){
    if(digit[0]==0 && digit.size()>1){
        int count =0;
        while(digit[count]==0){
            count++;
        }
        while (count--)
        {
            digit.pop_back();
        }
        reverse(digit.begin(),digit.end());
    }
    else{
        reverse(digit.begin(),digit.end());
    }
    int sum=0,carry =1;
    vector<int> ans;
    for(int i=0;i<digit.size();i++){
        sum = digit[i] + carry;
        ans.push_back(sum%10);
        carry = sum/10;
    }
    if(carry==1){
        ans.push_back(1);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){


    vector<int> digit  = {1,2,3};
    vector<int> ans = addOnePlus(digit);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}