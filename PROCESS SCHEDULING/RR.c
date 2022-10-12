#include <stdio.h>

void main(){
    int at[10], bt[10], rt[10], tq, n, wt = 0, ta = 0;
    printf("Enter the number of process: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        printf("P[%d] AT and BT: ", i);
        scanf("%d %d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }
    printf("Enter the time quantum: ");
    scanf("%d", &tq);
    printf("\n\nPID\tTurnaround time  Waiting Time\n");
    int time, flag = 0, i, remain = n;
    for(time = 0, i = 0; remain !=  0;){
        if(rt[i]<=tq && rt[i] > 0){
            time += rt[i];
            rt[i] = 0;
            flag = 1;
        }
        else if(rt[i] > 0){
            rt[i] -= tq;
            time += tq;
        }
        if(rt[i] == 0 && flag == 1){
            remain -= 1;
            printf("P[%d]\t\t%d\t\t%d\n", i+1, time - at[i], time - at[i] - bt[i]);
            wt += time - at[i] - bt[i];
            ta += time - at[i];
            flag = 0;
        }
        if(i == n -1)
            i = 0;
        else if(at[i+1] <= time)
            i++;
        else
            i = 0;
    }


}