#include "TaskManager.h"

void Menu(TaskManager &m)
{
	int user = 5;
	std::string name, desc;
	int priority;


	std::cout << "[Menu]\n" << "(1) [Add Task]\n" << "(2) [Complete Task]\n" << "(3) [Show All Tasks]\n" << "(0) [Exit]\n";



	while (user != 0)
	{
		std::cout << "[User]: "; std::cin >> user;
		switch (user)
		{
		case 1:
			std::cin.ignore();
			std::cout << "[Enter Name]: "; std::getline(std::cin, name); 
			std::cout << "[Enter Description]: "; std::getline(std::cin, desc); 
			std::cout << "[Enter Priority]: "; std::cin >> priority;
			m.addTask(name, desc, priority);
			break;
		case 2:
			m.completeTask();
			break;
		case 3:
			m.showTasks();
			break;
		case 0:
			exit(0);
		default:
			std::cout << "\n[Choose Valid Option]\n";
		}
	}
}


int main()
{
	TaskManager Manager;
	
	Menu(Manager);
}