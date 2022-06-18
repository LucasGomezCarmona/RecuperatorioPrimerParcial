/*
 * Nexo.c
 *
 *  Created on: 16 jun. 2022
 *      Author: lucas
 */

#include "Nexo.h"

//===================================================================================

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

int agregarServicio(Servicio listaServicios[], Mecanico listaMecanicos[], int size)
{
	int r=0;
	if(estadoLista(listaServicios, size) == 1)
	{
		r=1;
	}

	if(consultarDisponibilidad(listaServicios, size) == ERROR)
	{
		r=1;
	}

	for(int i=0;i<size;i++)
	{
		if(listaServicios[i].estado == LIBRE && r==0)
		{
			listaServicios[i].id = i+1;

			strcpy(listaServicios[i].nombreCliente,getString("Nombre del cliente: ", 50));

			utn_getNumero(&listaServicios[i].fecha[2], "\nAño: ","\nERROR año invalido", 2000, 2022, 50);
			utn_getNumero(&listaServicios[i].fecha[1], "\nMes: ","\nERROR mes invalido", 1, 12, 50);
			utn_getNumero(&listaServicios[i].fecha[0], "\nDia: ","\nERROR dia invalido", 1, 31, 50);

			for(int j=0;j<sizeMec;j++)
			{
				printf("\n%-4d | %10s | %4s", listaMecanicos[j].idMecanico, listaMecanicos[j].nombreMecanico, listaMecanicos[j].especialidad);
			}
			utn_getNumero(&listaServicios[i].idMecanico, "\nIngrese ID del mecanico:  ","\nERROR ID invalido", 1, 3, 50);

			listaServicios[i].estado = OCUPADO;
			r=0;
		}
	}

	return r;
}

//===================================================================================

int modificarServicio(Servicio listaServicios[],Mecanico listaMecanicos[], int size)
{
	int r=0;
	int option;
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
		if(listaServicios[i].estado == OCUPADO && listaServicios[i].id == id && r==0)
		{
			do
				{
					printf("\n1. Nombre\n2. Fecha\n3. Mecanico\n0. Salir");
					utn_getNumero(&option, "\nIngrese una opcion: ","\nERROR numero invalido", 0, 3, 50);

					switch(option)
					{
						case 1:
							printf("\nNombre del cliente: ");
							fflush(stdin);
							scanf("%s", listaServicios[i].nombreCliente);
							break;

						case 2:
							utn_getNumero(&listaServicios[i].fecha[2], "\nAño: ","\nERROR año invalido", 2000, 2022, 50);
							utn_getNumero(&listaServicios[i].fecha[1], "\nMes: ","\nERROR mes invalido", 1, 12, 50);
							utn_getNumero(&listaServicios[i].fecha[0], "\nDia: ","\nERROR dia invalido", 1, 31, 50);
							break;

						case 3:
							for(int j=0;j<3;j++)
							{
								printf("\n%-4d | %10s | %4s", listaMecanicos[j].idMecanico, listaMecanicos[j].nombreMecanico, listaMecanicos[j].especialidad);
							}
							utn_getNumero(&listaServicios[i].idMecanico, "\nIngrese ID del mecanico:  ","\nERROR ID invalido", 1, 3, 50);
							break;

						case 0:
							printf("LISTO");
							break;
					}
				}while(option != 0);
		}
	}

	return r;
}

//===================================================================================

int diagnosticarServicio(Servicio listaServicios[], Mecanico listaMecanicos[],Diagnostico listaDiagnosticos[],  int size)
{
	int r=0;
	int idMecanico;
	int id;
	int diagnostico;
	float costo;

	if(estadoLista(listaServicios,size) == 0)
	{
		r=1;
	}

	if(r==0)
	{
		utn_getNumero(&idMecanico, "\nIngrese ID del mecanico:  ","\nERROR ID invalido", 1, 3, 50);

		mostrarServicios(listaServicios, size);
		utn_getNumero(&id, "\nIngrese ID del servicio:  ","\nERROR ID invalido", 1, 1000, 50);

		mostrarDiagnosticos(listaDiagnosticos);
		utn_getNumero(&diagnostico, "\nIngrese: ","\nERROR ID invalido", 1, 6, 50);

		do{ printf("\nVuelva a intentarlo.");
		}while(validarFloat(&costo,"\nCotizacion del servicio: ") == 1);

		for(int i=0;i<size;i++)
		{
			if(listaServicios[i].id == id)
			{
				listaServicios[i].costo = costo;
			}
		}


		for(int i=0;i<size;i++)
		{
			if(listaServicios[i].id == id && listaServicios[i].estado == OCUPADO)
			{
				listaServicios[i].diagnostico = diagnostico;
				break;
			}
		}
	}

	return r;
}

