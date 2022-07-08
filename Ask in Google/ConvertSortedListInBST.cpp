#include<bits/stdc++.h>
using namespace std;


 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


 
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
pair<ListNode*,ListNode*> findMiddle(ListNode* A){
    if(A==nullptr||A->next==nullptr){
        return {nullptr,A};
    }
    ListNode* slow = A;
    ListNode* fast = A->next;
    ListNode* prev = nullptr;
    while(fast && fast->next){
        fast = fast->next->next;
        prev = slow;
        slow= slow->next;
    }
    return {prev,slow};
} 
TreeNode* sortedListToBST(ListNode* A) {
    
    if(A==nullptr){
        return nullptr;
    }
    pair<ListNode*,ListNode*> p = findMiddle(A);
    
    ListNode* prev = p.first;
    ListNode* middle = p.second;
    
    TreeNode* root = new TreeNode(middle->val);
    
    if(prev){
        prev->next = nullptr;
        root->left = sortedListToBST(A);
    }
    root->right = sortedListToBST(middle->next);
    return root;
}

int main(){

    return 0;
}