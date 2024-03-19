std::string ExtractDigits(const std::string& s) {
	std::string a = "";
	for (int i = 0; i < s.size(); i++) {
    	if (std::isdigit(s[i])) {
        	a += s[i];
        }
    }
    
    return a;
}