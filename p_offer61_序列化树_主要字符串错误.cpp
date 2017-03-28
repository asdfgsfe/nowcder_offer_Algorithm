class Solution {   
public:
    char* Serialize(TreeNode *root) {
       if(root == NULL)
           return NULL;
        string str;
        SerializeCore(root, str);
        char *ret = new char[str.length() + 1];
        int i;
        for(i = 0; i < str.length(); i++){
            ret[i] = str[i];
        }
        ret[i] = '\0';
        return ret;
    }
    void SerializeCore(TreeNode *root, string& str){
        if(root == NULL){
            str += '#';
            return ;
        }
        string r = to_string(root->val);
        str += r;
        str += ',';
        SerializeCore(root->left, str);
        SerializeCore(root->right, str);
    }
    
    TreeNode* DeserializeCore(char **str){//���ڵݹ�ʱ���᲻�ϵ�����ȡ�ַ���
        if(**str == '#'){  //����һ��Ҫ��**str,
            ++(*str);         //�Ա�֤�õ��ݹ��ָ��strָ��δ����ȡ���ַ�
            return NULL;
        }
        int num = 0;
        while(**str != '\0' && **str != ','){
            num = num*10 + ((**str) - '0');
            ++(*str);
        }
        TreeNode *root = new TreeNode(num);
        if(**str == '\0')
            return root;
        else
            (*str)++;
        root->left = DeserializeCore(str);
        root->right = DeserializeCore(str);
        return root;
    }
    
    TreeNode* Deserialize(char *str) {
        if(str == NULL)
            return NULL;
        TreeNode *ret = DeserializeCore(&str);
 
        return ret;
    }
    
};