#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        while(columnNumber){
            res.insert(res.size(),1,char('A'+(columnNumber-1)%26));
            columnNumber=(columnNumber-1)/26;
        }
        for(int i=0,j=res.size()-1;i<j;i++,j--) swap(res[i],res[j]);
        return res;
    }
};

int main(){
    Solution so;
    cout<<so.convertToTitle(2147483647)<<endl;
}