#include<stdio.h>
#include<string.h>

void penjual();
void pembeli();
void pilihmode();
int senjata[6]={0,0,0,0,0,0};int pilihan;

int main(){
	int i,input;
	printf ("===SISTEM INFORMASI KHAWARI STORE===\n\n");
	pilihmode();
	return 0;
}

void pilihmode(){
	printf("PILIH MODE\n");
	printf("1. PENJUAL\n");
	printf("2. PEMBELI\n");
	printf("INPUT: ");

	scanf("%d",&pilihan);
	printf("\n\n\n");
	if(pilihan==1) penjual();
	else pembeli();
}

void penjual(){
	printf("MODE PENJUAL\n");
	printf("1. Lihat Stock Senjata\n");
	printf("2. Tambah Stock Senjata\n");
	printf("3. Ganti Mode\n");
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
		penjual();
	}
	else if(pilihan==2){
		char masuk[10];
		int input;
		printf("TAMBAH STOCK SENJATA:\n");
		scanf("%s %d",masuk,&input);
		
		if(strcmp(masuk, "MP4A1")==0) senjata[0]+=input;
		else if(strcmp(masuk, "PM2-V1")==0) senjata[1]+=input;
		else if(strcmp(masuk, "SPR-3")==0) senjata[2]+=input;
		else if(strcmp(masuk, "SS2-V5")==0) senjata[3]+=input;
		else if(strcmp(masuk, "SPG1-V3")==0) senjata[4]+=input;
		else if(strcmp(masuk, "MINE")==0) senjata[5]+=input;

		printf("\n\n");
		penjual();
	}

	else {
		printf("\n\n");
		pilihmode();
	}
}

void pembeli(){
	printf("MODE PEMBELI\n");
	printf("1. Lihat Stock Senjata\n");
	printf("2. Beli Senjata\n");
	printf("3. Ganti Mode\n");
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
		pembeli();
	}

	else if(pilihan==2){
		char masuk[10];
		int input;
		printf("TAMBAH STOCK SENJATA:\n");
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
		pembeli();
	}

	else {
		printf("\n\n");
		pilihmode();
	}	
}

