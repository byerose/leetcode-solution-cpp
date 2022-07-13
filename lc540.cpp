#include<iostream>
#include<vector>

using namespace std;

class Solution {
//独立数总是出现在下标为偶数的位置
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l=0,r=nums.size()-1,mid;
        if(nums.size()==1) return nums[0];
        if(nums[0]!=nums[1]) return nums[0];
        if(nums[nums.size()-1]!=nums[nums.size()-2]) return nums[nums.size()-1];
        while (l<=r) {
            mid = l+(r-l)/2;
            mid = mid/2*2;
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1])
                return nums[mid];
            else if(nums[mid]!=nums[mid+1])
                r = mid-2;
            else 
                l = mid+2;
        }
        return -1;
    }
};

int main(){
    vector<int> nums={1,2,2,3,3};
    Solution so;
    cout<<so.singleNonDuplicate(nums);
}