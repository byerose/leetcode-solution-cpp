#include<iostream>
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
    bool hasCycle(ListNode *head) {
        if(head==nullptr) return false;
        ListNode *p = head->next;
        while (p!=nullptr&&p->next!=nullptr)
        {
            if(p!=head){
                p = p->next->next;
                head = head->next;
            }else
                return true;
        }
        return false;
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
    cout<<so.hasCycle(head);
}