#include <stdio.h>
#include <stdlib.h>
#include "listcadC.h"

void main(){
	linked_list *l = new_linked_list(-1);

	insert_last(20, l);
	insert_last(30, l);
	insert_last(40, l);
	insert_last(50, l);
	insert_first(10, l);
	insert_last(60, l);
	insert_last(70, l);
	insert_last(80, l);
	print(l);

	printf("Removido: %d\n",remove_first(l));
	print(l);

	printf("Removido: %d\n",remove_last(l));
	print(l);

	printf("Removido: 40\n");
	remove_value(40,l);
	print(l);

	printf("Restaurando a lista para primeiro print: \n");
	insert_at(10,0,l);
	insert_at(40,3,l);
	insert_at(80,7,l);
	print(l);

	printf("O valor 80 esta na posicao: %d\n",search(80,l));

	destroy_linked_list(&l);
	printf("Lista destruida e sem dangling pointers? %s\n", l == NULL ? "Sure!" : "Wah Wah Wah Waaaaaaaah!");
}