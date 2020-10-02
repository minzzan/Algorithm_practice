#include <stdio.h>
#include <stdlib.h>
#define SZ 20

struct node
{
	int data;
	struct node* next;
};

struct node* head = 0;

void AddToSLL(int _data)
{
	struct node* new_one = (struct node*)malloc(sizeof(struct node));
	new_one->next = 0;
	new_one->data = _data;

	if (head == 0)
	{
		head = new_one;
		return;
	}
	else
	{
		struct node* temp = head;
		while (1)
		{
			if (temp->next == 0)
			{
				break;
			}
			temp = temp->next;
		}
		temp->next = new_one;
		return;
	}
}

struct node * findSLL(int data)
{
	if (head == 0)
	{
		return 0;
	}
	struct node* temp = head;
	while (temp != 0)
	{
		if (temp->data == data)
		{
			return temp;
		}
		temp = temp->next;
	}
	return 0;
}

void insertSLL(int data,int former)
{
	struct node* new_one = (struct node*)malloc(sizeof(struct node));
	new_one->next = 0;
	new_one->data = data;

	struct node* form = findSLL(former);

}

void swap(int A, int B)
{
	
}

void bubblesort()
{
	int i, j;
	struct node* temp = head;
	while (1)
	{
		if (temp->data > temp->next->data)
		{
			swap(temp->data, temp->next->data);
		}
	}
}

void showSLL()
{
	if (head == 0)
	{
		printf("nothing");
		return;
	}
	else
	{
		struct node* temp = head;
		while (temp != 0)
		{
			printf("%d\n", temp->data);
			temp = temp->next;
		}
		return;
	}
}

int main()
{
	for (int i = 0;i < SZ;i++)
	{
		AddToSLL(rand() % 1000);
	}
	showSLL();
	return 0;
}
