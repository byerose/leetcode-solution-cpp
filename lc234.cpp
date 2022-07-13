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
    bool isPalindrome(ListNode* head) {
        ListNode* p_fast=head,* p_slow=head;
        while(p_fast && p_fast->next){
            p_fast = p_fast->next->next;
            p_slow = p_slow->next;
        }
        ListNode* right = reverseList(p_slow);
        while(right){
            if(right->val!=head->val) return false;
            right = right->next;
            head = head->next;
        }
        return true;
    }
};

int main(){

}