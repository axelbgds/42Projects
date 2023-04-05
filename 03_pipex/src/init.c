/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeaugra <abeaugra@student.42perp.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 11:34:18 by abeaugra          #+#    #+#             */
/*   Updated: 2023/04/05 11:15:14 by abeaugra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
/* La structure t_data contient des informations sur les fichiers d'entrée et de 
** sortie, les commandes à exécuter, les arguments, les variables d'environnement, 
** etc.*/

/* clean_init: Initialise une nouvelle structure de données t_data avec des valeurs
vides (chaînes à NULL et entiers à -1). Cette fonction renvoie la structure de 
données initialisée.*/
static t_data   clean_init(void)
{
    t_data  data;
    
    data.envp = NULL;
    data.ac = -1;
    data.av = NULL;
    data.heredoc = 0;
    data.fd_in = -1;
    data.fd_out = -1;
    data.pipe = NULL;
    data.nb_cmds = -1;
    data.child = -1;
    data.pids = NULL;
    data.cmd_options = NULL;
    data.cmd_path = NULL;
    return(data);
}

/*  generate_pipes: Crée une paire de descripteurs de fichiers pour chaque commande à
exécuter dans le pipeline. Les pipes sont stockés dans le tableau data->pipe.*/
static void generate_pipes(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nb_cmds - 1)
    {
        if (pipe(data->pipe + 2 * i) == -1)
            exit_error(msg("Could not create pipe", " ", "", 1), data);
        i++;
    }
}

/* init: Initialise la structure de données t_data en utilisant les arguments et les 
** variables d'environnement passés au programme. Cette fonction remplit la structure 
** data avec les informations nécessaires, telles que les fichiers d'entrée et de sortie,
** le nombre de commandes, et alloue de la mémoire pour les tableaux de descripteurs de 
** fichiers de pipe et de processus. Enfin, elle appelle la fonction generate_pipes pour 
** initialiser les pipes.*/
t_data  init(int ac, char **av, char **envp)
{
    t_data  data;

    data = clean_init();
    data.envp = envp;
    data.ac = ac;
    data.av = av;
    if (!ft_strncmp("here_doc", av[1], 9))
        data.heredoc = 1;
    get_input_file(&data);
    get_output_file(&data);
    data.nb_cmds = ac - 3 - data.heredoc;
    data.pids = malloc(sizeof * data.pids * data.nb_cmds);
    if (!data.pids)
        exit_error(msg("PID error", strerror(errno), "", 1), &data);
    data.pipe = malloc(sizeof * data.pipe * 2 *(data.nb_cmds - 1));
    if (!data.pipe)
        exit_error(msg("Pipe error", "", "", 1), &data);
    generate_pipes(&data);
    return (data);
}