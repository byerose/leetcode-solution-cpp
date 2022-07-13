#include<iostream>
#include<unordered_set>
#include<vector>

using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> sets;
        while (head!=nullptr)
        {
            if(sets.find(head)==sets.end()) sets.insert(head);
            else return head;
            head=head->next; 
        }
        return nullptr;
    }
};

int main(){
    vector<int> nums = {0,2,2,3};
    
    //创建链表
    ListNode *head = new ListNode(nums[0]);
    ListNode *p = head;
    for(int i=1;i<nums.size();i++){
        ListNode *n = new ListNode(nums[i]);
        n->next = p->next;
        p->next = n;
        p = n;
    }

    Solution so;
    ListNode *res = so.detectCycle(head);
    if(res!=nullptr)
        cout<<res->val;
    else
        cout<<0;    
}