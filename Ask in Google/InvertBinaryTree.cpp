#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

TreeNode* newNode(int value){
    TreeNode* node = new TreeNode(value);
    node->val = value;
    node->left = node->right = NULL;
    return node;
}

TreeNode* invertTree(TreeNode* root){
    if(root==NULL){
        return NULL;
    }
    invertTree(root->left);
    invertTree(root->right);
    swap(root->left,root->right);
    return root;
 }
void printTree(TreeNode* root){
    if(root==NULL) return;
    cout<<root->val<<" ";
    printTree(root->left);
    printTree(root->right);
}
int main(){

    TreeNode* root = newNode(4);
    root->left = newNode(2);
    root->right =newNode(7);
    root->left->left =newNode(1);
    root->left->right =newNode(3);
    root->right->left =newNode(6);
    root->right->right =newNode(9);
    invertTree(root);
    printTree(root);
    return 0;
}