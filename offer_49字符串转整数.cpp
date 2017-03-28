class Solution {
public:
    int StrToInt(string str) {
        int ret=0;
        int len=str.size();
       	int i;
        for(i=0; i<len; i++)
        {
            if((str[i]=='+' || str[i]=='-') && (i==0))
				continue; 
        	if(!(str[i]>='0' && str[i]<='9'))
            	return 0;
            ret=ret*10+str[i]-'0';
        }
        
        if(str[0]=='-')
            ret = -ret;
        
        return ret;
    }
};