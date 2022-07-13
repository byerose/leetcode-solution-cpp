#include<iostream>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        int l=1,r=x,mid;
        while (l<=r){
            mid = l+(r-l)/2;//mid=(l+r)/2可能会溢出，所以使用l+(r-l)/2
            if(x/mid == mid) return mid;
            else if(x/mid>mid) l = mid+1;
            else r = mid-1;
        }
        return r;
    }
};

int main(){
    int x = 8;
    Solution so;
    cout<<so.mySqrt(x);
}