// sstream
std::string line;
std::getline(fileStream, line);
std::stringstream ss(line);
std::string field;
std::getline(ss, field, ';');


// custom comparator
bool comparePeople(const Person& a, const Person& b)
{
    return a.age < b.age;
}
std::sort(people.begin(), people.end(), comparePeople);


// file i/o
std::ifstream inputFile("input.txt");
std::string line;
while (std::getline(inputFile, line)) {
    cout << line << endl;
}
char c;
while (infile.get(c)) {
    cout << c;
}
inputFile.close();

std::ofstream outputFile("output.txt");
outputFile << "Hello, world!" << endl;
outputFile.close();


// prime number check
bool is_prime(int n) {
    int i, flag = 1;
    for (i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            flag = 0;
            break;
        }
    }
    if (n <= 1)
        flag = 0;
    if (flag) return true;
    else return false;
}


// replace
std::string replace(std::string str, std::string old_string, std::string new_string) {
    int len_old = old_string.length();
    std::string ans;
    int index = 0;
    while (index < str.length()) {
        if (str.substr(index, len_old) == old_string) {
            ans += new_string;
            index = index + len_old;
        }
        else {
            ans += str[index];
            index++;
        }
    }
    return ans;
}


// count words in line
int count_words(std::string text) {
    int words = 0;
    for (char c : text) {
        if (c == ' '){
            words++;
        }
    }
    words++;
    return words;
}


// palindrome check
bool is_palindrome(std::string str) {
    std::string no_spaces = "";
    std::string reversed_string = "";
    for (char c : str) {
        if (c != ' ') {
            no_spaces += c;
        }
    }
    for (int i = no_spaces.length() - 1; i >= 0; i--) {
        reversed_string += no_spaces[i];
    }
    if (no_spaces == reversed_string) return true;
    else return false;
}


// reverse
std::string reverse_string(std::string str){
    std::string ans;
    for (int i = str.length() - 1; i >= 0; i--) {
        ans += str[i];
    }

    return ans;
}


// split line by char
std::vector<std::string> split(std::string str, char separator) {
    std::vector<std::string> ans;
    int index_start = 0;
    int length = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == separator) {
            ans.push_back(str.substr(index_start, length - 1));
            index_start = i + 1;
            length = 0;
        }
        length += 1;
    }
    ans.push_back(str.substr(index_start));
    return ans;
}


// join by char
std::string join(std::vector<std::string> vec, char sep) {
    std::string res;
    for (int i = 0; i < vec.size(); i++) {
        if (i == vec.size() - 1) {
            res += vec[i];
        } else res += vec[i] + sep;
    }
    return res;
}


// read file by line
std::string read_file(std::string file_path) {
    std::string text;
    std::ifstream in(file_path);
    if (in.is_open())
    {
        std::stringstream buff;
        buff << in.rdbuf();
        text = buff.str();
    }
    in.close();
    return text;
}


// copy file to another
void copyFile(const std::string& sourceFilePath, const std::string& destinationFilePath){
    std::string line;
    std::ifstream in(sourceFilePath);
    if (in.is_open())
    {
        std::ofstream out;
        out.open(destinationFilePath);
        if (out.is_open())
        {
            while (std::getline(in, line))
            {
                out << line << '\n';
            }
        }
    }
    in.close();
}


// delete empty lines from file
void remove_blank_lines(std::string inp, std::string outp) {
    std::string line;
    std::fstream in(inp);
    if (in.is_open()) {
        std::ofstream out;
        out.open(outp);
        if (out.is_open()) {
            while (std::getline(in, line)) {
                if (!line.empty()) out << line << '\n';
            }
        }
        out.close();
    }

    in.close();
}


// add text to the end of file
void appendToFile(const std::string& filePath, const std::string& content) {
    std::ofstream out(filePath, std::ios::app);
    if (out.is_open()) {
        out << content;
    }
    out.close();
};


// write matrix to file
void write_matrix(std::vector<std::vector<int>> matrix, char sep, std::string file_path) {
    std::ofstream out;
    out.open(file_path);
    if (out.is_open()) {
        int rows = matrix.size();
        int cols = matrix[0].size();


        for (int i = 0; i < rows; i++) {
            std::vector<int> row = matrix[i];
            for (int j = 0; j < cols; j++) {
                out << row[j] << sep;
            }
            out << '\n';
        }
    } else std::cerr << "Something went wrong";
}


// enter array with certain size
std::vector<int> input_array(int size){
    std::vector<int> ans;
    int n;
    for (int i = 0; i < size; i++) {
        std::cin >> n;
        ans.push_back(n);
    }
    return ans;
}


// output array with delimiter
void print_array(std::vector<int> v, char sep){
    for (int i = 0; i < v.size(); i++){
        if (i == v.size() - 1) std::cout << v[i];
        else std::cout << v[i] << sep;
    }
    std::cout << '\n';
}


// output matrix with delimiter
void print_matrix(std::vector<std::vector<int>> matrix, char sep){
    int rows = matrix.size();
    int cols = matrix[0].size();

    for (int i = 0; i < rows; i++) {
        std::vector<int> row = matrix[i];
        for (int j = 0; j < cols; j++) {
            std::cout << row[j] << sep;
        }
        std::cout << '\n';
    }
}