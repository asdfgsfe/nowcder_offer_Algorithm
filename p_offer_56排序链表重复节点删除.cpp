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
    void deleteDuplicationCore(ListNode **pHead)
    {
        if(pHead==NULL || *pHead==NULL)
        	return;
        ListNode *pPreNode=NULL;
        ListNode *pNode=*pHead;
        
        while(pNode)
        {
            ListNode *pNext=pNode->next;
            bool isDelete=false;
            if(pNext!=NULL && pNode->val==pNext->val)
				isDelete=true;
                
            if(isDelete==false)
            {
                pPreNode=pNode;
                pNode=pNext;
            }    
            else
            {
                int currVal=pNode->val;
                ListNode *pToBeDel=pNode;
                while(pToBeDel && pToBeDel->val==currVal)
                {
                    pNext=pToBeDel->next;
                    delete pToBeDel;
                    pToBeDel=NULL;
                    pToBeDel=pNext;
                }    
                if(pPreNode==NULL)//²»Àí½â
                    *pHead=pNext;
                else
                    pPreNode->next=pNext;
                pNode=pNext;
            }
        }   
    }    
        
    ListNode* deleteDuplication(ListNode* pHead)
    {
        deleteDuplicationCore(&pHead);
		return pHead;
    }
};