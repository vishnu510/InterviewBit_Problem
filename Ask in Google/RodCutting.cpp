#include<bits/stdc++.h>
using namespace std;


long long int MinCost(int start, int end, vector<int>& weak_pt, vector<vector<long long int>> &dp, vector<vector<int>> &cutting_pos){
   
    if(abs(start - end) <= 1)
        return 0;
   
    if(dp[start][end] != -1)
        return dp[start][end];
    long long int min_cost = -1;
    
    for(int cut_pos = start+1; cut_pos <= end-1; cut_pos++){
        
        long long int cost_for_cut = weak_pt[end] - weak_pt[start];
        long long int curr_cost = cost_for_cut + MinCost(start, cut_pos, weak_pt, dp, cutting_pos) + MinCost(cut_pos, end, weak_pt, dp, cutting_pos);
        if((curr_cost < min_cost) || (min_cost == -1LL)){
            min_cost = curr_cost;
            //as the most optimal cut for start ... end is unique we can store it
            cutting_pos[start][end] = cut_pos;
        }
    }
    return dp[start][end] = min_cost;
}

//this function fill the order of the cutting for minimising the cost
void Fill_order(int start, int end, vector<int> &order, vector<vector<int>> &cutting_pos, vector<int>& weak_pt){
    if(abs(start - end) <= 1)
        return;
    order.push_back(weak_pt[cutting_pos[start][end]]);
    Fill_order(start, cutting_pos[start][end], order, cutting_pos, weak_pt);
    Fill_order(cutting_pos[start][end], end, order, cutting_pos, weak_pt);
}
vector<int> rodCut(int len, vector<int> &weak_pt) {
    weak_pt.push_back(0);
    weak_pt.push_back(len);
    sort(weak_pt.begin(), weak_pt.end());
    int m = weak_pt.size();
    vector<vector<long long int>> dp(m+1, vector<long long int>(m+1, -1));
    vector<vector<int>> cutting_pos(m+1, vector<int>(m+1));
    
    MinCost(0, m-1, weak_pt, dp, cutting_pos);
   
    vector<int> order;
    Fill_order(0, m-1, order, cutting_pos, weak_pt);

    return order;
}


int main(){

    int len = 6;
    vector<int> weak_pt = {1,2,5};
    vector<int> ans = rodCut(len,weak_pt);

    for(auto x:ans){
        cout<<x<<",";
    }
    return 0;
}