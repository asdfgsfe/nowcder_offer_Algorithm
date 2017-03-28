//先反转前n个字符，在反转后n个字符，最后整体反转。
class Solution {
public:
    string LeftRotateString(string str, int n) {
			//此处如果要反转n个字符，则直接begin到begin+n;
			reverse(str.begin(), str.begin()+n);
			reverse(str.bengin()+n, str.end());
      reverse(str.begin(), str.end());
        
        return str;
    }
};