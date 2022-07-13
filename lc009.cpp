#include<iostream>
#include<vector>

using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        vector<int> nums;
        while(x){
            nums.push_back(x%10);
            x/=10;
        }
        for(int i=0;i<nums.size()/2;i++){
            if(nums[i]!=nums[nums.size()-1-i]) return false;
        }
        return true;
    }
};

int main(){
    int x = 101;
    Solution so;
    cout<<so.isPalindrome(x);
}