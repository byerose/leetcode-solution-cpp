#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int max_val = -1,count = arr.size();
        for(int i=0;i<arr.size();i++){
            max_val= max(max_val,arr[i]);
            if(i!=max_val) --count;
        }
        return count;
    }
};

int main(){
    vector<int> arr = {1,2,0,3};
    Solution so;
    cout<<so.maxChunksToSorted(arr);
}