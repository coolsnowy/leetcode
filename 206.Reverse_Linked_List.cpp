/**
 * Reverse a singly linked list.
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <queue>

using std::priority_queue;
using std::list;
using std::map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::stack;
using std::vector;


 // Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // need 6ms
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = NULL;
        while(head != NULL) {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }
    // recursion solution, need 9ms
    ListNode* reverseList1(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* newHead = reverseList1(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;

    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    ListNode* result = s.reverseList1(l1);
    while(result) {
        cout<<result->val<<'\t';
        if(result->next) {
            result = result->next;
        } else
            result = NULL;
    }
    return 0;
}