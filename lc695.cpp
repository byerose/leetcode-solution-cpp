#include<iostream>
#include<vector>
#include<queue>
#include<stack>

using namespace std;

class Solution1 {
public:
    int dfs(vector<vector<int>>& grid,int s_i,int s_j){
        if(s_i<0 || s_j<0 || s_i>=grid.size() || s_j>=grid[0].size() || grid[s_i][s_j]==0) return 0;
        grid[s_i][s_j]=0;
        int res = 1;
        res+=dfs(grid,s_i,s_j+1);
        res+=dfs(grid,s_i,s_j-1);
        res+=dfs(grid,s_i+1,s_j);
        res+=dfs(grid,s_i-1,s_j);
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_count = 0,res;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res = dfs(grid,i,j);
                if(max_count<res) max_count = res;
            }
        }
        return max_count;
    }
};

class Solution2 {
public:
    int bfs(vector<vector<int>>& grid,int s_i,int s_j){
        queue<pair<int,int>> grid_queue;
        int res = 0;
        pair<int,int> p;
        grid_queue.push(make_pair(s_i,s_j));
        while(!grid_queue.empty()){
            p = grid_queue.front();
            grid_queue.pop();
            if(p.first<0 || p.second<0 || p.first>=grid.size() || p.second>= grid[0].size() || grid[p.first][p.second]==0) 
                continue;
            res+=1;
            grid[p.first][p.second] = 0;
            grid_queue.push(make_pair(p.first,p.second+1));
            grid_queue.push(make_pair(p.first,p.second-1));
            grid_queue.push(make_pair(p.first+1,p.second));
            grid_queue.push(make_pair(p.first-1,p.second));   
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_count = 0,res;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res = bfs(grid,i,j);
                if(max_count<res) max_count = res;
            }
        }
        return max_count;
    }
};

class Solution3 {
public:
    int dfs(vector<vector<int>>& grid,int s_i,int s_j){
        stack<pair<int,int>> grid_stack;
        int res = 0;
        pair<int,int> p;
        grid_stack.push(make_pair(s_i,s_j));
        while(!grid_stack.empty()){
            p = grid_stack.top();
            grid_stack.pop();
            if(p.first<0 || p.second<0 || p.first>=grid.size() || p.second>= grid[0].size() || grid[p.first][p.second]==0) 
                continue;        
            grid[p.first][p.second]=0;
            res += 1;
            grid_stack.push(make_pair(p.first,p.second-1));
            grid_stack.push(make_pair(p.first,p.second+1));
            grid_stack.push(make_pair(p.first-1,p.second));
            grid_stack.push(make_pair(p.first+1,p.second));
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_count = 0,res;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                res = dfs(grid,i,j);
                if(max_count<res) max_count = res;
            }
        }
        return max_count;
    }
};

int main(){
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,1,1,0,1,0,0,0,0,0,0,0,0},{0,1,0,0,1,1,0,0,1,0,1,0,0},{0,1,0,0,1,1,0,0,1,1,1,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0},{0,0,0,0,0,0,0,1,1,1,0,0,0},{0,0,0,0,0,0,0,1,1,0,0,0,0}};
    for(auto& x:grid){
        for(auto& y:x){
            cout<<y;
        }
        cout<<endl;
    }
    // Solution2 so;
    Solution3 so;
    cout<<so.maxAreaOfIsland(grid);
}