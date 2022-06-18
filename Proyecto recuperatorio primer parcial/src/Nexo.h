/*
 * Nexo.h
 *
 *  Created on: 16 jun. 2022
 *      Author: lucas
 */

#ifndef NEXO_H_
#define NEXO_H_

#include "Input.h"
#include "Servicio.h"
#include "Mecanico.h"
#include "Diagnostico.h"

//===================================================================================

/// @brief
///
/// @param listaServicios
/// @param listaMecanicos
/// @param size
/// @return int 0 OK o -1 ERROR
int agregarServicio(Servicio listaServicios[], Mecanico listaMecanicos[], int size);

//===================================================================================

/// @brief permite modificar una posicion del array lista
///
/// @param listaServicios array Servicio
/// @param listaMecanicos array Mecanico
/// @param size int
/// @return int 0 OK o -1 ERROR
int modificarServicio(Servicio listaServicios[], Mecanico listaMecanicos[], int size);

//===================================================================================

/// @brief permite diagnosticar una posicion del array lista
///
/// @param listaServicios array Servicio
/// @param listaMecanicos array Mecanico
/// @param size int
/// @return int 0 OK o -1 ERROR
int diagnosticarServicio(Servicio listaServicios[], Mecanico listaMecanicos[],Diagnostico listaDiagnosticos[],  int size);

//===================================================================================

/// @brief Muestra mecanicos sin servicio
///
/// @param auxiliar
/// @param listaMecanicos
/// @return OK o ERROR
int mostrarMecaSinServicio(Auxiliar auxiliar[], Mecanico listaMecanicos[]);

//===================================================================================

/// @brief muestra los mecanicos que no tengan ningun servicio asignado
///
/// @param listaServicios array Servicio
/// @param listaMecanicos array Mecanico
/// @param auxiliar array Auxiliar
/// @param size int
/// @return int 0 OK o -1 ERROR
int mostrarC(Servicio listaServicios[], Mecanico listaMecanicos[], Auxiliar auxiliar[], int size);

//===================================================================================

/// @brief Muestra los servicios diagnosticados
///
/// @param listaServicios
/// @param listaDiagnosticos
/// @param size
/// @return OK o ERROR
int mostrarServiciosDiagnosticados(Servicio listaServicios[],Diagnostico listaDiagnosticos[], int size);

//===================================================================================

/// @brief muestra los servicios ordenados por fecha desde el mas antiguo al mas reciente
///
/// @param listaServicios array Servicio
/// @param size int
/// @return int 0 OK o -1 ERROR
int mostrarPorFecha(Servicio listaServicios[],Diagnostico listaDiagnosticos[], int size);

//===================================================================================

/// @brief realiza el calculo de promedio de cotizacion de los mecanicos
///
/// @param auxiliar
/// @param listaMecanicos
/// @return OK o ERROR
int cotizacionPromedioMecanico(Auxiliar auxiliar[], Mecanico listaMecanicos[]);

//===================================================================================

/// @brief Inicializa la estructura auxiliar
///
/// @param listaMecanicos
/// @param auxiliar
/// @return OK o ERROR
int inicializarAux(Mecanico listaMecanicos[], Auxiliar* auxiliar[]);

//===================================================================================

/// @brief muestra el promedio de cotizacion por mecanico
///
/// @param listaServicios array Servicio
/// @param listaMecanicos array Mecanico
/// @param auxiliar array Auxiliar
/// @param size int
/// @return int 0 OK o -1 ERROR
int mostrarPromedioMecanicos(Servicio listaServicios[], Mecanico listaMecanicos[],Auxiliar auxiliar[],  int size);

//===================================================================================

/// @brief Muestra los mecanicos del punto G
///
/// @param listaMecanicos
/// @param idAux
/// @param auxiliar
/// @param contadorMayor
/// @return OK o ERROR
int mostrarMecG(Mecanico listaMecanicos[], int idAux, Auxiliar auxiliar[], int contadorMayor);

//===================================================================================

/// @brief muestra el o los mecanicos que mas servicios diagnosticaron
///
/// @param listaServicios array Servicio
/// @param listaMecanicos array Mecanico
/// @param auxiliar array Auxiliar
/// @param size int
/// @return int 0 OK o -1 ERROR
int mostrarG(Servicio listaServicios[], Mecanico listaMecanicos[], Auxiliar auxiliar[], int size);

//===================================================================================

/// @brief muestra los servicios ordenados alfabeticamente por especialidad del mecanico
///
/// @param listaServicios array Servicio
/// @param listaMecanicos array Mecanico
/// @param size int
/// @return int 0 OK o -1 ERROR
int mostrarH(Servicio listaServicios[], Mecanico listaMecanicos[], int size);

//===================================================================================

/// @brief Muestra el porcentaje de cada mecanico
///
/// @param auxiliar
/// @param listaMecanicos
/// @param contadorDiagnosticados
/// @return OK o ERROR
int mostrarPorcentaje(Auxiliar auxiliar[], Mecanico listaMecanicos[], int contadorDiagnosticados);

//===================================================================================

/// @brief muestra el porcentaje del total que atiende cada mecanico
///
/// @param listaServicios array Servicio
/// @param listaMecanicos array Mecanico
/// @param auxiliar array Auxiliar
/// @param size int
/// @return int 0 OK o -1 ERROR
int mostrarJ(Servicio listaServicios[], Mecanico listaMecanicos[],  Auxiliar auxiliar[], int size);

//===================================================================================

/// @brief Contador de diagnosticos
///
/// @param size
/// @param listaServicios
/// @param auxiliar
/// @return OK o ERROR
int contadorDiag(int size, Servicio listaServicios[],Auxiliar* auxiliar[]);

//===================================================================================

/// @brief Ordena los diagnosticos por especialidad
///
/// @param auxiliar
/// @param auxiliarD
/// @return OK o ERROR
int ordenarDiag(Auxiliar* auxiliar[], Auxiliar auxiliarD[]);

//===================================================================================

/// @brief muestra la lista correspondiente a la parte 4 del parcial
///
/// @param listaServicios
/// @param auxiliar
/// @param listaDiagnosticos
/// @param size
/// @return OK o ERROR
int mostrarParteCuatro(Servicio listaServicios[], Auxiliar auxiliar[], Diagnostico listaDiagnosticos[], int size);

//===================================================================================

#endif /* NEXO_H_ */
