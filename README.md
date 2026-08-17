# 42sh
Le projet, le mythe, la légende. 4 codeurs, 1 coquillage.

# Prérequis
## Limitations
- C pur
- `libc` seulement (`man 2`)
- Execution dans mémoire minimale
## Objectifs
- Shell minimal
- `ft_readline`
- Redirections
	- `>`
	- `>>`
	- `<`
	- `<<`
	- `>&`
	- `<&`
- pipe `|` et separotors `;`
- built-ins (POSIX)
	- `cd`
	- `echo`
	- `exit`
	- `type`
	- `export`
	- `set`
	- `unset`
	- `jobs`
	- `fg`
	- `bg`
	- `fc`
	- `alias`
	- `unalias`
	- `hash`
- Logical operators (`&&`, `||` et `!`)
- Précédence des opérateurs
- Variables
	- Variables internes
	- Local environnement
	- Expension via `${NAME}` and `$NAME`
- Jobs (`&`)
- Signaux, à architecturer
- Inhibiteurs (`"`, `'` et `\`)
- Globbing (`*`, `?`, `[]`, `!` and internals `\` ???)
- Tiled expansion
	- `~`
	- `${parameter:-word}`
	- `${parameter:=word}`
	- `${parameter:?word}`
	- `${parameter:+word}`
	- `${#parameter}`
	- `${parameter%}`
	- `${parameter%%}`
	- `${parameter#}`
	- `${parameter##}`
- Sub-shells `()` et `{};`
- Substitution `$()` `<()` `>()`
- Math `$(())`
- History
	- `!!`
	- `!word`
	- `!number`
	- `!-number`
	- File saving
	- `^R`
- Completion dynamique
	- path
	- env
	- `_command`
- Shell script
- Launch options (to be defined)
# Roadmap
## Répartion des rôles

# Norme de code
- Nom de fonctions/variables explicites
- Pseudo doxygen
- `const` when const
- `static` dès que possible
- 80 char de largeur
- nombre d'arguments, tailles de fonctions et nombres de fonctions doivent etre justifié quand excède la norme usuelle
- snake\_case (function, variables).
- kebab-case (fichiers)
- headers en debut de fichiers
- Git:
	- 1 branche par fonctionalité
	- 1 commit par truc
	- branch `master` locked
	- merge par peer-review
	- en cas de peer-review negative, reglement sur le parking

# Contributors
- [hatefulpotato](https://github.com/unicorndancing)
- [Kymaloo](https://github.com/kymaloo)
- [lmaume](https://github.com/lmaume)
- [sur4c1](https://github.com/sur4c1)
