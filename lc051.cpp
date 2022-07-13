#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    bool check(vector<int>& nums,int n){
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++) //i!=j
                if(i-j==nums[i]-nums[j] || j-i==nums[i]-nums[j]) return false;
        return true;
    }
    void traceback(vector<int>& nums,int n,int k){
        if(k>=n){       
            if(check(nums,n)) res.push_back(nums);
            return;
        }
        for(int i=k;i<n;i++){
            swap(nums[i],nums[k]);
            traceback(nums,n,k+1);
            swap(nums[i],nums[k]);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<int> nums(n);
        for(int i=0;i<nums.size();i++) nums[i]=i;
        traceback(nums,n,0);
        vector<vector<string>> out(res.size(),vector<string>(n,string(n,'.')));
        for(int i=0;i<res.size();i++)
            for(int j=0;j<res[0].size();j++) out[i][j][res[i][j]]='Q';
        return out;
    }
};

int main(){
    int n=4;
    Solution so;
    for(auto& x:so.solveNQueens(n)){
        for(auto& y:x){
            cout<<y;
            cout<<endl;
        }
        cout<<endl;
    }
}