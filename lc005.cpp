#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int i,j,max_len=0,max_i=0;
        for(int k=0;k<s.size();k++){
            i=j=k;
            while(i>=0 && j<s.size()){
                if(s[i]!=s[j]) break;
                i--,j++;
            }
            if(j-i-1>max_len){
                max_i = (i+1);
                max_len = j-i-1;
            }
        }

        if(s.size()>=2){
            for(int si=0,sj=1;sj<s.size();si++,sj++){
                int i = si,j=sj;
                while(i>=0 && j<s.size()){
                    cout<<i<<" "<<j;
                    if(s[i]!=s[j]) break;
                    i--,j++;
                }
                if(j-i-1>max_len){
                    max_i = (i+1);
                    max_len = j-i-1;
                }
            }
        }
        return s.substr(max_i,max_len);
    }
};

int main(){
    string s = "aaca";
    Solution so;
    cout<<so.longestPalindrome(s)<<endl;
}