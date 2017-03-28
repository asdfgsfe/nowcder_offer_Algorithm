//选酋长问题；一般循环链表实现循环队列
//或者用数组实现循环队列
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {	if(n<=0)
        	return -1;
        
      int r=0;
     	int i;
        for(i=1; i<=n; i++)//此处i=1和i=2是相同的
        {  
            r=(r+m)%i;            
        }
    	return r;
    }
};