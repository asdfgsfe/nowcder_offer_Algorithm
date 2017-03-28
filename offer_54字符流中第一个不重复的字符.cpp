class Solution
{
public:
    Solution()
    {
        int i;
        for(i=0; i<256; i++)
            stream[i]=-1;
        index=0;
    }    
  //Insert one char from stringstream
    void Insert(char ch)
    {
    	if(stream[ch]==-1)
        	stream[ch]=index;
        else if(stream[ch]>=0)
        	stream[ch]=-2;
            
       	index++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
    	char ch = '\0';
        int minIndex=numeric_limits<int>::max();//找出最大的整数等价于~(1<<31)
        int i;
        for(i=0; i<256; i++)
        {
            if(stream[i]>=0 && stream[i]<minIndex)
            {
                ch=(char)i;
                minIndex=stream[i];
            }    
        } 
        if(ch=='\0')
            return '#';
        return ch;
    }
private:
    int stream[256];
    int index;
};