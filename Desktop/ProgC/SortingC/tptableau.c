#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "tptableau.h"

void init_tab(int32_t tab[], int32_t size, int32_t valmax){
	for (int i = 0; i < size; i++){
		tab[i]=rand()%valmax;
	}
}

int32_t find_min(int32_t tab[], int32_t size){
	int min = tab[0];
	for(int i = 1; i < size; i++){
		if(tab[i] < min){
			min = tab[i];
		}
	}
	return min;
}

indVal find_max(int32_t tab[], int32_t size){
	int max = tab[0];
	indVal pairMax;
	for(int i = 1; i < size; i++){
		if(tab[i] > max){
			max = tab[i];
			pairMax.ind = i;
			pairMax.val = tab[i];
		}
	}
	return pairMax;
}

void swap_max_to_last(int32_t tab[], int32_t n){
	indVal pairMax = find_max(tab,n);
	int temp_val = tab[n-1]; 
	tab[n-1] = pairMax.val;
       	tab[pairMax.ind] = temp_val;	
}

int32_t search_in_tab(int32_t tab[], int32_t n, int32_t src_n){
	int res = -1;
	for(int i = 0; i < n; i++){
		if(src_n == tab[i]){
			res = i;	
		}
	}
	return res;
}

double tab_moy(double tab[], int32_t n){
	double moy = 0;
	for(int i = 0; i < n; i++){
		moy += tab[i];
	}
	return moy/n;
}

double tab_var(double tab[], int32_t n){
	double var = 0;
	for(int i = 0; i < n; i++){
		var += pow(tab[i]-tab_moy(tab,n),2);
	}
	return var /= n;
}

void sort_tab_c(int32_t tab[], int32_t n){
	for (int i = 0; i < n; i++){
		for (int y = 1; y < n; y++){
			if(y > i){
				int tab_temp = tab[i];
				tab[i] = tab[y];
				tab[y] = tab_temp;
			}
		}
	}
}


int median_element(int32_t tab[], int32_t n){
	int med = 0;
	if(n%2 == 0){
		med = (tab[(n-1)/2] + tab[n/2]) / 2; 
	}else{
		med = tab[(n-1)/2];
	}
	return med;
}

void print_tab(int32_t tab[], int32_t n){
	printf("[");
	for (int i = 0; i < n; i++){		
		if(i == (n - 1)){
			printf("%d",tab[i]);
		}else{
			printf("%d, ",tab[i]);
		}
	}
	printf("]\n");
}
