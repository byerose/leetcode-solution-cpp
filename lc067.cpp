#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int i=a.size()-1,j=b.size()-1,c=0,r,t;
        while(i>=0 && j>=0){
            t = a[i]+b[j]-'0'-'0' + c;
            r = t%2;
            c = t/2;
            res.append(to_string(r));
            --i,--j;
        }
        while(i>=0){
            t = a[i]-'0' + c;
            r = t%2;
            c = t/2;
            res.append(to_string(r));            
            --i,--j;
        }
        while(j>=0){
            t = b[j]-'0' + c;
            r = t%2;
            c = t/2;
            res.append(to_string(r));
            --i,--j;
        }
        if(c) res.append(to_string(c));
        for(int i=0,j=res.size()-1;i<j;i++,j--) swap(res[i],res[j]);
        return res;
    }
};

int main(){
    string a = "0", b = "0";
    Solution so;
    cout<<so.addBinary(a,b);
}