//===================================================================================
//===================================================================================
//===================================================================================

int mostrarMecaSinServicio(Auxiliar auxiliar[], Mecanico listaMecanicos[])
{
	int contadorOcupados=0;

	printf("\nMecanico/s sin servicio/s:");
	for(int i=0;i<sizeMec;i++)
	{
		if(auxiliar[i].contadorServicios == 0)
		{
			printf("\n%-4d | %4s | %10s", listaMecanicos[i].idMecanico, listaMecanicos[i].nombreMecanico, listaMecanicos[i].especialidad);
		}
		else
		{
			contadorOcupados++;
		}
	}

	if(contadorOcupados == 3)
	{
		printf("\nTodos los mecanicos tienen un servicio.");
	}
	return OK;
}

//===================================================================================

int mostrarC(Servicio listaServicios[], Mecanico listaMecanicos[], Auxiliar auxiliar[], int size)
{

	for(int i=0;i<sizeMec;i++)
	{
		auxiliar[i].contadorServicios = 0;
		auxiliar[i].id = listaMecanicos[i].idMecanico;
	}

	for(int i=0;i<sizeMec;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(listaServicios[j].idMecanico == auxiliar[i].id && listaServicios[j].estado == OCUPADO)
			{
				auxiliar[i].contadorServicios ++;
			}
		}
	}

	mostrarMecaSinServicio(auxiliar,listaMecanicos);

	return OK;
}

//===================================================================================

int mostrarServiciosDiagnosticados(Servicio listaServicios[],Diagnostico listaDiagnosticos[], int size)
{
	for(int i=0;i<size;i++)
	{
		if(listaServicios[i].estado == OCUPADO && listaServicios[i].diagnostico != 0)
		{
			printf("\n%-4d | %10s | %4d/%d/%d | ", listaServicios[i].id, listaServicios[i].nombreCliente, listaServicios[i].fecha[0], listaServicios[i].fecha[1], listaServicios[i].fecha[2]);
			for(int j=0;j<sizeDiag;j++)
			{
				if(listaServicios[i].diagnostico == listaDiagnosticos[j].idDiagnostico)
				{
					printf("%s", listaDiagnosticos[j].descripcion);
				}
			}

			printf(" | %f", listaServicios[i].costo);
		}
	}

	return OK;
}

//===================================================================================

int mostrarPorFecha(Servicio listaServicios[],Diagnostico listaDiagnosticos[], int size)
{
	Servicio auxiliar[size];

	for(int i=0;i<size-1;i++)
	{
		for(int j=i+1;j<size;j++)
		{
			if(listaServicios[i].fecha[2] > listaServicios[j].fecha[2]  && listaServicios[i].estado == OCUPADO)
			{
				auxiliar[1] = listaServicios[i];
				listaServicios[i] = listaServicios[j];
				listaServicios[j] = auxiliar[1];
			}
			if(listaServicios[i].fecha[2] == listaServicios[j].fecha[2] && listaServicios[i].fecha[1] > listaServicios[j].fecha[1] && listaServicios[i].estado == OCUPADO)
			{
				auxiliar[1] = listaServicios[i];
				listaServicios[i] = listaServicios[j];
				listaServicios[j] = auxiliar[1];
			}
			if(listaServicios[i].fecha[2] == listaServicios[j].fecha[2] && listaServicios[i].fecha[1] == listaServicios[j].fecha[1] && listaServicios[i].fecha[0] > listaServicios[j].fecha[0]  && listaServicios[i].estado == OCUPADO)
			{
				auxiliar[1] = listaServicios[i];
				listaServicios[i] = listaServicios[j];
				listaServicios[j] = auxiliar[1];
			}
		}
	}

	mostrarServiciosDiagnosticados(listaServicios,listaDiagnosticos, size);

	return OK;
}

//===================================================================================

