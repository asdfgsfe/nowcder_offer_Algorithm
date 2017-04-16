class Solution {
public:
    typedef struct data
    {
        int index=-1;
        int num=0;
        
    }data_t;
    
    int FirstNotRepeatingChar(string str) {
        int len = str.size();
        if(len<=0)
            return -1;
        
        data_t data[270];
        memset(data, 0, sizeof(data));
        
        int i;
        for(i=0; i<len; i++)
        {
            data[str[i]].num++;
            data[str[i]].index=i;
        }    
        
        int firstId=10000;
        for(i=0; i<270; i++)
        {
            if(data[i].num==1 && data[i].index<firstId)
                firstId=data[i].index;
        }
        
        return firstId;
    }
};