#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string adds(string num1,string num2){
        int c=0,s;
        string res="";
        int i=num1.size()-1,j=num2.size()-1;
        while(i>=0&&j>=0){
            s = num1[i]-'0'+num2[j]-'0'+c;
            res.insert(0,to_string(s%10));
            
            c=s/10;
            i--,j--;
        }
        while(i>=0){
            s = num1[i]-'0'+c;
            res.insert(0,to_string(s%10));
            
            c=s/10;
            i--;
        }
        while(j>=0){
            s = num2[j]-'0'+c;
            res.insert(0,to_string(s%10));
            
            c=s/10;
            j--;
        }
        if(c) res.insert(0,to_string(c));
        return res;
    }
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0") return "0";
        int c,s;
        string t,res="0";
        for(int i=num1.size()-1;i>=0;i--){
            t.clear();
            for(int k=num1.size()-1-i;k>0;k--) t.insert(0,"0");
            c = 0,s = 0;
            for(int j=num2.size()-1;j>=0;j--){
                s = c+(num1[i]-'0')*(num2[j]-'0');
                t.insert(0,to_string(s%10));
                c = s/10;
            }
            if(c) t.insert(0,to_string(c));
            res = adds(res,t);
        }
        return res;
    }
};

int main(){
    string num1 = "123", num2 = "456";
    Solution so;
    cout<<so.multiply(num1,num2);
}