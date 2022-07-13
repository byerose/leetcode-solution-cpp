#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int,int> maps;
    int subarraySum(vector<int>& nums, int k) {
        int sums = 0,count=0;
        maps[0] = 1; // 为什么初始化呢？
        for(auto& x:nums){
            sums+=x;
            count+=maps[sums-k];
            ++maps[sums];
        }
        return count;
    }
};

int main(){
    vector<int> nums = {1,1,1};
    Solution so;
    cout<<so.subarraySum(nums,2);
}