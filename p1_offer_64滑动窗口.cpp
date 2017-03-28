class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
    	vector<int> maxArray;
      std::deque<int> winDque;
    	
    	int i;
    	for(i=0; i<(int)num.size(); i++)
      {
      	//�Ӻ������ε��������бȵ�ǰnumֵС��Ԫ�أ�
      	//ͬʱҲ�ܱ�֤������Ԫ��Ϊ��ǰ�������ֵ�±�
      	while(winDque.size() && num[winDque.back()] <= num[i])
      		winDque.pop_back();
      		
      	//����ǰ�����Ƴ�����Ԫ�����ڵ�λ�ã�������Ԫ�������Ӧ��num���ڴ����У���Ҫ����	
      	while(winDque.size() && i-winDque.front()+1 > size)
      		winDque.pop_front();
      		
      	//��ÿ�λ�����num�±�������	
      	winDque.push_back(i);
      	
      	//�����������׵�ַi���ڵ���sizeʱ�ſ�ʼд�봰�����ֵ
      	if(size && i+1>=size) 
      		maxArray.push_back(num[winDque.front()]);
      }   
      return maxArray;
    }
};