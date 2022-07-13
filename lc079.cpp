#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    bool traceback(vector<vector<char>>& board, vector<vector<int>>& visited,string word, int s_i, int s_j, int k){
        if(s_i<0 || s_j<0 || s_i>=board.size() || s_j>=board[0].size()){
            return false;
        }
        visited[s_i][s_j]=1;
        bool res1=0,res2=0,res3=0,res4=0;
        if(board[s_i][s_j]==word[k]){
            k+=1;
            if(k == word.size()) return true;
            if(s_i>0 && visited[s_i-1][s_j]==0)
                res1 = traceback(board,visited,word,s_i-1,s_j,k);
            if(s_j>0 && visited[s_i][s_j-1]==0)
                res2 = traceback(board,visited,word,s_i,s_j-1,k);
            if(s_i<board.size()-1 && visited[s_i+1][s_j]==0)
                res3 = traceback(board,visited,word,s_i+1,s_j,k);
            if(s_j<board[0].size()-1 && visited[s_i][s_j+1]==0)
                res4 = traceback(board,visited,word,s_i,s_j+1,k);
        }
        visited[s_i][s_j]=0;
        return res1 || res2 || res3 || res4;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(traceback(board,visited,word,i,j,0)) return true;
            }
        }
        return false;
    }
};

int main(){
    vector<vector<char>> board =   {{'A','B','C','E'},
                                    {'S','F','C','S'},
                                    {'A','D','E','E'}};
    // vector<vector<char>> board = {{'a'}};
    string word = "ABCD";
    Solution so;
    cout<<so.exist(board,word);
}