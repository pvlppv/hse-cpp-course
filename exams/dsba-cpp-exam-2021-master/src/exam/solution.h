/*! \file       solution.h
 *  \author     ---=Put your name here=---
 *  \version    1.0
 *  \date       29.06.2022
 *
 *  Final Exam. Solution module. Put ALL the declarations and definitions right here.
 *  All the class methods must be defined here (do not put their in a separated
 *  file). If you need to create a non-member auxilliary function, put its defintion
 *  here as well.
 *
 *      → Provide your solution here and upload this only file to Ya.Contest! ←
 *
 */

#ifndef SOLUTION_H
#define SOLUTION_H

#include <string>
#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>

//========================================
//==========< Problem 1 [3pts] >==========

class Teacher
{
public:
    Teacher(const std::string& name)
        : _name(name) {}
    virtual ~Teacher() {}
    const std::string& getName() const { return _name; }
    virtual double calcWages() const = 0;
    virtual Teacher* cloneMe() const = 0;
protected: 
    std::string _name;
};

class AssociateTeacher : public Teacher
{
public:
    AssociateTeacher(const std::string& name, const int& bonus)
        : Teacher(name), _bonus(bonus) {}
    static const int BASE_SALARY = 1500;
    const int& getBonus() const { return _bonus; };
    double calcWages() const override { return BASE_SALARY + _bonus; };
    Teacher* cloneMe() const override { return new AssociateTeacher(_name, _bonus); };
protected:
    int _bonus;
};

class InvitedTeacher : public Teacher
{
public:
    InvitedTeacher(const std::string& name, const int& _stuGroups)
        : Teacher(name), _stuGroups(_stuGroups) {}
    static const int GROUP_TAX = 2000;
    const int& getStuGroups() const { return _stuGroups; };
    double calcWages() const override { return GROUP_TAX * _stuGroups; };
    Teacher* cloneMe() const override { return new InvitedTeacher(_name, _stuGroups); };
protected:
    int _stuGroups;
};

//========================================
//==========< Problem 2 [3pts] >==========

class TArray {
public:
    TArray()= default;
    ~TArray() {
        for (auto e : _arr) {
            delete e;
        }
    }
    TArray(const TArray& other){
        if (!_arr.empty()) _arr.clear();

        for (int i = 0; i < other.getSize(); i++){
            _arr.push_back(other[i]->cloneMe());
        }
    }
    TArray& operator=(const TArray& other){
        if (!_arr.empty()) _arr.clear();

        for (int i = 0; i < other.getSize(); i++){
            _arr.push_back(other[i]->cloneMe());
        }

        return *this;
    }
    size_t getSize() const { return _arr.size(); }
    AssociateTeacher* addAssociateTeacher(const std::string & name, int bonus) {
        AssociateTeacher* associateTeacher = new AssociateTeacher(name, bonus);
        _arr.push_back(associateTeacher);
        return associateTeacher;
    }
    InvitedTeacher* addInvitedTeacher(const std::string& name, int groupsNum) {
        InvitedTeacher* invitedTeacher = new InvitedTeacher(name, groupsNum);
        _arr.push_back(invitedTeacher);
        return invitedTeacher;
    }
    Teacher* operator[](size_t index) const {
        if (index >= _arr.size()) {
            throw std::out_of_range("Index out of range");
        }
        return _arr[index];
    }
protected:
    std::vector<Teacher*> _arr;
};

std::ostream& operator << (std::ostream& os, const TArray& tArr)
{
    for (int i = 0; i < tArr.getSize(); i++) {
        Teacher* teacher = tArr[i];
        os << teacher->getName() << ", " << teacher->calcWages() << "\n";
    }
    return os;
}

//========================================
//==========< Problem 3 [2pts] >==========

std::pair<int,int> totalWagesOfTopTeachers(const TArray& tArr, int minGroups, int minBonus)
{
    std::pair<int, int> pair;
    int sum;
    for (int i = 0; i < tArr.getSize(); i++) {
        Teacher* teacher = tArr[i];
        if (InvitedTeacher* invitedTeacher = dynamic_cast<InvitedTeacher*>(teacher)) {
            if (invitedTeacher->getStuGroups() >= minGroups) {
                pair.first += invitedTeacher->calcWages();
            }
        } 
        else if (AssociateTeacher* associateTeacher = dynamic_cast<AssociateTeacher*>(teacher)) {
            if (associateTeacher->getBonus() >= minBonus) {
                pair.second += associateTeacher->calcWages();
            }
        }
    }
    return pair;
}

#endif
