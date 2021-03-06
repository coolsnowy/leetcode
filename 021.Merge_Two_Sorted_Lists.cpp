/*
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4

*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>

using std::list;
using std::map;
using std::cout;
using std::string;
using std::cin;
using std::endl;
using std::stack;
using std::vector;

/**
 * Definition for singly-linked list.
 * */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //my accepted solution, 9ms
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *p = new ListNode(0);
        ListNode *preHead = p;
        while(l1 || l2) {
            if (l1 && l2) {
                if (l1->val <= l2->val) {
                    p->next = new ListNode(l1->val);
                    p = p->next;
                    if (l1->next) l1 = l1->next;
                    else l1 = NULL;
                } else {
                    p->next = new ListNode(l2->val);
                    p = p->next;
                    if (l2->next) l2 = l2->next;
                    else l2 = NULL;
                }
            } else if (l1 && !l2) {
                while (l1) {
                    p->next = new ListNode(l1->val);
                    p = p->next;
                    if (l1->next) {
                        l1 = l1->next;
                    } else
                        l1 = NULL;
                }
            } else if(l2 && !l1) {
                while (l2) {
                    p->next = new ListNode(l2->val);
                    p = p->next;
                    if (l2->next) {
                        l2 = l2->next;
                    } else
                        l2 = NULL;
                }
            }
        }
        return preHead->next;
    }
    //see some other solution
    /**
     * Approach #1 Recursion [Accepted]

Intuition

We can recursively define the result of a merge operation on two lists as the following (avoiding the corner case logic surrounding empty lists):

list1[0] + merge(list1[1:], list2)  list1[0] < list2[0]
list2[0] + merge(list1, list2[1:])  otherwise
​​
Namely, the smaller of the two lists' heads plus the result of a merge on the rest of the elements.

Algorithm

We model the above recurrence directly, first accounting for edge cases. Specifically, if either of l1 or l2 is initially null,
     there is no merge to perform, so we simply return the non-null list.
     Otherwise, we determine which of l1 and l2 has a smaller head, and recursively set the next value for that head to the next merge result.
     Given that both lists are null-terminated, the recursion will eventually terminate.
     */
    /**
     * Complexity Analysis

Time complexity : O(n + m)

Because each recursive call increments the pointer to l1 or l2 by one (approaching the dangling null at the end of each list),
     there will be exactly one call to mergeTwoLists per element in each list.
     Therefore, the time complexity is linear in the combined size of the lists.

Space complexity : O(n + m)

The first call to mergeTwoLists does not return until the ends of both l1 and l2 have been reached,
     so n + m stack frames consume O(n+m) space.

     */
    // 具体的递归过程需要在纸上想想， l1和l2指针逐一向后移动，然后递归结束后，指针再向前一个一个往前移动
    // 具体的递归过程可以通过clion的gdb观察具体的变化
    ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
        //返回条件
        if(l1 == NULL)  return l2;
        else if(l2 == NULL)  return l1;
        else if(l1->val < l2->val) {
            // recursion, meanwhile l1 = l2->next, gret!
            l1->next = mergeTwoLists1(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists1(l1,l2->next);
            return l2;
        }
    }
    /**
     * Approach #2 Iteration [Accepted]

Intuition

We can achieve the same idea via iteration by assuming that l1 is entirely less than l2 and processing the elements one-by-one,
     inserting elements of l2 in the necessary places in l1.

Algorithm

First, we set up a false "prehead" node that allows us to easily return the head of the merged list later.
     We also maintain a prev pointer, which points to the current node for which we are considering adjusting its next pointer.
     Then, we do the following until at least one of l1 and l2 points to null: if the value at l1 is less than or equal to the value at l2,
     then we connect l1 to the previous node and increment l1.
     Otherwise, we do the same, but for l2. Then, regardless of which list we connected,
     we increment prev to keep it one step behind one of our list heads.

After the loop terminates, at most one of l1 and l2 is non-null.
     Therefore (because the input lists were in sorted order), if either list is non-null,
     it contains only elements greater than all of the previously-merged elements.
     This means that we can simply connect the non-null list to the merged list and return it.


    Complexity Analysis

Time complexity : O(n + m)

Because exactly one of l1 and l2 is incremented on each loop iteration,
     the while loop runs for a number of iterations equal to the sum of the lengths of the two lists.
     All other work is constant, so the overall complexity is linear.

Space complexity : O(1)
The iterative approach only allocates a few pointers, so it has a constant overall memory footprint.
     */
     ListNode* mergeTwoLists2(ListNode* l1, ListNode* l2) {
        // maintain an unchanging reference to node ahead of the return node.
        ListNode* prehead = new ListNode(-1);

        ListNode* prev = prehead;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                prev->next = l1;
                l1 = l1->next;
            } else {
                prev->next = l2;
                l2 = l2->next;
            }
            prev = prev->next;
        }

        // exactly one of l1 and l2 can be non-null at this point, so connect
        // the non-null list to the end of the merged list.
        prev->next = l1 == NULL ? l2 : l1;

        return prehead->next;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(2);
    l1->next->next = new ListNode(4);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    ListNode* result = s.mergeTwoLists1(l1, l2);
    while(result) {
        cout<<result->val<<'\t';
        if(result->next) {
            result = result->next;
        } else
            result = NULL;
    }
    return 0;
}