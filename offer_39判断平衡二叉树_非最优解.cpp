
class Solution {
public:
    int max(int a, int b)
    {
        return a>b?a:b;
    }    
    
    int heightTree(TreeNode *root)
    {
        if(root==NULL)
        	return -1;
        return max(heightTree(root->left),heightTree(root->right))+1;
    }    
    
    bool IsBalanceCore(TreeNode *root)
    {
        if(root==NULL)
            return true;
        if(heightTree(root->left)- heightTree(root->right) <= 1
          ||heightTree(root->left)- heightTree(root->right) >= -1)
            return true;
        /*IsBalanceCore(root->left);
		IsBalanceCore(root->right);*/ //注意此处写法 丢掉了判断最后根节点左右子树是否平衡。应该如下：
        return IsBalanceCore(root->left) && IsBalanceCore(root->right);;
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(pRoot==NULL)
           return true;
        return IsBalanceCore(pRoot);
    }
};