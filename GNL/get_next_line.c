/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkaerts <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 19:23:26 by pkaerts           #+#    #+#             */
/*   Updated: 2021/02/19 19:23:28 by pkaerts          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Ceci ne constitue pas un programme dans le sens ou le main, qui a ici été préparé par moi-même afin de tester le programme, devra être absent du rendu. Ces fonctions seront appellées par le main du programme qui corrigera mon travail
//Le programme sera expliqué en détail dans le pdf enovyé en annexe qui est le pdf que j'ai moi-même obtenu en tant qu'explication de l'exercice que je dois accomplir
//mais pour le résumer il consiste en lire dans un fichier ou une entrée sortie standard la première ligne, l'enregistrant dans la chaîne de caractère passée en paramètre à la fonciton et renverra un valeur égale à -1, 0 ou 1
//-1: Erreur. 0: Nous avons atteint la fin du fichier. 1: Voici la ligne, mais nous n'avons pas atteint le fichier.
//La fonction get_next_line si appellée plusieurs fois, devra donc pouvoir envoyer une à une chaque ligne jusqu'à la fin du fichier

#include "get_next_line.h"
#include <fcntl.h>

int	check_rest(char **rest, char **line)// Cette fonction sert à analyser si le reste de l'appel de fonction précédent doit-être entièrement ajouté à la nouvelle ligne ou si une partie seulement doit-être extraite car le reste contient plus d'un ligne
{
	size_t	i;
	char	*tmp;// un variable temporaire dans laquelle je stockerai temporairement le reste si je dois en extraire uniquement un partie et récupérer l'autre

	i = ft_strchr(*rest, '\n');// Je cherche un caractère de fin de ligne dans le programme et localise (et retient) sa position si il est présent
	if (i > 0)//	Si le caractère est présent je stockerai tout ce qui se situe avant dans la nouvelle ligne et stockerai dans le reste ce qu'il se situe après
	{
		if (i == 1)// Si la valeur est égale à 1 cela signifie que la ligne est uniquement composée d'un retour à la ligne je gère donc ce cas particulier en copiant un ligne vide
			*line = ft_strdup("");
		else
			*line = ft_strjoin_gnl(*line, *rest, '\n');//Sinon j'ajouterai simplement le contenu jusqu'au caractère de fin de ligne
		tmp = ft_strdup(*rest + i);//Je stocke la ligne à partir du caractère après le caractère de fin de ligne 
		ft_strdel(rest);// Je libère la mémoire du reste
		*rest = ft_strdup(tmp);// Je recupère dans le reste, ce que j'ai stocké dans la variable temporaire gardant uniquement le nouveau reste
		ft_strdel(&tmp);// Je libère à son tour la variable temporaire
		return (1);
	}
	*line = ft_strdup(*rest);//Si le caractère est absent je copie juste l'entièreté du reste dans la ligne et je libère le reste
	ft_strdel(rest);
	return (2);
}

int	read_line(int fd, char *buffer, char **rest, char **line)//Cette fonction lira à l'aide de read le fichier donné jusqu'à atteindre le '\n' signalant une fin de ligne, et stockera ce qui est lu après la ligne dans la variable rest afin de ne pas être oublié lors d'un appel de fonction suivant
{
	size_t	i;
	size_t	ret;

	ret = 1;// La valeur démarre à un afin de pouvoir entrer dans la boucle une première fois
	while (ret > 0)
	{
//		printf("\tCheck read line\n");
		ret = read(fd, buffer, BUFFER_SIZE);//lit le buffer et retient la valeur retour de read afin de vérifier si le bon nombre de caractères a été lu
		printf("\tCheck ret : %zu\n", i);// un test visant à vérifier la valeur retour, celui-ci m'intrigue considérant que les valeurs renvoyées ne semble pas être en accord avec ce que le man prétend que la fonction est censée renvoyer
		if (ret > BUFFER_SIZE)// Si la valeur retour(étant censée être gale au nombre de caractères lus) est inférieurs à celle qui est censée être lue cela indique à priori que j'ai atteint la fin du fichier et que je n'aurais plus besoin d'utiliser le read
			return (0);
		if (ret < 1)//Si il n'a rien lu c'est que la fin du fichier avait déjà été atteinte ou que le fichier est vide
			return (ret);
		buffer[ret] = '\0';
		i = ft_strchr(buffer, '\n');// Cette fonction me renverra la une valeur égale à l'emplacement du caractère passé en apramètre s'il est présent +1, 0 si il est absent
//		printf("\tCheck 1\n");// Différents tests afin de vérifier le contenu de mes variables à cet instant dans le programme
//		printf("\tCheck buffer: %s\n", buffer);	
//		printf("\tCheck line: %s\n", *line);	
//		printf("\tCheck i: %zu\n", i);	
		if (i)// Si le caractère est présent le buffer sera copié jusqu'au caractère de fin de ligne et ce qu'il se trouve après (si il se trouve quelque chose) sera stocké dans la variable statique rest
		{
//			printf("\tCheck\n");
			*line = ft_strjoin_gnl(*line, buffer, '\n');
			if (buffer[i])
				*rest = ft_strdup(buffer + i);
			return (1);
		}
		*line = ft_strjoin_gnl(*line, buffer, '\0');//Sinon l'entièreté du buffer sera ajoutée à la ligne et la boucle se relancera
	}
	return (0);
}

int	get_next_line(int fd, char **line) //la fonction principale du projet. Celle qui sera appellée par le main du programme de correction
{
	char		buffer[BUFFER_SIZE + 1];//	Il est possible que l'on ait durant le dernier appel de open avant le EOF(end of file) pas besoin de l'entièreté de la taille de cette chaîne, mais ça e devrait jamais causer problème
	static char	*rest;//	Cette variable retiendra ce que le buffer a lu après le caractère de fin de ligne afin de pouvoir l'ajouter au début de la lecture de la ligne suivante
	int			ret;//	Cette variable retiendra les valeurs de retour des autres fonctions afin de savoir si tout s'est passé comme prévu

	ret = 2;// Je démarre la valeur retour à 2 afin qu'elle entre dans mes conditions une première fois
	if (fd < 0 || read(fd, buffer, 0) == -1 || fd > FOPEN_MAX)// Je vérifie s'il y a un soucis avec les données reçues qui empêcherait le programme de fonctionner correctement
		return (-1);
//	printf("\tCheck rest: %s\n", rest); Un test visant à vérifer le contenu du rest
	if (rest && ret > 1)//	Je vérifie s'il y a un reste d'un appel de fonction précédent
		ret = check_rest(&rest, line);
	while (ret > 1)//S'il n'y a pas de rest d'appel de fonction précédent je vais lire le premier ou le buffer suivant
	{
		ret = read_line(fd, buffer, &rest, line);
	}
	if (!*line)// Je renvoie un ligne vide pour gérer la cas ou on m'enverrait un fichier vide
		*line = ft_strdup("");
	return (ret);
}


int		main(void)// Ce main est un main que j'ai préparé personnellement afin de tester mon programme, il ne sera pas présent dans le rendu et doit-être mis en commentaire afin d'utiliser les test faits par d'autres personnes
{
	int     fd = open("text.txt",O_RDONLY);
	char    *line = NULL;
	int 	line_nbr = 1;
	int 	 nb;

	while ((nb = get_next_line(fd, &line)) >= 0)
	{
		printf("Ligne %d : %s\n", line_nbr, line);
		ft_strdel(&line);
		line_nbr++;
		if (nb == 0)
			break;
	}
	return 0;
}

//compile with: gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o prog

//J'ai joint dans le dossier quelques test préaprés par d'autres élèves lorsqu'il rendaient eux-même leur travail, mis par après à disposition des élèves à venir. On ne peut pas garantir que passer ces tests permettra de passer le programme de correction de l'école, ni qu'échouer ces tests nous empêchera de passer le programme de correction de l'école.
//Uniquement que des élèves qui ont passé le correcteur de l'école ont rendu un travail qui passait aussi ces cest tests(Pas forcément les trois)
//https://github.com/charMstr/GNL_lover GNL lover est retrouvable ici avec les instructions laissées par le créateur du test et se lance à priori comme ça $>./GNL_lover.sh
//https://github.com/mrjvs/42cursus_gnl_tests pour 42cursus_gnl_tests et se lance avec des commandes make
//https://github.com/Mazoise/42TESTERS-GNL contient 42TESTERS-GNL et se lance avec bash all_tests.sh