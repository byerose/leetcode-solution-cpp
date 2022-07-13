#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
    int quick_select(vector<int>& nums,int left, int right, int k){
        int l = left,r = right,key = nums[l],count;
        while(l<r){
            while(l<r && nums[r]>=key) --r;
            nums[l] = nums[r];
            while(l<r && nums[l]<=key) ++l;
            nums[r] = nums[l];
        }
        nums[l] = key;
        count = l-left+1;
        if(count==k) return nums[l];
        else if(count>k) return quick_select(nums,left,l-1,k);
        else return quick_select(nums,l+1,right, k - count);
    }
};

int main(){
    vector<int> nums  = {3,2,1,5,6,4};
    Solution so;
    cout<<so.quick_select(nums,0,nums.size()-1,2);
}