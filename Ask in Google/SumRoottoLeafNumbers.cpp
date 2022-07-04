#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

void getSum(TreeNode* A,int num,int & ans){
    if(A->left==nullptr && A->right==nullptr){
        num = ((num*10)%1003 + A->val%1003)%1003;
        ans = (ans%1003 + num%1003)%1003;
        return;
    }
    num = ((num*10)%1003 + A->val%1003)%1003;
    if(A->left==NULL){
        getSum(A->right,num,ans);
    }
    if(A->right==NULL){
        getSum(A->left,num,ans);
    }
}

int sumNumbers(TreeNode* A){
    if(A==nullptr){
        return 0;
    }
    int ans =0;
    getSum(A,0,ans);
    return ans;
}

int main(){

    return 0;
}