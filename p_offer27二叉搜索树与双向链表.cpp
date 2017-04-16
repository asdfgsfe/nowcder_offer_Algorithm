/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    void ConvertCore(TreeNode *pNode, TreeNode **listNode)
    {
        if(pNode==NULL)
            return ;
        
        TreeNode *pCurrent = pNode;
        if(pNode->left)
        	ConvertCore(pCurrent->left, listNode);
        
        pCurrent->left = *listNode;
        if(*listNode)
            (*listNode)->right=pCurrent;
        *listNode = pCurrent;
        
        if(pNode->right)
            ConvertCore(pCurrent->right, listNode);
    }
    
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(pRootOfTree == NULL)
            return NULL;
        TreeNode *listNode=NULL;
        ConvertCore(pRootOfTree, &listNode);
        
        TreeNode *pHeadList=listNode;
        while(pHeadList!=NULL && pHeadList->left!=NULL)
            pHeadList=pHeadList->left;
        
        return pHeadList;
    }
};