class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        int sz = (int) cells.size();
        vector<int> result(sz);
        int len = (n%14 == 0 ? 14 : n %14);
        for (int j = 0; j < len; j++)
        {
            for (int i = 0; i < sz; i++)
            {
                if (i == 0 || i == sz - 1)
                {
                    result[i] = 0;
                } 
                else 
                {
                    if (cells[i - 1] == cells[i + 1])
                    {
                        result[i] = 1;
                    } 
                    else
                    {
                        result[i] = 0;
                    }
                }
            }
            result.swap(cells);
        }
        return cells;
    }
};
