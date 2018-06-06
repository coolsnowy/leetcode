/**
 * Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given 1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
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
    // my accepted answer, need 3 ms
    // 在纸上画一下，方便理解
    ListNode* swapPairs(ListNode* head) {
        // 创建一个dummy，作为返回结果使用
        // pre是为了后面的交换完成
        ListNode* dummy = new ListNode(0);
        ListNode* pre = new ListNode(0);
        dummy->next = head;
        pre->next = head;

        if(head == NULL || head->next == NULL) {
            return dummy->next;
        }
        // 因为本题不允许交换值，必须交换节点，dummy节点指向head节点
        // head节点的操作会改变dummy节点，所以如果第一次交换发生了，为了dummy指向第一个节点，
        // 必须要有下面这一句，不然没有交换之前的第二个节点交换后变成第一个节点丢了
        //第一次交换完成以后，head就被重新赋值了，dummy就不会因为head而改变了
        dummy->next = head->next;
        while(head && head->next) {
            if(head == NULL || head->next == NULL) {
                return dummy->next;
            }
            // 以下四句完成节点的交换完成任务
            ListNode *after  =head->next;
            pre->next = head->next;
            head->next = after->next;
            after->next = head;
            // 为下一次循环做准备，更新节点位置
            pre = head;
            head = head->next;
        }
        return dummy->next;
    }

    // great recursion solutin, accepted but it doesn't use const space
    // 3ms, it need N space
    ListNode* swapPairs1(ListNode* head) {
        if(!head || !head->next) {
            return head;
        }
        ListNode* n = head->next;
        head->next = swapPairs(head->next->next);
        n->next = head;
        return n;
    }

    // another solution similar to my solution
    ListNode* swapPairs2(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* current = dummy;
        while (current->next != NULL && current->next->next != NULL) {
            ListNode* first = current->next;
            ListNode* second = current->next->next;
            first->next = second->next;
            current->next = second;
            current->next->next = first;

            current = current->next->next;
        }
        return dummy->next;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(3);
    l1->next->next->next = new ListNode(4);
    l1->next->next->next->next = new ListNode(5);
    ListNode* result = s.swapPairs2(l1);
    while(result) {
        cout<<result->val<<'\t';
        if(result->next) {
            result = result->next;
        } else
            result = NULL;
    }
    return 0;
}