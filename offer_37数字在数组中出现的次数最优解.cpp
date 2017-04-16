
//×îÓÅ½âlog(n)
class Solution {
public:
    int getFirstKIndex(vector<int>data, int k, int start, int end)
    {
        if(start>end)
            return -1;
        int center=(start+end)/2;
        if(data[center] == k)
		{
            if((center>0 && data[center-1] != k) || center==0)
            	return center;
            else
                end=center-1;
        }        
        else if(data[center] > k)
            end=center-1;
        else
            start=center+1;
        
        return getFirstKIndex(data, k, start, end);
    }
    
    int getEndKIndex(vector<int>data, int k, int start, int end)
    {
        if(start>end)
            return -1;
        int center=(start+end)/2;
        if(data[center] == k)
		{
            if((center<data.size()-1 && data[center+1] != k) || center==data.size()-1)
            	return center;
            else
                end=center-1;
        }        
        else if(data[center] > k)
            end=center-1;
        else
            start=center+1;
        
        return getEndKIndex(data, k, start, end);
    }
    
int GetNumberOfK(vector<int> data, int k) {
	
    int len=data.size();
    if(len==0)
        return -1;
    int first=getFirstKIndex(data, k, 0, data.size()-1);
    int end=getEndKIndex(data, k, 0, data.size()-1);
    
	//if(first>-1 && end<len)
		return first-end+1;
	}
};