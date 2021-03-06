/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** launch_game.c
*/

#include "lemipc.h"

int			**delete_position(int **map, t_players *p)
{
	lock(p->sem_id);
	if (map[p->abscissa][p->orderly] == p->sem_id) {
		map[p->abscissa][p->orderly] = 0;
	}
	unlock(p->sem_id);
	return (map);
}

int			alive_players(int **map)
{
	int		abscissa = 0;
	int		orderly = 0;
	int		nb_players = 0;

	while (abscissa < HEIGHT_MAP) {
		while (map[abscissa][orderly]) {
			if (map[abscissa][orderly] != 0) {
				nb_players++;
			}
			orderly++;
		}
		orderly = 0;
		abscissa++;
	}
	return (nb_players);
}

int			launch_game(int **map, t_players *p)
{
	int		nb_players = 2;
	int		timer = 0;
	struct shmid_ds	remaining_players;

	while (nb_players > 1 || timer <= 10) {
		nb_players = alive_players(map);
		map = delete_position(map, p);
		lock(p->sem_id);
		map = move_player(map, p);
		unlock(p->sem_id);
		if (p->order == 1)
			my_showtab(map);
		timer += 1;
		sleep(1);
	}
	shmctl(p->shm_id, IPC_STAT, &remaining_players);
	if (remaining_players.shm_nattch < 3)
		end(p);
	return (0);
}
