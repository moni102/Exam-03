#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define COUNT 10

double randReal(double min, double max)
{
    return min + ((double)rand() / RAND_MAX) * (max - min);
}

typedef struct
{
    double x;
    double y;
} point_t;

typedef struct
{
    point_t A;
    point_t B;
} rectangle_t;

typedef struct node
{
    rectangle_t data;
    struct node *next;
} node_t;

node_t *create_node(rectangle_t data)
{
    node_t *node = malloc(sizeof(node_t));
    node->data = data;
    node->next = NULL;
    return node;
}

void push(node_t **list, rectangle_t data)
{
    node_t *n = malloc(sizeof(node_t));
    n->data = data;
    n->next = *list;
    *list = n;
}

size_t listSize(node_t *list)
{
    size_t count = 0;
    node_t *current = list;
    while (current)
    {
        count++;
        current = current->next;
    }
    return count++;
}

double areaRects(note_t *list)
{
    node_t *current = *list;
    double area;
    rectangle_t r;
    double x1 = r.A.x;
    double x2 = r.B.x;
    double y1 = r.A.y;
    double y2 = r.B.y;
    double dx = fabs(x1 - x2);
    double dy = fabs(y1 - y2);
    area = dx * dy;
    return area;
}

void filterRects(node_t **list, double min, double max)
{
    node_t *current = *list, *prev;
    double area = areaRects(current);
    if (area > min && area < max)
    {
        prev = current;
        current = current->next;
        free(prev);
    }
}

int main()
{
    srand(time(NULL));
    node_t *list = NULL;
    point_t p;
    rectangle_t r;
    for (int i = 0; i < COUNT; i++)
    {
        r.A.x = randReal(-10.0, 10.0);
        r.A.y = randReal(-10.0, 10.0);
        r.B.x = randReal(-10.0, 10.0);
        r.B.y = randReal(-10.0, 10.0);
        push(&list, r);
    }
    
    return 0;
}