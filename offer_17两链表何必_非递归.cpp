//����������ϲ� ���ǵݹ�ʵ�֣��������������Ȳ�һ����Ӧ�û����
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
        if(pHead1==NULL && pHead2==NULL)
            return NULL;
        if(pHead1==NULL)
            return pHead2;
        if(pHead2==NULL)
            return pHead1;
            
        ListNode *newHead = NULL;
        if(pHead1->val >= pHead2->val)
            newHead=pHead2;
        else
            newHead=pHead1;
        
        ListNode *pNode = NULL;
        while(pHead1!=NULL && pHead2!=NULL)
    	{
            if(pHead1->val < pHead2->val)
            {
                pNode=pHead1->next;
                pHead1->next=pHead2;
                pHead1=pNode;
            } 
            else 
            {
                pNode=pHead2->next;
                pHead2->next=pHead1;
                pHead2=pNode; 
            }    
        }
        
        return newHead;
    }
};