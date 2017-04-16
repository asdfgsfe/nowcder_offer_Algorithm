/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
//�������ľ��� �������ҽڵ� ��ǰ����� �ݹ� ʵ��
//���߲������
class Solution {
public:
    void Mirror(TreeNode *pRoot) {
		if(pRoot==NULL)
            return ;
        if(pRoot->left == NULL && pRoot->right == NULL)
            return ;
        
        TreeNode* tmp=pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right=tmp;
        
        if(pRoot->left)
            Mirror(pRoot->left);
        if(pRoot->right)
            Mirror(pRoot->right);
    }
};