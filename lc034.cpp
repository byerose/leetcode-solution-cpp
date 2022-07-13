#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchleft(vector<int>& nums, int target) {
        int left=0,right=nums.size(),mid;
        while (left<right){
            mid = left + (right-left)/2;
            if(nums[mid]>=target) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    int searchright(vector<int>& nums, int target) {
        int left=0,right=nums.size(),mid;
        while (left<right){
            mid = left + (right-left)/2;
            if(nums[mid]>target) right = mid;
            else left = mid+1;
        }
        return left-1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return {searchleft(nums,target),searchright(nums,target)};
    }
};

int main(){
    vector<int> nums = {5,7,7,8,8,10};
    Solution so;
    for(auto& x:so.searchRange(nums,8)){
        cout<<x;
    }
}