#include<iostream>
#include<vector>
#include<string>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {

    }
};

int main(){
    string beginWord = "hit", endWord = "cog";
    vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
    Solution so;
    for(auto& x:so.findLadders(beginWord, endWord, wordList)){
        for(auto& y:x){
            cout<<y;
        }
        cout<<endl;
    }

}