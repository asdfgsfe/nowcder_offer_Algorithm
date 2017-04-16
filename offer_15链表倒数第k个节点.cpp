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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    	int flags=0;//此处从0开始
        if(pListHead==NULL || k<=0)
            return NULL;
        ListNode* pNode=pListHead;
        while(pNode!=NULL && flags<k)
        {
            flags++;
            pNode=pNode->next;
        }   
        if(pNode==NULL && flags<k)
            return NULL;
       	if(pNode==NULL && flags==k)
            return pListHead;
        
        while(pNode!=NULL && pListHead!=NULL)
        {
            pNode=pNode->next;
            pListHead=pListHead->next;
        }
        return pListHead;
    }
};