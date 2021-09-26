/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry_over = 0;
        int leading = l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;
        if (leading > 9) {
            carry_over = leading / 10;
            leading = leading % 10;
        }
        ListNode * ret = new ListNode(leading);
        ListNode * temp = ret;
        
        while (l1 != nullptr && l2 != nullptr) {
            leading = l1->val + l2->val + carry_over;
            l1 = l1->next;
            l2 = l2->next;
            carry_over = 0;
            if (leading > 9) {
                carry_over = leading / 10;
                leading = leading % 10;
            }
            temp->next = new ListNode(leading);
            temp = temp->next;
        }
        
        if (l1 == nullptr && l2 == nullptr && carry_over != 0) {
            temp->next = new ListNode(carry_over);
            return ret;
        } else if (l1 == nullptr) {
            while (l2 != nullptr) {
                leading = l2->val + carry_over;
                l2 = l2->next;
                carry_over = 0;
                if (leading > 9) {
                    carry_over = leading / 10;
                    leading = leading % 10;
                }
                temp->next = new ListNode(leading);
                temp = temp->next;
            }
        } else {
            while (l1 != nullptr) {
                leading = l1->val + carry_over;
                l1 = l1->next;
                carry_over = 0;
                if (leading > 9) {
                    carry_over = leading / 10;
                    leading = leading % 10;
                }
                temp->next = new ListNode(leading);
                temp = temp->next;
            }
        }
        if (carry_over != 0) {
            temp->next = new ListNode(carry_over);
        }
        return ret;
    }
};