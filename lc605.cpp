#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        if(flowerbed[0]==0 && flowerbed.size()<=1) return false; 
        for(int i=0;i<flowerbed.size();i++){
            if(i>0 && i<flowerbed.size()-1){
                if(flowerbed[i]==0 && flowerbed[i-1]==0 && flowerbed[i+1]==0){
                    flowerbed[i]=1;
                    ++count;
                }
            }else if(i==0){
                if(flowerbed[i]==0 && flowerbed[i+1]==0){
                    flowerbed[i]=1;
                    ++count;
                }
            }else if(i==flowerbed.size()-1){
                if(flowerbed[i]==0 && flowerbed[i-1]==0){
                    flowerbed[i]=1;
                    ++count;
                }
            }
        }
        return count>=n?true:false;
    }
};

int main(){
    vector<int> nums = {0};
    int n = 1;
    Solution so;
    cout<<so.canPlaceFlowers(nums,n)<<endl;
    for(auto& x:nums)
        cout<<x;
}