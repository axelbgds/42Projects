/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 10:46:29 by abeaugra          #+#    #+#             */
/*   Updated: 2023/07/26 16:12:39 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>
# include "../libft/libft.h"

// typedef struct s_varibles
// {
// 	char	*cmdl;
// 	int	    type;
// 	t_env	*myenv;
// 	t_tokk	*tok;
// }			t_varibles;

char	*read_command(void);

#endif
