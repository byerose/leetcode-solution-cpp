#include<iostream>
#include<cmath>
using namespace std;

class Solution {
public:
    bool judgeSquareSum(int c) {
        for(int i=0;i<=sqrt(c);i++){
            if(i*i+int(sqrt(c-i*i))*int(sqrt(c-i*i))==c) return true;
        }
        return false;
    }
};

int main(){
    Solution so;
    cout<<so.judgeSquareSum(0);
}