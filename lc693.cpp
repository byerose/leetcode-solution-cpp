#include<iostream>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int t=-2,c=-1;
        while(n){
            c = t;
            t = n%2;
            if(c==t) return false;
            n/=2;
        }
        return true;
    }
};

int main(){
    Solution so;
    cout<<so.hasAlternatingBits(11);
}