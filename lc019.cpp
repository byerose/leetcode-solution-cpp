#include<iostream>
#include<stack>

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*> stack_node;
        ListNode* p=head;
        while(p){
            stack_node.push(p);
            p=p->next;
        }
        while(n--){
            stack_node.pop();
        }
        if(!stack_node.empty()){
            p = stack_node.top();
            p->next = p->next->next;
            return head;
        }else{
            return head->next;
        }
    }
};