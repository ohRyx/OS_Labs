#include<stdio.h>
#include<stdlib.h>

#define BufferSize 3

int mutex = 1;
int full = 0;
int empty = BufferSize;
int count = 0;

int main()
{
    int n;
    void producer();
    void consumer();
    int wait(int);
    int signal(int);
    printf("\n1.Producer\n2.Comsumer\n3.Exit");
    while(1)
    {
        printf("\nEnter your choice\n");
        scanf("%d", &n);
        switch(n)
        {
            case 1: if((mutex==1) && (empty!=0))
            producer();
            else
            printf("Buffer is full!!");
            break;

            case 2:if((mutex ==1) && (full!=0))
            consumer();
            else
            printf("Buffer is empty!!");
            break;

            case 3:
            exit(0);
            break;
        }
    }

    return 0;
}

int wait(int s)
{
    return(--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex=wait(mutex);
    full=signal(full);
    empty=wait(empty);
    count++;
    printf("\nProducer produces the item %d", count);
    mutex=signal(mutex);
}

void consumer()
{
    mutex=wait(mutex);
    full=wait(full);
    empty=signal(empty);
    printf("\nConsumer consumes item %d", count);
    count--;
    mutex=signal(mutex);
}