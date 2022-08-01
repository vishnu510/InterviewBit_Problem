#include <iostream>
#include<vector>
#include<queue>
using namespace std;
int main() {
     vector<vector<int>> maze = {{0,0,1,0,0},{0,0,0,0,0},{0,0,0,1,0},{1,1,0,1,1},{0,0,0,0,0}};
    vector<int> start = {0,4};
    vector<int> destination = {4,4};
     cout<<"he";
    int m = maze.size();
    int n = maze[0].size();
        
    vector<vector<int>> visited(m,vector<int> (n,0));
    queue<pair<int,int>> q;
    q.push({start[0],start[1]});
    while(!q.empty()){
        auto temp = q.front();
        q.pop();
        int dx[] = {-1,0,1,0};
        int dy[] = {0,-1,1,0};
        int count =0;
        for(int k = 0;k<4;k++){
            int newX = temp.first;
            int newY = temp.second;

            if(newX == destination[0] and newY== destination[1]){
                cout<<count<<endl;
                break;
            }

            while(newX>=0 and newX<m and newY>=0 and newY<n and maze[newX][newY] == 1){
                newX += dx[k];
                newY +=dy[k];
                count++;
            }
            newX -=dx[k];
            newY -=dy[k];
            if(!visited[newX][newY]){
                visited[newX][newY] = 1;
                q.push({newX,newY});
            }
        }
        cout<<"-1";
    }
}