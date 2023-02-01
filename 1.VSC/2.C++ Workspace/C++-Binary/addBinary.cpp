string addBinary(string a, string b) {
    string res="";
    int carry = 0,i = a.size()-1,j = b.size()-1;
    while(i>=0 || j>=0 || carry!=0){
        int m = i<0 ? 0 : a[i--] - '0';
        int n = j<0 ? 0 : b[j--] - '0';
        res += (m+n+carry)%2 + '0';
        carry = (m+n+carry)/2;
    }
    reverse(res.begin(),res.end());
    return res;
}

