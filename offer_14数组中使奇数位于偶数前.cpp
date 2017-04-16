class Solution {
public:
    void reverse(vector<int> &array, int left, int right)
	{
	while (left < right)
	{
		int tmp = array[left];
		array[left] = array[right];
		array[right] = tmp;
		left++;
		right--;
	}
}
    
    void reOrderArray(vector<int> &array) {
        int len = array.size();
        if(len<=0)
            return ;
        
        int i, p, tmp;
        for(p=1; p<len; p++)
        {
            tmp=array[p];
            for(i=p; i>0 && ((array[i-1]&1)==0); i--)
           		array[i]=array[i-1];	
            array[i]=tmp;
        }
        for (i = 0; i < len; i++)
		{
			if((array[i]&1) == 0)
			{
				reverse(array, i, len-1);
				break;
			}
		}
    }
};