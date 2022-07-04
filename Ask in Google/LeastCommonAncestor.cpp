#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

bool find(TreeNode* A,int B){
     if(A==NULL){
         return false;
     }
     if(A->val==B){
         return true;
     }
     return find(A->left,B)||find(A->right,B);
 }

int helper(TreeNode* A,int B,int C){
    if(A==NULL){
        return -1;
    }
    if(A->val==B || A->val==C){
        return A->val;
    }
    int k = helper(A->left,B,C);
    int l = helper(A->right,B,C);
    if(k!=-1 && l!=-1){
        return A->val;
    }
    else if(k==-1 && l==-1){
        return -1;
    }
    else if(l==-1){
        return k;
    }
    else{
        return l;
    }
} 
 
int lca(TreeNode* A, int B, int C) {
    if(A==NULL){
        return -1;
    }
    if(find(A,B)&&find(A,C)){
        return helper(A,B,C);
    }
    else{
        return -1;
    }
}

int main(){

    return  0;
}