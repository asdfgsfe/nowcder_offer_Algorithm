class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int res = 0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j)
                if (!bigger(threshold, i, j))
                    ++res;
                else if (rows == 1 || cols == 1)
                    return res;
        return res;
    }
    bool bigger(int num, int m, int n) {
        int sum = 0;
        while (m) {
            sum += m % 10;
            m /= 10;
        }
        while (n) {
            sum += n % 10;
            n /= 10;
        }
        return (num < sum);
    }
};