#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()>haystack.size() || needle.size()==0) return 0;
        int j,k;
        for(int i=0;i<=haystack.size()-needle.size();i++){
            j = i;k=0;
            while (haystack[j]==needle[k] && j<haystack.size() && k<needle.size()){
                j++;k++;
            }
            if(k==needle.size()) return i;
        }
        return -1;
    }
};

int main(){
    string txt = "hello",pat = "ll";
    Solution so;
    cout<<so.strStr(txt,pat);
}