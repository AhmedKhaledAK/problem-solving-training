class Solution {
public:
    string predictPartyVictory(string senate) {
        int radiantToDie, direToDie, radiantAlive, direAlive;
        radiantToDie = direToDie = radiantAlive = direAlive = 0;
        vector<char> senators;
        for (char c : senate)
        {
            if (c == 'R')
                radiantAlive++;
            else 
                direAlive++;
            senators.push_back(c);
        }
        int idx = 0;
        while(radiantAlive > 0 && direAlive > 0)
        {
            if (idx > senate.size() - 1)
                idx = 0;
            if (senators[idx] == 'X')
            {
                idx++;
                continue;
            }
            if (senators[idx] == 'R')
            {
                if (radiantToDie > 0)
                {
                    senators[idx] = 'X';
                    radiantToDie--;
                    radiantAlive--;
                }
                else
                {
                    direToDie++;
                }
            } 
            else 
            {
                if (direToDie > 0)
                {
                    senators[idx] = 'X';
                    direToDie--;
                    direAlive--;
                }
                else
                {
                    radiantToDie++;
                }
            }
            idx++;
        }
        return radiantAlive > 0 ? "Radiant" : "Dire";
    }
};
