#include<bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };
 
 ListNode* merge(ListNode* l1,ListNode* l2){
        ListNode* res = new ListNode(0);
        ListNode* ans = res;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        if(p1==NULL) return p2;
        if(p2==NULL) return p1;
        while(p1!=NULL && p2!=NULL){
            if(p1->val<p2->val){
                ans->next = p1;
                ans = ans->next;
                p1 = p1->next;
            }
            else{
                ans->next = p2;
                ans = ans->next;
                p2 = p2->next;
            }
        }
        while(p1!=NULL){
            ans->next = p1;
            ans = ans->next;
            p1 = p1->next;
        }
        while(p2!=NULL){
            ans->next  = p2;
            ans = ans->next;
            p2 = p2->next;
        }
        return res->next;
    }
    ListNode* partition(vector<ListNode*>& lists,int s,int e){
        if(s>e) return NULL;
        if(s==e) return lists[s];
        int mid = s+(e-s)/2;
        ListNode* l1 = partition(lists,s,mid);
        ListNode* l2 = partition(lists,mid+1,e);
        return merge(l1,l2);
    } 
 
ListNode* mergeKLists(vector<ListNode*> &A) {
    
    int n = A.size();
    if(n==0){
        return NULL;
    }
    return partition(A,0,n-1);
    
}

int main(){

    return 0;
}