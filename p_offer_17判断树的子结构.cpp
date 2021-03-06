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
    bool doTreeHaveTree2(TreeNode *pRoot1, TreeNode *pRoot2)
    {

        if(pRoot2==NULL )
            return true;
        if(pRoot1==NULL)
            return false;
        if(pRoot1->val != pRoot2->val)
            return false;
        return doTreeHaveTree2(pRoot1->left, pRoot2->left) 
            && doTreeHaveTree2(pRoot1->right, pRoot2->right);
    }
    
    bool HasSubtree(TreeNode *pRoot1, TreeNode *pRoot2){
        bool result = false;
        if(pRoot1!=NULL && pRoot2!=NULL)
     	{
            if(pRoot1->val == pRoot2->val)
                result = doTreeHaveTree2(pRoot1, pRoot2);
            if(!result)
            	result = HasSubtree(pRoot1->left, pRoot2);
            if(!result)
                result = HasSubtree(pRoot1->right, pRoot2);
        } 
        
		return result;
    }
};