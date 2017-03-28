//占内存较大12m

class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
		int len=data.size();
        int i;
        int max=data[0];
        int min=data[0];
        for(i=0; i<len; i++)
        {
            if(data[i] < min)
            	min=data[i];
            if(data[i] > max)
            	max=data[i];
        }
        
        int *p=(int*)malloc(sizeof(int)*(max-min+1));
       	memset(p, 0, sizeof(int)*(max-min+1));
        
        for(i=0; i<len; i++)
        	p[data[i]-min]++;
        
        int a[2];
        int j=0;
        for(i=0; i<len; i++)
        {
            if(p[i] == 1)
             a[j++]=i+min;   
        }
        *num1=a[0];
        *num2=a[1];

    }
};