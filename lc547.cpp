#include<iostream>
#include<vector>
#include<queue>

using namespace std;

class Solution1 {
public:
    void dfs(vector<vector<int>>& isConnected,vector<int>& visited,int i){
        for(int k=0;k<visited.size();k++){
            if(isConnected[i][k]==1 && visited[k]==0){
                visited[k] = 1;
                dfs(isConnected,visited,k);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> visited(isConnected[0].size());
        int count = 0;
        for(int i=0;i<visited.size();i++){
            if(!visited[i]){
                visited[i] = 1;
                dfs(isConnected,visited,i);
                ++count;
            }
        }
        return count;
    }
};

class Solution2 {
public:
    int find(vector<int>& dsu,int k){
        if(dsu[k]==k) return k;
        else return find(dsu,dsu[k]);
    }

    void merge(vector<int>& dsu,int i,int j){
        dsu[find(dsu,i)] = find(dsu,j);
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<int> dsu(isConnected[0].size());
        for(int i=0;i<dsu.size();i++) dsu[i] = i;
        for(int i=0;i<isConnected.size();i++){
            for(int j=i+1;j<isConnected[0].size();j++){
                if(isConnected[i][j]==1){
                    merge(dsu,i,j);
                }
            }
        }
        int count = 0;
        for(int i=0;i<dsu.size();i++){
            if(dsu[i]==i) ++count;
        }
        return count;
    }
};

int main(){
    vector<vector<int>> isConnected = {{1,0,0},{0,1,0},{0,0,1}};
    for(auto& x:isConnected){
        for(auto& y:x){
            cout<<y;
        }
        cout<<endl;
    }
    // Solution1 so;
    Solution2 so;
    cout<<so.findCircleNum(isConnected);
}