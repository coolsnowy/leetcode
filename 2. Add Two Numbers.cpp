/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode *result;
		ListNode *node;
		int an = 0;
		while(l1->next && l2->next){
			int val = l1->val + l2->val + an;
			node->val = val % 10;
			an = val / 10;
			result = node;
			result->next = new ListNode(an);
			result = result->next;
            l1 = l1->next;
            l2 = l2->next;
		}
		return result;
    }
};

// can't resolve it,see answer

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		 ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *c1 = l1;
		ListNode *c2 = l2;
		ListNode *sentinel = new ListNode(0);
		ListNode *d = sentinel;
		int sum = 0;
		while(c1 != NULL || c2 != NULL) {
			sum /= 10;
			if(c1 != NULL) {
				sum += c1->val;
				c1 = c1->next;
			}
			if(c2 != NULL) {
				sum += c2->val;
				c2 = c2->next;
			}
			d->next  = new ListNode(sum % 10);
			d = d->next;
		}
		if(sum / 10 == 1)
			d->next = new ListNode(1);
		return sentinel->next;
	}
};

















