#include <cstdio>
#include <stdlib.h>
#include <iostream>


template<typename T>
class Stack
{
private:
	T *values;
	int length, index;

public:
	Stack()
	{
		length = 1;
		index = 0;
		values = (T*)malloc(sizeof(T) * length);
	}

	~Stack() {
		destroy_stack();
	}

	void push(T value)
	{
		if (index == length)
		{
			values = (T*)realloc(values, sizeof(T) * ++length);
		}
		values[index] = value;
		index++;
	}

	bool isEmpty()
	{
		return index == 0;
	}

	T top()
	{
		if (!isEmpty())
		{
			//std::cout << values[index-1] << std::endl;
			return values[index-1];
			
		}		
		else
			return 0;
	}

	void clear_stack()
	{
		free(values);
		length = 1;
		index = 0;
		values = (T*)malloc(sizeof(T) * length);
	}
	void destroy_stack()
	{
		free(values);
	}

	T pop()
	{
		if (!isEmpty())
		{
			T for_r = top();
			index--;
			values = (T*)realloc(values, sizeof(T) * --length);
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