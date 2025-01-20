/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_format.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftomaz-c <ftomaz-c@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 20:56:10 by ftomaz-c          #+#    #+#             */
/*   Updated: 2023/09/05 16:09:04 by ftomaz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

int	nbr_format(int nbr)
{
	int	len;

	len = nbr_len(nbr);
	ft_putnbr_fd(nbr, 1);
	return (len);
}
