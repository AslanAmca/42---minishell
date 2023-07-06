/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 07:56:55 by aaslan            #+#    #+#             */
/*   Updated: 2023/06/20 13:50:43 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	*ft_memset(void *s, int c, size_t n)
{
	void	*s_address;

	s_address = s;
	while (0 < n)
	{
		*(unsigned char *)s = (unsigned char)c;
		s++;
		n--;
	}
	return (s_address);
}
