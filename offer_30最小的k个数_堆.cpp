#define leftChild(i) (2*(i)+1)
class Solution {
public:
    void percDown(vector<int> &a, int i, int n)
    {
        int child = leftChild(i);
        int tmp;
        for(tmp=a[i]; leftChild(i)<n; i=child)
        {
            child=leftChild(i);
            if(child != n-1 && a[child+1]>a[child])
                child++;
            if(tmp<a[child])
                a[i]=a[child];
            else
                break;
        }
        a[i]=tmp;
    }    
    
    void swap(int *a, int *b)
    {
        int tmp=*a;
        *a=*b;
        *b=tmp;
    }    
    
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> ret;
        
        int len = input.size();
        if(len<=0 || k<=0 || k>len)//注意边界条件的判断 若k大于输入数组的长度
            return ret;
        int i;
        for(i=k/2; i>=0; i--)
        	percDown(input, i, k);
        
        for(i=k; i<len; i++)
        {
            if(input[0] > input[i])
            {    
                swap(&input[0], &input[i]);
             	percDown(input, 0, k);   
            }
        }
        
        for(i=0; i<k; i++)
            ret.push_back(input[i]);
        
        return ret;
    }
};