class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.size() != popV.size())
            return false;
        
        std::stack<int> sv;
        
        int len=pushV.size();
        int i, j;
        for(i=0, j=0; i<len && j<len; i++)
        {
            sv.push(pushV[i]);
            if(sv.top() == popV[j])
             {
                sv.pop();
                j++;
             }
        }
        
        while(!sv.empty() && j<len)
        {
            if(sv.top() == popV[j])
            {
                sv.pop();
                j++;
            }
            else
                break;
        } 
        
        if(!sv.empty())
            return false;
        return true;
    }
};