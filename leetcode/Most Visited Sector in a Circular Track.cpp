class Solution {
public:
    vector<int> mostVisited(int n, vector<int>& rounds) {
        int m = rounds.size();
        int startSector = rounds[0];
        int endSector = rounds[m - 1];
        vector<int> res;
        if (startSector == endSector) 
        {
            res.push_back(startSector);
        }
        else if (startSector <  endSector)
        {
            for (int i = startSector; i <= endSector; i++)
            {
                res.push_back(i);
            }
        }
        else 
        {
            for (int i = 1; i <= endSector; i++)
            {
                res.push_back(i);
            }
            for (int i = startSector; i <= n; i++)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
