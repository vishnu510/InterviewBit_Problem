#include<bits/stdc++.h>
using namespace std;

class ListNode{
    public:
    int val;
    ListNode* next;
    ListNode(int data){
        val = data;
        next = NULL;
    }
};


void insertion_at_Tail(ListNode*& head, int val) {
    if (head == NULL) {
        ListNode* node = new ListNode(val);
        head = node;
        return;
    }
    ListNode* temp = head;
    ListNode* node = new ListNode(val);
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}
void print_ll(ListNode* &head){
  ListNode* temp = head;
  while(temp){
      cout<<temp->val<<"->";
      temp = temp->next;
  }

}

ListNode* InsertionSortList(ListNode* l1){
    ListNode* p1 = l1,*p2=l1;
    vector<int> ans;
    while(p1!=NULL){
        ans.push_back(p1->val);
        p1 = p1->next;
    }
    int i,j,keyVal;
    for(int i=1;i<ans.size();i++){
        keyVal = ans[i];
        j = i-1;
        while(j>=0 && ans[j]>keyVal){
            ans[j+1] = ans[j];
            j = j-1;
        }
        ans[j+1] =keyVal;
    }
    for(int i=0;i<ans.size();i++){
        p2->val = ans[i];
        p2 = p2->next;
    }
    return l1;
}

int main(){

    ListNode* l1 = NULL;
    insertion_at_Tail(l1,1);
    insertion_at_Tail(l1,2);
    insertion_at_Tail(l1,8);
    insertion_at_Tail(l1,5);
    insertion_at_Tail(l1,7);
    insertion_at_Tail(l1,9);
    ListNode* ptr1 = InsertionSortList(l1);
    print_ll(ptr1);  
    return 0;
}