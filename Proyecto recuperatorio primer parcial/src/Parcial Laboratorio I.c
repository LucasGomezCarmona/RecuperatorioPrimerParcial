/*
 ============================================================================
 Name        : Parcial.c
 Author      :
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "Nexo.h"

//===================================================================================

#define size 10
#define sizeMec 3
#define LIBRE 0
#define OCUPADO 1

//===================================================================================

int main(void)
{
	setbuf(stdout, NULL);
	int option;
	int optionSub;

	Auxiliar auxiliar[3];
	Servicio listaServicios[size];
	Mecanico listaMecanicos[sizeMec] = {{1, "Hector", "Aceite"},
								  	  	{2, "Carlos", "Motor"},
										{3, "Ricardo", "Suspension"}};

	Diagnostico listaDiagnosticos[6] = {{1,"Aceite"},{2,"Motor"},{3,"Suspension"},{4,"Audio"},{5,"Ploteado"},{6,"Pintura"}};


	inicializarServicios(listaServicios, size);
	printf("Taller mecanico");
	do
			{
				printf("\n1. Agregar servicio\n2. Modificar servicio\n3. Eliminar servicio\n4. Diagnosticar\n5. Informar servicios\n0. Salir");
				utn_getNumero(&option, "\nIngrese una opcion: ","\nERROR numero invalido", 0, 5, 50);

				switch(option)
				{
					case 0:
						printf("\nGracias por usar el programa");
						break;

					case 1:
						agregarServicio(listaServicios,listaMecanicos,size);
						break;

					case 2:
						modificarServicio(listaServicios,listaMecanicos,size);
						break;

					case 3:
						eliminarServicio(listaServicios,size);
						break;

					case 4:
						diagnosticarServicio(listaServicios,listaMecanicos,listaDiagnosticos,size);
						break;

					case 5:
						if(estadoLista(listaServicios,size) == 0)
						{
							printf("\nLista vacia.");
							break;
						}
						do
						{
							printf("\n1. Todos los mecanicos"
									"\n2.Todos los servicios"
									"\n3. Todos los mec�nicos a los cuales no se les haya asignado ning�n servicio"
									"\n4. Listado de servicios ordenados por fecha, desde el m�s antiguo hasta el m�s reciente"
									"\n5. Para una fecha determinada se necesita saber cu�l fue la suma de cotizaciones en concepto de cambio de aceite."
									"\n6. Cotizaci�n promedio de cada uno de los mec�nicos"
									"\n7. Determinar cu�l/cu�les son los mec�nicos que diagnosticaron m�s servicios."
									"\n8. Listado de servicios ordenados por especialidad del mec�nico alfab�ticamente"
									"\n9. Listado de todos los servicios entre el mes de Marzo y Mayo del 2022 para una especialidad determinada"
									"\n10. Porcentaje de servicio diagnosticados que atiende cada mec�nico en funci�n del total de diagn�sticos"
									"\n11. Mostrar parte 4 parcial"
									"\n0. Salir");
							utn_getNumero(&optionSub, "\nIngrese una opcion: ","\nERROR numero invalido", 0, 11, 50);

							switch(optionSub)
							{
								case 0:
									printf("\nVolviendo al menu principal.");
									break;

								case 1:
									mostrarMecanicos(listaMecanicos);
									break;

								case 2:
									mostrarServicios(listaServicios,size);
									break;

								case 3:
									mostrarC(listaServicios,listaMecanicos,auxiliar,size);
									break;

								case 4:
									mostrarPorFecha(listaServicios,listaDiagnosticos,size);
									break;

								case 5:
									mostrarPuntoE(listaServicios,size);
									break;

								case 6:
									mostrarPromedioMecanicos(listaServicios,listaMecanicos,auxiliar,size);
									break;

								case 7:
									mostrarG(listaServicios,listaMecanicos,auxiliar,size);
									break;

								case 8:
									mostrarH(listaServicios,listaMecanicos,size);
									break;

								case 9:
									mostrarI(listaServicios,size);
									break;

								case 10:
									mostrarJ(listaServicios,listaMecanicos,auxiliar,size);
									break;

								case 11:
									mostrarParteCuatro(listaServicios,auxiliar,listaDiagnosticos,size);
									break;
							}
						}while(optionSub != 0);
						break;

				}
			}while(option != 0);

	return EXIT_SUCCESS;
}
