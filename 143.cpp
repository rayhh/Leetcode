class Solution {
public:
	void reorderList(ListNode* head) {
		if(head==nullptr|| head->next==nullptr) return;
    int flag = 1;
		ListNode* slow = head;
		ListNode* fast = head;

    std::function<void(ListNode*)> dfs=[&](ListNode* fast){        //回溯算法+递归lambda
		    if (fast->next->next == nullptr) return;
		    fast = fast->next;
		    dfs(fast);
		    if ((slow == fast) || (fast->next->next == slow)) flag = 0;
		    if (flag == 0) return;
		    fast->next->next = slow->next;
		    slow->next = fast->next;
		    fast->next = nullptr;
		    slow = slow->next->next;
	  };
    
		dfs(fast);
		return;
	}
};
