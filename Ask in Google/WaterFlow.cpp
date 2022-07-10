#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};


void dfs(vector<vector<int>>&grid,vector<vector<bool>>&sea,int i,int j,int m,int n){
     if(i<0 ||j<0 || i>=m ||j>=n){
        return;
     }

     for(int k=0;i<dir.size();i++){
        int x  = dir[k][0] + i;
        int y = dir[k][1] + j;
        if(x>=0 && y>=0 && x<m && y<n && sea[x][y]==false){
            if(grid[x][y]>=grid[i][j]){
                sea[x][y] = true;
                dfs(grid,sea,x,y,m,n);
            }
        }
     }
     return;
}

int solution(vector<vector<int>> & grid){
    int m=grid.size();
    int n=grid[0].size();
   
    vector<vector<bool>> blue(m , vector<bool>(n , false));
    vector<vector<bool>> red(m , vector<bool>(n , false));
   
    for(int i=0;i<m;i++)
    {
        blue[i][0]=true;
        red[i][n-1]=true;
    }
   
    for(int i=0;i<n;i++)
    {
        blue[0][i]=true;
        red[m-1][i]=true;
    }
    for(int i=0;i<m;i++)
    {
        dfs(grid , blue , i , 0 , m ,n);
    }
   
    for(int i=0;i<n;i++)
    {
        dfs(grid , blue , 0 , i , m , n);
    }
   
     for(int i=0;i<m;i++)
    {
        dfs(grid , red , i , n-1 , m ,n);
    }
   
    for(int i=0;i<n;i++)
    {
        dfs(grid , red , m-1 , i , m , n);
    }
   
    int ans=0;
   
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(red[i][j]==true && blue[i][j]==true)
            {
                ans++;
            }
        }
    }
   
    return ans;
}

int main(){
    vector<vector<int>> A = {{1, 2, 2, 3, 5},
                             {3, 2, 3, 4, 4},
                             {2, 4, 5, 3, 1},
                             {6, 7, 1, 4, 5},
                             {5, 1, 1, 2, 4},
                            };
    cout<<solution(A);
    return 0;
}