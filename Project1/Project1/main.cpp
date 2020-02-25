#include <cstdio>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct List {
	int value;
	struct List* next;
} List;

void printList(const List* head) {
	while (head) {
		printf("%d ", head->value);
		head = head->next;
	}
	printf("\n");
}

List* push(List* head, int data) {
	List* tmp = (List*)malloc(sizeof(List));
	tmp->value = data;
	tmp->next = (head);
	return tmp;
}





int pop(List** head) {
	List* prev = NULL;
	int val;
	if (head == NULL) {
		exit(-1);
	}
	prev = (*head);
	val = prev->value;
	(*head) = (*head)->next;
	free(prev);
	return val;
}

List* getNth(List* head, int n) {
	int counter = 0;
	while (counter < n && head) {
		head = head->next;
		counter++;
	}
	return head;
}

List* getLast(List* head) {
	if (head == NULL) {
		return NULL;
	}
	while (head->next) {
		head = head->next;
	}
	return head;
}

void pushBack(List* head, int value)
{
	List* last = getLast(head);
	List* tmp = (List*)malloc(sizeof(List));
	tmp->value = value;
	tmp->next = NULL;
	last->next = tmp;
}

List* getLastButOne(List* head)
{
	if (head == NULL) {
		exit(-2);
	}
	if (head->next == NULL) {
		return NULL;
	}
	while (head->next->next) {
		head = head->next;
	}
	return head;
}

void popBack(List** head) {
	List* lastbn = NULL;
	//Получили NULL
	if (!head) {
		exit(-1);
	}
	//Список пуст
	if (!(*head)) {
		exit(-1);
	}
	lastbn = getLastButOne(*head);
	//Если в списке один элемент
	if (lastbn == NULL) {
		free(*head);
		*head = NULL;
	}
	else {
		free(lastbn->next);
		lastbn->next = NULL;
	}
}


void insert(List* head, unsigned n, int val) {
	unsigned i = 0;
	List* tmp = NULL;
	//Находим нужный элемент. Если вышли за пределы списка, то выходим из цикла,
	//ошибка выбрасываться не будет, произойдёт вставка в конец
	while (i < n && head->next) {
		head = head->next;
		i++;
	}
	tmp = (List*)malloc(sizeof(List));
	tmp->value = val;
	//Если это не последний элемент, то next перекидываем на следующий узел
	if (head->next) {
		tmp->next = head->next;
		//иначе на NULL
	}
	else {
		tmp->next = NULL;
	}
	head->next = tmp;
}


int deleteNth(List** head, int n) {
	if (n == 0) {
		return pop(head);
	}
	else {
		List* prev = getNth(*head, n - 1);
		List* elm = prev->next;
		int val = elm->value;

		prev->next = elm->next;
		free(elm);
		return val;
	}
}

void deleteList(List** head) {
	List* prev = NULL;
	while ((*head)->next) {
		prev = (*head);
		(*head) = (*head)->next;
		free(prev);
	}
	free(*head);
}



int main()
{
	List* head = NULL;
	head = push(head, 10);
	pushBack(head, 11);
	pushBack(head, 12);
	pushBack(head, 13);
	pushBack(head, 14);
	printList(head);


	system("pause");
	return 0;
}

/*typedef struct stack
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
}*/