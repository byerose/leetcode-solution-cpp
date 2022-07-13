#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        unordered_set<int> sets;
        for(auto& x:nums) sets.insert(x);
        for(int i=0;i<=nums.size();i++){
            if(sets.find(i)==sets.end()) return i;
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {3,0,1};
    Solution so;
    cout<<so.missingNumber(nums);
}