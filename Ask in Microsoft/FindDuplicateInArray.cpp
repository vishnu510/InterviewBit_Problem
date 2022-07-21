#include<bits/stdc++.h>
using namespace std;

// O(nlogn) because sorting there
int repeatedNumber(vector<int> & A){

   sort(A.begin(),A.end());
   int i;
   for(i=0;i<A.size();i++){
      if(A[i]==A[i+1]){
        break;
      }
   }
   return A[i];
}
// using map
int repeatedNum(vector<int> & A){

   unordered_map<int,int> mp;

   for(auto i:A){
    mp[i]++;
   }

   for(auto it:mp){
    if(it.second>1){
        return it.first;
        break;
    }
   }
   return 0;
}

int main(){
     
    vector<int> A = {1,2,3,4,3};
    cout<<repeatedNumber(A)<<"||"<<repeatedNum(A);
    return 0;
}