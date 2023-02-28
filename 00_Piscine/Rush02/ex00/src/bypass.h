/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bypass.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsharma <tsharma@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 17:05:57 by tsharma           #+#    #+#             */
/*   Updated: 2022/02/13 17:12:52 by tsharma          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BYPASS_H
# define BYPASS_H

# include "structs.h"

struct s_bypass
{
	struct s_dict_entry	*entries;
	int					entryc;
};

#endif