/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode *findCommNode(ListNode *pHead)
    {
    	if(pHead==NULL)
        	return NULL;
        ListNode *pSlow=pHead->next;
        if(pSlow==NULL)
            return NULL;
        ListNode *pFast=pSlow->next;
        while(pSlow!=NULL && pFast!=NULL)
        {
            if(pSlow==pFast)
            	return pSlow;
            
            pSlow=pSlow->next;
            pFast=pFast->next;
            if(pFast!=NULL)
                pFast=pFast->next;
        }
        return NULL;
    }
    
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
		ListNode *commNode=findCommNode(pHead);
        	int n=1;
        if(commNode != NULL)
        {    
        	ListNode *pNode=commNode->next;
			while(commNode!=pNode)
        	{
            	n++;
            	pNode=pNode->next;
        	}  
        }
        else
            return NULL;
        
        ListNode *pNode1=pHead;
        ListNode *pNode2=pHead;
        while(n--)
        {
            pNode2=pNode2->next;
        }
        
        while(pNode1!=pNode2)
        {
            pNode1=pNode1->next;
            pNode2=pNode2->next;
        }    
    	return pNode1;
    }
};