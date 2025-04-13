#pragma once
#include "iostream"
#include "string"
#include "queue"
#include "fstream"


struct Task
{
	std::string TaskName;
	std::string TaskDesc;
	Task(std::string name, std::string desc);
};

class TaskManager
{
private:
	std::queue<Task> priority1;
	std::queue<Task> priority2;
	std::queue<Task> priority3;

	void showQueue(std::queue<Task> q);
	
public:
	void addTask(const std::string& name, const std::string& desc, int priority);
	void completeTask();
	void showTasks();
};
