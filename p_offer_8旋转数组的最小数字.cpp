class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        int len = rotateArray.size();
        if(len<=0)
            return 0;
        
        int left=0;
        int right=len-1;
        int center;
        while(rotateArray[left]>=rotateArray[right])
        {
			if(right-left == 1)
            {
                center = right;
                break;
            }    
            
            center=(left+right)/2;
            if(rotateArray[center] >= rotateArray[left])
                left=center;
            else if(rotateArray[center] <= rotateArray[right])
            	right = center;

        }
        return rotateArray[center];
    }
};