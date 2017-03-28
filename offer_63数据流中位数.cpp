class Solution {
public:
    void Insert(int num)
    {
        if(((max.size()+min.size()) & 1)==0)
        {
            if(max.size()>0 && num<max[0])
            {
                max.push_back(num);
            	push_heap(max.begin(), max.end(), less<int>());
            
           		num=max[0];
				pop_heap(max.begin(), max.end(), less<int>());
           	 	max.pop_back();
            }
        
        	min.push_back(num);
        	push_heap(min.begin(), min.end(), greater<int>());
        }
        else
            {
            	if(min.size()>0 && num>min[0])
            	{
                    min.push_back(num);
					push_heap(min.begin(), min.end(), greater<int>());
                    
                    num=min[0];
                    pop_heap(min.begin(), min.end(), greater<int>());
                    min.pop_back();
                }
            	max.push_back(num);
            	push_heap(max.begin(), max.end(), less<int>());
        	}
    }

    double GetMedian()
    { 
    	if((max.size() + min.size()) & 1 == 1)
      		return min[0];
        else
            return (double)(min[0] + max[0])/2;//强制转换类型为double很重要
    }
    private:
    	vector<int> max;
    	vector<int> min;
};