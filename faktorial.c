#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid;

int status;

void* factorial(void *y){
	status = 0;
	int x = (int)y;

	int i;
	int fac = 1; 
	for (i=1; i<=x; i++){
	fac = fac * i;
	}

	printf ("Hasil %d! = %d", y, fac);
	printf ("\n");
	return 0;
}

int main(int input, char *arr[]){

	pthread_t tid[100];
	char *tmp;
	
	int i;
	for (i=1; i<input; i++){
	    int j;
	    for (j=i+1; j<input; j++){
	        if (strcmp(arr[i],arr[j]) > 0){
	            tmp = arr[i];
		    arr[i] = arr[j];
		    arr[j] = tmp;
		}
	    }
	}

	for (i=1; i<input; i++){
	    char *a = arr[i];
	    char *num = a;

	    while (*num < '0' || *num > '9'){
	    num++;
	    }

	    int number = atoi(num); //atoi: mengubah string angka jadi bilangan numerik int
	    pthread_create(&(tid[i]), NULL, &factorial, (void*)number);
	}

	for (i=1; i<input; i++){
	pthread_join(tid[i], NULL);
	}
	return 0;
}
