class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prevGroup = dummy;

        while(true) {

            // Check whether k nodes are available
            ListNode* kth = prevGroup;

            for(int i = 0; i < k; i++) {
                kth = kth->next;

                if(kth == NULL)
                    return dummy->next;
            }

            // Node after the current group
            ListNode* nextGroup = kth->next;

            // Reverse current k nodes
            ListNode* prev = nextGroup;
            ListNode* curr = prevGroup->next;

            while(curr != nextGroup) {
                ListNode* next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            // Connect previous group to reversed group
            ListNode* temp = prevGroup->next;
            prevGroup->next = kth;

            // temp is now the tail of reversed group
            prevGroup = temp;
        }

        return dummy->next;
    }
};