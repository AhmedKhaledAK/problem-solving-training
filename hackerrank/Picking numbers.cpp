int pickingNumbers(vector<int> a) {

    sort(a.begin(), a.end());
    vector<int> sizes;
    int mn = a[0], size=0;

    for(int i =0; i < a.size(); i++){
        if(abs(a[i]-mn) <=1) size++;
        else {
            sizes.push_back(size);
            size=1;
            mn=a[i];
        }
    }
    sizes.push_back(size);

    sort(sizes.begin(), sizes.end());
    return sizes[sizes.size()-1];
}

