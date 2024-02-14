/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_demical.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seohyeki <seohyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:04:44 by seohyeki          #+#    #+#             */
/*   Updated: 2024/02/14 14:09:29 by seohyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_demical(int num)
{
	ssize_t	len;
	char	*str;

	str = ft_itoa(num);
	if (str == NULL)
		return (-1);
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
