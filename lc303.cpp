#include<iostream>
#include<vector>

using namespace std;

class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        sums.resize(nums.size()+1);
        for(int i=0;i<nums.size();i++){
            sums[i+1] = nums[i]+sums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right+1]-sums[left];
    }
};

int main(){
    vector<int> nums = {-2, 0, 3, -5, 2, -1};
    NumArray* obj = new NumArray(nums);
    cout<<obj->sumRange(0,2);
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */