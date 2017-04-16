/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* reConstructBinaryTreeCore(int *startPrev, int *endPrev,
                                        int *startVin, int *endVin)
    {
        int rootVal=startPrev[0];
        TreeNode *root=(TreeNode *)malloc(sizeof(struct TreeNode));
        root->val=rootVal;
        root->left=root->right=NULL;
        
        if(startPrev==endPrev)
        {
            if(startVin==endVin && *startPrev==*startVin)
                return root;
            else
                return NULL;
        }    
        int *rootVin = startVin;
        while(rootVin<=endVin && *rootVin!=rootVal)
        	rootVin++;
        if(rootVin==endVin && *rootVin!=rootVal)
            return NULL;
        int leftLength = rootVin-startVin;
        int *leftPrevEnd = startPrev+leftLength;
        if(leftLength > 0)
            root->left = reConstructBinaryTreeCore(startPrev+1, leftPrevEnd,
                                                   startVin, rootVin-1);  
        if(leftLength<endPrev-startPrev)
            root->right=reConstructBinaryTreeCore(leftPrevEnd+1, endPrev,
                                                 rootVin+1, endVin);
        
        return root;
    }
    
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
		TreeNode* root = NULL;
        int lenPrev=pre.size();
        int lenVin=vin.size();
        if(lenPrev<=0 || lenVin<=0 || lenPrev!=lenVin)
            return NULL;
        
        int *aPrev = (int *)malloc(lenPrev*sizeof(int));
        int *aVin = (int *)malloc(lenPrev*sizeof(int));
        
        int i;
        for(i=0; i<lenPrev; i++)
        {
            aPrev[i]=pre[i];
            aVin[i]=vin[i];
        }    
       	root = reConstructBinaryTreeCore(aPrev, aPrev+lenPrev-1, 
                                         aVin, aVin+lenPrev-1);
 
        return root;
    }
};