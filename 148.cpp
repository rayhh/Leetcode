class Solution {
private:
    ListNode* merge(ListNode* h1,ListNode*h2){            //归并排序
        ListNode* dummy=new ListNode(-1);
        ListNode* cur=dummy;
        while(h1&&h2){
            if(h1->val<h2->val){
                cur->next=h1;
                h1=h1->next;
            }else{
                cur->next=h2;
                h2=h2->next;
            }
            cur=cur->next;
        }
        cur->next=h1?h1:h2;
        return dummy->next;
    }
    
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next) return head;
        ListNode *slow=head,*fast=head,*firsthead=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode* sechead=slow->next;
        slow->next=nullptr;
        firsthead=sortList(firsthead);
        sechead=sortList(sechead);
        return merge(firsthead,sechead);        
    }
};
