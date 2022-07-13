#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r = nums.size()-1,mid;
        while(l<=r){
            mid = l + (r-l)/2;
            if(nums[mid]==target) return mid;
            else if(nums[mid]>target) r = mid-1;
            else l = mid+1;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    Solution so;
    cout<<so.search(nums,2);
}