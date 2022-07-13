#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i=0,j=numbers.size()-1;
        while (i<j)
        {
            if(numbers[i]+numbers[j]==target) break;
            else if(numbers[i]+numbers[j]<target) ++i;
            else --j;
        }
        return vector<int> {i+1,j+1};
    }
};

int main(){
    vector<int> nums = {2,3,4};
    Solution so;
    for(auto& x:so.twoSum(nums,6)){
        cout<<x;
    }
}