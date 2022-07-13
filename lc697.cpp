#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int,vector<int>> maps;        //[first,last,freq]
    int findShortestSubArray(vector<int>& nums) {  
        vector<int> res;
        for(int i=0;i<nums.size();i++){
            if(maps.count(nums[i])){
                maps[nums[i]][1] = i;
                ++maps[nums[i]][2];
            }else{
                maps[nums[i]]={i,i,1};
            }
        }
        int max_freq=0,left=0,right=nums.size()-1;  
        for(auto& x:maps){
            if(x.second[2]>=max_freq){
                max_freq = x.second[2];
            }
        }
        for(auto& x:maps){
            if(x.second[2]==max_freq && x.second[1]-x.second[0]<right-left){
                cout<<x.first<<x.second[2];
                left = x.second[0];
                right = x.second[1];
            }
        }
        return right-left+1;
    }
};

int main(){
    vector<int> nums = {1,2,2,1,2,1,1,1,1,2,2,2};
    Solution so;
    cout<<so.findShortestSubArray(nums);
}