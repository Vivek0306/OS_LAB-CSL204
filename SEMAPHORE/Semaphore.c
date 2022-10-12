#include <stdio.h>
#include <stdlib.h>
void producer();
void consumer();
int wait(int);
int signal(int);
int mutex = 1, full = 0, empty = 3, x = 0;

void main(){
    int n;
    printf("1.Producer\t2.Consumer\t3.Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&n);
        switch (n)
        {
        case 1:
            if(mutex == 1 && empty!=0)
                producer();
            else
                printf("Buffer is full!\n");
            break;
        case 2:
            if(mutex == 1 && full!=0)
                consumer();
            else
                printf("Buffer is empty!\n");
            break;    
        case 3:
            exit(0);
            break;
        default:
            printf("Invalid choice");
        }
    }

}
    int wait(int s){
        return (--s);
    }
    int signal(int s){
        return  (++s);
    }
    void producer(){
        mutex = wait(mutex);
        full = signal(full);
        empty = wait(empty);
        x++;
        printf("Producer produces item\n");
        mutex = signal(mutex);
    }
    void consumer()
    {
        mutex=wait(mutex);
        full=wait(full);
        empty=signal(empty);
        x--;
        printf("Consumer consumes item\n");
        mutex = signal(mutex);
    }