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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=NULL){
            fast=fast->next;
            if(fast != NULL){
                fast=fast->next;
                slow=slow->next;
            }
            if(fast==slow){
                //If we get this condition, it means the list has a loop, so break & come out of loop
                break;
            }

        }
        if(fast==NULL)
            return NULL;
        slow=head;
        while(fast != slow){
            fast=fast->next;
            slow=slow->next;
        }
        cout<<slow->val;
        return fast;
    }
};