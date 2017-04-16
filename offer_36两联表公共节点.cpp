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
    int clcListLen(ListNode *pHead)
    {
        if(pHead==NULL)
            return 0;
        ListNode *pNode=pHead;
        int len=0;
        while(pNode != NULL)
        {
        	pNode=pNode->next;
            len++;
        }    
        return len;
    }
    
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==NULL || pHead2==NULL)
            return NULL;
        int len1=clcListLen(pHead1);
        int len2=clcListLen(pHead2);;
		int diff=len1-len2;
        
        ListNode* commNode=NULL;
        ListNode* longList=pHead1;
        ListNode* shortList=pHead2;
        
        if(diff<0)
		{	
            diff=-diff;
            longList=pHead2;
			shortList=pHead1;
        }
            
        int i;
        for(i=0; i<diff; i++)
            longList=longList->next;
        
        while(longList!=NULL && shortList!=NULL 
              &&shortList!=longList)
        {
         	longList=longList->next;
            shortList=shortList->next;
        }
       commNode=shortList;

     return commNode;   
    }
};