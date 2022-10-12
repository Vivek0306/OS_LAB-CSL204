//scan
#include <stdio.h>
#include <stdlib.h>

void main(){
    int t[100], a[100], new = 0, head, i, k, j, temp, n, sum = 0;
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    printf("Enter the head position: ");
    scanf("%d", &head);
    printf("Enter the track records: ");
    for(i = 0; i < n; i++){
        scanf("%d", &t[i]);
    }
    t[n+2] = 0;
    t[n+1] = 199;
    t[n] = head;
    n = n + 3;
    for(i = 0; i < n; i++){
        for(j = 0; j < n - i - 1; j++){
            if(t[j] > t[j+1]){
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }
    for(i=0;i < n; i++){
        if(t[i] == head){
            k = i;
            break;
        }
    }
    for(i = k - 1; i >= 0; i--){
        // printf("%d - %d\n", head, t[i]);
        new = abs(head - t[i]);
        sum += new;
        head = t[i];
    }
    for(i = k + 1;i < n - 1;i++){
        // printf("%d - %d\n", t[i], head);
        new  = abs(t[i] - head);
        sum += new;
        head = t[i];
    }

    printf("Total head movement: %d\n", sum);

}