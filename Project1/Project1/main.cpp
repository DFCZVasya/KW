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

int top(stack* p);
int isEmpty(stack* p);

stack* create_stack()
{
	stack* p = (stack*)malloc(sizeof(stack));
	p->index = 0;
	p->length = 1;
	p->values = (int*)malloc(sizeof(int) * p->length);
	return p;
}

void destroy_stack(stack* p)
{
	free(p->values);
	free(p);
}

void show_stack(stack* p)
{
	for (int i = 0; i < p->length; i++)
	{
		cout << p->values[i] << endl;
	}
}


void push(stack* p, int x)
{
	if (p->index == p->length)
	{
		p->values = (int*)realloc(p->values, sizeof(int) * ++p->length);
	}
	p->values[p->index] = x;
	p->index++;
}

int pop(stack* p) 
{
	if (!isEmpty(p))
	{
		int for_r = top(p);
		p->index--;
		p->values = (int*)realloc(p->values, sizeof(int) * --p->length);
		return for_r;
	}
	else
		return 0;
}


int top(stack* p)
{
	if (isEmpty(p))
		return p->values[p->index];
	else
		return 0;
}

void clear(stack* p)
{
	destroy_stack(p);
	create_stack();
}
int isEmpty(stack* p) {	return p->index == 0;}

int main()
{
	stack* a = create_stack();
	push(a, 10);
	push(a, 101);
	push(a, 102);
	show_stack(a);
	pop(a);
	show_stack(a);

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