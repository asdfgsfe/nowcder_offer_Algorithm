/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;//Ϊ�ýڵ�ĸ��׽ڵ�
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
//�����ҳ�pNode�ڵ������������һ���ڵ㡣����ýڵ�������������������������ڵ�Ϊ��һ���ڵ㡣
//��������������Ҹýڵ�Ϊ�丸�׽ڵ������ӣ���ø��׽ڵ������һ���ڵ㡣
//�������������Ҳ�����������Ҹýڵ�Ϊ�丸�׽ڵ���Ҷ��ӣ���һֱ���������׽ڵ�Ϊ�ջ���Ϊ���׽ڵ������Ӵ���
//�˿̸��׽ڵ������һ���ڵ㡣
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
            return NULL;
        
        TreeLinkNode* pNext=NULL;
        if(pNode->right)
        {
         	TreeLinkNode* pRight=pNode->right;
            while(pRight->left)
                pRight=pRight->left;
            pNext=pRight;
        }    
        else if(pNode->next)
        {
            TreeLinkNode* pParent=pNode->next;
            TreeLinkNode* pCurrent=pNode;
            while(pParent!=NULL && pParent->right==pCurrent)
            {
                pCurrent=pParent;
                pParent=pParent->next;
            }    
            pNext=pParent;
        }    
        return pNext;
    }
};