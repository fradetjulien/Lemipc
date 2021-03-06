/*
** EPITECH PROJECT, 2018
** lemipc
** File description:
** end.c
*/

#include "lemipc.h"

void		end(t_players *p)
{
	shmctl(p->shm_id, IPC_RMID, NULL);
	semctl(p->sem_id, 0, IPC_RMID, 0);
	printf("Team %d wins the game\n", p->team_id);
	free(p->player_name);
	free(p);
}
