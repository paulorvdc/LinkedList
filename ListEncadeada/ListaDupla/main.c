#include <stdio.h>
#include <stdlib.h>
#include "listcadD.h"

void main(){
	linked_list *l = new_linked_list(-1);

	insert_first(10, l);
	insert_first(20, l);
	insert_first(30, l);
	insert_first(40, l);
	insert_first(50, l);
	insert_last(0,l);
	print(l);

	printf("Removido: %d\n",remove_first(l));
	print(l);

	printf("Removido: %d\n",remove_last(l));
	print(l);

	printf("Remover 30: \n");
	remove_value(30, l);
	print(l);

	printf("Restaurando lista: \n");
	insert_at(50,0,l);
	insert_at(30,2,l);
	insert_at(0,5,l);
	print(l);

	printf("O valor 60 esta na posicao: %d\n",search(60,l));

	destroy_linked_list(&l);
	printf("Lista destruida e sem dangling pointers? %s\n", l == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
}