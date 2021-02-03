#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void *thread_function(void *para)
{
    printf("the second thread start!\n");
    // each time around sleeping five seconds and then printing out a message.
    while (1)
    {
        sleep(5);
        printf("the second thread is running!\n");
    }
    printf("the second thread finish!\n");
    return 0;
}

int main()
{
    pthread_t ntid;
    int err = pthread_create(&ntid, NULL, &thread_function, NULL);
    if (err != 0)
    {
        printf("can't create second thread\n");
        return -1;
    }
    printf("main thread: press any key to quit the second thread.\n");
    int c = getchar();
    pthread_cancel(ntid);
    pthread_join(ntid, NULL);
    return 0;
}