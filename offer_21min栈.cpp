class Solution {
public:    
    void push(int value) {
        data_s.push(value);
        
        if(min_s.size()==0 || value<min_s.top()) //此处必须先判断栈是否为空 然后操作栈
         	min_s.push(value);  
    }
    void pop() {
        if(data_s.size()>0 && min_s.size()>0)
        {    
        	if(data_s.top()==min_s.top())
            	min_s.pop();
           data_s.pop();
        }
    }
    int top() {
    	return data_s.top();
    }
    int min() {
        return min_s.top();
    }
private:
	stack<int> data_s;
  	stack<int> min_s;
};