vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
    int j = 1, i = 1;
    for(i =1; i < scores.size(); i++){
        if(scores[i] != scores[i-1]){
            scores[j++] = scores[i];
        }
    }
    int size = scores.size();
    for(i = 0; i < size-j; i++){
        scores.pop_back();
    }
    vector<int> ranks;

    i = 0;
    j = scores.size()-1;
    while(i < alice.size()){
        if(j < 0){
            ranks.push_back(1);
            i++;
            continue;
        }
        if(alice[i] < scores[j]){
            ranks.push_back(j+2);
            i++;
        } else if(alice[i] > scores[j]){
            j--;
        } else {
            ranks.push_back(j+1);
            i++;
        }
    }

    return ranks;
}
