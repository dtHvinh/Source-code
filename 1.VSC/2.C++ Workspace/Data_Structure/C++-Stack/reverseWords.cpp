string reverseWords(string s) {
    stack<char>st;
    string res="";
    for(auto i:s){
        if(i!=' '){
            st.push(i);
        }
        else{
            while(!st.empty()){
                res += st.top();
                st.pop();
            }
            res += ' ';
        }
    }
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    return res;
}
// cach 2 su dung ham reverse //
string reverseWords(string s) {
    int j=0;
    for(int i=0 ; s[i]!='\0' ; i++){
        if(s[i] == ' '){
            reverse(s.begin()+j , s.begin()+i);     // s.begin() s.end() la 2 con tro
            j = i+1;
        }
    }
    reverse(s.begin()+j , s.end());
    return s;
}