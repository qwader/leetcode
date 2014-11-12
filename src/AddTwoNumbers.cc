/**
 * You are given two linked lists representing two non-negative numbers. 
 * The digits are stored in reverse order and each of their nodes contain a single digit. 
 * Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
**/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        if(l1 == NULL || l2 == NULL){
            return l1 ? l1 : l2;
        }
        ListNode ret(0);
        ListNode **p = &ret.next;
        int carry = 0;
        while(l1 && l2){
            *p = new ListNode((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            p = &(*p)->next;
            l1 = l1->next;
            l2 = l2->next;
        };
        ListNode *res = l1 ? l1 : l2;
        while(res){
            *p = new ListNode((res->val + carry) % 10);
            carry = (res->val + carry) / 10;
            res = res->next;
            p = &(*p)->next;
        }
        if(carry){
            *p = new ListNode(carry);
        }
        return ret.next;
    }
};

