#include<bits/stdc++.h>
using namespace std;

bool isSafe(int i,int j, int m,int n){
        
        return (i>=0 && i<m && j>=0 && j<n);
    }
    
bool isBorder(int i,int j,int m,int n){
        
        return (i==0 || i==m-1 || j==0 || j==n-1);
}
    
void solve(vector<vector<char>>& A) {
        
        if(A.size()==0){
            return;
        }
        queue<pair<int,int>> q;
        vector<pair<int, int>> dir = {{1,0}, {-1,0}, {0, 1}, {0, -1}};
        int m = A.size(),n = A[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]=='O' && isBorder(i,j,m,n)){
                    A[i][j] = '.';
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            pair<int,int> f = q.front();
            q.pop();
            for(int i=0;i<dir.size();i++){
                int dx = f.first + dir[i].first;
                int dy = f.second + dir[i].second;
                if(isSafe(dx,dy,m,n) && !isBorder(dx,dy,m,n) && A[dx][dy]=='O'){
                    A[dx][dy] = '.';
                    q.push({dx,dy});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(A[i][j]=='O'){
                    A[i][j] = 'X';
                }
                else if(A[i][j]=='.'){
                    A[i][j] = 'O';
                }
            }
        }
    }

int main(){
   
   vector<vector<char>> A = {{'X','X','X','X'},
                                 {'X','O','O','X'},
                                 {'X','X','O','X'},
                                 {'X','O','X','X'}};

    solve(A);                             
    for(int i=0;i<A.size();i++){
        for(int j=0;j<A[0].size();j++){
            cout<<A[i][j]<<" ";
        }
        cout<<endl;
    }

}