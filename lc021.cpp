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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prehead=new ListNode(-1);

        ListNode* head = prehead;
        ListNode* p;
        while(list1 && list2){
            if(list1->val<list2->val){
                p = list1;
                list1 = list1->next;
            }else{
                p =list2;
                list2 = list2->next;
            }
            head->next = p;
            head = p;
        }
        if(list1) head->next = list1;
        if(list2) head->next = list2;

        return prehead->next;
    }
};

int main(){
    vector<int> l1 = {1,2,4}, l2 = {1,3,4};
    ListNode *head1 = new ListNode(l1[l1.size()-1]);
    ListNode *head2 = new ListNode(l2[l2.size()-1]);
    for(int i=l1.size()-2;i>=0;i--){
        ListNode* n = new ListNode(l1[i],head1);
        head1 = n;
    }
    for(int i=l2.size()-2;i>=0;i--){
        ListNode* n = new ListNode(l2[i],head2);
        head2 = n;
    }
    ListNode*h1 = head1;
    ListNode*h2 = head2;
    while(h1){
        cout<<h1->val;
        h1 = h1->next;
    }
    while(h2){
        cout<<h2->val;
        h2 = h2->next;
    }
    cout<<endl;
    Solution so;
    ListNode* head = so.mergeTwoLists(head1,head2);
    while(head){
        cout<<head->val;
        head = head->next;
    }
}