#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        vector<int> out(0);
        for(int i=0;i<nums.size();i++){
            res[nums[i]-1]=1;
        }
        for(int i=0;i<res.size();i++){
            if(!res[i]) out.push_back(i+1);
        }
        return out;
    }
};

int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};
    Solution so;
    for(auto& x:so.findDisappearedNumbers(nums)){
        cout<<x;
    }
}