/*! \file       solution.h
 *  \author     ---=Put your name here=---
 *  \version    1.0
 *  \date       18.04.2022
 *
 *  Midterm Test. Types aliases and definitions, and function skeletons.
 *
 *      → Provide your solution here and upload this only file to Ya.Contest! ←
 *
 */

#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <sstream>
// TODO: do not forget to include all necessary headers here!

// Use the following datatypes and do not modify them!
// See notes in the task description.
using Ingredients = std::map<std::string, int>;

struct Dish {
    std::string name;
    std::set<std::string> ingredients;
};

using Dishes = std::vector<Dish>;
using DishesIngredients = std::pair<Dishes&, Ingredients&>;


//=========================[TASK 1]===========================================//

Ingredients readIngredients(std::istream& istr)
{
    Ingredients res;

    std::string line;
    std::getline(istr, line);
    int ingredientsCount = std::stoi(line);

    for (int i = 0; i < ingredientsCount; i++)
    {
        std::getline(istr, line);
        std::stringstream ss(line);
        std::string name;
        std::string field;
        std::map<std::string, int> map;
        
        std::getline(ss, name, ' ');
        std::getline(ss, field, ' ');
        int n = std::stoi(field);
        
        res[name] = n;
    }

    return res;
}

// This is a complete implementation. Don't modify it, use it and consider it
// as an example
Dishes readDishes(std::istream& istr)
{
    Dishes res;

    size_t num;
    istr >> num;
    for (size_t i = 0; i < num; ++i)
    {
        Dish dish;
        istr >> dish.name;
        size_t ingNum;
        istr >> ingNum;
        for (size_t j = 0; j < ingNum; ++j)
        {
            std::string ingr;
            istr >> ingr;
            dish.ingredients.insert(ingr);
        }
        res.push_back(dish);
    }

    return res;
}

//=========================[TASK 2]===========================================//

std::ostream& operator<<(std::ostream& ostr, const Dish& dish)
{
    std::string name = dish.name;
    std::set<std::string> ingredients = dish.ingredients;
    std::string msg;
    msg += name;
    msg += ": ";

    for (auto ing : ingredients)
    {
        msg += ing;
        msg += ", ";
    } 

    msg.erase(msg.rfind(","));

    ostr << msg;

    return ostr;
}

//=========================[TASK 3]===========================================//

int calcCalories(const Dish& dish, const Ingredients& ingrs)
{
    int total = 0;

    for (auto ing: ingrs)
    {
        for (auto ing2: dish.ingredients)
        {
            if (ing.first == ing2)
            {
                total += ing.second;
            }
        }
    }

    return total;
}


//=========================[TASK 4]===========================================//


// This is a complete implementation. Don't modify it and consider it
// as an example.
//
// ! It is NOT mandatory to use this method in the program.
std::ostream& operator<<(std::ostream& ostr, const Dishes& dishes)
{
    for (const Dish& dish : dishes)
    {
        ostr << dish << "\n";
    }
    return ostr;
}


std::ostream& operator<<(std::ostream& ostr, const DishesIngredients& di)
{
    std::string msg;

    for (auto d : di.first)
    {
        msg += d.name;
        msg += ": ";
        for (auto ing : d.ingredients)
        {
            msg += ing;
            msg += ", ";
        }
        msg.erase(msg.rfind(","));
        msg += "; ";

        int total = 0;
        for (auto ing: di.first)
        {
            for (auto ing2 : ing.ingredients)
            {
                for (auto ing3 : di.second)
                {
                    if (ing2 == ing3.first)
                    {
                        total += ing3.second;
                    }
                }
            }
        }
        msg += total;
        msg += "\n";
    }

    ostr << msg;

    return ostr;
}

//=========================[TASK 5]===========================================//

struct Comparator
{
    const Ingredients& ingrs;

    Comparator(Ingredients& i) : ingrs(i) {}
    bool operator() (const Dish& d1, const Dish& d2)
    {
        if (calcCalories(d1, ingrs) > calcCalories(d2, ingrs))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

};


void sortDishesByCalories(DishesIngredients& di)
{
    std::sort(di.first.begin(), di.first.end(), Comparator(di.second));
}
