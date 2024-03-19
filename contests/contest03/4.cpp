std::string join(const std::vector<std::string>& tokens, char delimiter) {
    std::string a = "";

    for (int i = 0; i < tokens.size(); i++) {
        if (i == tokens.size() - 1) {
            a += tokens[i];
        } 
        else {
            a += tokens[i] + delimiter;
        }
    }

    return a;
}