class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int len=array.size();
        int maxSum=0x80000000;
        int curSum=0;
        
        int i;        
        for(i=0; i<len; i++)
        {
						if(curSum <=0)					//�����ǰ��С��0��Ӧ������������һ��ֵ��������0��
                curSum = array[i];	//�˾��ڼӵ�ǰ�棬���Ա�֤С��0ʱ������������һ��ֵ��
            else
                curSum += array[i];
            if(curSum > maxSum)
                maxSum = curSum;
        }
        return maxSum;
    }
};