#include <iostream>
#include "human.h"
#include "teacher.h"
#include <windows.h>
int main()
{	
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);
	unsigned int teacher_work_time = 40;
	teacher* tch = new teacher("�������", "�������", "���������", teacher_work_time);
	std::cout << tch->get_full_name() << std::endl;
	std::cout << "���������� �����: " << tch->get_work_time() << std::endl;
	return 0;
}
