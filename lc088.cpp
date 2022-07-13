#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for(int i=0;i<n;i++){
            int j=m+i;
            while(j>0&&nums1[j-1]>nums2[i]){
                nums1[j]=nums1[j-1];
                j--;
            }
            nums1[j]=nums2[i];
        }
    }
};

int main(){
    int m=3,n=3;
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};

    Solution so;
    so.merge(nums1,m,nums2,n);
    for(auto& x:nums1)
        cout<<x;
}