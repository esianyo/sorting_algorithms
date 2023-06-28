#include "sort.h"
#include <stdlib.h>

/**
 * listint_len - Calculates the length of a doubly linked list
 * @list: Pointer to the head of the list
 * Return: Length of the list
 */
size_t listint_len(const listint_t *list)
{
	size_t count = 0;
	const listint_t *current = list;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	return count;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers using
 *                        the insertion sort algorithm
 * @list: Pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	listint_t *sorted;
	listint_t *unsorted = *list;
	listint_t *current;
	listint_t *temp;

	while (unsorted != NULL)
	{
		current = unsorted;

		unsorted = unsorted->next;

		sorted = NULL;

		if (sorted == NULL || current->n < sorted->n)
		{
			current->next = sorted;
			if (sorted != NULL)
				sorted->prev = current;
			sorted = current;
		}
		else
		{
			temp = sorted;

			while (temp->next != NULL && temp->next->n < current->n)
				temp = temp->next;

			current->next = temp->next;
			if (temp->next != NULL)
				temp->next->prev = current;
			temp->next = current;
			current->prev = temp;
		}

		if (current->prev == NULL)
			*list = current;

		print_list(*list);
	}
}
