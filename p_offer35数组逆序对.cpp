class Solution {
public:
    int InversePairsCore(vector<int>data, int *tmpData, int start, int end)
    {
   		if(start==end)
        {
        	tmpData[start]=data[start];
            return 0;
        }    
        
        int length=(end-start)/2;
        int left=InversePairsCore(data, tmpData, start, start+length);
        int right=InversePairsCore(data, tmpData, start+length+1, end);
        
        int i=start+length;
        int j=end;
        int tmpPos=end;
        int count=0;
        
        while(i>=start && j>=start+length+1)
        {
            if(data[i]>data[j])
            {    
                tmpData[tmpPos--]=data[i--];
            	count += j-start-length;
            }
            else
                tmpData[tmpPos--]=data[j--];
        }
        
        for(;i>=start; i--)
			tmpData[tmpPos--]=data[i];
        for(;j>=start+length+1; j--)
        	tmpData[tmpPos--]=data[j];
        
        return left+right+count;
    }    
    
    int InversePairs(vector<int> data) {
        int len=data.size();
        int *tmpData = new int[len];
        int i;
        for(i=0; i<len; i++)
            tmpData[i]=data[i];
        
        num = InversePairsCore(data, tmpData, 0, len-1);
        delete[] tmpData;
        
        return  num%1000000007;
    }
};