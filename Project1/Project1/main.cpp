#include <cstdio>
#include <stdlib.h>
#include <iostream>
using namespace std;

void smth();

typedef struct stack
{
	int* values;
	int index, length;
};

stack* create_stack()
{
	stack* p = (stack*)malloc(sizeof(stack));
	p->index = 0;
	p->length = 2;
	p->values = (int*)malloc(sizeof(int) * p->length);
	return p;
}

void destroy_stack(stack* p)
{
	free(p->values);
	free(p);
}


void push(stack* p, int x);
void pop(stack* p);
void top(stack* p);
void clear(stack* p);
int isEmpty(stack* p)
{
	return p->index == 0;
}

int main()
{
	
	system("pause");
	return 0;
}


void smth()
{
	int* input_numbers;
	int length = 1, index = 0, inp_n = 1;

	input_numbers = (int*)malloc(sizeof(int) * length);


	while (inp_n != 0)
	{
		cin >> inp_n;
		if (index >= length)
		{
			input_numbers = (int*)realloc(input_numbers, sizeof(int) * ++length);
		}

		input_numbers[index] = inp_n;
		index++;
	}

	for (int i = length - 1; i >= 0; i--)
	{
		cout << input_numbers[i] << " ";
	}
	cout << endl;
	free(input_numbers);
}