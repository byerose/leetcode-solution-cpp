#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<unordered_map>

using namespace std;

class Solution1 {
public:
    static bool compare(const pair<char,int>& a,pair<char,int>& b){
        if(a.second > b.second) return true;
        else if(a.second == b.second) return a.first <b.first;
        else return false;
    }
    string frequencySort(string s) {
        map<char,int> map_ini;
        int count;
        for(auto& x:s){
            map_ini[x]+=1;
        }
        vector<pair<char,int>> maps(map_ini.begin(),map_ini.end());
        sort(maps.begin(),maps.end(),compare);
        string out = "";
        for(auto& x:maps){  
            while (x.second--)
                out+=x.first;
        }
        return out;
    }
};

class Solution2{
    public:
        string frequencySort(string s){
            unordered_map<char,int> ch;
            int max_freq = 0,len = s.size();
            for(auto& x:s){
                ++ch[x];
                if(max_freq<ch[x]) max_freq = ch[x]; 
            }
            vector<string> buckets(max_freq+1);
            for(auto &x:ch){
                buckets[x.second]+=x.first;
            }
            string ret="";
            for(int i=max_freq;i>0;i--){
                for(auto &cr:buckets[i]){
                    for(int k=i;k>0;k--)
                        ret+=cr;
                }
            }
            return ret;
        }
};

int main(){
    string s = "xtxree";
    // Solution1 so;
    Solution2 so;
    cout<<so.frequencySort(s);
}