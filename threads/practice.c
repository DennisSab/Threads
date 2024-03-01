#include <stdio.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int shared_resource = 0;

void *increment_thread(void *arg) {
    pthread_mutex_lock(&mutex); // Acquire the mutex

    shared_resource++; // Access the shared resource okokoko

    pthread_mutex_unlock(&mutex); // Release the mutex

    return NULL;
}

int main() {
    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, increment_thread, NULL);
    pthread_create(&thread2, NULL, increment_thread, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Shared resource value: %d\n", shared_resource);
    printf("siuuuuuuuu");

    return 0;
}

