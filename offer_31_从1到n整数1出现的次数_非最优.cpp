//巧妙的利用格式化函数sprintf(strNum, "%d", i) i为整数;
//直接做出来 每个数字的统计
public:
    int clcOfOneNum(char *str)
    {
        int numOfOne=0;
        int len=strlen(str);
        int i;
        for(i=0; i<len; i++)
        {
            if(str[i] == '1')
               numOfOne++; 
        }    
        return numOfOne;
    }
    
    int NumberOf1Between1AndN_Solution(int n)
    {
    	int numOfOne=0;
        int i;
        char strNum[21]={0};
        for(i=1; i<=n; i++)
        {
            sprintf(strNum, "%d", i);
             numOfOne += clcOfOneNum(strNum);          
        } 
        
        return numOfOne;
    }
};