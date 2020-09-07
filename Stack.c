#include <stdio.h>

#define MAX_SIZE 5
int stack[MAX_SIZE];

int top = -1;

void push(int item)
{
	if (top-1 == MAX_SIZE)
	{
		printf("full\n");
		return;
	}
	else
	{
		top = top + 1;
		stack[top] = item;
	}
}

int pop()
{
	if (top == -1)
	{
		printf("no item\n");
		return 0;
	}
	else
	{
		printf("%d\n", stack[top]);
		top = top - 1;
	}
}

int main()
{
	int item;
	for (int i = 0;i < MAX_SIZE;i++)
	{
		scanf_s("%d", &item);
		push(item);
	}

	for (int i = 0;i < MAX_SIZE;i++)
	{
		pop();
	}
	return 0;
}
