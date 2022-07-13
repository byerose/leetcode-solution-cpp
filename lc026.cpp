#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0,j=1;
        if(nums.size()>1){
            while (j<nums.size()){   
                if(nums[j]!=nums[i])
                    nums[++i] = nums[j];
                j++;
            }
            return i+1;
        }else
            return nums.size();
    }
};

int main(){
    vector<int> nums = {0,1,2};
    Solution so;
    cout<<so.removeDuplicates(nums);
}