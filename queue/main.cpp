#include <iostream>
#include "Queue.h"

int main()
{
	Queue<int> q;
	q.push(5);

	try
	{
		int front = q.front();
		std::cout << front << std::endl;
	}
	catch (const char* msg)
	{
		std::cout << msg << std::endl;
	}

	system("pause");
	return 0;
}