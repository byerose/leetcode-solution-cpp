#include<iostream>
#include<vector>
#include<set>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        multiset<int> sets;
        for(auto& x:nums) sets.insert(x);
        int max_sum=nums[0];
        while(!sets.empty()){
            int cur1 = *(sets.begin()),cur2=cur1,max_tmp=cur1;
            sets.erase(cur1);
            while(sets.find(--cur1)!=sets.end()){
                max_tmp+=cur1;
                sets.erase(cur1);
            }
            while(sets.find(++cur2)!=sets.end()){
                max_tmp+=cur2;
                sets.erase(cur2);
            }
            max_sum = max(max_sum,max_tmp);
        }
        return max_sum;
        return 0;
    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    Solution so;
    cout<<so.maxSubArray(nums);
}