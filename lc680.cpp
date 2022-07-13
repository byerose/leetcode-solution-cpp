#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool is_huiwen(string s,int i,int j){
        while (i<j&&s[i]==s[j])
            ++i,--j;
        return i>=j;
    }
    bool validPalindrome(string s) {
        int i=0,j=s.size()-1;
        while (i<j&&s[i]==s[j])
            ++i,--j;
        return is_huiwen(s,i+1,j) || is_huiwen(s,i,j-1);
    }
};

int main(){
    string s =  "abcacaba";
    Solution so;
    cout<<so.validPalindrome(s)<<endl;
}