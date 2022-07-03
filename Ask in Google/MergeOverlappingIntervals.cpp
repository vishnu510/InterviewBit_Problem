#include<bits/stdc++.h>
using namespace std;

struct Interval {
      int start;
      int end;
      Interval() : start(0), end(0) {}
      Interval(int s, int e) : start(s), end(e) {}
 };
bool fun(Interval a1,Interval a2){
    return a1.start<a2.start;
}
vector<Interval> mergeOveralpInterval(vector<Interval>&A){
    if(A.size()<=1){
        return A;
    }
    sort(A.begin(),A.end(),fun);
    for(int i=0;i<A.size();i++){
        int j = i+1;
        int endVal = A[i].end;
        while(j<A.size() && A[j].start<=endVal){
            endVal = max(endVal,A[j].end);
            A.erase(A.begin()+j);
        }
        A[i].end = max(endVal,A[i].end);
    }
    return A;
}

int main(){

    vector<Interval> internals = {{1,3},{2,6},{8,10},{15,18}};
    mergeOveralpInterval(internals);
    for(int i=0;i<internals.size();i++){
        cout<<"[";
        cout<<internals[i].start<<" "<<internals[i].end;
        cout<<"]";
    }  
    return 0;
}