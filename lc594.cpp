#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int,int> maps;
    int findLHS(vector<int>& nums) {
        for(auto& x:nums){
            ++maps[x];
        }
        int max_len = 0;
        for(auto& x:maps){
            if(maps.count(x.first+1))
                max_len = max(maps[x.first]+maps[x.first+1],max_len);
        }
        return max_len;
    }
};

int main(){
    vector<int> nums = {1,3,5,7,9,11,13,15,17};
    Solution so;
    cout<<so.findLHS(nums);
}