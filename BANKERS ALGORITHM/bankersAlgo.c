#include <stdio.h>

typedef struct process{
    int a, b, c;
}process;

void main(){
    process max[10], need[10], alloc[10], avail[1];
    int i, n, flag[10];
    printf("Enter the num of processes: ");
    scanf("%d", &n);
    printf("Enter the process details\n");
    for(i = 0; i < n; i++){
        printf("Enter max resource for P[%d]: ",i);
        scanf("%d %d %d", &max[i].a, &max[i].b, &max[i].c);
        printf("Enter allocated resource for P[%d]: ",i);
        scanf("%d %d %d", &alloc[i].a, &alloc[i].b, &alloc[i].c);
        flag[i] = 1;
    }
    printf("Enter the available resources: ");
    scanf("%d %d %d", &avail[0].a, &avail[0].b, &avail[0].c);

    for(i = 0; i < n; i++){
        need[i].a = max[i].a - alloc[i].a;
        need[i].b = max[i].b - alloc[i].b;
        need[i].c = max[i].c - alloc[i].c;
    }
    int  j = 0, k = 0, state[10];
    while(j < n){
        if((avail[0].a >= need[k].a) && (avail[0].b >= need[k].b) && (avail[0].c >= need[k].c) && flag[k] == 1){
            state[j] = k;
            j++;
            avail[0].a += alloc[k].a;
            avail[0].b += alloc[k].b;
            avail[0].c += alloc[k].c;
        }
        k = (k+1)%n;
    }


    printf("Process Details are: \n");
    printf("PID\t\tMAX\t\tALLOC\t\tNEED\t\tAVAIL\n");
    for(i = 0; i < n; i++){
        if(i == 0)
            printf("P[%d]\t\t%d %d %d\t\t%d %d %d\t\t%d %d %d\t\t%d %d %d\n", i, max[i].a, max[i].b, max[i].c, alloc[i].a, alloc[i].b, alloc[i].c, need[i].a, need[i].b, need[i].c, avail[0].a, avail[0].b, avail[0].c);
        else{
            printf("P[%d]\t\t%d %d %d\t\t%d %d %d\t\t%d %d %d\n", i, max[i].a, max[i].b, max[i].c, alloc[i].a, alloc[i].b, alloc[i].c, need[i].a, need[i].b, need[i].c);
        }
    }
    for(i = 0; i < n; i++){
        printf("%d ", state[i]);
    }
}