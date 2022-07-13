#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
    unordered_map<string,string> routes;
    vector<string> findItinerary(vector<vector<string>>& tickets) {    
        vector<string> res = {"JFK"};
        for(auto& x:tickets){
            routes.insert(make_pair(x[0],x[1]));
        }
        pair<string,string> t;
        string tmp = "JFK";
        while(routes.find(tmp)!=routes.end()){
            t = *(routes.find(tmp));
            res.push_back(t.second);
            tmp = t.second;
        }
        return res;
    }
};

int main(){
    // vector<vector<string>> tickets = {{"MUC","LHR"},{"JFK","MUC"},{"SFO","SJC"},{"LHR","SFO"}};
    vector<vector<string>> tickets = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    Solution so;
    for(auto& x:so.findItinerary(tickets)){
        cout<<x<<endl;
    }
}