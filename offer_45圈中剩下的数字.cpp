//ѡ�������⣻һ��ѭ������ʵ��ѭ������
//����������ʵ��ѭ������
class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {	if(n<=0)
        	return -1;
        
      int r=0;
     	int i;
        for(i=1; i<=n; i++)//�˴�i=1��i=2����ͬ��
        {  
            r=(r+m)%i;            
        }
    	return r;
    }
};