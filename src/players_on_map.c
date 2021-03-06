/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** players_on_map.c
*/

#include "lemipc.h"

int		is_free(t_players *p, int **map)
{
	if (map[p->abscissa][p->orderly] == 0) {
		return (0);
	}
	return (-1);
}

int		players_on_map(t_players *p, int **map)
{
	while (is_free(p, map) == -1) {
		srand(time(NULL));
		p->abscissa = rand() % HEIGHT_MAP;
		p->orderly = rand() % WIDTH_MAP;
	}
	if (is_free(p, map) == 0) {
		lock(p->sem_id);
		map[p->abscissa][p->orderly] = p->team_id;
		unlock(p->sem_id);
	}
	return (0);
}
