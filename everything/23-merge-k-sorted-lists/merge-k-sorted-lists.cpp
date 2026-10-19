
class Solution {
public:
    ListNode* helper(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* head;

        if (list1->val <= list2->val) {
            head = list1;
            list1 = list1->next;
        } else {
            head = list2;
            list2 = list2->next;
        }

        ListNode* curr = head;

        while (list1 && list2) {
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }

            curr = curr->next;
        }

        curr->next = list1 ? list1 : list2;

        return head;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();

        if (n == 0) return NULL;

            ListNode* temp = lists[0];

        for (int i = 1; i < n; i++) {
            temp = helper(temp, lists[i]);
        }

        return temp;
    }
};
