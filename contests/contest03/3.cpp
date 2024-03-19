std::string common_suffix(const std::string& a, const std::string& b) {
    std::string c = "";
    int i = a.length() - 1;   
    int j = b.length() - 1;

    while (i >= 0 && j >= 0) {
        if (a[i] == b[j]) {
            c += a[i];
        }
    	else {
            break;
        }
        i--;
        j--;
    }
    	
    int start = 0;
    int end = c.length() - 1;
    while (start < end) {
        char temp = c[start];
        c[start] = c[end];
        c[end] = temp;
        start++;
        end--;
    }

    return c;
}