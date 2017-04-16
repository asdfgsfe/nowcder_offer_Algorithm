//不是最优解o(n)解法
class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int len=data.size();
        int left=0;
        int right=len-1;
        int center;
        int kIndex=-1;
        
        while(left<right)
        {
            center=(left+right)/2;
            if(data[center]<k)
                left=center+1;
            else if(data[center]>k)
                right=center-1;
            else 
            {    
                kIndex=center;  
                break;
            }
        }
        int times=0;
        int i=kIndex;
        while(data[i]==k && i<len)
        {
            ++times;
            ++i;
        }    
        
       	i=kIndex;
        while(data[i]==k && i>=0)
        {
            ++times;
            --i;
        }
        return times-1;
    }
};