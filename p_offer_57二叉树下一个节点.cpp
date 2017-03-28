/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;//为该节点的父亲节点
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
//就是找出pNode节点中序遍历的下一个节点。如果该节点有右子树，则右子树的最左节点为下一个节点。
//如果无右子树，且该节点为其父亲节点的左儿子，则该父亲节点就是下一个节点。
//如果无右子树，也无左子树，且该节点为其父亲节点的右儿子，则一直遍历到父亲节点为空或者为父亲节点的左儿子处。
//此刻父亲节点就是下一个节点。
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