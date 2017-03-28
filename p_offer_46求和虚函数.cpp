class A;
A *Array[2];

class A
{
public:
    virtual unsigned int sum (unsigned int n)
	{
        return 0;
    }    
};
class B:public A
{
public:
	virtual unsigned int sum(unsigned int n)
	{
    	return Array[!!n]->sum(n-1)+n;
    }
};

class Solution {
public:    
    int Sum_Solution(int n) {
		A a;
        B b;
        Array[0]=&a;
        Array[1]=&b;
        int value = Array[1]->sum(n);
        
        return value;
    }
};