/*
Given a linked list, remove the nth node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:
Given n will always be valid.
Try to do this in one pass.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>

using std::list;
using std::map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::vector;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
         int val;
         ListNode *next;
         ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    // my answer can work out the problem, but when sumit, prompt the time limited
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        std::vector<ListNode *> vec;
        ListNode* p = head;
        while(p != NULL) {
            vec.push_back(p);
            if(p->next != NULL) {
                p = p->next;
            }
            else break;
        }
        if(n < vec.size()) {
            vec[vec.size()-n-1]->next = vec[vec.size()-n+1];
            vec[vec.size()-n] = NULL;
        } else if(n == vec.size()) {
            vec[0] == NULL;
            head = vec[1];
        }
        return head;
    }

    /**
     * Approach #1 (Two pass algorithm)

Intuition

     We notice that the problem could be simply reduced to another one :
     Remove the (L - n + 1)th node from the beginning in the list , where L is the list length.
     This problem is easy to solve once we found list length L.

Algorithm

     First we will add an auxiliary "dummy" node, which points to the list head.
     The "dummy" node is used to simplify some corner cases such as a list with only one node, or removing the head of the list.
     On the first pass, we find the list length L. Then we set a pointer to the dummy node and start to move it through the list
     till it comes to the (L - n) th node. We relink next pointer of the (L - n) th node to the (L - n + 2) th node and we are done.
     我的方法是l-n-1指向l-n+1，但是这里前面加了一个dummy所以是这样的，而且加了一个指针， 就不用像我之前当删除第一个的时候 分情况讨论
     */
// 这方法和我的看起来差不多，但是因为使用的都是原始类型而没有使用vector，所以时间更加高效
    /*
     * Complexity Analysis

    Time complexity : O(L).
    The algorithm makes two traversal of the list, first to calculate list length L
     and second to find the (L - n) th node. There are 2L−n operations and time complexity is O(L).
    9ms
    Space complexity : O(1). We only used constant extra space
     */
    ListNode* removeNthFromEnd1(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        int length  = 0;
        ListNode* first = head;
        while (first != NULL) {
            length++;
            first = first->next;
        }
        length -= n;
        first = dummy;
        while (length > 0) {
            length--;
            first = first->next;
        }
        first->next = first->next->next;
        return dummy->next;
    }

    /*
     * Approach #2 (One pass algorithm)
        Algorithm

        The above algorithm could be optimized to one pass.
        Instead of one pointer, we could use two pointers.
        The first pointer advances the list by n+1 steps from the beginning, while the second pointer starts from the beginning of the list.
        Now, both pointers are exactly separated by n nodes apart.
        We maintain this constant gap by advancing both pointers together until the first pointer arrives past the last node.
        The second pointer will be pointing at the nth node counting from the last.
        We relink the next pointer of the node referenced by the second pointer to point to the node's next next node.
     */
    /*
     * Complexity Analysis

        Time complexity : O(L). The algorithm makes one traversal of the list of LL nodes. Therefore time complexity is O(L).
        6ms
        Space complexity : O(1). We only used constant extra space.
     */
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* first = dummy;
        ListNode* second = dummy;
        for(int num = 0; num<n+1; num++) {
            first = first->next;
        }
        while(first != NULL) {
            first = first->next;
            second = second->next;
        }
        second->next = second->next->next;
        return dummy->next;
    }
};

int main() {
    ListNode *head = new ListNode(1);
    ListNode *p = head;
    head->next = new ListNode(2);
    head = head->next;
    head->next = new ListNode(3);
    head = head->next;
    head->next = new ListNode(4);
    head = head->next;
    head->next = new ListNode(5);
    head = head->next;
    head->next =NULL;
    Solution s;
    auto ptr = s.removeNthFromEnd2(p,2);
    while(ptr) {
        cout<<ptr->val<<'\t';
        if(ptr->next != NULL) {
            ptr = ptr->next;
        }
        else break;
    }cout<<endl;

}