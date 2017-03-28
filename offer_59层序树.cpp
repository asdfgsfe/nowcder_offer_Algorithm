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
        vector<vector<int> > Print(TreeNode* pRoot) {
        	vector<vector<int>> result;
            vector<int> everyNum;
            if(pRoot == NULL)
            	return result;
            
            std::queue<TreeNode *> tQue;
            tQue.push(pRoot);
            while(!tQue.empty())
            {
                int size=tQue.size();
                while(size--)
                {
                    TreeNode *pNode=tQue.front();
                    everyNum.push_back(pNode->val);
                    tQue.pop();
                    
                    if(pNode->left)
                    	tQue.push(pNode->left);
                    if(pNode->right)
                    tQue.push(pNode->right);
                }
                
                result.push_back(everyNum);
                everyNum.clear();
            }
            return result;
        }
    
};