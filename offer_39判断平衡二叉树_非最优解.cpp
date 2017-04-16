
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
		IsBalanceCore(root->right);*/ //ע��˴�д�� �������ж������ڵ����������Ƿ�ƽ�⡣Ӧ�����£�
        return IsBalanceCore(root->left) && IsBalanceCore(root->right);;
    }
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(pRoot==NULL)
           return true;
        return IsBalanceCore(pRoot);
    }
};