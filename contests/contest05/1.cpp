#include <iostream>
#include <vector>
#include <set>

int main()
{
    // input
    int n;
    int k;
    std::cin >> n >> k;
    std::vector<int> v(n);
    std::multiset<int> m;
    std::vector<int> answers;
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }

    // creating a window from which everything starts
    for (int i = 0; i < k; i++)
    {
        m.insert(v[i]);
    }

    // placing other windows
    for (int i = 0; i < n - k + 1; i++)
    {
        answers.push_back(*m.begin());
        m.erase(m.lower_bound(v[i]));
        m.insert(v[i + k]);
    }

    for (size_t i = 0; i < answers.size(); i++)
    {
        std::cout << answers[i] << std::endl;
    }

    return 0;
}
