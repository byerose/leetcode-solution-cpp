#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        char t;
        for(int i = 0;i<=(s.size()-1)/2;i++){
            swap(s[i],s[s.size()-1-i]);
        }
    }
};

int main(){
    vector<char> str = {'a','c','d','e','f'};
    Solution so;
    so.reverseString(str);
    for(auto& x:str)
        cout<<x;
}