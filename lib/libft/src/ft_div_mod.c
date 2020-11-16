/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agautier <agautier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 19:42:40 by agautier          #+#    #+#             */
/*   Updated: 2020/11/10 13:17:45 by agautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Divise les deux paramètres a et b et stocke le resultat dans l’int pointé
**	par div.
**	Elle stocke également le reste de la division de a et b dans l’int pointé
**	par mod.
*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
