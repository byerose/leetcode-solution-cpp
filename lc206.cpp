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
    ListNode* reverseList(ListNode* head) {
        ListNode* k;
        ListNode* p = nullptr;
        while(head!=nullptr){
            k = head->next;
            head->next = p;
            p = head;
            cout<<p->val;
            head = k;
        }
        return p;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5};
    ListNode* head = new ListNode(0);
    ListNode* p=head;
    for(auto& x:nums){
        ListNode* n = new ListNode(x);
        p->next = n;
        p = n;
    }
    ListNode* k = head;
    while(k!=nullptr){
        cout<<k->val<<",";
        k = k->next;
    }
    Solution so;
    head = so.reverseList(head);
    ListNode* c = head;
    while(c!=nullptr){
        cout<<c->val<<"..";
        c = c->next;
    }

}