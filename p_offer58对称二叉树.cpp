/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
    	return isSymmetricaCore(pRoot, pRoot);
    }
    
    bool isSymmetricaCore(TreeNode *pRoot1, TreeNode *pRoot2)
    {
        if(pRoot1==NULL && pRoot2==NULL)
            return true;
        if(pRoot1==NULL || pRoot2==NULL)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        
        return isSymmetricaCore(pRoot1->left, pRoot2->right)
            &&isSymmetricaCore(pRoot1->right, pRoot2->left);
    }    
};