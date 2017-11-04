#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdlib.h>

pthread_t tid[5];
int hewan[2];

void* lohangabut(void *end){
	while(1){
		sleep(10);
		hewan[0]-=15;
	}
}

void* kepitinggabut(void *end){
	while(1){
		sleep(20);
		hewan[1]-=20;
	}
}

void* kepitingmakan(void *end){
	hewan[1]+=10;
}

void* lohanmakan(void *end){
	hewan[0]+=10;
}

void* cekstatus(void *end){
        printf("Status Lohan: %d\n", hewan[0]);
		printf("Status Kepiting: %d\n",hewan[1]);
}
int main(void){
	hewan[0]=100; //lohan
	hewan[1]=100; //kepiting
	int pilih;
	pthread_create(&(tid[0]),NULL,lohangabut,NULL);
	pthread_create(&(tid[1]),NULL,kepitinggabut,NULL);
	printf("PILIHAN KEGIATAN:\n");
	printf("1. Beri makan Lohan\n");
	printf("2. Beri makan Kepiting\n");
    printf("3. Cek Status Saat Ini\n");

	while(scanf("%d",&pilih)){
        if(pilih==1){
			pthread_create(&(tid[2]),NULL,lohanmakan,NULL);	
		}
		else if(pilih==2){
			pthread_create(&(tid[3]),NULL,kepitingmakan,NULL);		
		}
        else if(pilih==3){
            pthread_create(&(tid[4]),NULL,cekstatus,NULL);
        }
        if(hewan[0]>100 || hewan[1]>100 ||hewan[0]<0||hewan[1]<0){
			printf("===GAME TELAH BERAKHIR===\n\n\n");
			break;
		}
	}
	return 0;
}
