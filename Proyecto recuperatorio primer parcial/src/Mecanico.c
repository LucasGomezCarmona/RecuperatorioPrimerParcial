/*
 * Mecanico.c
 *
 *  Created on: 16 jun. 2022
 *      Author: lucas
 */

#include "Mecanico.h"

#define size 10
#define sizeDiag 6
#define sizeMec 3
#define LIBRE 0
#define OCUPADO 1
#define OK 0
#define ERROR -1
#define ACEITE 1
#define MOTOR 2
#define SUSPENSION 3

//===================================================================================

int mostrarMecanicos(Mecanico listaMecanicos[])
{
	for(int i=0;i<sizeMec;i++)
	{
		printf("\n%-4d | %4s | %10s", listaMecanicos[i].idMecanico, listaMecanicos[i].nombreMecanico, listaMecanicos[i].especialidad);
	}

	return OK;
}
