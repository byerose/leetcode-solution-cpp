#include<iostream>
#include<vector>

using namespace std;

class Solution{
    public:
        void quick_sort(vector<int>& nums,int left,int right){
            if(left>=right) return;
            int l = left, r = right, key = nums[l];
            while(l<r){
                while(l<r && nums[r]>=key) --r;
                nums[l] = nums[r];
                while(l<r && nums[l]<=key) ++l;
                nums[r]=nums[l];
            } 
            nums[l]=key;
            quick_sort(nums,left,l);
            quick_sort(nums,l+1,right);
        }

        void bubble_sort(vector<int>& nums){
            bool swapped;
            for(int i=nums.size()-1;i>0;i--){
                swapped = false;
                for(int j = 0;j<i;j++){
                    if(nums[j]>nums[j+1]){
                        swap(nums[j],nums[j+1]);
                        swapped = true;
                    }
                }
                if(!swapped) break;
            }
        }

        void insert_sort(vector<int>& nums){
            for(int i=0;i<nums.size();i++){
                for(int j=i;j>0 && nums[j]<nums[j-1];j--){
                    swap(nums[j],nums[j-1]);
                }
            }
        }

        void select_sort(vector<int>& nums){
            int idx;
            for(int i=0;i<nums.size();i++){
                idx = i;
                for(int j=i;j<nums.size();j++){
                    if(nums[j]<nums[idx]){
                        idx = j;
                    }
                }
                swap(nums[idx],nums[i]);
            }
        }

        void merge_sort(vector<int>& nums,int l,int r,vector<int> &tmp){
            if(l+1<r) return;
            int mid = l+(r-l)/2;
            merge_sort(nums,l,mid,tmp);
            merge_sort(nums,mid,r,tmp);
            int p=l,q=mid,i=l;
            while (p<mid || q<r){
                if(q>=r || (p<mid && nums[p] <= nums[q])){
                    tmp[i++] = nums[p++];
                }else{
                    tmp[i++] = nums[q++];
                }
            }
            for(i=l;i<r;++i){
                nums[i]=tmp[i];
            }
        }
};

int main(){
    vector<int> nums = {5, 9, 1, 1, 9, 5, 3, 7, 6, 1};
    Solution so;
    // so.quick_sort(nums,0,nums.size()-1);
    // so.bubble_sort(nums);
    // so.insert_sort(nums);
    // so.select_sort(nums);
    // so.merge_sort(nums,0,nums.size(),tmp);
    for(auto& x:nums){
        cout<<x;
    }
}