#include <stdio.h>
#include <stdlib.h>

#include "ex10q1.h"
Ring *ring_create(void)
{
    Ring *ring = (Ring *)malloc(sizeof(Ring));
    ring->capacity = 128;
    ring->head = (int *)malloc(ring->capacity * sizeof(int));
    ring->start = ring->head;
    ring->end = ring->head;
    ring->length = 0;
    return ring;
}

void addLast(Ring *ring, int value)
{
    if (ring->length == ring->capacity)
    {
        ring->capacity = ring->capacity * 2;
        ;
        int *temphead;
        int *tempstart;
        // printf("inside addLast %d\n", ring->capacity);
        temphead = (int *)malloc((ring->capacity) * sizeof(int));
        tempstart = temphead;
        for (int i = 0; i < ring->length; i++)
        {
            *tempstart = *(ring->start);
            tempstart++;
            ring->start++;
            if (ring->start == ring->length + ring->head)
            {
                ring->start = ring->head;
            }
        }
        free(ring->head);
        ring->start = temphead;
        ring->head = temphead;
        ring->end = tempstart;
    }
    *(ring->end) = value;
    ring->end++;
    if(ring->end == ring->head + ring->capacity){
        ring->end = ring->head;
    }
    ring->length++;
}

void addfirst(Ring *ring, int value)
{
    if (ring->length == ring->capacity)
    {
        ring->capacity = ring->capacity * 2;
        int *temphead;
        int *tempstart;
        // printf("inside addFirst %ld\n", ring->capacity * sizeof(int));
        temphead = (int *)malloc(ring->capacity * sizeof(int));
        // printf("done");
        *(temphead) = value;
        tempstart = temphead + 1;
        for (int i = 0; i < ring->length; i++)
        {
            *(tempstart) = *(ring->start);
            tempstart++;
            ring->start++;
            //change
            if (ring->start == ring->head + ring->length)
            {
                ring->start = ring->head;
            }
        }
        free(ring->head);
        ring->start = temphead;
        ring->head = temphead;
        ring->end = tempstart;
        // change
        if(ring->end == ring->head + ring->capacity){
            ring->end = ring->head;
        }
    }
    else
    {
        ring->start--;

        if (ring->start < ring->head)
        {
            ring->start = ring->head - 1 + ring->capacity;
        }
        *(ring->start) = value;
    }
    ring->length++;
}

int removeLast(Ring *ring)
{
    if (ring->length == 0)
    {
        exit(5);
    }

    ring->end--;

    if (ring->end < ring->head)
    {
        ring->end = ring->head + ring->capacity - 1;
    }

    int value = *(ring->end);
    ring->length--;

    return value;
}

int removeFirst(Ring *ring)
{
    if (ring->length == 0)
    {
        exit(5);
    }

    int value = *(ring->start);
    ring->length--;

    ring->start++;
    if (ring->start >= ring->capacity + ring->head)
    {
        ring->start = ring->head;
    }

    return value;
}

void ringfree(Ring *ring)
{
    free(ring->head);
    free(ring);
}

void printRing(Ring *ring)
{
    int *tempstart = ring->start;
    for (int i = 0; i < ring->length; i++)
    {
        printf("%d\n", *(tempstart));
        tempstart++;
        if (tempstart == ring->head + ring->capacity)
        {
            tempstart = ring->head;
        }
    }
}

int main()
{
    Ring *front = ring_create();
    Ring *back = ring_create();

    char action;
    int x, studentID, autograph;

    while (scanf(" %c", &action) != EOF)
    {
        if (action == 'L')
        {
            if (back->length == 0 && front->length == 0)
            {
                continue;
            }
            if (back->length == 0 && front->length == 1)
            {
                removeLast(front);
                continue;
            }
            removeLast(back);
            if (front->length > back->length + 1)
            {
                int temp = removeLast(front);
                addfirst(back, temp);
            }
        }
        else if (action == 'F')
        {
            if (front->length == 0 && back->length == 0)
            {
                printf("empty\n");
            }
            else
            {
                autograph = removeFirst(front);
                printf("%d\n", autograph);
                if (back->length > front->length)
                {
                    int temp = removeFirst(back);
                    addLast(front, temp);
                }
            }
        }
        else if (action == 'N')
        {
            scanf("%d %d", &x, &studentID);
            if (x > (front->length + back->length))
            {
                addLast(back, studentID);
                if ((front->length - back->length > 1) || (front->length < back->length))
                {
                    int temp = removeFirst(back);
                    addLast(front, temp);
                }
            }
        }
        else if (action == 'C')
        {
            scanf("%d %d", &x, &studentID);
            if (x > front->length)
            {
                addfirst(back, studentID);
                if (back->length > front->length)
                {
                    int temp = removeFirst(back);
                    addLast(front, temp);
                }
            }
        }
    }

    ringfree(front);
    ringfree(back);

    return 0;
}
