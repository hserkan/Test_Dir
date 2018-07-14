#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int value;
    struct node* next;
} node;

int main()
{
    node *first;
    node *current = (node *)malloc(sizeof(node));
    first = current;
    current->value = 0;
    for (int i=1; i < 10; i++)
    {
        node *nextPtr = (node *)malloc(sizeof(node));
        current->next = nextPtr;
        current = nextPtr;
        current->value = i;
    }
    current->next = NULL;
    current = first;
    node *nextPtr;
    while (current != NULL)
    {
        printf("%d\n",current->value);
  
        nextPtr = current->next;
        free(current);
        current = nextPtr;
    }
    return 0;
}