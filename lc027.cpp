#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i=0,j=0;
        while (i<nums.size()){
            if(nums[i]==val){
                ++i;
            }else{
                nums[j] = nums[i];
                j++,i++;
            }
        }
        return j;
    }
};

int main(){
    vector<int> nums = {3,2,2,3};
    Solution so;
    cout<<so.removeElement(nums,3);
}