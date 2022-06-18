/*
 * Input.c
 *
 *  Created on: 17 may 2022
 *      Author: Lucas
 */

#include "Input.h"

//===================================================================================

int ValidateString (char *B)
{
	int i;
	        for (i = 0; B[i] != '\0'; i++)
	        {
	               if (!(B[i] >= 65 && B[i] <= 90) && !(B[i] >= 97 && B[i] <= 122) && !(B[i] >= 48 && B[i] <= 57))
	              {
	                    return 0;
	              }
	       }
	       return 1;
}

//===================================================================================

char getString(char message[], int size)
{
	char cadena[size];

	printf("%s", message);
	scanf("%s", *cadena);


	return cadena;
}

//===========================================================================

int myGets(char* cadena, int longitud)
{
	fflush(stdin);
	fgets(cadena, longitud, stdin);
	cadena[strlen(cadena)-1] = '\0';

	return 0;
}

//===========================================================================

int esNumerica(char* cadena)
{
int retorno = 1;
int i=0;

	if(cadena[0] == '-')
	{
		i = 1;
	}

	for( ; cadena[i] != '\0'; i++)
	{
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}
return retorno;
}

//===========================================================================

int getInt(int* pResultado)
{
int retorno = -1;
char bufferString[4096];

if(myGets(bufferString, sizeof(bufferString)) == 0 && esNumerica(bufferString))
{
	retorno = 0;
	*pResultado = atoi(bufferString);
}
return retorno;
}

//===========================================================================

int utn_getNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
int retorno = -1;
int bufferInt;

if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
{
	do
	{
		printf("%s", mensaje);
			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
				break;
			}
		reintentos--;
		printf("%s", mensajeError);
	}while(reintentos >= 0);
}
return retorno;
}

//===========================================================================

int validarFloat(float* input, char mensaje[])
{
	int r=0;
	char aux[20];
	float *auxiliar;

	printf("%s", mensaje);
	scanf(auxiliar);
	input = auxiliar;

	if(input != NULL)
	{
		sprintf(aux,"%f",*input);
		for(int i=0;i<strlen(aux);i++)
		{
			if(!isdigit(input[i]))
			{
				r=1;
			}
		}
	}

	return r;
}

//===========================================================================

int validarAlfanumerico(char variable[]) // valida el si el dato es alfanumerico
{
	int retorno = 1;
	int i;

		for(i=0 ; i<strlen(variable); i++)
		{
			if(!((variable[i]>=65 && variable[i]<=90)||	(variable[i]>=97 && variable[i]<=122)||
				(variable[i]>='0' && variable[i]<='9')))
			{
				printf("\nError ingrese un codigo de vuelo valido");
				retorno = 0;
				break;
			}
		}
	return retorno;
}

//===========================================================================

void PedirAlfanumerico(char* nombre[], char mensaje[]) // Piede el dato alfanumerico
{
	int retorno;

		do{
	         printf("\n%s", mensaje);
	         scanf("%s", &nombre);
	         retorno = validarAlfanumerico(nombre);

	     }while(retorno == 0);
}

//===========================================================================

