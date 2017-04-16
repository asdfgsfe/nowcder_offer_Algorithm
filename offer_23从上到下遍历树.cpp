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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> result;
        if(root==NULL)
            return result;
        
        std::queue<TreeNode *> qt;
        qt.push(root);
        
        while(!qt.empty())
        {
            int size=qt.size();
            while(size--)
            {
                TreeNode *pNode = qt.front();
                qt.pop();
                result.push_back(pNode->val);
                
                if(pNode->left)
                    qt.push(pNode->left);
                if(pNode->right)
                    qt.push(pNode->right);
            }
        }
        return result;
    }
};