int cotizacionPromedioMecanico(Auxiliar auxiliar[], Mecanico listaMecanicos[])
{
	printf("\nCotizacion promedio de los mecanicos:");
	for(int i=0;i<sizeMec;i++)
	{
		auxiliar[i].promedioCostos = auxiliar[i].acumuladorCostos/auxiliar[i].contadorServicios;
		printf("\n%-4d | %10s | %4.2f", auxiliar[i].id, listaMecanicos[i].nombreMecanico, auxiliar[i].promedioCostos);
	}

	return OK;
}

//===================================================================================

int inicializarAux(Mecanico listaMecanicos[], Auxiliar* auxiliar[])
{
	for(int i=0;i<sizeMec;i++)
	{
		auxiliar[i]->contadorServicios = 0;
		auxiliar[i]->acumuladorCostos = 0;
		auxiliar[i]->id = listaMecanicos[i].idMecanico;
	}
	return OK;
}

//===================================================================================

int mostrarPromedioMecanicos(Servicio listaServicios[], Mecanico listaMecanicos[], Auxiliar auxiliar[], int size)
{
	Auxiliar* pAux[sizeMec];
	*pAux[sizeMec] = auxiliar[sizeMec];
	inicializarAux(listaMecanicos,pAux);

	for(int i=0;i<sizeMec;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(listaServicios[j].idMecanico == auxiliar[i].id && listaServicios[j].diagnostico != 0 && listaServicios[i].estado == OCUPADO)
			{
				auxiliar[i].contadorServicios ++;
				auxiliar[i].acumuladorCostos = auxiliar[i].acumuladorCostos + listaServicios[i].costo;
			}
		}
	}

	cotizacionPromedioMecanico(auxiliar,listaMecanicos);

	return OK;
}

int mostrarMecG(Mecanico listaMecanicos[], int idAux, Auxiliar auxiliar[], int contadorMayor)
{
	printf("\nEl/los mecanico/s con mas servicios es/son: ");
	for(int i=0;i<sizeMec;i++)
	{
		if(idAux == listaMecanicos[i].idMecanico || (idAux != listaMecanicos[i].idMecanico && auxiliar[i].contadorServicios == contadorMayor))
		{
			printf("%-4d | %10s", listaMecanicos[i].idMecanico, listaMecanicos[i].nombreMecanico);
		}
	}
	return OK;
}
//===================================================================================

int mostrarG(Servicio listaServicios[], Mecanico listaMecanicos[], Auxiliar auxiliar[], int size)
{
	Auxiliar* pAux[sizeMec];
	*pAux[sizeMec] = auxiliar[sizeMec];
	inicializarAux(listaMecanicos,pAux);

	int idAux;
	int contadorMayor;



	for(int i=0;i<sizeMec;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(listaServicios[j].idMecanico == auxiliar[i].id)
			{
				auxiliar[i].contadorServicios++;
			}
		}
	}

	if(auxiliar[0].contadorServicios >= auxiliar[1].contadorServicios && auxiliar[0].contadorServicios >= auxiliar[2].contadorServicios)
	{
		idAux = auxiliar[0].id;
		contadorMayor = auxiliar[0].contadorServicios;
	}
	if(auxiliar[1].contadorServicios >= auxiliar[0].contadorServicios && auxiliar[1].contadorServicios >= auxiliar[2].contadorServicios)
	{
		idAux = auxiliar[1].id;
		contadorMayor = auxiliar[1].contadorServicios;
	}
	if(auxiliar[2].contadorServicios >= auxiliar[0].contadorServicios && auxiliar[2].contadorServicios >= auxiliar[1].contadorServicios)
	{
		idAux = auxiliar[2].id;
		contadorMayor = auxiliar[2].contadorServicios;
	}

	mostrarMecG(listaMecanicos,idAux,auxiliar,contadorMayor);

	return OK;
}

//===================================================================================

