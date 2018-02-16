#include <stdlib.h>
#include <stdio.h>
#include "listcadC.h"

linked_list *new_linked_list(int size) {
	linked_list *l = (linked_list*) malloc(sizeof(linked_list));
	l->count = 0;
	l->max = size;
	l->first = NULL;
	l->last = NULL;

	return l;
}

int is_empty(linked_list *l) {
	return l->first == NULL;
}

int is_full(linked_list *l) {
	return l == NULL || l->max == -1 ? 0 : l->count == l->max;
}

void insert_first(int x, linked_list *l) {
	if(l == NULL || is_full(l)) return;

	node *new_node = create_node(x);
	if(is_empty(l)) {
		l->first = new_node;
		new_node->next = l->first;
		l->last = new_node;
	} else {
		new_node->next = l->first;
		l->first = new_node;
	}
	l->count++;
}

node *create_node(int x) {
	node *new_node = (node*) malloc(sizeof(node));
	new_node->value= x;
	new_node->next = NULL;
	return new_node;
}

void print(linked_list *l) {
	if (l == NULL || is_empty(l))
		return;

	node *aux = l->first;
	printf("Begin:\n");
	while(aux != l->last) {
		printf("%d\n", aux->value);
		aux=aux->next;
	}
	printf("%d\n", aux->value);
	printf("End.\n");
}

void destroy_linked_list(linked_list **l) {
	if (is_empty(*l)) return;

	node *aux = (*l)->first;
	while(aux != (*l)->last) {
		node *del = aux;
		aux=aux->next;
		free(del);
	}
	free(*l);
	*l = NULL;
}

int remove_first(linked_list *l) {
	if (l == NULL || is_empty(l))
		return -1;
	node *aux = l->first;
	int x = aux->value;
	if (l->first == l->last) {
		l->first = NULL;
		l->last = NULL;
		free(aux);
		return x;
	}
	l->first = aux->next;
	l->last->next = l->first;
	free(aux);
	l->count--;
	return x;
}

void insert_last(int x, linked_list *l) {
	if(l == NULL || is_full(l)) return;
	if(is_empty(l)) {
		insert_first(x,l);
		return;
	} 
	node *new_node = create_node(x);
	new_node->next = l->first;
	l->last->next = new_node;
	l->last = new_node;
	l->count++;	
}

int remove_last(linked_list *l) {
	if (l == NULL || is_empty(l))
		return -1;
	node *aux = l->first;
	while (aux->next != l->last) {
			aux = aux->next;
	}
	node *del = aux->next;
	int x = del->value;
	aux->next = l->first;
	l->last = aux;
	free(del);
	del = NULL;
	l->count--;
	return x;
}

void remove_value(int x, linked_list *l) {
	if (l == NULL || is_empty(l))
		return;
	node *aux = l->first;
	if (aux->value == x) {
		remove_first(l);
		return;
	}
	while((aux->next->value != x) && (aux->next != l->last)) {
		aux = aux->next;
	}
	if (aux->next->value == x) {
		if (aux->next == l->last) {
			remove_last(l);
			return;
		}
		node *del = aux->next;
		aux->next = del->next;
		free(del);
		del = NULL;
		l->count--;
	}
}

void insert_at(int x, int i, linked_list *l) {
	if (is_full(l) || l == NULL) return;
	if (i > l->count) return;
	if (i == 0) {
		insert_first(x,l);
		return;
	}
	if (i == l->count) {
		insert_last(x,l);
		return;
	}
	node *new_node = create_node(x);
	node *aux = l->first;
	for (int j=0 ; j < (i-1) ; j++)
		aux = aux->next;
	new_node->next = aux->next;
	aux->next = new_node;
	l->count++;
}

int search(int x, linked_list *l) {
	if (l == NULL || is_empty(l))
		return -1;
	int j = 0;
	node *aux = l->first;
	while((aux->value != x) && (aux != l->last)) {
		aux = aux->next;
		j++;
	}
	if (aux->value == x) {
		return j;
	}
	return -1;
}