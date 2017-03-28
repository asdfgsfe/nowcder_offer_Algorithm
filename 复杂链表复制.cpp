/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {

		RandomListNode *aNode=pHead;
		RandomListNode *bNode=NULL;
		RandomListNode *pNode=NULL;
	
		if(pHead == NULL)
			return NULL;
		
		while(aNode != NULL)
		{
			pNode=(RandomListNode *)malloc(sizeof(struct RandomListNode));
			if(pNode == NULL)
			{
                printf("Not many apace!\n");
                return NULL;
            }
			pNode->label = aNode->label;
			pNode->next = aNode->next;
			pNode->random = NULL;

			aNode->next = pNode;
			aNode = pNode->next;
		}
        
        aNode=pHead;
        while(aNode)
		{
            RandomListNode *pNode = aNode->next;
            if(aNode->random && pNode)
            	pNode->random=aNode->random->next;
            aNode=pNode->next;
        }   	
		/*aNode=pHead;
		bNode=aNode->next;
		pNode=bNode;
	
		while(aNode->next)
		{
			aNode->next = pNode->next;
            if(aNode->next)
				pNode->next=aNode->next->next;
			//if(aNode->random)
			//	pNode->random=aNode->random->next;
		
			aNode=aNode->next;
			pNode=pNode->next;
		}*/
        
        aNode=pHead;
        bNode=pNode=aNode->next;
		aNode->next=bNode->next;
        aNode=aNode->next;
	
        while(aNode)
        {
            pNode->next=aNode->next;
            pNode=pNode->next;
            aNode->next=pNode->next;
            aNode=aNode->next;
        }
        
        
		return bNode;      
    }
};