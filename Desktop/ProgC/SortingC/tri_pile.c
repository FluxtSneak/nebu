#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "tptableau.h"
#include "librairie_pile.h"

bool greater_than(int a, int b){
	return a > b;
}

bool lesser_than(int a, int b){
	return a < b;
}

void stack_transfert(pile *stk, pile *stk2){
    pile_empiler(stk2, pile_depiler(stk));
}

void sort(int32_t *sorted, const int32_t *const orig, int32_t nitems, bool (*comp)(int32_t, int32_t)){
    pile g,d;
    g = pile_creer(nitems);
    d = pile_creer(nitems);
    
    pile_empiler(&g, orig[0]);
    
    for(int i=0; i<nitems;i++){
        
        while(!pile_est_vide(g) && comp(orig[i], pile_sommet(g))){ 
            stack_transfert(&g,&d);
        }
        while(!pile_est_vide(d) && !comp(orig[i] ,pile_sommet(d))){
            stack_transfert(&d, &g);
        }
        pile_empiler(&g,orig[i]);
    }
    while(!pile_est_vide(d)){
        stack_transfert(&d, &g);
    }
    for(int i=0; i<nitems; i++){
        sorted[i]=pile_depiler(&g);
    }
    pile_detruire(&d);
    pile_detruire(&g);

}

void test_ordre(int size,int array[size], bool (*comp)(int32_t, int32_t)) {
   for (int i=0;i<size-1;i++) { 
      if (!comp(array[i],array[i+1]) && array[i] != array[i + 1]) {
         printf("erreur");
         return;
      }
   }
   printf("tri ok \n \n");
}

int main(int argc, char **argv){
    srand(time(NULL));   //change seed of rand
    if(argc<2)EXIT_FAILURE;
    int size= atoi(argv[1]);
    int32_t tab[size];
    int32_t stack_sorted[size];
    for(int i=0; i<size;i++){
        tab[i]= rand()%500;
    }
    print_tab(tab,size);
    struct timespec start, finish;
    clock_gettime(CLOCK_MONOTONIC, &start);

    // code à mesurer
    sort(stack_sorted, tab, size, greater_than);

    clock_gettime(CLOCK_MONOTONIC, &finish);
    double seconds_elapsed = finish.tv_sec-start.tv_sec;
    seconds_elapsed += (finish.tv_nsec-start.tv_nsec)/1.0e9;
    printf("time elapsed : %g sec \n",seconds_elapsed);
    print_tab(stack_sorted,size);
    test_ordre(size, stack_sorted, lesser_than);


    //Calcul moyenne et variance sur 1000 iterations
    double tabmoyvar[1000];
    double seconds_elapsed_1000 = finish.tv_sec-start.tv_sec;
    
    for (int i = 0; i<1000; i++){
    // code à mesurer 1000 fois
    for(int i=0; i<size;i++){
        tab[i]= rand()%500;
    }
    clock_gettime(CLOCK_MONOTONIC, &start);
    sort(stack_sorted, tab, size, greater_than);
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
