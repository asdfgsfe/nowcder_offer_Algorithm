class Solution {
public:
    int max(int a, int b)
    {
        return a>b?a:b;
    }
    
    int heightTree(TreeNode *root)
    {
        if(root == NULL)
        	return -1;
        return max(heightTree(root->left),heightTree(root->right))+1;
    }
    
    bool IsBalanceCore(TreeNode *root, int *height)
    {
        if(root==NULL)
        {
            *height=0;
            return true;
        }    
        
        int leftHeight, rightHeight;
        if(IsBalanceCore(root->left, &leftHeight) 
           && IsBalanceCore(root->right, &rightHeight))
        {
            int diff=leftHeight-rightHeight;
            if(diff <=1 && diff >=-1)
            {
                *height=1+max(leftHeight, rightHeight);
                return true;
            }	
        }
        return false;
    }    
    
    bool IsBalanced_Solution(TreeNode* pRoot) {
		if(pRoot==NULL)
           return true;
        int height=0;
        return IsBalanceCore(pRoot, &height);
    }
};