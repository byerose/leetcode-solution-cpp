#include<iostream>
#include<vector>
#include<stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size());
        stack<int> daystack;
        for(int i=0;i<temperatures.size();i++){
            while(!daystack.empty() && temperatures[i]>temperatures[daystack.top()]){
                ans[daystack.top()] = i-daystack.top();
                daystack.pop();
            }
            daystack.push(i);
        }
        return ans;
    }
};

int main(){
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    Solution so;
    for(auto& x:so.dailyTemperatures(temperatures)){
        cout<<x;
    }
}