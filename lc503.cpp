#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    stack<int> st;
    vector<int> nextGreaterElements(vector<int>& nums) {
        int len = nums.size();
        vector<int> res(len,-1);
        for(int i=0;i<2*len-1;i++){
            while(!st.empty() && nums[st.top()]<nums[i%len]){
                res[st.top()] = nums[i%len];
                st.pop();
            }
            st.push(i%len);
        }
        return res;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,3};//2,3,4,-1,4
    Solution so;
    for(auto& x:so.nextGreaterElements(nums)){
        cout<<x;
    }
}