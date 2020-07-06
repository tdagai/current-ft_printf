/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_g_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 14:08:32 by teva              #+#    #+#             */
/*   Updated: 2020/07/03 14:57:34 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
char	*wrapper_g(va_list ap, char c, t_flags flags)
{
	t_g_var v;

	v.dbl = flags.capital_l ? va_arg(ap, long double) : va_arg(ap, double);
	v.prec = pf_float_precision(flags);
	v = pf_sci_g(&v, flags);
	v = pf_float_g(&v);
	pf_cap

}

t_g_var	pf_sci_g(t_g_var *v, t_flags flags)
{
	v->x = ft_dtosci_for_g(&v->str_e, v.dbl, v.prec - 1, flags);
	return (*v);
}

t_g_var	pf_float_g(t_g_var *v)
{
	v->prec -= (v->x + 1);
	v->str_f = ft_dtoa_for_g(v->dbl, v->prec, 10);
	return (*v);
}

*/
