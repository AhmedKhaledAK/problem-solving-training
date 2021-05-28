class Solution {
public:
    string largestTimeFromDigits(vector<int>& arr) {
        int max_time = -1;
        
        sort(arr.begin(), arr.end());
        
        do {
            int hrs = arr[0] * 10 + arr[1];
            int minutes = arr[2] * 10 + arr[3];
            
            if (hrs < 24 && minutes < 60) {
                int new_time = hrs * 60 + minutes;
                max_time = new_time > max_time ? new_time : max_time;
            }
        } while(next_permutation(arr.begin(), arr.end()));
        
        if (max_time == -1) return "";
        else {
            std::ostringstream strstream;
            strstream << std::setw(2) << std::setfill('0') << max_time / 60
               << ":" << std::setw(2) << std::setfill('0') << max_time % 60;
            return strstream.str();
        }
    }
};
