# Minishell
Minishell est un projet qui demande de recréer un shell miniature.<br />
Celui-ci doit afficher un prompt et attendre des inputs. (+ Historique)<br />
Il doit gérer :<br />
- les simple/double quotes et ne pas interpréter les quotes non fermés<br />
- Les redirections ( > , < , >> , << )<br />
- Implémenter les pipes<br />
- Gérer les variables d’environnement<br />
- Gérer $?<br />
- Gérer ctrl-C, ctrl-D et ctrl-\<br />

Il doit également permettre d'utiliser les commandes bash, certaines recodées, d'autres via le PATH d'env.<br />
Les commades à recoder étaient :<br />
- echo (et -n)<br />
- cd uniquement avec un chemin relatif ou absolu<br />
- pwd sans aucune option<br />
- export sans aucune option<br />
- unset sans aucune option<br />
- env sans aucune option ni argument<br />
- exit sans aucune option<br />

# Utilisation

> $>./minishell<br />
