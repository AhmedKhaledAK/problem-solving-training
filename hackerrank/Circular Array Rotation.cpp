int getidx(int k, int n){
    while(k < 0) {
        k += n;
    }
    return k % n;
}

// Complete the circularArrayRotation function below.
vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {

    int n = a.size();
    int ar[n];

    for(int i=0; i<n; i++) {
        ar[i] = a[getidx(i-k+n,n)];
    }
    
    for(int i =0; i < queries.size(); i++){
        queries[i] = ar[queries[i]];
    }
    return queries;
}
