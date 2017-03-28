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
    TreeNode *KthNodeCore(TreeNode *pRoot, int &k)
    {
    	std::stack<TreeNode *> sTree;
        
        while(pRoot!=NULL || !sTree.empty())
        {
            while(pRoot!=NULL)
            {
                sTree.push(pRoot);
                pRoot=pRoot->left;
            }
            
            if(!sTree.empty())
            {
                pRoot=sTree.top();
                sTree.pop();
                k--;
                if(k==0)
                    return pRoot;
               pRoot=pRoot->right; //×¢Òâ´Ë´¦pRoot
            }    
        }    
        return NULL;
    }
    
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot == NULL || k==0)
            return NULL;
        return KthNodeCore(pRoot, k);
    }  
};