int mostrarH(Servicio listaServicios[], Mecanico listaMecanicos[], int size)
{
	for(int i=0;i<size;i++)
	{
		if(listaServicios[i].diagnostico == 1 && listaServicios[i].estado == OCUPADO)
		{
			printf("\n%-4d | %10s | %4d/%d/%d | ", listaServicios[i].id, listaServicios[i].nombreCliente, listaServicios[i].fecha[0], listaServicios[i].fecha[1], listaServicios[i].fecha[2]);
			printf("Cambio de aceite");
			printf(" | %4.2f", listaServicios[i].costo);
		}
	}

	for(int i=0;i<size;i++)
	{
		if(listaServicios[i].diagnostico == 2 && listaServicios[i].estado == OCUPADO)
		{
			printf("\n%-4d | %10s | %4d/%d/%d | ", listaServicios[i].id, listaServicios[i].nombreCliente, listaServicios[i].fecha[0], listaServicios[i].fecha[1], listaServicios[i].fecha[2]);
			printf("Reparacion de motor");
			printf(" | %4.2f", listaServicios[i].costo);
		}
	}

	mostrarSuspension(listaServicios, size);
	return OK;
}

//===================================================================================

int mostrarPorcentaje(Auxiliar auxiliar[], Mecanico listaMecanicos[], int contadorDiagnosticados)
{
	float porcentaje;

	for(int i=0;i<sizeMec;i++)
	{
		porcentaje = (100*auxiliar[i].contadorServicios)/contadorDiagnosticados;

		for(int i=0;i<sizeMec;i++)
		{
			printf("\n%-4d | %4s | %10.2f", listaMecanicos[i].idMecanico, listaMecanicos[i].nombreMecanico, porcentaje);
		}
	}
	return OK;
}
//===================================================================================

int mostrarJ(Servicio listaServicios[], Mecanico listaMecanicos[],  Auxiliar auxiliar[], int size)
{
	int contadorDiagnosticados = 0;
	Auxiliar* pAux[sizeMec];
	*pAux[sizeMec] = auxiliar[sizeMec];
	inicializarAux(listaMecanicos,pAux);

	for(int i=0;i<sizeMec;i++)
	{
		for(int j=0;j<size;j++)
		{
			if(listaServicios[j].idMecanico == auxiliar[i].id)
			{
				auxiliar[i].contadorServicios++;
			}
		}
	}

	contadorDiagnosticados = contarDiagnosticados(listaServicios,size);

	mostrarPorcentaje(auxiliar,listaMecanicos,contadorDiagnosticados);

	return OK;
}

//===================================================================================

int contadorDiag(int size, Servicio listaServicios[],Auxiliar* auxiliar[])
{
	for(int i=0;i<size;i++)
	{
		for(int j=0;j<sizeDiag;j++)
		{
			if(listaServicios[i].diagnostico == auxiliar[j]->id)
			{
				auxiliar[j]->contadorDiagnosticados ++;
			}
		}
	}

	return OK;
}

//===================================================================================

int ordenarDiag(Auxiliar* auxiliar[], Auxiliar auxiliarD[])
{
	for(int i=0;i<sizeDiag-1;i++)
	{
		for(int j=i+1;j<sizeDiag;j++)
		{
			if(auxiliar[i]->contadorDiagnosticados < auxiliar[j]->contadorDiagnosticados)
			{
				auxiliarD[1] = *auxiliar[i];
				auxiliar[i] = auxiliar[j];
				*auxiliar[j] = auxiliarD[1];
			}
		}
	}

	return OK;
}

//===================================================================================

int printDiag(Auxiliar auxiliar[],Diagnostico listaDiagnosticos[])
{
	int pos = 0;
	for(int i=0;i<sizeMec;i++)
	{
		pos ++;
		printf("%d. ", pos);
		for(int j=0;j<sizeDiag;j++)
		{
			if(auxiliar[i].id == listaDiagnosticos[j].idDiagnostico)
			{
				printf("%-4d | %s ", listaDiagnosticos[j].idDiagnostico, listaDiagnosticos[j].descripcion);
			}
		}
	}
	return OK;
}
//===================================================================================

int mostrarParteCuatro(Servicio listaServicios[], Auxiliar auxiliar[], Diagnostico listaDiagnosticos[], int size)
{
	Auxiliar* pAux[sizeMec];
	*pAux[sizeMec] = auxiliar[sizeMec];

	Auxiliar auxiliarD[1];
	for(int i=0;i<sizeDiag;i++)
	{
		auxiliar[i].id = listaDiagnosticos[i].idDiagnostico;
		auxiliar[i].contadorDiagnosticados = 0;
	}

	contadorDiag(size,listaServicios,pAux);

	ordenarDiag(pAux, auxiliarD);

	printDiag(auxiliar,listaDiagnosticos);

	return OK;
}
