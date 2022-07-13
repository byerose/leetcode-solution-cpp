#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> bar(128,0),flag(128,0);
        int l = 0,lmin=0,minsize = s.size()+1,cnt=0;
        for(auto& x:t){
            ++bar[x];
            flag[x]=true;
        }
        for(int r=0;r<s.size();r++){
            if(flag[s[r]]){
                if(--bar[s[r]]>=0) ++cnt;
            }
            while (cnt==t.size()){
                if(flag[s[l]] && ++bar[s[l]]>0) --cnt;
                if(r-l+1<minsize){
                    minsize = r-l+1;
                    lmin = l;
                }
                ++l;
            }
        }
        return minsize>s.size()?"":s.substr(lmin,minsize);          
    }        
};

int main(){
    string s = "ADOBECODEBANC",t = "ABC";
    Solution so;
    cout<<so.minWindow(s,t);
}