//�ȷ�תǰn���ַ����ڷ�ת��n���ַ���������巴ת��
class Solution {
public:
    string LeftRotateString(string str, int n) {
			//�˴����Ҫ��תn���ַ�����ֱ��begin��begin+n;
			reverse(str.begin(), str.begin()+n);
			reverse(str.bengin()+n, str.end());
      reverse(str.begin(), str.end());
        
        return str;
    }
};