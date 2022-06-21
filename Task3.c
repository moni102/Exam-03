#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randint(int min, int max)
{
    return min + rand() % (max - min + 1);
}

typedef struct Node
{
    int data;
    struct Node *next;
} node_t;

void print(struct Node *cll)
{
    if (cll == NULL)
    {
        return;
    }
    int start = cll;
    do
    {
        printf("%d ", cll->data);
        cll = cll->next;
    } while (cll != start);
    printf("\n");
}

struct Node *insertAfter(struct Node *cll, int skipCount, int newElem)
{
    if (skipCount == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
    for(int i=0;i<skipCount;i++)
    {
        cll = cll->next;
    }
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = newElem;
    new_node->next = cll->next;
    cll->next = new_node;

    return *new_node;
}

int main(int argc, char **argv)
{
    srand(time(NULL));

    int *cll = calloc(argv[0], sizeof(int));
    print(cll);
    int skipCount = randint(0, 1000000), newElem=randint(0, 1000);
    insertAfter(cll,skipCount,newElem);

    free(cll);
    return 0;
}