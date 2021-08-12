class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        unordered_map<string, int> namesMap;
        unordered_set<string> namesSet;
        vector<string> result;
        for (string name : names) {
            if (namesSet.find(name) == namesSet.end())
            {
                namesSet.insert(name);
                namesMap[name] = 0;
                result.push_back(name);
            } else {
                int k = namesMap[name];
                k++;
                string newName = name + "(" + to_string(k) + ")";
                while (namesMap.find(newName) != namesMap.end())
                {
                    k++;
                    newName = name + "(" + to_string(k) + ")";
                }
                namesSet.insert(newName);
                namesMap[newName] = 0;
                namesMap[name] = k;
                result.push_back(newName);
            }
        }
        return result;
    }
};