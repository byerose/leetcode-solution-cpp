#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string res;
    string convertToBase7(int num) {
        int r,n=num;
        do{
            r = num%7;
            if(r<0) r *=-1;
            res.append(to_string(r));
            num/=7;
        }while(num);
        if(n<0) res.append("-");
        for(int i=0,j=res.size()-1;i<j;i++,j--){
            swap(res[i],res[j]);
        }
        
        return res;
    }
};

int main(){
    int num = -8;
    Solution so;
    cout<<so.convertToBase7(num);
}