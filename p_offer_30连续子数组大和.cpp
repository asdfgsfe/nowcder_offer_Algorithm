class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
    	int len=array.size();
        int maxSum=0x80000000;
        int curSum=0;
        
        int i;        
        for(i=0; i<len; i++)
        {
						if(curSum <=0)					//如果当前和小于0就应该让他等于下一个值，而不是0；
                curSum = array[i];	//此句在加的前面，可以保证小于0时，让他等于下一个值。
            else
                curSum += array[i];
            if(curSum > maxSum)
                maxSum = curSum;
        }
        return maxSum;
    }
};