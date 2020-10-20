class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> first = getVersion(version1);
        vector<int> second = getVersion(version2);
        
        int idx1, idx2;
        idx1 = idx2 = 0;
        
        while (idx1 < first.size() && idx2 < second.size()) {
            if (first[idx1] != second[idx2]) {
                return first[idx1] > second[idx2] ? 1 : -1;
            }
            idx1++;
            idx2++;
        }
        
        while (idx1 < first.size()) {
            if (first[idx1] != 0) {
                return 1;
            }
            idx1++;
        }
        
        while (idx2 < second.size()) {
            if (second[idx2] != 0) {
                return -1;
            }
            idx2++;
        }
        return 0;
    }
    
    vector<int> getVersion(const string & version) {
        vector<int> op;
        int idx, curr;
        idx = curr = 0;
        while (idx < version.size()) {
            if (version[idx] == '.') {
                op.push_back(curr);
                curr = 0;
            } else {
                curr = curr * 10 + (version[idx] - '0');
            }
            idx++;
        }
        op.push_back(curr);
        return op;
    }
    
};
