#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string ten2two(int n){
        string res="";
        if(n==0) res.append(to_string(n));
        while(n){
            res.append(to_string(!(n%2)));
            n/=2;
        }
        return res;
    }
    int two2ten(string s){
        int c=1,res=0;
        for(int i=0;i<s.size();i++){
            res+=((s[i]-'0')*c);
            c*=2;
        }
        return res;
    }
    int findComplement(int num) {
        return two2ten(ten2two(num));
    }
};

int main(){
    Solution so;
    cout<<so.findComplement(1);
}