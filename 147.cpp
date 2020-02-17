class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode* prehead=new ListNode(-1);
        prehead->next=head;
        ListNode *sorted=head, *pre=prehead;
        while(sorted->next){
            pre=prehead;
            ListNode* cur=sorted->next;
            while(pre->next->val<=cur->val&&pre->next!=sorted) pre=pre->next;
            if(pre->next!=sorted){
                ListNode* tmp=pre->next;
                pre->next=cur;
                sorted->next=cur->next;
                cur->next=tmp;
            }
            else {
                if(cur->val<=sorted->val) swap(cur->val,sorted->val);
                sorted=sorted->next;
            }
        };
        return prehead->next;
    }
};
