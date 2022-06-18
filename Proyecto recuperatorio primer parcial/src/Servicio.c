/*
 * Entities.c
 *
 *  Created on: 17 may 2022
 *      Author: Lucas
 */

#include "Servicio.h"

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

int validarInicializado(Servicio listaServicios[], int size)
{
	int r = 0;
	int contador = 0;

	for(int i=0;i<size;i++)
	{
		if(listaServicios[i].estado == LIBRE)
		{
			contador++;
		}
	}

	if(contador != size)
	{
		r = -1;
	}

	return r;
}

//===================================================================================

int consultarDisponibilidad(Servicio listaServicios[], int size)
{
	int r = 0;
	int contadorlibres = 0;

		for(int i=0;i<size;i++)
		{
			if(listaServicios[i].estado == LIBRE)
			{
				contadorlibres++;
			}
		}

		if(contadorlibres == 0)
		{
			r = -1;
		}

	return r;
}

//===================================================================================

int consultarEstado(Servicio listaServicios[], int size, int id)
{
	int r=0;
	int i = id-1;
	if(listaServicios[i].estado == LIBRE)
	{
		r = -1;
	}

	return r;
}

int estadoLista(Servicio listaServicios[], int size)
{
	int r=0;
	int contador = 0;

	for(int i=0;i<size;i++)
	{
		if(listaServicios[i].estado == OCUPADO)
		{
			contador++;
		}
	}

	switch(contador)
	{
		case 0:
			printf("\nLista vacia.");
			break;

		case 10:
			printf("\nLista llena.");
			r = 1;
			break;
	}

	return r;
}

//===================================================================================

int inicializarServicios(Servicio listaServicios[], int size)
{
	int r=0;

	for(int i=0;i<size;i++)
	{
		listaServicios[i].estado = LIBRE;
		listaServicios[i].diagnostico = 0;
	}

	r = validarInicializado(listaServicios, size);

	return r;
}

//===================================================================================

int eliminarServicio(Servicio listaServicios[], int size)
{
	int r;
	int id;

	if(estadoLista(listaServicios,size) == 0)
	{
		r=1;

	}
	utn_getNumero(&id, "\nIngrese ID: ","\nERROR numero invalido", 1, size, 50);
	if(consultarEstado(listaServicios,size,id) == -1)
	{
		printf("ERROR. ID no encontrado o libre.");
		r=1;
	}

	for(int i=0;i<size;i++)
	{
		if(listaServicios[i].id == id && listaServicios[i].estado == OCUPADO && r == 0)
		{
			listaServicios[i].estado = LIBRE;
			break;
		}
	}

	return r;
}

//===================================================================================

int mostrarServicios(Servicio listaServicios[], int size)
{
	for(int i=0;i<size;i++)
	{
		if(listaServicios[i].estado == OCUPADO && listaServicios[i].diagnostico == 0 )
		{
			printf("\n%-4d | %10s | %4d/%d/%d", listaServicios[i].id, listaServicios[i].nombreCliente, listaServicios[i].fecha[0], listaServicios[i].fecha[1], listaServicios[i].fecha[2]);
		}
	}

	return OK;
}

//===================================================================================

int mostrarPuntoE(Servicio listaServicios[], int size)
{
	float acumuladorAceite = 0;
	int dia;
	int mes;
	int anio;

	utn_getNumero(&anio, "\nAño: ","\nERROR año invalido", 2000, 2022, 50);
	utn_getNumero(&mes, "\nMes: ","\nERROR mes invalido", 1, 12, 50);
	utn_getNumero(&dia, "\nDia: ","\nERROR dia invalido", 1, 31, 50);

	for(int i=0;i<size;i++)
	{
		if(listaServicios[i].fecha[0] == dia && listaServicios[i].fecha[1] == mes && listaServicios[i].fecha[2]  == anio && listaServicios[i].diagnostico == 1  && listaServicios[i].estado == OCUPADO)
		{
			acumuladorAceite = acumuladorAceite + listaServicios[i].costo;
		}
	}

	printf("\nPara el dia %4d/%d/%d la suma de cotizaciones en cambio de aceite fue: %.2f", dia, mes, anio, acumuladorAceite);

	return OK;
}

//===================================================================================

int mostrarI(Servicio listaServicios[], int size)
{
	int diagnostico;

	utn_getNumero(&diagnostico, "\nDiagnostico\n1. Cambio de aceite\n2. Reparacion de motor\n3. Suspension\nIngrese: ","\nERROR diagnostico invalido", 1, 3, 50);

	for(int i=0;i<size;i++)
		{
			if(listaServicios[i].diagnostico == diagnostico && listaServicios[i].fecha[1] >= 3 && listaServicios[i].fecha[1]>=5 && listaServicios[i].fecha[2] == 2022)
			{
				if(listaServicios[i].estado == OCUPADO)
					{
						printf("\n%-4d | %10s | %4d/%d/%d | ", listaServicios[i].id, listaServicios[i].nombreCliente, listaServicios[i].fecha[0], listaServicios[i].fecha[1], listaServicios[i].fecha[2]);
						switch(listaServicios[i].diagnostico)
						{
							case 1:
								printf("Cambio de aceite");
								break;

							case 2:
								printf("Reparacion de motor");
								break;

							case 3:
								printf("Suspension");
								break;
						}

						printf(" | %4.2f", listaServicios[i].costo);
					}
			}
		}

	return OK;
}

//===================================================================================

int mostrarSuspension(Servicio listaServicios[], int size)
{
	for(int i=0;i<size;i++)
	{
		if(listaServicios[i].diagnostico == 3 && listaServicios[i].estado == OCUPADO)
		{
			printf("\n%-4d | %10s | %4d/%d/%d | ", listaServicios[i].id, listaServicios[i].nombreCliente, listaServicios[i].fecha[0], listaServicios[i].fecha[1], listaServicios[i].fecha[2]);
			printf("Suspension");
			printf(" | %4.2f", listaServicios[i].costo);
		}
	}
	return OK;
}

//===================================================================================

int contarDiagnosticados(Servicio listaServicios[], int size)
{
	int contadorDiagnosticados=0;
	for(int i=0;i<size;i++)
	{
		if(listaServicios[i].diagnostico != 0  && listaServicios[i].estado == OCUPADO)
		{
			contadorDiagnosticados++;
		}
	}
	return contadorDiagnosticados;
}
