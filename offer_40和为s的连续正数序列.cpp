
//������õ��㷨 �ӽ�o��3��
class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> ret;
        vector<int> tmp;
        if(sum<=2)
            return ret;
        int i;
        int j;
  		int s;
        for(i=1; i<=sum; i++)
        {
            s=sum;
            for(j=i; j<=sum; j++)
            {
            	s = s-j;    
                if(s==0 && (j-i)>0)
                {    
                 int k;
                 for(k=i; k<=j; k++)
                     tmp.push_back(k);
                 ret.push_back(tmp);
                 tmp.clear();   
                 break;
                }
            }
            
        }
        return ret;
    }
};