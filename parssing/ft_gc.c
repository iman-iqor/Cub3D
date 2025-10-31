/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:20:44 by imiqor            #+#    #+#             */
/*   Updated: 2025/10/31 15:50:52 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

//  *   Append the given node `new` to the end of the singly-linked list
//  *   referenced by `*gc`. If the list is empty (*gc == NULL), the new node
//  *   becomes the head. If `new` is NULL, this function does nothing.
void	add(t_gc **gc, t_gc *new)
{
	t_gc	*ptr;

	if (new)
	{
		ptr = *gc;
		while (ptr && ptr->next)
			ptr = ptr->next;
		if (ptr)
			ptr->next = new;
		else
			*gc = new;
	}
}

// * create - Allocate and initialize a new t_gc tracking node.
//  *
//  * Description:
//  *   Allocate a t_gc node, initialize its `ptr` field with the supplied
//  *   pointer and set `next` to NULL.
//  *
//  * Parameters:
//  *   ptr - the pointer to be tracked by the new node; this function does not
//  *         copy the pointed-to memory, it only stores the pointer value.
//  *
//  * Returns:
//  *   Pointer to the newly allocated t_gc node on success.
//  *   NULL if memory allocation for the node fails.
t_gc	*create(void *ptr)
{
	t_gc	*gc;

	gc = malloc(sizeof(t_gc));
	if (!gc)
	{
		return (NULL);
	}
	gc->ptr = ptr;
	gc->next = NULL;
	return (gc);
}

//  * fr_ee - Free an entire t_gc tracking list and the memory it tracks.
//  *
//  * Description:
//  *   Iterate over the supplied t_gc list and for each node:
//  *     - free the node->ptr if it is non-NULL,
//  *     - free the node itself.
void	fr_ee(t_gc *gc)
{
	t_gc	*next;

	next = NULL;
	while (gc)
	{
		next = gc->next;
		if (gc->ptr)
			free(gc->ptr);
		if (gc)
			free(gc);
		gc = next;
	}
}

// By making gc static, the variable
// Is initialized only once, the first time the function runs.
// Persists across all future calls to ft_gc.
// Keeps track of all allocated nodes you’ve added through previous calls.
void	*ft_gc(size_t n, char flag)
{
	static t_gc	*gc;
	void		*ptr;
	t_gc		*new;

	if (flag == 'm')
	{
		ptr = malloc(n);
		if (ptr == NULL)
			return (NULL);
		new = create(ptr);
		if (new == NULL)
		{
			free(ptr);
			return (NULL);
		}
		add(&gc, new);
		return (ptr);
	}
	else if (flag == 'f')
		fr_ee(gc);
	return (NULL);
}
