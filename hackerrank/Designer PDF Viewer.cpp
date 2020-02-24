int designerPdfViewer(vector<int> h, string word) {

    int height=0;
    for(int i = 0; i < word.size(); i++){
        if(h[word[i]-97] > height) height=h[word[i]-97];
    }
    return height*word.size();
}
