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
    void prevOrder(TreeNode *root, vector<TreeNode*>&leaf, vector<TreeNode*>&prevNode)
    {
    	if(root!=NULL)
        {
            if(root->left==NULL && root->right==NULL)
                leaf.push_back(root);
            prevNode.push_back(root);
            
            prevOrder(root->left, leaf, prevNode);
            prevOrder(root->right, leaf, prevNode);
        }    
    }
    
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
		vector<vector<int> > result;
        if(root==NULL)
            return result;
        
        TreeNode *leftNode=root->left;
        TreeNode *rightNode=root->right;
        
        vector<TreeNode*> leaf;
        vector<TreeNode*> prevNode;
        vector<int> tmp;
        
        prevOrder(root, leaf, prevNode);
        
        int sum=0;
        int len=prevNode.size();
        int i;
        int j=0;
        for(i=0; i<len; i++)
        {
            tmp.push_back(prevNode[i]->val);
            sum += prevNode[i]->val;
            if(prevNode[i] != rightNode)
            {    
            	if(prevNode[i] == leaf[j])
            	{
                	if(sum==expectNumber)
                    	result.push_back(tmp);
               		tmp.pop_back();
               		sum -=  prevNode[i]->val;
               		j++;
            	}
            }
            else if(prevNode[i] == rightNode)
            {
                tmp.clear();
                sum=root->val + rightNode->val;
                tmp.push_back(root->val);
                tmp.push_back(rightNode->val);
            }    
        }
        if(i==len && sum==expectNumber)
            result.push_back(tmp);
        
        return result;
    }
};