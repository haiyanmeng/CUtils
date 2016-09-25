#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

static pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t c1 = PTHREAD_COND_INITIALIZER;
static int value = 1;

static void *threadFunc1(void *arg) {
	while(value <= 100) {
		pthread_mutex_lock(&m1);
		while(value % 2 == 0) {
			pthread_cond_wait(&c1, &m1);
		}

		if (value > 100) {
			return NULL;
		}

		fprintf(stdout, "%d\n", value);
		value++;
		pthread_mutex_unlock(&m1);
		pthread_cond_signal(&c1);
	}
	return NULL;
}

static void *threadFunc2(void *arg) {
	while(value <= 100) {
		pthread_mutex_lock(&m1);
		while(value % 2 == 1) {
			pthread_cond_wait(&c1, &m1);
		}

		if (value > 100) {
			return NULL;
		}

		fprintf(stdout, "%d\n", value);
		value++;
		pthread_mutex_unlock(&m1);
		pthread_cond_signal(&c1);
	}
	return NULL;
}

static void *threadFunc(void *arg) {
	int odd = *((int *)arg);
	while(value <= 100) {
		pthread_mutex_lock(&m1);
		if(odd == 1) {
			while(value % 2 == 0) {
				pthread_cond_wait(&c1, &m1);
			}
		} else {
			while(value % 2 == 1) {
				pthread_cond_wait(&c1, &m1);
			}
		}
	
		if (value > 100) {
			return NULL;
		}

		fprintf(stdout, "%d\n", value);
		value++;
		pthread_mutex_unlock(&m1);
		pthread_cond_signal(&c1);
	}
	return NULL;
}

int main(int argc, char *argv[]) {
	pthread_t t1, t2;
	int s;
	int odd = 1, even = 0;

	//s = pthread_create(&t2, NULL, threadFunc2, NULL);
	s = pthread_create(&t1, NULL, threadFunc, &odd);
	if(s != 0) {
		fprintf(stderr, "pthread_create failed\n");
	}

	//s = pthread_create(&t1, NULL, threadFunc1, NULL);
	s = pthread_create(&t2, NULL, threadFunc, &even);
	if(s != 0) {
		fprintf(stderr, "pthread_create failed\n");
	}

	s = pthread_join(t1, NULL);
	if(s != 0) {
		fprintf(stderr, "pthread_join failed\n");
	}

	s = pthread_join(t2, NULL);
	if(s != 0) {
		fprintf(stderr, "pthread_join failed\n");
	}
	exit(EXIT_SUCCESS);
}
