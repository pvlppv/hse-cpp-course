
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
    bool operator<(const Task& other) const;
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
    for (const auto& workload : workloads)
    {
       total += workload.second;
    }
    return total;
}

// Task operator <
bool Task::operator<(const Task& other) const
{
    if (this->getTotalLoad() != other.getTotalLoad())
    {
        return this->getTotalLoad() < other.getTotalLoad();
    }
    if (this->date != other.date)
    {
        return this->date < other.date;
    }
    return this->text < other.text;
}

// Comparator for std::sort
bool compareTasks(const Task& task1, const Task& task2)
{
    if (task1.getTotalLoad() != task2.getTotalLoad())
    {
        return task1.getTotalLoad() < task2.getTotalLoad();
    }
    if (task1.date != task2.date)
    {
        return task1.date < task2.date;
    }
    return task1.text < task2.text;
}

// task 3
void sortTasks(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(), tasks.end());
}

// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
    int total = 0;
    for (const auto& task : allTasks)
    {
        for (const auto& workload : task.workloads)
        {
            if (workload.first == worker.login)
            {
                total += workload.second;
            }
        }
    }
    return total;
}

// task 5
void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    for (const auto& newtask : newTask.workloads)
    {
        for (const auto& worker : workers)
        {
            if (newtask.first == worker.login)
            {
                if (getWorkerLoad(tasks, worker) + newtask.second > worker.maxLoad)
                {
                    throw std::runtime_error("Overworked");
                } 
            }
        }
    }
    tasks.push_back(newTask);
}

bool compareWorkers(const std::pair<std::string, int> worker1, const std::pair<std::string, int> worker2)
{
    return worker1.first < worker2.first;
}

// task 6
void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    std::vector<std::pair<std::string, int>> overworked;

    tasks.push_back(newTask);

    for (const auto& worker : workers)
    {
        int worker_load = getWorkerLoad(tasks, worker);
        if (worker_load > worker.maxLoad)
        {
            overworked.push_back({worker.login, worker_load - worker.maxLoad});
        }
    }

    if (!overworked.empty())
    {
        std::sort(overworked.begin(), overworked.end(), compareWorkers);
        std::string msg = "Overworked: ";
        for (const auto& overworker : overworked)
        {
            msg += overworker.first + " by " + std::to_string(overworker.second) + ", ";
        }
        msg.erase(msg.rfind(","));
        throw std::runtime_error(msg);
    }
}
