class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
    	int len=numbers.size();
        if(len<=0)
            return 0;
        
		int max=numbers[0];
        int min=numbers[0];
        int i;
        for(i=0; i<len; i++)
        {
            if(numbers[i]>max)
                max=numbers[i];
            if(numbers[i]<min)
                min=numbers[i];
        }
            
        int *hash = (int *)malloc(sizeof(int)*(max-min+1));
        //for(i=0; i<len; i++)//为什么不能给数组赋值 与编译器有关
        //hash[i]=0;
        memset(hash, 0, sizeof(int)*(max-min+1));
        for(i=0; i<len; i++)
        {
            hash[numbers[i]-min]++;
        	if(hash[numbers[i]-min] > len/2)
                return numbers[i];
        }
        return 0;
    }
};