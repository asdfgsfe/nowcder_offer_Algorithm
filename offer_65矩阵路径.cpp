class Solution {
public:  
    
    bool hashPathCore(char* matrix, int rows, int cols, int row,
                     int col, char* str, int &strCurPos, bool *visited)
    {
        if(str[strCurPos] == '\0')
            return true;
        
        bool res=false;
        if(row>=0 && row<rows && col>=0 && col<cols
           && matrix[row*cols + col] == str[strCurPos] 
           && !visited[row*cols + col])
        {
            ++strCurPos;
             visited[row*cols + col]=true;
            
       		res = hashPathCore(matrix, rows, cols, row, col+1, str,strCurPos, visited)
                || hashPathCore(matrix, rows, cols, row, col-1, str,strCurPos, visited)
                || hashPathCore(matrix, rows, cols, row-1, col, str,strCurPos, visited)
                || hashPathCore(matrix, rows, cols, row+1, col, str,strCurPos, visited);
        
        	if(!res)
        	{
            	--strCurPos;
            	visited[row*cols + col]=false;
        	}
        }
        return res;
    }
    
    bool hasPath(char* matrix, int rows, int cols, char* str)
    {
    	bool *visited = new bool[rows*cols];
        int i;
        for(i=0; i< rows*cols; i++)
        	visited[i]=false;
        
        int row, col;
        int strCurPos=0;
        for(row=0; row<rows; row++)
        {  
            for(col=0; col<cols; col++)
         	{
                if(hashPathCore(matrix, rows, cols, 
                            row, col, str, strCurPos, visited))
                    return true;
            }
        }   
        
        delete[] visited;
        return false;
    }
};