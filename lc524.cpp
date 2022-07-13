#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    bool get_after_delete(string s,string t){
        int i=0,j=0;
        while (j<t.size() && i<s.size()){
            if(s[i]==t[j]) ++i,++j;
            else ++i;
        }
        if(j==t.size()) return true;
        else return false;
}

    string findLongestWord(string s, vector<string>& dictionary) {
        int idx_min=-1,find_sub = 0;
        for(int i=0;i<dictionary.size();i++){
            if(get_after_delete(s,dictionary[i])){
                if(idx_min>=0){
                    if(dictionary[i].size()>dictionary[idx_min].size()) 
                        idx_min = i;
                    else if(dictionary[i].size()==dictionary[idx_min].size()&&dictionary[i]<dictionary[idx_min])
                        idx_min = i;
                }else{
                    idx_min = i;   
                }
            }
        }
        if(idx_min>=0)
            return dictionary[idx_min];
        else
            return "";
    }
};

int main(){
    string s = "abce";
    vector<string> dictionary = {"abe","abc"};
    Solution so;
    cout<<so.findLongestWord(s,dictionary);
}