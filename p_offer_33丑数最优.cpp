class Solution {
public:
    int min(int num1, int num2, int num3)
    {
		int min = (num1<num2) ? num1:num2;
        min = (min<num3)? min:num3;
        return min;
    }    
    
    int GetUglyNumber_Solution(int index) {
        if(index<=0)
            return 0;
        
        int *pUglyNum = new int[index];
        pUglyNum[0]=1;
        int nextUglyId=1;
        
        int *pMut2=pUglyNum;
        int *pMut3=pUglyNum;
        int *pMut5=pUglyNum;
        
        while(nextUglyId < index)
        {
            int minNum = min(*pMut2*2, *pMut3*3, *pMut5*5);
            pUglyNum[nextUglyId]=minNum;
            
            while(*pMut2*2 <= pUglyNum[nextUglyId])
                pMut2++;
             while(*pMut3*3<= pUglyNum[nextUglyId])
                pMut3++;
             while(*pMut5*5<= pUglyNum[nextUglyId])
                pMut5++;
            
            nextUglyId++;
        }
        
        int ugly = pUglyNum[nextUglyId-1];
        delete[] pUglyNum;
        return ugly;
    }
};