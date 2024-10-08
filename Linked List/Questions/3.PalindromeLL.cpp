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
    bool isPalindrome(ListNode* head) {
        //Break list into two havles
        ListNode* midNode=middleNode(head);
        ListNode* head2=midNode->next;
        midNode->next=NULL;

        //Reverse Second Half
        ListNode* prev=NULL;
        ListNode* curr=head2;
        head2=reverseUsingRecursion(prev,curr);

        //Compare both lists
        bool ans=compareList(head, head2);
        return ans;
    }
    ListNode* middleNode(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next != NULL){
            fast=fast->next;
            if(fast->next!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        return slow;
    }
    ListNode* reverseUsingRecursion(ListNode* prev, ListNode* curr){
        if(curr==NULL)
            return prev;
        ListNode* nextNode=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextNode;
        return reverseUsingRecursion(prev, curr);
    }
    bool compareList(ListNode* head, ListNode*head2){
        while(head!=NULL && head2!=NULL){
            if(head->val != head2->val)
                return false;
            else{
                head=head->next;
                head2=head2->next;
            }
        }
        return true;
    }
    
    

};