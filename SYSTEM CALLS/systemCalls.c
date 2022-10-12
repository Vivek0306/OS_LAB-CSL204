#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

void main(){
    printf("Inside the system call\n");

    int stat;
    int pid = fork();

    if(pid == -1){
        printf("Fork can't be created, error occured\n");
        exit(1);
    }
    else if(pid == 0){
        printf("Child process created\n");
        printf("Child process PID = %u\n", getpid());
    }
    else{
        printf("Parent process PID = %u\n", getpid());

    }
}