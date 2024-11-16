/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgottsch <lgottsch@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 14:50:00 by lgottsch          #+#    #+#             */
/*   Updated: 2024/11/15 17:40:11 by lgottsch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../full_libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
