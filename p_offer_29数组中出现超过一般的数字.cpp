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
            if(times==0)//�˴��������ж��Ƿ�Ϊ0
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
        for(i=0; i<len; i++)//����ʱ������жϽṹ�Ƿ�Ϊ����һ������֣�
        											//�п��ܳ��ִ������ģ���û�г���һ��
        {
            if(numbers[i]==result)
            	num++;
        }    
        if(num > len/2)
        	return result;
        
 		return 0;
    }
};