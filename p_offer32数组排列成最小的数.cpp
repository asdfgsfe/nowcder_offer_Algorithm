class Solution {
public:    
 	char *sstr1 = new char[21];
	char *sstr2 = new char[21];  
    
    int compare(const void *str1, const void *str2)
    {
        strcpy(sstr1, *(const char **)str1);
        strcat(sstr1, *(const char **)str2);
        strcpy(sstr2, *(const char **)str2);
        strcat(sstr2, *(const char **)str1);
        
        return strcmp(sstr1, sstr2);
    }
    
    string PrintMinNumber(vector<int> numbers) 
    {
     	int len=numbers.size();
        string ret;
        if(len<0)
            return ret;

        char **strNum = (char **)new int[len];
        int i;
        for(i=0; i<len; i++)
        {
            strNum[i] = new char[11];
            sprintf(strNum[i], "%d", numbers[i]);
        }    
        
        qsort(strNum, len, sizeof(char *), compare);
        
        for(i=0; i<len; i++)
            ret += strNum[i];
        
        return ret;
    }
};