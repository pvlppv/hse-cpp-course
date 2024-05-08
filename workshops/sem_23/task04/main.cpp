
// Вам дан словарь, состоящий из пар слов. 
// Каждое слово является синонимом к парному ему слову. 
// Все слова в словаре различны. Для каждого данного слова 
// определите его синоним.
// Для решения данной задачи используйте STL
// Формат ввода
// Программа получает на вход количество пар синонимов N (0 ≤ N ≤ 105). 
// Далее следует N строк, каждая строка содержит ровно два слова-синонима.
// Затем идет число Q (1 ≤ Q ≤ 105) — количество запросов к словарю. 
// Далее на каждой следующей из Q строк идет слово, к которому надо вывести
// синоним.
// Формат вывода
// Программа должна вывести синонимы к данным слову на отдельных строках.
// Пример
// Ввод Скопировать ввод	Вывод Скопировать вывод
// 3
// car plane
// mouse cat
// base stream
// 3
// plane
// stream
// base
// car
// base
// stream
#include <unordered_map>
#include <string>
#include <iostream>
#include <exception>
#include <string>


int main() {
    int n;
    std::cin >> n;

    std::unordered_map<std::string, std::string> dictionary;
    for (int i = 0; i < n; ++i) {
        std::string word1, word2;
        std::cin >> word1 >> word2;
        dictionary[word1] = word2;
        dictionary[word2] = word1;
    }

    int q;
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        std::string word;
        std::cin >> word;
        auto it = dictionary.find(word);
        if (it != dictionary.end()) {
            std::cout << it->second << std::endl;
        } else {
            std::cout << "eh" << std::endl;
        }
    }

    return 0;
}

