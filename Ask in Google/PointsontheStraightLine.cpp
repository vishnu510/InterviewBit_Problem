#include<bits/stdc++.h>
using namespace std;

int maxPoints(vector<vector<int>>& points) {
    int n = points.size();
    if(n<=2) return n;   
    int result  = 0;
    for(int i=0;i<n;i++){
        unordered_map<double,int> mp;
        int duplicate =0;
        double slope = 0.0;
        for(int j=0;j<n;j++){
            int x1 = points[i][0];
            int x2 = points[j][0];
            int y1 = points[i][1];
            int y2 = points[j][1];
            
            int dx = x2-x1;
            int dy = y1-y2;
            if(dy==0 && dx==0){
                duplicate++;
                continue;
            }
            if(dx!=0){
                slope = dy*1.0/dx;
            }
            else{
                slope  = INT_MAX;
            }
            mp[slope]++;
        }
        if(mp.size()==0){
            result = duplicate;
        }
        else{
            for(auto slope:mp){
                result = max(result,slope.second+duplicate);
            }
        }
    }
    return result;
}

int main(){
    
    vector<vector<int>> points = {{1,1},{2,2},{3,3}};
    cout<<maxPoints(points);
    return 0;
}