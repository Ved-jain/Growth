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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head==NULL || head->next ==NULL){
            return head;

        }
        int n = 0 ;

        ListNode* temp = head;
        while(temp!=NULL){
            n++;
            temp = temp->next;
        }
        k = k%n;
        

        if(k==0)return head;

        ListNode* slow = head;
        ListNode* fast = head;
        while(k--){
            fast = fast->next;
        }
        while(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* newh = slow->next;
        fast->next = head;
        slow->next = NULL;
        return newh;
    }
};