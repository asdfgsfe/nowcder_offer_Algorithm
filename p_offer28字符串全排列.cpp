class Solution {
public:
    void PermutationCore(char *pStr, char *pBegin, vector<string> &result)
    {
        if(*pBegin == '\0')
        {
            result.push_back(str);
            return ;
        }    
        else
        {
            for(char *pCh = pBegin; *pCh != '\0'; pCh++)
            {
                char tmp = *pCh;
                *pCh = *pBegin;
                *pBegin = tmp;
                
                PermutationCore(str, pBegin+1);
                
                tmp = *pCh;
                *pCh = *pBegin;
                *pBegin = tmp;
            }
        }    
    }
    
    
    vector<string> Permutation(string str) {
        vector<string> result;
        int len=str.size();
        if(len==0)
            return result;
        char *pStr = str.data();
        
       	PermutationCore(pStr, pStr, result);
    }
};