#include<stdio.h>

int A[100];
int top = -1;

void Push(int x) 
{
  if(top == 100) 
    {
		printf("Error: stack overflow\n");
		return;
	}
	top++;
	A[top] = x;
}

void Pop() 
{
	if(top == -1) 
	{
		printf("Error: No element to pop\n");
		return;
	}
	top--;
}

int Top() 
{
	return A[top];
}

int IsEmpty()
{
    if(top == -1) 
    return 1;
    else
    return 0;
}

void Print() 
{
	printf("Stack: ");
	for(int i = 0;i<=top;i++)
		printf("%d ",A[i]);
	printf("\n");
}

void main() 
{	
	Push(2);
	Print();
	Push(5);
	Print();
	Push(10);
	Print();
	Pop();
	Print();
	Push(12);
	Print();
}
