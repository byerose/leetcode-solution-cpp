#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int child=0,cookie=0;
        for(;child<g.size()&&cookie<s.size();){
            if(g[child]<=s[cookie]) ++child;
            ++cookie;
        }
        return child;
    }
};

int main(){
    vector<int> g ={1,2,3} ,s={1,1};
    Solution so;
    cout<<so.findContentChildren(g,s);
}