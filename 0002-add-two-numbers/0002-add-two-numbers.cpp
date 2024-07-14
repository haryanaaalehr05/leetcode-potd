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
        // Initialize dummy node and current pointer
        ListNode* dummy = new ListNode();
        ListNode* curr = dummy;
        int carry = 0;

        // Traverse both lists
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the values from the current nodes or 0 if the node is null
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum and carry
            int sum = val1 + val2 + carry;
            carry = sum / 10;
            sum = sum % 10;

            // Create a new node with the sum and attach it to the result list
            curr->next = new ListNode(sum);
            curr = curr->next;

            // Move to the next nodes in the input lists
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        // Return the next node of dummy as the head of the result list
        return dummy->next;
    }
};