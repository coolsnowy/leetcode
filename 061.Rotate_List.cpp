/**
 * Given a list, rotate the list to the right by k places, where k is non-negative.


Example:

Given 1->2->3->4->5->NULL and k = 2,

return 4->5->1->2->3->NULL.
    */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <vector>
#include <stack>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cassert>
#include <sstream>
#include <algorithm>


using std::priority_queue;
using std::vector;
using std::map;
using std::stack;
using std::unordered_map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;

 // Definition for singly-linked list.
struct ListNode {
 int val;
 ListNode *next;
 ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    // my accepted solution 14 ms
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return NULL;
        ListNode *find = head, *tail = head;
        int len = 1;
        // find point to the tail
        while(tail->next) {
            tail = tail->next;
            len++;
        }
        // 输入测试样例有k > len 的，所以进行了取余操作
        k = k % len;
        if(len - k <= 0) return head;
        // find the position before the new head which need process, which is new tail
        for(int i = 1; i < len - k; i++) {
            find = find->next;
        }
        // if new head is the one past the last element
        if(find->next == NULL) return head;
        ListNode *begin = find->next;
        find->next = NULL;
        tail->next = head;
        return begin;
    }

    // discuss solution， complexity is same as mine
    ListNode* rotateRight1(ListNode* head, int k) {
        if(!head) return head;
        int len=1; // number of nodes
        ListNode *newH, *tail;
        newH=tail=head;
        while(tail->next)  // get the number of nodes in the list
        {
            tail = tail->next;
            len++;
        }
        // 先构成了一个环
        tail->next = head; // circle the link
        if(k %= len)
        {
            for(auto i=0; i<len-k; i++) tail = tail->next; // the tail node is the (len-k)-th node (1st node is head)
        }
        newH = tail->next;
        tail->next = NULL;
        return newH;
    }
};

int main() {
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    auto result = s.rotateRight(head, 5);
    while(result) {
        cout<<result->val<<'\t';
        result = result->next;
    }
}