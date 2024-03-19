/*
Humanitarian steps:
1. get M, N and then M words with N-dimensional vectors
2. iterate through each word and calculate its vector product
3. compare a vector product of initial word with other ones and print the closest one

Technical steps:
1. std::cin 
2. for loop each word
3. store each word with its vector as pair in main vector
4. keep initial vector
5. for loop main vector
6. calculate the product of the initial vector and the iterated one
7. update the largest product
8. store all words with the largest vector in words_with_largest_product vector
9. print words with the largest product
*/

#include <iostream>
#include <vector>


int vectorProduct(const std::vector<int>& vector1, const std::vector<int>& vector2)
{
    int result = 0;
    for (size_t i = 0; i < vector1.size(); i++)
    {
        result += vector1[i] * vector2[i];
    }

    return result;
}


int main()
{
    // input
    int M, N;
    std::cin >> M >> N;

    // initial word
    std::string initial_word;
    std::vector<int> initial_vector(N);
    std::cin >> initial_word;
    for (int i = 0; i < N; i++)
    {
        std::cin >> initial_vector[i];
    }

    // other words
    std::vector<std::pair<std::string, std::vector<int>>> main_vector;
    for (int i = 1; i < M; i++)
    {
        std::string word;
        std::cin >> word;
        std::vector<int> vector(N);
        for (int j = 0; j < N; j++)
        {
            std::cin >> vector[j];
        }
        main_vector.push_back({word, vector});
        // or main_vector.push_back(std::make_pair(word, vector));
    }

    // logic
    int largest_product = -1000000;
    std::vector<std::string> words_with_largest_product;
    for (const auto& v: main_vector)
    {
        int product = vectorProduct(initial_vector, v.second);
        if (product > largest_product)
        {
            largest_product = product;
            words_with_largest_product.clear();
            words_with_largest_product.push_back(v.first);
        }
        else if (product == largest_product)
        {
            words_with_largest_product.push_back(v.first);
        }
    }

    for (const auto& v: words_with_largest_product)
    {
        std::cout << v << std::endl;
    }

    return 0;
}
