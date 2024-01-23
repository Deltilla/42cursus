#include "push_swap.h"

void smoves(ti_list *lista, ti_list *listb, char *param, int ctrl)
{
	int	aux;

	if (param == "sa")
	{
		aux = lista->content;
		lista->content = lista->next->content;
		lista->next->content = aux;
	}
	if (param == "sb")
	{
		aux = listb->content;
		listb->content = listb->next->content;
		listb->next->content = aux;
	}
	if (param == "ss")
	{
		smoves (lista, listb, "sa", 0);
		smoves (lista, listb, "sb", 0);
		printf ("ss\n");
	}
	if (ctrl)
		printf("%s\n", param);
}

void sort_params(ti_list *lista, ti_list *listb, char *param)
{
    if (param == "sa")
		smoves (lista, listb, "sa", 1);
    if (param == "sb")
		smoves (lista, listb, "sb", 1);
    if (param == "ss")
		smoves (lista, listb, "ss", 0);
    /*if (param == "pa");
    if (param == "pb");
    if (param == "ra");
    if (param == "rb");
    if (param == "rr");
    if (param == "rra");
    if (param == "rrb");
    if (param == "rrr");*/
}