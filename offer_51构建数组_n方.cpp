class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	vector<int>array;
        int len=A.size();
        int i, j;
        for(i=0; i<len; i++)
        	array.push_back(1);
        
        for(i=0; i<len; i++)
        {
            for(j=0; j<len; j++)
            {
                int p = A[j];
                if(i==j)
                    p=1;
                array[i] *= p;
            }
        }    
        return array;
    }
};