#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
using namespace std;

// solution1 位运算，利用亦或的性质——0^a=a,a^a=0,a^b=b^a
class Solution1 {
public:
    int singleNumber(vector<int>& nums) {
        int st=0;
        for(int i=0;i<nums.size();i++){
            st^=nums[i];
        }
        return st;
    }
};

//solution2 集合中存在？删除：插入
class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> sets;
        for(auto& x:nums){
            if(sets.find(x)!=sets.end()) sets.erase(x);
            else sets.insert(x);
        }
        return *sets.begin();
    }
};

//solution3
class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> maps;
        for(auto& x:nums){
            if(maps.find(x)!=maps.end())
                maps[x]++;
            else
                maps.insert(make_pair(x,0));
        }
        for(auto& x:maps)
            if(x.second==0) return x.first;
        return 0; 
    }
};
int main(){
    
    vector<int> nums = {4,1,2,1,2};

    Solution1 so1;
    Solution2 so2;
    Solution3 so3;
    
    cout<<so1.singleNumber(nums)<<endl;
    cout<<so2.singleNumber(nums)<<endl;
    cout<<so3.singleNumber(nums)<<endl;
}