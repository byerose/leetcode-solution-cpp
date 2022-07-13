#include<iostream>
#include<unordered_map>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution1 {
public:
    bool containsDuplicate(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> maps;
        for(int i=0;i<nums.size();i++){
            ++maps[nums[i]];
        }
        for(auto& x:maps){
            if(x.second>1) return true;
        }
        return false;
    }
};
class Solution2 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> sets;
        for(auto& x:nums){
            if(sets.find(x)!=sets.end()){
                return true;    
            }
            sets.insert(x);
        }
        return false;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    Solution2 so;
    cout<<so.containsDuplicate(nums);
}