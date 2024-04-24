/*! \file       main.cpp
 *  \author     Sergey Shershakov
 *  \version    1.0
 *  \date       18.04.2022
 *
 *  Exam. Main module.
 *  It's for your reference only (consider tests)! Do not upload it as a solution!
 *  Your submission MUST NOT contain the main() function inside.
 */

#include <fstream>
#include <iostream>
#include <stdexcept>
#include <cassert>

// here we include your solution
#include "solution.h"


// TODO: put the full path to the given file dishes.txt in your system!!!
const char* CSV_FILE_NAME = "/Users/pavelpopov/Downloads/Test2-main/data/dishes.txt";

// reads a file and fills up a collection of ingredients and a collection of dishes
void test1()
{
    std::ifstream inpFile(CSV_FILE_NAME);
    if(!inpFile.is_open())
        throw std::runtime_error("Can't open file");

    // reading ingredients
    Ingredients ingredients = readIngredients(inpFile);
    assert(ingredients.size() == 8);

    auto it = ingredients.find("Potato");
    assert(it != ingredients.end());
    assert(it->second == 142);

    // reading dishes
    Dishes dishes = readDishes(inpFile);

    int a = 0;
}

// outputs a dish only in a stream
void test2()
{
    std::ifstream inpFile(CSV_FILE_NAME);
    if(!inpFile.is_open())
        throw std::runtime_error("Can't open file");

    Ingredients ingredients = readIngredients(inpFile);
    Dishes dishes = readDishes(inpFile);

    std::cout << dishes[0] << "\n\n";

    // the following is an example of printing of a collection of dishes
    std::cout << dishes;

}

// outputs a dish and its calories in a stream
void test3()
{
    std::ifstream inpFile(CSV_FILE_NAME);
    if(!inpFile.is_open())
        throw std::runtime_error("Can't open file");

    Ingredients ingredients = readIngredients(inpFile);
    Dishes dishes = readDishes(inpFile);

    std::cout << dishes[0];
    std::cout << "; " << calcCalories(dishes[0], ingredients) << "\n\n";
}

// outputs a vector of dishes and their calories in a stream
void test4()
{
    std::cout << "\n\n";
    std::ifstream inpFile(CSV_FILE_NAME);
    if(!inpFile.is_open())
        throw std::runtime_error("Can't open file");

    Ingredients ingredients = readIngredients(inpFile);
    Dishes dishes = readDishes(inpFile);

    DishesIngredients di {dishes, ingredients};
    std::cout << di;
}

// sorts and output
void test5()
{
    std::cout << "\n\n";
    std::ifstream inpFile(CSV_FILE_NAME);
    if(!inpFile.is_open())
        throw std::runtime_error("Can't open file");

    Ingredients ingredients = readIngredients(inpFile);
    Dishes dishes = readDishes(inpFile);

    DishesIngredients di {dishes, ingredients};
    sortDishesByCalories(di);
    std::cout << di;
}


int main()
{
    // test1();
    // test2();
    // test3();
    // test4();
    test5();

    return 0;
}
