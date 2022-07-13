#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0,j=0,t;
        while (i<nums.size())
        {
            while (i<nums.size() && nums[i]==0) i++;
            while (j<nums.size() && nums[j]!=0) j++;
            if(i>j && j<nums.size() && i<nums.size()){
                t = nums[i];nums[i]=nums[j];nums[j]=t;
            }
            i++;            
        }
    }
};

int main(){
    vector<int> nums = {1,0,1};
    Solution so;
    so.moveZeroes(nums);
    for(auto& x:nums)
        cout<<x;
}