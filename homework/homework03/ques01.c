#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#define PHILOSOPHER_NUM 5
#define MAX_SLEEP_TIME 20000

sem_t chopsticks[PHILOSOPHER_NUM];
sem_t max_current_sem;

int philosophers[PHILOSOPHER_NUM] = {0,1,2,3,4};

void random_time() {
  int cnt = rand() % MAX_SLEEP_TIME;
    for (int i = 0; i < cnt; i++) {
        int mm = 0;
        for (int j = 0; j < MAX_SLEEP_TIME; j++) {
            mm++;
        }
    }
}

void philosopher_thinking(int i) {
    random_time();
    printf("Philosopher: %d thinking time over.\n", i);
}

void philosopher_eating(int i) {
    random_time();
    printf("Philosopher: %d eating time over.\n", i);
}

void* philosopher_process(void* data) {
    int index = *((int*)data);
    int leftHand = index, rightHand = (index + 1) % PHILOSOPHER_NUM;

    while (1) {
        printf("Philosopher: %d is thinking a complex problem.\n", index);
        philosopher_thinking(index);

        printf("Philosopher: %d is hungry now and want to eat.\n", index);
        sem_wait(&max_current_sem);
        sem_wait(&chopsticks[leftHand]);
        printf("Philosopher: %d got the %d chopsticks in hand, but can not to eat.\n", index, leftHand);
        sem_wait(&chopsticks[rightHand]);
        printf("Philosopher: %d got the %d chopsticks in hand, ready to eat.\n", index, rightHand);
        philosopher_eating(index); 
        sem_post(&chopsticks[leftHand]);
        printf("Philosopher: %d released the %d left chopsticks\n", index, leftHand);
        sem_post(&max_current_sem);
        sem_post(&chopsticks[rightHand]);
        printf("Philosopher: %d released the %d right chopsticks\n", index, rightHand);
    }
}

int main() {

    srand(time(NULL));
    pthread_t philosopher_threads[PHILOSOPHER_NUM];

    for (int i = 0; i < PHILOSOPHER_NUM; i++) {
        sem_init(&chopsticks[i], 0, 1);
    }
    sem_init(&max_current_sem, 0, 4);

    for (int i = 0; i < PHILOSOPHER_NUM; i++) {
        pthread_create(&philosopher_threads[i], NULL, philosopher_process, &philosophers[i]);
    }


    for (int i = 0; i < PHILOSOPHER_NUM; i++) {
        pthread_join(philosopher_threads[i], NULL);
    }

    for (int i = 0; i < PHILOSOPHER_NUM; i++) {
        sem_destroy(&chopsticks[i]);
    }
    sem_destroy(&max_current_sem);

    return 0;
}
