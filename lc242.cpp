#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<char,int> smap,tmap;
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()) return false;
        for(int i=0;i<s.size();i++){
            ++smap[s[i]];
            ++tmap[t[i]];
        }
        for(auto& x:smap){
            if(smap[x.first]!=tmap[x.first]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s = "rat", t = "car";
    Solution so;
    cout<<so.isAnagram(s,t);
}