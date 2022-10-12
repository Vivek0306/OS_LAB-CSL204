#include <stdio.h>
#include <stdlib.h>
void main(){
    int tr[20], n, head, sum = 0, new;
    printf("Enter the number of tracks: ");
    scanf("%d", &n);
    printf("Enter the head position: ");
    scanf("%d", &head);
    printf("Enter the track records: ");
    for(int i = 0; i < n; i++){
        new = 0;
        scanf("%d", &tr[i]);
        printf("%d - %d", head, tr[i]);
        new = abs(head - tr[i]);
        head = tr[i];
        sum += new;
    }
    printf("Total head movement: %d\n", sum);
}