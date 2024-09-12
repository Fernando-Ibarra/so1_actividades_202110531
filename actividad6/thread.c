#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

// Función para el hilo
void* thread_function(void* arg) {
    printf("Hilo creado en el proceso con PID: %d\n", getpid());
    return NULL;
}

int main() {
    pid_t pid;
    pthread_t thread;

    pid = fork();
    
    if (pid == 0) {  // Proceso hijo
        printf("Proceso hijo con PID: %d\n", getpid());
        fork();  // El proceso hijo crea otro proceso
        printf("Proceso nieto creado\n");

        // Crea un hilo dentro del proceso hijo
        if (pthread_create(&thread, NULL, thread_function, NULL)) {
            fprintf(stderr, "Error creando el hilo\n");
            return 1;
        }

        // Espera a que termine el hilo
        pthread_join(thread, NULL);
    }

    // Proceso padre y cualquier proceso creado anteriormente ejecutan otro fork()
    fork();  
    printf("Proceso con PID: %d\n", getpid());

    return 0;
}