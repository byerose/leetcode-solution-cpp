#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>tmp = matrix;
        int h = tmp.size(),w=tmp[0].size();
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                matrix[j][h-i-1] = tmp[i][j]; 
            }
        }
    }
};

int main(){
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution so;
    so.rotate(matrix);
    for(auto& x:matrix){
        for(auto& y:x){
            cout<<y;
        }
        cout<<endl;
    }
}