#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string res; 
    string addStrings(string num1, string num2) {    
        int i=num1.size()-1,j=num2.size()-1,c=0,t,r;
        while(i>=0&&j>=0){
            t = num1[i]+num2[j]-'0'-'0'+c;
            c = t/10;
            r = t%10;
            res.append(to_string(r));
            --i,--j;
        }
        while(i>=0){
            t = num1[i]-'0'+c;
            c = t/10;
            r = t%10;
            res.append(to_string(r));
            --i,--j;
        }
        while(j>=0){
            t = num2[j]-'0'+c;
            c = t/10;
            r = t%10;
            res.append(to_string(r));
            --i,--j;
        }
        if(c) res.append(to_string(c));
        for(int i=0,j=res.size()-1;i<j;i++,j--) swap(res[i],res[j]);
        return res;
    }
};

int main(){
    string str1="0",str2="0";
    Solution so;
    cout<<so.addStrings(str1,str2);
}