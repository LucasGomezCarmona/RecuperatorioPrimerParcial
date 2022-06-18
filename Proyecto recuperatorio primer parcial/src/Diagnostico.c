/*
 * Diagnostico.c
 *
 *  Created on: 16 jun. 2022
 *      Author: lucas
 */

#include "Diagnostico.h"

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

int mostrarDiagnosticos(Diagnostico listaDiagnosticos[])
{
	for(int i=0;i<sizeDiag;i++)
	{
		printf("\n%-4d | %10s", listaDiagnosticos[i].idDiagnostico, listaDiagnosticos[i].descripcion);
	}

	return OK;
}




