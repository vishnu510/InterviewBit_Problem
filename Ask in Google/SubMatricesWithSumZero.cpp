#include<bits/stdc++.h>
using namespace std;

int getSumZero(vector<vector<int>>&A){

    int n = A.size(),m= A[0].size();

    for(int i=0;i<n;i++){

        for(int j=1;j<m;j++){

            A[i][j] = A[i][j] + A[i][j-1];
        }
    }

    int count =0,sum;
    unordered_map<int,int> mp;

    for(int cs = 0;cs<m;cs++){

        for(int col = cs;col<m;col++){

            mp.clear();
            mp[0]=1;
            sum =0;
            for(int row = 0;row<n;row++){

                sum+= A[row][col] - (cs>0 ? A[row][cs-1]:0);

                count+=(mp.find(sum)!=mp.end()?mp[sum]:0);
                mp[sum]++;
            }
        }
    }
    return count;
}

int main(){
    
    vector<vector<int>> A ={{-8,5,7},{3,7,-8},{5,-8,9}};
    cout<<getSumZero(A);
    return 0;
}