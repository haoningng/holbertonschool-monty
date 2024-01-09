#include "monty.h"

/**
 * add_dnodeint - adds a new node at the beginning of a dlistint_t list
 * @head: pointer to pointer to dlistint_t list
 * @n: integer value of the new node
 *
 * Return: address of the new element or NULL if it failed
 */
void add_dnodeint(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new->n = n;
	new->next = *head;
	new->prev = NULL;

	if (*head != NULL)
	{
		(*head)->prev = new;
	}

	*head = new;
}

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: pointer to pointer to dlistint_t list
 * @n: integer value of the new node
 *
 * Return: address of the new element or NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new;
	stack_t *ptr;

	ptr = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		return (NULL);
	}
	new->n = n;
	new->next = NULL;
	new->prev = *head;
	if (*head == NULL)
	{
		*head = new;
		return (*head);
	}
	else
	{
		while (ptr->next != NULL)
		{
			ptr = ptr->next;
		}
		ptr->next = new;
		new->prev = ptr;
		return (new);
	}
}

/**
 * free_dlistint - frees a dlistint_t list
 * @head: the pointer to the dlistint_t list
 *
 * Return: Nothing
 */
void free_dlistint(stack_t *head)
{
	stack_t *ptr;

	if (head != NULL)
	{
		ptr = head->next;
		while (ptr != NULL)
		{
			free(head);
			head = ptr;
			ptr = ptr->next;
		}
		free(head);
	}
}
