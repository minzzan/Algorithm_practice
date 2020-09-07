#include <stdio.h>

#define MAX_SIZE 5
int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item)
{
	if (((rear+1) % MAX_SIZE) == front)
	{
		printf("FULL");
		return;
	}
	queue[rear] = item;
	rear = (rear + 1) % MAX_SIZE;
}

int dequeue()
{
	int result = 0;
	if (front == rear)
	{
		printf("EMPTY");
		return -999;
	}
	result = queue[front];
	front = (front + 1) % MAX_SIZE;
	return result;
}

int main()
{
	int item;
	for (int i = 0;i < MAX_SIZE;i++)
	{
		scanf_s("%d", &item);
		enqueue(item);
	}
	for (int i = 0;i < MAX_SIZE;i++)
	{
		printf("%d\n",dequeue(item));
	}
	return 0;
}
