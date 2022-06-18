/*
 * Entities.h
 *
 *  Created on: 17 may 2022
 *      Author: Lucas
 */

#ifndef ENTITIES_H_
#define ENTITIES_H_

#include "Input.h"

//===================================================================================

typedef struct
{
	int id; //PK
	char nombreCliente[50];
	int fecha[3];
	int diagnostico; //FK
	float costo;
	int idMecanico; //FK
	int estado;
}Servicio;

//===================================================================================

typedef struct{
	int id;
	int contadorServicios;
	float acumuladorCostos;
	float promedioCostos;
	int contadorDiagnosticados;
}Auxiliar;

//===================================================================================

/// @brief Inicializa todas las posiciones del array listaServicios
///
/// @param listaServicios array Servicio
/// @param size int
/// @return int 0 OK -1 ERROR
int validarInicializado(Servicio listaServicios[], int size);

//===================================================================================

/// @brief consulta la disponibilidad del array listaServicios
///
/// @param listaServicios array Servicio
/// @param size int
/// @return int 0 SI 1 NO
int consultarDisponibilidad(Servicio listaServicios[], int size);

//===================================================================================

/// @brief consulta el estado de un servicio ingresando el id
///
/// @param listaServicios array Servicio
/// @param size int
/// @param id int
/// @return -1 LIBRE 0 OCUPADO
int consultarEstado(Servicio listaServicios[], int size, int id);

//===================================================================================

/// @brief consulta el estado de la lista
///
/// @param listaServicios array Servicio
/// @param size int
/// @return int 0 vacia 1 llena
int estadoLista(Servicio listaServicios[], int size);

//===================================================================================

/// @brief inicializa todas las posiciones del array lista
///
/// @param listaServicios array Servicio
/// @param size int
/// @return 0 OK
int inicializarServicios(Servicio listaServicios[], int size);

//===================================================================================

/// @brief permite eliminar un servicio del array lista
///
/// @param listaServicios array Servicio
/// @param size int
/// @return int 0 OK o -1 ERROR
int eliminarServicio(Servicio listaServicios[], int size);

//===================================================================================

/// @brief Muestra todos los servicios
///
/// @param listaServicios
/// @param size
/// @return OK o ERROR
int mostrarServicios(Servicio listaServicios[], int size);

//===================================================================================

/// @brief muestra todos los servicios de una fecha determinada por el usuario
///
/// @param listaServicios array Servicio
/// @param size int
/// @return int 0 OK o -1 ERROR
int mostrarPuntoE(Servicio listaServicios[], int size);

//===================================================================================

/// @brief muestra todos los servicios entre marzo y mayo del 2022
///
/// @param listaServicios array Servicio
/// @param size int
/// @return int 0 OK o -1 ERROR
int mostrarI(Servicio listaServicios[], int size);

//===================================================================================

/// @brief muestra todos los servicios de la especialidad suspension
///
/// @param listaServicios
/// @param size
/// @return OK o ERROR
int mostrarSuspension(Servicio listaServicios[], int size);

//===================================================================================

/// @brief Cuenta los diagnosticados totales
///
/// @param listaServicios
/// @param size
/// @return OK o ERROR
int contarDiagnosticados(Servicio listaServicios[], int size);

//===================================================================================



#endif /* ENTITIES_H_ */

