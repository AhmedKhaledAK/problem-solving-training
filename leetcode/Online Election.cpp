class TopVotedCandidate {
    vector<int> leaders;
    vector<int> times;
public:
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
        this->times = times;
        // vectors votes holds the number of votes for each person. remember that 0 <= persons[i] < person.size
        vector<int> votes(persons.size(), 0);
        int leader = 0;
        for (int i = 0; i < persons.size(); i++) {
            int person = persons[i];
            votes[person]++;
            // whenever we find a person whose votes exceed the current leader, we replace the leader
            // the = sign is for taking the most recent vote
            if (votes[person] >= votes[leader]) {
                leader = person;
            }
            leaders.push_back(leader);
        }
    }
    
    int q(int t) {
        // lower_bound search for the first item not less than t
        int idx = lower_bound(times.begin(), times.end(), t) - times.begin();
        // if the item is not found, vector size is returned -- so we need to handle this case
        if (idx >= times.size()) {
            return leaders.back();
        }
        // if lower_bound returned the first item that is not less than t, then if this item is greater than t
        // -- we know for sure that idx-- is either less than or equal to t (because this is binary search)
        if (times[idx] > t)
            idx--;
        return leaders[idx];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
