#include <pthread.h>
#include <stdio.h>

const int N_PROCESS=10;
int nParam;
pthread_mutex_t mutex;
void * Thread (void * arg) {
	int nMyParam;
	nMyParam = nParam;

	printf("nMyParam: %d, arg: %d, ", nMyParam ,(int)arg);
	if(nMyParam == (int)arg)
		printf("ok");
	else
		printf("bug !!!!!");
	printf("\n");
	pthread_mutex_unlock(&mutex);
	pthread_detach(pthread_self());
	return NULL;
}

int main (int argc, char *argv[]) {
	int i;
	pthread_t writer_id;

		printf("\nExemple de bug-MUTEX et passage de parametres.\n\n");
		pthread_mutex_init(&mutex, NULL);
		//pthread_mutex_lock(&mutex);
	for (i = 0; i < N_PROCESS; i++) {
		nParam = i;
	pthread_create (&writer_id, NULL, Thread, (void *)i);
	pthread_mutex_lock(&mutex);
	}
	pthread_mutex_destroy(&mutex);
	pthread_exit (NULL);
	return 0;
} 