#include<stdio.h>
#include<string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

int pilihan;

int main(){
	key_t key=1234;
	int *senjata;
        int shmid = shmget(key, sizeof(int), IPC_CREAT | 0666);
        senjata = shmat(shmid, NULL, 0);
	printf ("===SISTEM INFORMASI KHAWARI STORE SEBAGAI PENJUAL===\n\n");

	while(1){
		printf("1. Lihat Stock Senjata\n");
		printf("2. Beli Senjata\n");
		printf("INPUT: ");
		scanf("%d",&pilihan);
		if(pilihan==1){
			printf("STOK SENJATA\n");
			int i=0;
			while(i<6){
				if(i==0 && senjata[i]!=0) printf("MP4A1 %d\n",senjata[i]);
				else if(i==1 && senjata[i]!=0) printf("PM2-V1 %d\n",senjata[i]);
				else if(i==2 && senjata[i]!=0) printf("SPR-3 %d\n",senjata[i]);
				else if(i==3 && senjata[i]!=0) printf("SS2-V5 %d\n",senjata[i]);
				else if(i==4 && senjata[i]!=0) printf("SPG1-V3 %d\n",senjata[i]);
				else if(i==5 && senjata[i]!=0) printf("MINE %d\n", senjata[i]);		
				i++;
			}
			printf("\n\n");
		}

		else if(pilihan==2){
			char masuk[10];
			int input;
			printf("BELI STOCK SENJATA:\n");
			scanf("%s %d",masuk,&input);
		
			if(strcmp(masuk, "MP4A1")==0) {
				if(senjata[0]>=input) senjata[0]-=input;
				else printf("Barang di stock tidak cukup.");
			}
			else if(strcmp(masuk, "PM2-V1")==0) {
				if(senjata[1]>=input) senjata[1]-=input;
				else printf("Barang di stock tidak cukup.");
			}
			else if(strcmp(masuk, "SPR-3")==0){
				if(senjata[2]>=input) senjata[2]-=input;
				else printf("Barang di stock tidak cukup.");
			}
			else if(strcmp(masuk, "SS2-V5")==0) {
				if(senjata[3]>=input) senjata[3]-=input;
				else printf("Barang di stock tidak cukup.");
			}
			else if(strcmp(masuk, "SPG1-V3")==0) {
				if(senjata[4]>=input) senjata[4]-=input;
				else printf("Barang di stock tidak cukup.");
			}
			else if(strcmp(masuk, "MINE")==0) {
				if(senjata[5]>=input) senjata[5]-=input;
				else printf("Barang di stock tidak cukup.");
			}
	
			printf("\n\n");
		}
	}

	shmdt(senjata);
	shmctl(shmid, IPC_RMID, NULL);
	return 0;
}

