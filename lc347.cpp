#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

class Solution {
public:
    static bool compare(const pair<int,int>& a,pair<int,int>& b){
        if(a.second > b.second) return true;
        else if(a.second == b.second) return a.first > b.first;
        else return false;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> map_ini;
        for(auto& x:nums){
            if(map_ini.find(x)!=map_ini.end()) map_ini[x]+=1;
            else map_ini.insert(make_pair(x,1));
        }
        vector<pair<int,int>> maps(map_ini.begin(),map_ini.end());
        vector<int> out;
        sort(maps.begin(),maps.end(),compare);
        for(int i=0;i<k;i++) out.push_back(maps[i].first);
        return out;
    }
};

int main(){
    vector<int> nums = {1,1,1,2,2,3};
    Solution so;
    for(auto& x:so.topKFrequent(nums,2)) cout<<x;
}