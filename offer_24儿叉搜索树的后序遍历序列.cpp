class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
		int len = sequence.size();
        if(len<=0)
            return false;
        
        int i;
        int rootNode=sequence[len-1];
        for(i=0; i<len-1; i++)
        {
            if(sequence[i] > rootNode)
            	break;
        }
        
        for(; i<len-1; i++)
        {
            if(sequence[i] < rootNode)
            	break;
        }
        
        if(i == len-1)
            return true;
        
        return false;
    }
};