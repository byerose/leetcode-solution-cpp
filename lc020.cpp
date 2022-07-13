#include<iostream>
#include<string>
#include<stack>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stacks;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stacks.push(s[i]);
            }else if(s[i]==')' && stacks.size() && stacks.top()=='('){
                stacks.pop();
            }else if(s[i]=='}' && stacks.size() && stacks.top()=='{'){
                stacks.pop();
            }else if(s[i]==']' && stacks.size() && stacks.top()=='['){
                stacks.pop();
            }else
                return false;
        }
        return !stacks.size();
    }
};


int main(){
    string s = "]";
    Solution so;
    cout<<so.isValid(s);
}