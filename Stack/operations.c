#include <stdio.h>
#define MAX  5
int stk[MAX];
int top = -1;
void push(int val)  // Term use for Insertion in stack
{
    // check IF stack is full 
    // CODE HERE
    {
        printf ("Can't Insert Element OVERFLOW!\n" );
        return;
    }
    // Else Insertion in stack
    // CODE HERE
    

    
}
void pop()   // Term use for deletion in stack
{
    // check IF stack is Empty
    // CODE HERE
    {
        printf("Can't Delete Element UNDERFLOW!\n");
        return;
    }
    // Else Deletion in stack
    // CODE HERE


}
void size()
{
    // Print The SIZE OF STACK
    printf("Size of stack is: %d\n","CODE HERE");
}

void peek()
{   
    if (top <0)
    {
        printf("Can't Peek Stack Empty\n");
        return;
    }
    // CODE BELOW
    printf("Top Element is : %d","CODE HERE");
}

void empty()
{
    if (top ==-1)
    {
    printf("Stack is Empty\n");
    return;
    }
  
    printf("Stack is Not Empty\n");
    
}
void traverse()
{
    if (top < 0)
    {
        printf("Stack Is Empty\n");
        return;
    }
    printf("ELements are:");
    // Traverese the stack in LIFO order
    // CODE HERE


}
int main()
{
    return 0;
}



