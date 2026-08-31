class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> positions;

        ListNode* prev=head;
        ListNode* curr=head->next;

        int pos=1;

        while(curr->next!=NULL){

            if((curr->val>prev->val && curr->val>curr->next->val) ||
               (curr->val<prev->val && curr->val<curr->next->val)){

                positions.push_back(pos);
            }

            prev=curr;
            curr=curr->next;
            pos++;
        }

        if(positions.size()<2)
            return {-1,-1};

        int mn=INT_MAX;

        for(int i=1;i<positions.size();i++){
            mn=min(mn,positions[i]-positions[i-1]);
        }

        int mx=positions.back()-positions.front();

        return {mn,mx};
    }
};