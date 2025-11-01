/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imiqor <imiqor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 17:15:39 by mbenjbar          #+#    #+#             */
/*   Updated: 2025/11/01 18:32:24 by imiqor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	up(double angle)
{
	if (angle > 0 && angle < M_PI)
		return (1);
	return (0);
}

int	down(double angle)
{
	if (angle > M_PI)
		return (1);
	return (0);
}

int	right(double angle)
{
	if ((angle < 0.5 * M_PI) || (angle > 1.5 * M_PI))
		return (1);
	return (0);
}

int	left(double angle)
{
	if ((angle > 0.5 * M_PI) && (angle < 1.5 * M_PI))
		return (1);
	return (0);
}
