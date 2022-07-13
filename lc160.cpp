#include<iostream>
#include<unordered_set>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    unordered_set<ListNode*> sets;
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA){
            sets.insert(headA);
            headA = headA->next;
        }
        while(headB){
            if(sets.count(headB)) return headB;
            headB = headB->next;
        }
        return nullptr;
    }
};

int main(){

}