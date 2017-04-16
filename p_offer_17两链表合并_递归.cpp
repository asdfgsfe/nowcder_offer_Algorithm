//两排序链表合并 ，非递归实现，若果两个链表长度不一样，应该会出错
/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
            
  		ListNode *newHead = NULL;
        
    	if(pHead1->val < pHead2->val)
       	{
            newHead=pHead1;
            newHead->next=Merge(pHead1->next, pHead2);
        }
     	else
        {
            newHead=pHead2;
            newHead->next=Merge(pHead1, pHead2->next);
        }    
        
        return newHead;
    }
};