#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<int,int> maps;
    int longestPalindrome(string s) {
        int flag = 0,count=0,t;
        for(auto& x:s){
            ++maps[int(x)];
        }
        for(auto& x:maps){
            cout<<x.second<<endl;
            if(x.second%2==0){
                count+=x.second;
            }
            else{
                flag = 1;
                count+=(x.second-1);
            }
        }
        return count+flag;
    }
};

int main(){
    string s = "abccccdd";
    Solution so;
    cout<<so.longestPalindrome(s);
}