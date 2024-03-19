#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);
    int getTotalLoad() const;
};

// task 1
Task::Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads)
    : text(text), date(date), workloads(workloads) {}


struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    // might be needed for task 5
    bool isOverworked(const std::vector<Task>& tasks) const;
};

// task 1
Worker::Worker(const std::string& name, const std::string& login, int maxLoad) 
    : name(name), login(login), maxLoad(maxLoad) {}


// task 2
int Task::getTotalLoad() const
{
    int total = 0;
    for (const auto& i : workloads) {
        total += i.second;
    }
    return total;
}

// task 3
bool compareTasks(const Task& task1, const Task& task2) {
    if (task1.getTotalLoad() != task2.getTotalLoad()) {
        return task1.getTotalLoad() < task2.getTotalLoad();
    }

    if (task1.date != task2.date) {
        return task1.date < task2.date;
    }

    return task1.text < task2.text;
}

void sortTasks(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end(), compareTasks);
}

// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker) {
    int count = 0;
    for (const auto& i : allTasks) {
        for (const auto& j: i.workloads) {
            if (j.first == worker.login) {
                count += j.second;
            }
        }        
    }
    return count;
}

// task 5
void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    for (const auto& i : newTask.workloads) {
        for (const auto& j : workers) {
            if (i.first == j.login) {
                int totalLoad = getWorkerLoad(tasks, j) + i.second;
                if (totalLoad > j.maxLoad) {
                    throw std::runtime_error("Overworked");
                }
            }
        }
    }
    tasks.push_back(newTask);
}

// task 6
bool compareWorkers(std::pair<std::string, int> worker1, std::pair<std::string, int> worker2) {
    return worker1.first < worker2.first;
}

void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    tasks.push_back(newTask);
    std::pair<std::string, int> pair;
    std::vector<std::pair<std::string, int>> overworked_workers;

    for (const auto& i : workers) {
        int totalLoad = getWorkerLoad(tasks, i);
        pair.first = i.login;
        pair.second = totalLoad - i.maxLoad;
        if (totalLoad > i.maxLoad) {
            overworked_workers.push_back(pair);
        }
    }

    if (!overworked_workers.empty() > 0) {
        std::sort(overworked_workers.begin(), overworked_workers.end(), compareWorkers);
        std::string msg = "Overworked: ";
        for (int i = 0; i < overworked_workers.size(); i++) {
            msg += overworked_workers[i].first + " by " + std::to_string(overworked_workers[i].second) + ", ";
        }
        msg.erase(msg.end() - 2, msg.end());
        throw std::runtime_error(msg);
    }
}

