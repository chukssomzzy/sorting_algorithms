# include "sort.h"
static void remove_node(listint_t *list);
static void insert_node(listint_t *pos, listint_t *node, listint_t **);

/**
 * insertion_sort_list - sort list in ascending order
 * @list: pointer to a double linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *nxt, *cmp, *tmp_cmp;

	if (!list || !*list)
		return;
	nxt = *list;
	while (nxt)
	{
		cmp = nxt;
		tmp_cmp = nxt->prev;
		while (tmp_cmp && tmp_cmp->n > cmp->n)
		{
			remove_node(cmp);
			tmp_cmp = tmp_cmp->prev;
			insert_node(tmp_cmp, cmp, list);
			print_list(*list);
		}
		nxt = nxt->next;
	}
}
/**
 * remove_node - remove node at current position
 * @list: pointer to node to remove
 */

void remove_node(listint_t *list)
{
	listint_t *prev;

	prev =  list->prev;
	prev->next = list->next;
	if (list->next)
		list->next->prev = prev;
	list->next = NULL;
	list->prev = NULL;
}

/**
 * insert_node - insert node at position
 * @pos: position to insert node
 * @node: node to node
 * @list: pointer to linked list
 */

void insert_node(listint_t *pos, listint_t *node, listint_t **list)
{
	listint_t *tmp = pos->next;

	if (!pos)
	{
		node->next = *list;
		node->prev = NULL;
		*list = node;
		return;
	}
	pos->next = node;
	node->next = tmp;
	node->prev = pos;
	tmp->prev = node;
}
