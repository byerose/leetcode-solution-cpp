#include<iostream>
#include<vector>

using namespace std;

class NumArray {
public:
    vector<int> sums;
    NumArray(vector<int>& nums) {
        sums.resize(nums.size()+1);
        for(int i=0;i<nums.size();i++){
            sums[i+1] = sums[i]+nums[i];
        }
    }
    
    void update(int index, int val) {
        int d = val -(sums[index+1]-sums[index]);
        for(int i=index+1;i<sums.size();i++){
            sums[i] += d;
        }
    }
    
    int sumRange(int left, int right) {
        return sums[right+1]-sums[left];
    }
};

int main(){
    vector<int> nums = {1, 3, 5};
    NumArray* obj = new NumArray(nums);
    cout<<obj->sumRange(0,2);
    obj->update(1,2);
    cout<<obj->sumRange(0,2);
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */