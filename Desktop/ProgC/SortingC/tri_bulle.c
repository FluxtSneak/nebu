#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tptableau.h"


bool greater_than(int a, int b){
	return a >= b;
}

bool lesser_than(int a, int b){
	return a <= b;
}

void swap(int32_t* tab, int32_t a, int32_t b){
	int32_t temp = tab[a];
	tab[a] = tab[b];
	tab[b] = temp;
}


void sort(int32_t *sorted, const int32_t *const orig, int32_t nitems, bool (*comp)(int32_t, int32_t)){
	//copy tab
	for(int i = 0; i < nitems; i++){
		sorted[i] = orig[i];
	}
	//sort tab
	for(int x = nitems - 1; x > 0; x--){
		for(int i = 0; i < x; i++){
			if(comp(sorted[i], sorted[i+1])){
				swap(sorted, i, i+1);			
			}	
		}
	}
}		

void test_ordre(int size,int array[size], bool (*comp)(int32_t, int32_t)) {
   for (int i=0;i<size-1;i++) { 
      if (!comp(array[i],array[i+1]) && array[i] != array[i + 1]) {
         printf("erreur");
         return;
      }
   }
   printf("tri ok \n");
}

int main(int argc, char **argv){
    srand(time(NULL));   //change seed of rand
    if(argc<2)EXIT_FAILURE;
    int size= atoi(argv[1]);
    int32_t tab[size];
    int32_t bubble_sorted[size];
    for(int i=0; i<size;i++){
        tab[i]= rand()%500;
    }
    print_tab(tab,size);
    struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // code à mesurer
    sort(bubble_sorted, tab, size, greater_than);

    clock_gettime(CLOCK_MONOTONIC, &finish);
    double seconds_elapsed = finish.tv_sec-start.tv_sec;
    seconds_elapsed += (finish.tv_nsec-start.tv_nsec)/1.0e9;
    printf("time elapsed : %f sec \n",seconds_elapsed);
    print_tab(bubble_sorted,size);
    test_ordre(size, bubble_sorted, lesser_than);


    //Calcul moyenne et variance sur 1000 iterations
    double tabmoyvar[1000];
    double seconds_elapsed_1000 = finish.tv_sec-start.tv_sec;
    
    for (int i = 0; i<1000; i++){
    // code à mesurer 1000 fois
    for(int i=0; i<size;i++){
        tab[i]= rand()%500;
    }
    clock_gettime(CLOCK_MONOTONIC, &start);
    sort(bubble_sorted, tab, size, greater_than);
    clock_gettime(CLOCK_MONOTONIC, &finish);
    seconds_elapsed_1000 += (finish.tv_nsec-start.tv_nsec)/1.0e9;
    tabmoyvar[i] = seconds_elapsed_1000;
    }
    printf("time elapsed for 1000 iterations : %g sec \n",seconds_elapsed_1000);
    double moy = tab_moy(tabmoyvar, 1000);
    double var = tab_var(tabmoyvar, 1000);
    printf("Moyenne d'un tri : %lf Variance : %g \n", moy, var);
    return 0;
    }


