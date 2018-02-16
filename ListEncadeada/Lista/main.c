#include <stdio.h>
#include <stdlib.h>
#include "listcad.h"

void main(){
	linked_list *l = new_linked_list(-1);

	insert_last(10, l);
	insert_last(20, l);
	insert_last(30, l);
	insert_last(40, l);
	insert_last(50, l);
	insert_last(60, l);
	insert_last(70, l);
	insert_last(80, l);

	print(l);

	printf("Removido: %d\n",remove_first(l));
	print(l);

	insert_first(10, l);
	print(l);

	printf("Removido: %d\n",remove_last(l));
	print(l);

	printf("Remover 50: \n");
	remove_value(50, l);
	print(l);

	printf("Reinserindo 50: \n");
	insert_at(50,4,l);
	print(l);

	printf("Colocando valores de 5 em 5: \n");
	insert_at(15,1,l);
	insert_at(25,3,l);
	insert_at(35,5,l);
	insert_at(45,7,l);
	insert_at(55,9,l);
	insert_at(65,11,l);
	insert_at(75,13,l);
	print(l);

	printf("O valor 80 esta na posicao: %d\n",search(80,l));
	
	destroy_linked_list(&l);
	printf("Lista destruida e sem dangling pointers? %s\n", l == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
}