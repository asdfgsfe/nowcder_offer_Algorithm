//距离最远的两个数字就是乘积最小的那个
class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> ret;
        int i;
        int j=array.size()-1;
        for(i=0; i<j;)
        {
            if(array[i]+array[j] > sum)
                j--;
         	else if(array[i]+array[j] < sum)
                i++;
            else if(array[i]+array[j] == sum)
            {    
                    ret.push_back(array[i]);
                	ret.push_back(array[j]);
                    break;
            }
        }
        return ret;
        
    }
};