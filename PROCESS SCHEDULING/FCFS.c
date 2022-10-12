#include <stdio.h>
typedef struct process{
    int PID;
    int TA;
    int AT;
    int WT;
    int CT;
    int BT;
}process;

void calculate(process P[], int n){
    P[0].CT = P[0].BT;
    for(int i =1; i < n; i++){
        P[i].CT = P[i].BT + P[i-1].CT;
    }
    for(int i = 0; i < n; i++){
        P[i].TA = P[i].CT - P[i].AT;
        P[i].WT = P[i].TA - P[i].BT;
    }
}

void main(){
    process P[10];
    int n, i, j;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the process details: \n");
    for(i = 0; i < n; i++){
        printf("P[%d] Burst Time, Arrival Time: ", i);
        scanf("%d %d", &P[i].BT, &P[i].AT);
    }
    calculate(P, n);
    printf("THE PROCESS DETAILS ARE: \n");
    printf("PID\t\tArrival Time\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time\t\tCompletion Time\n");
    for(i = 0; i < n; i++){
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t\t%d\t\t\t%d\n",i,P[i].AT, P[i].BT, P[i].TA, P[i].WT, P[i].CT);
    }
}