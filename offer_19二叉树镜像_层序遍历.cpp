//层序遍历 产生二叉树镜像 
//利用队列 交换左右子树
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
    void Mirror(TreeNode *pRoot) {
		if(pRoot==NULL)
            return ;
        std::queue<TreeNode *> qt;
        qt.push(pRoot);
        
        while(!qt.empty())
        {
            pRoot=qt.front();
            qt.pop();
            
            TreeNode *tmp=pRoot->left;
            pRoot->left = pRoot->right;
            pRoot->right = tmp;
            
            if(pRoot->left)
                qt.push(pRoot->left);
            if(pRoot->right)
                qt.push(pRoot->right);
        }    
    }
};