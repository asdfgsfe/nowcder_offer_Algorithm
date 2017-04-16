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
    ListNode* ReverseList(ListNode* pHead) {
		if(pHead==NULL)
            return NULL;
        
        ListNode *newHead=NULL;
        ListNode *pNode=NULL;
        
        while(pHead!=NULL)
        {
            pNode = pHead->next;
            pHead->next = newHead;
            
            newHead=pHead;
            pHead=pNode;
        }    
        return newHead;
    }
};