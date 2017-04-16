class Solution {
public:
    void merge(vector<int> data, int lPos, int rPos, int rightEnd, 
               vector<int>tmpData, int *num)
    {    
		int leftEnd=rPos-1;
        while(lPos<=leftEnd && rPos<=rightEnd)
        {
            if(data[lPos]>data[rPos])
            {
                tmpData.push_back(data[rPos]);
                rPos++;
                num++;
            }    
            else
            {
               tmpData.push_back(data[lPos]);
                lPos++;
            }    
        } 
        
        while(lPos<=leftEnd)
        {
            tmpData.push_back(data[lPos]);
            lPos++;
        }
        
        while(rPos<=rightEnd)
        {
            tmpData.push_back(data[rPos]);
            rPos++;
        }
    }
    
    void InversePairsCore(vector<int>data, int left, int right, int *num,
         vector<int> tmpData)    
    {
        int center;
        if(left<right)
		{   
        	center=(right-left)/2;
			InversePairsCore(data,left, center, num, tmpData);
        	InversePairsCore(data,center+1, right, num, tmpData);
        	merge(data, left, center, right, tmpData, num);
        }
    }
    
    
    int InversePairs(vector<int> data) {
        int num=0;
        int len=data.size();
        vector<int> tmpData;
        
        InversePairsCore(data, 0, len-1, &num, tmpData);
        return  num%1000000007;
        
    }
};