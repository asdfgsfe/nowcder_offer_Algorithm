class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
    	int len=A.size();
    	//此处注意，如果定义为vector<int>array；
    	//vecto的大小不知道有可能数组越界，合理应该指出数组大小。
      vector<int>array(len);  
        
        int i;
        array[0]=1;
        for(i=1; i<len; i++)
			array[i]=array[i-1]*A[i-1];
        
       	double tmp=1;
        for(i=len-2; i>=0; i--)
  		{
            tmp *= A[i+1];
			array[i] *= tmp;
        }
        return array;
    }
};