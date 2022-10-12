#include <stdio.h>
void firstFit(int process[], int p, int blocks[], int b, int doneB[], int doneP[]);
void worstFit(int process[], int p, int blocks[], int b, int doneB[], int doneP[]);
void bestFit(int process[], int p, int blocks[], int b, int doneB[], int doneP[]);
void main(){
    int process[10], blocks[10], doneB[10], doneP[10];
    int p, b, i, j;

    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the process sizes: ");
    for(i = 0; i < p; i++){
        scanf("%d", &process[i]);
        doneP[i] = 0;
    }
    printf("Enter the number of blocks: ");
    scanf("%d", &b);
    printf("Enter the block sizes: ");
    for(i = 0; i < b; i++){
        scanf("%d", &blocks[i]);
        doneB[i] = 0;
    }
    printf("\nPROCESS        SIZE\n");
    for(i = 0; i < p; i++){
        printf("%d\t\t%d\n",i+1, process[i]);
    }
    printf("\nBLOCKS         SIZE\n");
    for(i = 0; i < b; i++){
        printf("%d\t\t%d\n",i+1, blocks[i]);
    }
    int ch;
    printf("MEMORY ALLOCATION\n1. First Fit\t2. Best Fit\t3. Worst Fit\nEnter your choice: ");
    scanf("%d", &ch);
    switch (ch)
    {
    case 1:
        firstFit(process, p, blocks, b, doneB, doneP);
        break;
    case 2:
        bestFit(process, p, blocks, b, doneB, doneP);
        break;
    case 3:
        worstFit(process, p, blocks, b, doneB, doneP);
        break;
    default:
        printf("Invalid choice!");
    }
}

void firstFit(int process[], int p, int blocks[], int b, int doneB[], int doneP[]){
    int i, j;
    printf("Process\t\tAllocated Block\n");
    for(i = 0; i < p; i++){
        for(j = 0; j < b; j++){
            if(doneP[i]!=1 && doneB[i]!=1 && process[i] <= blocks[j]){
                printf("P[%d] %d\t\t%d\n", i+1, process[i], blocks[j]);
                blocks[j] -= process[i];
                doneP[i] = 1;
                doneB[i] = 1;
            }
        }
        if (doneP[i] != 1){
            printf("P[%d] %d\t\tNA\n",i+1,process[i]);
        }
    }
}

void worstFit(int process[], int p, int blocks[], int b, int doneB[], int doneP[]){
    int i, j, temp;
    for(i = 0; i < b; i++){
        for(j = 0; j < b - i -1; j++){
            if(blocks[j+1] > blocks[j]){
                temp = blocks[j];
                blocks[j] = blocks[j+1];
                blocks[j+1] = temp;
            }
        }
    }
    printf("Process\t\tAllocated Block\n");
    for(i = 0; i < p; i++){
        for(j = 0; j < b; j++){
            if(doneP[i]!=1 && doneB[i]!=1 && process[i] <= blocks[j]){
                printf("P[%d] %d\t\t%d\n", i+1, process[i], blocks[j]);
                blocks[j] -= process[i];
                doneP[i] = 1;
                doneB[i] = 1;
            }
        }
        if (doneP[i] != 1){
            printf("P[%d] %d\t\tNA\n",i+1,process[i]);
        }
    }
}
void bestFit(int process[], int p, int blocks[], int b, int doneB[], int doneP[]){
        int i, j, temp;
    for(i = 0; i < b; i++){
        for(j = 0; j < b - i -1; j++){
            if(blocks[j+1] < blocks[j]){
                temp = blocks[j];
                blocks[j] = blocks[j+1];
                blocks[j+1] = temp;
            }
        }
    }
    printf("Process\t\tAllocated Block\n");
    for(i = 0; i < p; i++){
        for(j = 0; j < b; j++){
            if(doneP[i]!=1 && doneB[i]!=1 && process[i] <= blocks[j]){
                printf("P[%d] %d\t\t%d\n", i+1, process[i], blocks[j]);
                blocks[j] -= process[i];
                doneP[i] = 1;
                doneB[i] = 1;
            }
        }
        if (doneP[i] != 1){
            printf("P[%d] %d\t\tNA\n",i+1,process[i]);
        }
    }
}
 