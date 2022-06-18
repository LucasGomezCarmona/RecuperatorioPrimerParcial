/*
 * Mecanico.h
 *
 *  Created on: 16 jun. 2022
 *      Author: lucas
 */

#ifndef MECANICO_H_
#define MECANICO_H_

#include "Input.h"

//===================================================================================

typedef struct
{
	int idMecanico; //PK
	char nombreMecanico[50];
	char especialidad[50];
}Mecanico;

//===================================================================================

/// @brief muestra en pantalla los mecanicos
///
/// @param listaMecanicos array Mecanico
/// @return int 0 OK o -1 ERROR
int mostrarMecanicos(Mecanico listaMecanicos[]);

//===================================================================================

#endif /* MECANICO_H_ */
