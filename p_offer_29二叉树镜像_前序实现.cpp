/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//二叉树的镜像 交换左右节点 用前序遍历 递归 实现
//或者层序遍历
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if(pRoot==NULL)
            return ;
        if(pRoot->left == NULL && pRoot->right == NULL)
            return ;
        
        TreeNode* tmp=pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right=tmp;
        
        if(pRoot->left)
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);
    }
};