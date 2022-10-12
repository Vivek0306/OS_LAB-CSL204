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
    P[0].TA = P[0].BT;
    for(int i =1; i < n; i++){
        P[i].TA = P[i].BT + P[i-1].TA;
    }
    for(int i = 0; i < n; i++){
        P[i].WT = P[i].TA - P[i].BT;
    }
}
void sort(process P[], int n){
    process temp;
    int i,j;
    for (i=0; i<n; i++) {
        for (j=0; j<n-i-1; j++) {
            if (P[j].BT > P[j+1].BT) {
                temp.PID = P[j].PID;
                temp.BT = P[j].BT;
                P[j].BT = P[j+1].BT;
                P[j].PID = P[j+1].PID;
                P[j+1].BT = temp.BT;
                P[j+1].PID = temp.PID;
            }
        }
    }
    for(int i = 0; i < n; i++){
        printf("%d ", P[i].BT);
    }
}
void main(){
    process P[10];
    int n, i, j;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    printf("Enter the process details: \n");
    for(i = 0; i < n; i++){
        printf("Process Id Burst Time ");
        scanf("%d %d", &P[i].PID, &P[i].BT);
    }
    sort(P, n);
    calculate(P, n);
    printf("THE PROCESS DETAILS ARE: \n");
    printf("PID\t\tBurst Time\t\tTurnaround Time\t\tWaiting Time\n");
    for(i = 0; i < n; i++){
        printf("P[%d]\t\t%d\t\t\t%d\t\t\t%d\n",P[i].PID, P[i].BT, P[i].TA, P[i].WT);
    }
}