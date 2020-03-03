// Complete the permutationEquation function below.
vector<int> permutationEquation(vector<int> p) {
    int n = p.size();
    int ar[n+1];
    vector<int> y;
    for(int i =0; i < n; i++){
        ar[p[i]] = i+1;
    }
    for(int i =1; i<=n; i++){
        y.push_back(ar[ar[i]]); 
    }
    return y;
}
