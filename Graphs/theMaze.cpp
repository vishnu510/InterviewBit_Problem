#include<bits/stdc++.h>
using namespace std;



bool hashPath(vector<vector<int>> & maze,vector<int>& start,vector<int>& dest){

    int n =  maze.size(), m = maze[0].size();

    vector<vector<bool>> visited(n,vector<bool>(m,false));

    queue<pair<int,int>> q;

    visited[start[0]][start[1]] =1;
    q.push({start[0],start[1]});

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if(x==dest[0] && y==dest[1]) return true;

        int dx[] = {-1,0,1,0};
        int dy[] = {0,1,0,-1};

        for(int i=0;i<4;i++){

            int newX = x;
            int newY = y;

            while (newX >= 0 && newX < n && newY >= 0 && newY < m && maze[newX][newY]==0)
            {
                newX += dx[i];
                newY += dy[i];
            }
            
            newX -= dx[i];
            newY -= dy[i];

            if(visited[newX][newY]==0){
                visited[newX][newY] = 1;
                q.push({newX,newY});
            }
        }
    }
    return false;
}

int main(){

    vector<vector<int>> grid = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> start = {0,4} , destination = {4,4};
    cout<<hashPath(grid,start,destination);
    return 0;
}