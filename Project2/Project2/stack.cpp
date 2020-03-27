#include <cstdio>
#include <stdlib.h>
#include <iostream>


template<typename data>
class Stack
{
private:
	data *values;
	int length, index;

public:
	Stack()
	{
		length = 1;
		index = 0;
		values = (data*)malloc(sizeof(data) * length);
	}

	~Stack() {
		destroy_stack();
	}

	void push(data value)
	{
		if (index == length)
		{
			values = (data*)realloc(values, sizeof(data) * ++length);
		}
		values[index] = value;
		index++;
	}

	bool isEmpty()
	{
		return index == 0;
	}

	data top()
	{
		if (!isEmpty())
		{
			std::cout << values[index] << std::endl;
			return values[index];
			
		}		
		else
			return 0;
	}

	void clear_stack()
	{
		free(values);
		length = 1;
		index = 0;
		values = (data*)malloc(sizeof(data) * length);
	}
	void destroy_stack()
	{
		free(values);
	}

	data pop()
	{
		if (!isEmpty())
		{
			data for_r = top();
			index--;
			values = (data*)realloc(values, sizeof(data) * --length);
			return for_r;
		}
		else
			return 0;
	}

	void print_stack()
	{
		for (int i = 0; i < length; i++)
		{
			std::cout << values[i] << std::endl;
		}
	}
};