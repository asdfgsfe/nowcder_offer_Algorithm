class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int len=numbers.size();
        if(len<=0)
            return 0;
        
		int result=numbers[0];
        int times=1;
        
        int i;
        for(i=1; i<len; i++)
        {
            if(times==0)//此处必须先判断是否为0
            {
                times=1;
                result=numbers[i];
            }
            else if(result==numbers[i])
            	times++;
            else
				times--;    
        }   
        int num=0;
        for(i=0; i<len; i++)//结束时间必须判断结构是否为超过一般的数字，
        											//有可能出现次数最多的，但没有超过一般
        {
            if(numbers[i]==result)
            	num++;
        }    
        if(num > len/2)
        	return result;
        
 		return 0;
    }
};