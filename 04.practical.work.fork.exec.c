#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h> 
int main() {
    __pid_t pid1, pid2;
    pid1 = fork();

    if (pid1 == 0) {
        printf("Im child 1, launching ps -ef\n");
        char *args[] = {"/bin/ps", "-ef" , NULL};
        execvp("/bin/ps", args);
    }
    else {
        wait(NULL);
        pid2 = fork();
        if (pid2 == 0) {
            printf("\nIm child 2, launching free -h\n");
            char *args[] = {"bin/free", "-h" , NULL};
            execvp("/usr/bin/free", args);
        }
    }

}