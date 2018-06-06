/**
 * Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.

You may not alter the values in the nodes, only nodes itself may be changed.

Only constant memory is allowed.

For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5
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
    // see the solution, 23ms
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode* curr = head;
        if(head == NULL || k == 0) return head;
        while(curr != NULL && count <k) {
            curr = curr->next;
            count++;
        }
        if(count == k) {
            // 这里的返回值，回溯过程中每次返回的head，然后赋值给curr
            // head指向将要逆序的首节点，curr指向已经完成好的首节点，是通过回溯返回值head指定的
            curr = reverseKGroup(curr, k);
            while(count-- > 0) {
                ListNode *next = head->next;
                head->next = curr;

                curr = head;
                head = next;
            }

            head = curr;
        }
        return head;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    ListNode* result = s.reverseKGroup(l1, 2);
    while(result) {
        cout<<result->val<<'\t';
        if(result->next) {
            result = result->next;
        } else
            result = NULL;
    }

    return 0;
}