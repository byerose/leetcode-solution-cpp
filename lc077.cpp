#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> nums;
    void traceback(int i,int n,int k){
        if(nums.size()>=k){
            res.push_back(nums);
            return;
        }
        for(int l=i;l<=n;l++){
            nums.push_back(l);
            traceback(l+1,n,k);
            nums.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        traceback(1,n,k);
        return res;
    }
};

int main(){
    int n=4,k=2;
    Solution so;
    for(auto& x:so.combine(n,k)){
        for(auto& y:x){
            cout<<y;
        }
        cout<<endl;
    }
}