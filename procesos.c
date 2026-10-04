#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    int n=10000;
    pid_t pid = fork(); 
    if (pid < 0) {
        perror("Fork failed");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        for(int i=10000; i>=0; i--){
            printf("%d\n", i);
        }
        printf("Child process: PID = %d\n", getpid());
    } else {
        for(int i=0; i<=n; i++){
            printf("%d\n", i);
        }
        printf("Parent process: PID = %d, Child PID = %d\n", getpid(), pid);
    }
    return 0;
}