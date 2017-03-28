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
        
        int flag = 1;
        std::queue<TreeNode *> tQue;
        std::stack<TreeNode *> tStack;
        tQue.push(pRoot);
        while(!tQue.empty())
        {
            int size=tQue.size();
            while(size--)
            {
                TreeNode *pNode=tQue.front();
                if((flag & 1) ==1)
                	everyNum.push_back(pNode->val);
                else 
                	tStack.push(pNode);
                tQue.pop();
               
                	if(pNode->left)
  	                	tQue.push(pNode->left);
                    if(pNode->right)
						tQue.push(pNode->right);
            }
            while(!tStack.empty())
			{
            	TreeNode *pNode=tStack.top();
                everyNum.push_back(pNode->val);
                tStack.pop();
            }
            
            result.push_back(everyNum);
            everyNum.clear();
            flag++;
        }    
        return result;
    }
    
};