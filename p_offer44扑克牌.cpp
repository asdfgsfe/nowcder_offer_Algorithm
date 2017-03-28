//题目中传入的numbers为已经随机选出的5数字

class Solution {
public:
    void insertSort(vector<int>&a, int n)
    {
        int i,p;
        for(p=1; p<n; p++)
        {
            int tmp=a[p];
            for(i=p; i>0 && a[i-1]>tmp; i--)
                a[i]=a[i-1];
            a[i]=tmp;
        }    
    }    
    
    void bubbleSort(vector<int>&a, int n)//对于vector定义的数组，想改变其值必须传引用
    {
        int i, j, tmp;
        for(i=0; i<n; i++)
        {
            for(j=i+1; j<n; j++)
            {
                if(a[i]>a[j])
                {
                    tmp=a[i];
                    a[i]=a[j];
                    a[j]=tmp;
                }    
            }
        }
    }    
    
    bool IsContinuous( vector<int> numbers ) {
        int len=numbers.size();
        if(len<5)
            return false;
    	    
        bubbleSort(numbers, len);
        
        int numbersOfZero=0;
        int numbersOfGap=0;
        
        int i;
        for(i=0; i<len && numbers[i]==0; i++)
            numbersOfZero++;
            
        int small=numbersOfZero;
        int big=small+1;
        while(big < len)
        {
            if(numbers[big] == numbers[small])
                return false;
            
            numbersOfGap += numbers[big]-numbers[small]-1;
            small=big;
            big++;
        }    
        
        return (numbersOfGap>numbersOfZero) ? false:true;
    }
};