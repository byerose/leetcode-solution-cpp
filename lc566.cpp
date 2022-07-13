#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        vector<vector<int>> matrixReshape(vector<vector<int>>& mat,int r,int c){
            if(r*c!=mat.size()*mat[0].size()) return mat;
            vector<vector<int>> res(r,vector<int>(c,0));
            for(int i=0;i<mat.size();i++){
                for(int j=0;j<mat[0].size();j++){
                    res[(i*mat[0].size()+j)/c][(i*mat[0].size()+j)%c] = mat[i][j];
                }
            }
            return res;
        }
};

int main(){
    vector<vector<int>> mat = {{1,2},{3,4}};
    Solution so;
    for(auto& x:so.matrixReshape(mat,2,2)){
        for(auto& y:x){
            cout<<y;
        }
        cout<<endl;
    }
}