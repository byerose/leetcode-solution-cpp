#include<iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==0) return false;
        if(n==1) return true;
        int t = n,r = 3;
        while(n!=1){
            if(n%r!=0){
                if(r==3) return false;
                if(r>3){
                    r/=3;
                }
            }
            else{
                n/=r;
                r*=3;
            }
        }
        return true;
    }
};

int main(){
    int n = 18;
    Solution so;
    cout<<so.isPowerOfThree(n);
}