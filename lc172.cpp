#include<iostream>

using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0) return 0;
        int c2=0,c5=0,t;
        for(int i=1;i<=n;i++){
            t = i;
            while(t%2==0){
                c2+=1;
                t/=2;
            }
            while(t%5==0){
                c5+=1;
                t/=5;
            }
        }
        return min(c2,c5);
    }
};

int main(){
    int n = 10;
    Solution so;
    cout<<so.trailingZeroes(n);
}