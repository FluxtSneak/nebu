#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>
#include "librairie_pile.h"

bool pile_est_valide(pile stack) {
   return (stack.capacite > 0 && stack.sommet >= -1 && stack.data != NULL);
}

bool pile_est_vide(pile stack) {
   assert(pile_est_valide(stack));
   return (-1 == stack.sommet);
}

bool pile_est_pleine(pile stack) {
   assert(pile_est_valide(stack));
   return (stack.capacite-1 == stack.sommet);
}

int pile_count(pile stack) {
   assert(pile_est_valide(stack));
   return stack.sommet+1;
}

int pile_sommet(pile stack) {
   assert(!pile_est_vide(stack));
   return stack.data[stack.sommet]; 
}

pile pile_creer(int max) {
   assert(max > 0);
   pile stack;
   stack.capacite = max;
   stack.sommet = -1;
   stack.data = malloc(max*sizeof(int));
   return stack;
}

void pile_resize(pile* stack,int max) {
   assert(pile_est_valide(*stack));
   if (max > stack->capacite) {
      stack->capacite = max;
      stack->data = realloc(stack->data,max*sizeof(int));
   }
}

void pile_detruire(pile* stack) {
   stack->capacite = -1;
   stack->sommet = INT_MIN;
   free(stack->data);
   stack->data = NULL;
}

void pile_empiler(pile* stack,int val) {
   if (pile_est_pleine(*stack)) {
      pile_resize(stack,stack->capacite+100);
   }
   stack->sommet++;
   stack->data[stack->sommet] = val;
}

int pile_depiler(pile* stack) {
   int val = pile_sommet(*stack);
   stack->sommet--;
   return val; 
}
