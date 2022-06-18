/*
 * Diagnostico.h
 *
 *  Created on: 16 jun. 2022
 *      Author: lucas
 */

#ifndef DIAGNOSTICO_H_
#define DIAGNOSTICO_H_

#include "Input.h"

//===================================================================================

typedef struct
{
	int idDiagnostico; //PK
	char descripcion[50];
}Diagnostico;

//===================================================================================

/// @brief Muestra todos los servicios diagnosticados
///
/// @param listaDiagnosticos
/// @return OK o ERROR
int mostrarDiagnosticos(Diagnostico listaDiagnosticos[]);

//===================================================================================

#endif /* DIAGNOSTICO_H_ */
