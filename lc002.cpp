#include<iostream>

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0,s,flag;
        ListNode* pre1,* pre2;
        ListNode* h1 = l1,* h2=l2;
        while(l1&&l2){
            s = l1->val+l2->val+c;
            l1->val = s%10;
            l2->val = l1->val;
            c = s/10;
            pre1 = l1;
            pre2 = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            flag = 1;
            s = l1->val + c;
            l1->val = s%10;
            c = s/10;
            pre1 = l1;
            l1 = l1->next;
        }
        while(l2){
            flag = 0;
            s = l1->val + c;
            l2->val = s%10;
            c = s/10;
            pre2 = l2;
            l2 = l2->next;
        }
        if(c){
            if(flag){
                pre1->next = new ListNode(c);
                pre1->next->next = nullptr;
            }
            else{
                pre2 = new ListNode(c);
                pre2->next->next = nullptr;
            }
        }
        if(flag) return h1;
        return h2;
    }
};