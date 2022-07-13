#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> Pa,At,res;
    void dfs(vector<vector<int>>& heights,vector<vector<int>>& visited,int s_i,int s_j){
        if(visited[s_i][s_j]) return;
        
        visited[s_i][s_j] = 1;
        
        if(Pa[s_i][s_j]&&At[s_i][s_j]) res.push_back({s_i,s_j});

        if(s_i>0 && heights[s_i][s_j]<=heights[s_i-1][s_j]) dfs(heights,visited,s_i-1,s_j);
        if(s_j>0 && heights[s_i][s_j]<=heights[s_i][s_j-1]) dfs(heights,visited,s_i,s_j-1);
        if(s_i<heights.size()-1 && heights[s_i][s_j]<=heights[s_i+1][s_j]) dfs(heights,visited,s_i+1,s_j);
        if(s_j<heights[0].size()-1 && heights[s_i][s_j]<=heights[s_i][s_j+1]) dfs(heights,visited,s_i,s_j+1);
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        Pa=At=vector<vector<int>>(heights.size(),vector<int>(heights[0].size(),0));
        for(int i=0;i<heights.size();i++){ 
            dfs(heights,Pa,i,0);
            dfs(heights,At,i,heights[0].size()-1);
        }
        for(int j=0;j<heights[0].size();j++){
            dfs(heights,Pa,0,j);
            dfs(heights,At,heights.size()-1,j);
        }
        return res;
    }
};

int main(){
    vector<vector<int>> heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};
    Solution so;
    vector<vector<int>> res; 
    res = so.pacificAtlantic(heights);
    for(int i=0;i<res.size();i++){
        for(int j=0;j<res[0].size();j++){
            cout<<res[i][j];
        }
    }
}