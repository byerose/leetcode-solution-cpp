#include<iostream>

using namespace std;

class Solution {
public:
    int hammingDistance(int x, int y) {
        int c=0;
        while(x || y){
            if(x%2!=y%2) ++c;
            x/=2;
            y/=2;
        }
        return c;
    }
};

int main(){
    int x=1,y=4;
    Solution so;
    cout<<so.hammingDistance(x,y);
}