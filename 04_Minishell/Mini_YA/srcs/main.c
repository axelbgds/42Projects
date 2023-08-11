#include "includes/minishell.h"
#include <stddef.h>

typedef struct s_v
{
	char	*cmdl;
	int	    type;
	t_env	*myenv;
	t_tokk	*tok;
}			t_v;

int	main(int ac, char **av, char **env)
{
	t_varibles v;
    // Ignorer le signal SIGQUIT(Ctrl+\) pour quitter un processus.
	(void)av;
	(void)ac;
	signal(SIGQUIT, SIG_IGN);

    // copier (env) dans (v.myenv) pour ne pas toucher env principale.
    dupenv(&v.myenv, env);

    // Désactiver la gestion des signaux par la bibliothèque readline.
    rl_catch_signals = 0;

    while (1)
    {
        // Rediriger le signal SIGINT(Ctrl+C) vers la fonction param_sig.
        signal(SIGINT, param_sig);

        // Lire la commande entrée par l'utilisateur et la stocker dans la variable v.cmdl.
        v.cmdl = readline("minishell-$ ");

        // Si (cmdl == Ctrl+D) s'arrete
        if (v.cmdl == NULL)
            break;

        // Diviser la commande avec la fonction (Div) et stocker dans v.tok.
        v.tok = Div(v.cmdl);

        // stocker  dans v.type apres l'analyser avec la fonction parser.
        v.type = parser(&v.tok);

        // Exécuter la commande dans (myenv)
        execution(v.type, &v.myenv);

        // Si la commande n'es pas vide l'ajouter à l'historique des commandes.
        if (*v.cmdl)
            add_history(v.cmdl);

        // Libérer la mémoire allouée
        free(v.cmdl);
    }
    exit(stat);
}

