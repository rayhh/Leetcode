//快慢指针，第一次相遇后。让其中一个指针回到头结点，然后直到两个指针二次相遇，一定是在环的入口。

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head) return nullptr;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
            if(slow==fast) break;
        }
        if(fast==nullptr||fast->next==nullptr) return nullptr;
        fast=head;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
};
