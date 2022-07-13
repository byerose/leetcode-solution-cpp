#include<iostream>
#include<string>
#include<cmath>

using namespace std;

class Solution {
public:
    bool cmp_str(string s1,string s2){
        if(s1.size()!=s2.size()) return s1.size()>s2.size();
        int i=0,j=0;
        while(i<s1.size()){
            if(s1[i]==s2[j]){
                i++;
                j++;
                continue;
            }
            return s1[i]>s2[i];
        }
        return 0;
    }
    int myAtoi(string s) {
        string res;
        int flag = 1;
        int i = 0;
        while(i<s.size() && s[i]==' '){
            i++;
        }
        if(s[i]=='-'){
            flag = -1;
            i++;
        }else if(s[i]=='+'){
            flag = 1;
            i++;
        }
        while(s[i]=='0') i++;
        int t = i;
        while(i<s.size()&& (s[i]>='0'&&s[i]<='9')){
            res.push_back(s[i]);
            i++;
        }        
        if(t==i){
            res.clear();
            res.push_back('0');
        }
        //cout<<res<<" "<<flag<<endl;
        if(flag<0)
            if(cmp_str(res,"2147483648"))
                return -2147483648;
            else{
                res.insert(0,"-");
                return res;
            }
        if(flag>0) 
            if(cmp_str(res,"2147483647"))
                return 2147483647;
            else{
                return res;
            }
    }
};

int main(){
    string s = "  -0000000000012345678";
    Solution so;
    cout<<so.myAtoi(s);
}