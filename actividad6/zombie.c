#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(1);
    }

    if (pid == 0) {
        // Código del proceso hijo
        printf("Soy el proceso hijo con PID: %d\n", getpid());
        // El proceso hijo termina inmediatamente
        exit(0);
    } else {
        // Código del proceso padre
        printf("Soy el proceso padre con PID: %d, el hijo tiene PID: %d\n", getpid(), pid);

        // Espera 60 segundos antes de terminar
        sleep(60);

        // Espera a que el hijo termine, liberando el estado zombie
        wait(NULL);

        printf("El proceso hijo (PID: %d) ya ha sido eliminado\n", pid);
    }

    return 0;
}