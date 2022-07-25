#include<bits/stdc++.h>
using namespace std;

bool hotel(vector<int> &A, vector<int> &D, int K){

    vector<pair<int,int>> trips;

    for(int i=0;i<A.size();i++){
        trips.push_back({A[i],D[i]});
    }
    sort(trips.begin(),trips.end());
    priority_queue<int,vector<int>,greater<int>> rooms;

    for(int i=0;i<A.size();i++){
        if(rooms.size()<K) rooms.push(trips[i].second);

        else if(trips[i].first > rooms.top()){
            rooms.pop();
            rooms.push(trips[i].second);
        }
        else if(trips[i].first == trips[i].second){
            if(rooms.size() >= K){
                return false;
            }
            else{
                rooms.pop();
                rooms.push(trips[i].second);
            }
        }
        else {
            return false;
        }
    }
    return true;
}

int main(){

    vector<int> arrive = {1,3,5};
    vector<int> departure = {2,6,8};
    cout<<hotel(arrive,departure,1);
    return 0;
}