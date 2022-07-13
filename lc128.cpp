#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

class Solution {
public:
    unordered_set<int> sets;
    int longestConsecutive(vector<int>& nums) {
        int max_len=0;
        for(auto& x:nums){
            sets.insert(x);
        }
        while(!sets.empty()){
            int cur1 = *(sets.begin()),cur2=cur1;
            sets.erase(cur1);
            while(sets.find(--cur1)!=sets.end()){
                sets.erase(cur1);
            }
            while(sets.find(++cur2)!=sets.end()){
                sets.erase(cur2);
            }
            max_len = max(max_len,cur2-cur1-1);   
        }
        return max_len;
    }
};

int main(){
    vector<int> nums = {100,4,200,1,3,2};
    Solution so;
    cout<<so.longestConsecutive(nums);
}