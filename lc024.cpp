#include<iostream>
#include<vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* prehead = new ListNode(-1);
        prehead->next = head;
        ListNode* p = prehead,* t;
        while(p->next && p->next->next){
            t = p->next;
            p->next = t->next;
            t->next = t->next->next;
            p->next->next = t;
            p = p->next->next;
        }
        return prehead->next;
    }
};

int main(){
    vector<int> nums = {1,2,3,4};
    ListNode* prehead = new ListNode(-1);
    ListNode* hd = prehead;
    for(auto& x:nums){
        hd->next = new ListNode(x);
        hd = hd->next;
    }
    hd->next = nullptr;
    hd = prehead->next;
    
    ListNode* h1 = prehead->next;
    while(h1){
        cout<<h1->val;
        h1 = h1->next;
    }
    Solution so;
    ListNode* h = so.swapPairs(hd);
    while(h){
        cout<<h->val;
        h = h->next;
    }
}