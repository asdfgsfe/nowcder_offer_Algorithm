class Solution {
public:
    string LeftRotateString(string str, int n) {
        char tmp[100]={0};
        int len=str.size();
        int i;
        for(i=0; i<n; i++)
            tmp[i]=str[i];
        
        int j;
        for(j=0; i<len; i++)
        	str[j++]=str[i];
        for(i=0; i<n; i++)
            str[j++]=tmp[i];
        
        return str;
    }
};