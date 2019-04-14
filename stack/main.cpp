#include "Node.h"
#include "Stack.h"
#include <iostream>

int main()
{
	Stack<int> st;

	st.push(5);

	try
	{
		int top = st.top();
		std::cout << top << std::endl;
	}
	catch (const char* msg)
	{
		std::cout << msg;
	}
}