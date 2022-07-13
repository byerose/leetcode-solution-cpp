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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* post = head,* t = head;
        while(post->next){
            post = post->next;
        }
        ListNode* p = post;
        while(t!=post&&t->next!=post){
            p->next = t->next;
            p = p->next;
            t->next = t->next->next;
            t=t->next;
        }
        if(t->next==post){
            p->next = t->next;
            p=p->next;
            t->next = t->next->next;
        }
        p->next = nullptr;
        return head;
    }
};

