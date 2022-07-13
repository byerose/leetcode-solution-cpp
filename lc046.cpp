#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    void traceback(vector<int>& nums,int k){
        if(k>=nums.size()){ 
            res.push_back(nums);
            return;
        }
        for(int i=k;i<nums.size();i++){
            swap(nums[i],nums[k]);
            traceback(nums,k+1);
            swap(nums[i],nums[k]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        traceback(nums,0);
        return res;
    }
};


int main(){
    vector<int> nums = {1,2,3};
    Solution so;
    for(auto& x:so.permute(nums)){
        for(auto& y:x){
            cout<<y;
        }
        cout<<endl;
    }
}