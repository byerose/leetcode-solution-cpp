#include<iostream>
#include<string>
#include<unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<char> sets;
    int lengthOfLongestSubstring(string s) {
        int right = 0,max_len = 0;
        for(int left = 0;left<s.size();left++){
            while(right<s.size() && !sets.count(s[right])){
                sets.insert(s[right]);
                ++right;
            }
            sets.erase(s[left]);
            max_len = max(right-left,max_len);
        }
        return max_len;
    }
};

int main(){
    string s = "pwwkew";
    Solution so;
    cout<<so.lengthOfLongestSubstring(s);
}