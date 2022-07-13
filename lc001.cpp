#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++)
                if(nums[i]+nums[j]==target)
                    return vector<int> {i,j};
        }
        return vector<int> {};
    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    Solution so;
    for(auto& x:so.twoSum(nums,9))
        cout<<x;
}