#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <time.h>
#include "tptableau.h"

void print(int size,int tab[size]) {
   for (int i=0;i<size;i++) {
      printf("%d ",tab[i]);
   }
}

void random_tab(int size,int tab[size],int inf,int sup){
   assert(sup > inf);
   for (int i=0;i<size;i++) {
      tab[i] = inf+rand()%(sup-inf);
   }
}

void swap(int* p_a,int* p_b) { 
   int tmp = *p_a;
   *p_a = *p_b;
   *p_b = tmp;
}

// Partition du tableau <array> autour d'une valeur pivot:
int partition(int size,int array[size],int first,int last,bool (*comp)(int32_t, int32_t)) {
   int pivot = array[last];
   int i = first-1,j = last;
   while(true) {
   	// à compléter pour <i>: do {...} while (...);
        do{
            i++;
        } while (comp(array[i],pivot));
    // à compléter pour <j>: do {...} while (...);
        do{
            j--;
        } while(!comp(array[j],pivot));

        if (i >= j) {
      		break;
	    }
        swap(&array[i], &array[j]);
    }
   swap(&array[i],&array[last]);
   return i;
}

// Tri rapide récursif
void quicksort(int size,int array[size],int first,int last, bool (*comp)(int32_t, int32_t)) {
   if (first < last) {
      int midpoint = partition(size,array,first,last,comp);
      if (first < midpoint-1) {
         quicksort(size,array,first,midpoint-1,comp);
      }
      if (midpoint+1 < last) {
         quicksort(size,array,midpoint+1,last,comp);
      }
   }
}

// Test si le tableau <array> est ordonné croissant
void test_ordre(int size,int array[size], bool (*comp)(int32_t, int32_t)) {
   for (int i=0;i<size-1;i++) { 
      if (!comp(array[i],array[i+1]) && array[i] != array[i + 1]) {
         printf("erreur");
         return;
      }
   }
   printf("tri ok \n");
}

bool greater_than(int a, int b){
	return a > b;
}

bool lesser_than(int a, int b){
	return a < b;
}

void sort(int32_t *sorted, const int32_t *const orig, int32_t nitems, bool (*comp)(int32_t, int32_t)){
	//copy tab
	for(int i = 0; i < nitems; i++){
		sorted[i] = orig[i];
	}
	//sort tab
	quicksort(nitems, sorted, 0, nitems - 1, comp);
}	

int main(int argc, char **argv){
    srand(time(NULL));   //change seed of rand
    if(argc<2) EXIT_FAILURE;
    int size= atoi(argv[1]);
    int tab[size];
    int quick_sorted[size];
    for(int i=0; i<size;i++){
        tab[i]= rand()%50;
    }
    print_tab(tab,size);
    struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // code à mesurer
    sort(quick_sorted, tab, size, greater_than);

    clock_gettime(CLOCK_MONOTONIC, &finish);
    double seconds_elapsed = finish.tv_sec-start.tv_sec;
    seconds_elapsed += (finish.tv_nsec-start.tv_nsec)/1.0e9;
    printf("time elapsed : %f sec \n",seconds_elapsed);
    print_tab(quick_sorted,size);
    test_ordre(size, quick_sorted, greater_than);



    //Calcul moyenne et variance sur 1000 iterations
    double tabmoyvar[1000];
    double seconds_elapsed_1000 = finish.tv_sec-start.tv_sec;
    
    for (int i = 0; i<1000; i++){
    // code à mesurer 1000 fois
    for(int i=0; i<size;i++){
        tab[i]= rand()%500;
    }
    clock_gettime(CLOCK_MONOTONIC, &start);
    sort(quick_sorted, tab, size, greater_than);
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

