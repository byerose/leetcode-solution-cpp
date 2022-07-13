#include<iostream>

using namespace std;

class Solution1 {
public:
    bool isPowerOfFour(int n) {
        if(n==0) return false;
        if(n==1) return true;
        int t = n,r = 4;
        while(n!=1){
            if(n%r!=0){
                if(r==4) return false;
                if(r>4){
                    r/=4;
                }
            }
            else{
                n/=r;
                r*=4;
            }
        }
        return true;
    }
};

class Solution2{
    public:
        bool isPowerOfFour(int n){
            return n>0 && (n&(n-1))==0 && (n&0xaaaaaaaa)==0;
        }
};

int main(){
    Solution2 so;
    cout<<so.isPowerOfFour(4);
}