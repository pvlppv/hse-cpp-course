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

