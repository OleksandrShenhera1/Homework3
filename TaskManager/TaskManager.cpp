#include "TaskManager.h"

Task::Task(std::string name, std::string desc) : TaskName(name), TaskDesc(desc) {}

void TaskManager::addTask(const std::string& name, const std::string& desc, int priority)
{
	Task task(name, desc);
	switch (priority)
	{
	case 1:
		priority1.push(task);
		break;
	case 2:
		priority2.push(task);
		break;
	case 3:
		priority3.push(task);
		break;
	default:
		std::cout << "\n[Wrong Priority]\n";
	}
}

void TaskManager::completeTask()
{
	if (!priority1.empty())
	{
		std::cout << "[Compeleted Task]: " << priority1.front().TaskName << " [Despriction]: " << priority1.front().TaskDesc << "\n";
		priority1.pop();
	}
	else if (!priority2.empty())
	{
		std::cout << "[Compeleted Task]: " << priority2.front().TaskName << " [Despriction]: " << priority2.front().TaskDesc << "\n";
		priority2.pop();
	}
	else if (!priority3.empty())
	{
		std::cout << "[Compeleted Task]: " << priority3.front().TaskName << " [Despriction]: " << priority3.front().TaskDesc << "\n";
		priority3.pop();
	}
	else
	{
		std::cout << "\n[No Tasks Left]\n";
	}
}

void TaskManager::showTasks()
{
	std::cout << "\n[Priority (1) Tasks]\n\n";
	showQueue(priority1);
	std::cout << "\n[Priority (2) Tasks]\n\n";
	showQueue(priority2);
	std::cout << "\n[Priority (3) Tasks]\n\n";
	showQueue(priority3);
}

void TaskManager::showQueue(std::queue<Task> q)
{
	if (q.empty())
	{
		std::cout << "[No Tasks Left]\n";
		return;
	}


	while (!q.empty())
	{
		std::cout << "[Task]: " << q.front().TaskName << " [Description]: " << q.front().TaskDesc << "\n";
		q.pop();
	}
}
