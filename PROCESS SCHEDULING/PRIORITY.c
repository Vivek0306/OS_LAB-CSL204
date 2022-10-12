#include <stdio.h>

void main(){
    int n, id[10], bt[10], ta[10], wt[10], p[10];
    printf("Enter the number of process: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("PID Priority  BT: ");
        scanf("%d %d %d",&id[i], &p[i], &bt[i]);
    }
    int t1, t2, t3;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(p[j] > p[j+1]){
                t1 = id[j];
                t2 = p[j];
                t3 = bt[j];
                id[j] = id[j+1];
                p[j] = p[j+1];
                bt[j] = bt[j+1];
                id[j+1] = t1;
                p[j+1] = t2;
                bt[j+1] = t3;
            }
        }
    }

    ta[0] = bt[0];
    for(int i = 1; i < n; i++){
        ta[i] = bt[i] + ta[i-1];
    }
    for(int i = 0; i < n; i++){
        wt[i] = ta[i] - bt[i];
    }

    printf("PID\tPriority\tBurst time   Turnaround time   Waiting Time\n");
    for(int i = 0; i < n; i++){
        printf("P[%d]\t\t%d\t%d\t\t%d\t\t%d\n",id[i], p[i], bt[i], ta[i], wt[i]);
    }


}