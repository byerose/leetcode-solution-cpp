#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0],max_diff = 0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]-min_val>max_diff) max_diff = prices[i]-min_val;
            if(prices[i] < min_val) min_val = prices[i];
        }
        return max_diff;
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution so;
    cout<<so.maxProfit(prices);
}