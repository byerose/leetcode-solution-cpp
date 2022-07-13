#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;

//排序
class Solution1 {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};

//哈希
class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> maps;
        for(auto& x:nums){
            if(maps.find(x)!=maps.end())
                maps[x]++;
            else
                maps.insert(make_pair(x,1));
        }
        for(auto& x:maps){
            if(x.second>nums.size()/2) return x.first;
        }
        return 0;
    }
};

int main(){

    vector<int> nums = {2,2,1,1,1,2,2};
    
    Solution1 so1;
    Solution1 so2;
    
    cout<<so1.majorityElement(nums);
    cout<<so2.majorityElement(nums);

}