#include "input.h"

int esCadenaVacia(char* cadena, int limite);
static int getString(char* cadena, int longitud);
static int getInt(int* pResultado);
int esNumerica(char* cadena, int limite);
int esNumericaSinSigno(char* cadena, int limite);
static int getFloat(float* pResultado);
int esFlotante(char* cadena, int limite);
static int getNombre(char* pResultado, int longitud);
int esNombre(char* cadena,int longitud);
static int getNumberAsString(char* pResultado, int longitud);
static void FormatoCUIT(char* pResultado);
int esDescripcion(char* cadena, int limite);
static int getDescripcion(char* pResultado, int longitud);

int esCadenaVacia(char* cadena, int limite)
{
	int retorno = 1;
	int i;

	for(i = 0; i<limite && cadena[i] != '\0'; i++)
	{
		if(cadena[i] != ' ')
		{
			retorno = 0;
			break;
        }
	}
	//BREAK
	return retorno;
}

/**
 * \brief 	Lee de stdin hasta que encuentra un '\n' o hasta que haya copiado en cadena
 * 			un máximo de 'longitud - 1' caracteres.
 * \param pResultado Puntero al espacio de memoria donde se copiara la cadena obtenida
 * \param longitud Define el tamaño de cadena
 * \return Retorna 0 (EXITO) si se obtiene una cadena y -1 (ERROR) si no
 *
 */
static int getString(char* cadena, int longitud)
{
    int retorno;
    char bufferString[4096];

    retorno = -1;

    if(cadena != NULL && longitud > 0)
    {
        fflush(stdin);
        if(fgets(bufferString, sizeof(bufferString), stdin) != NULL)
        {
            if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] == '\n')
            {
                bufferString[strnlen(bufferString, sizeof(bufferString))-1] = '\0';
            }

            if(strnlen(bufferString, sizeof(bufferString)) <= longitud &&
               esCadenaVacia(bufferString, longitud) == 0)
            {
                strncpy(cadena, bufferString, longitud);
                retorno = 0;
            }
        }
    }

    return retorno;
}

/**
 * \brief Obtiene un numero entero
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 *
 */
static int getInt(int* pResultado)
{
    int retorno = -1;
    char bufferString[50];

    if(	pResultado != NULL &&
    	getString(bufferString,sizeof(bufferString)) == 0 &&
    	esNumerica(bufferString,sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atoi(bufferString); //ATOI CONVIERTE UN STRING A INT.

	}

    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es numerica
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es numerica y 0 (falso) si no lo es
 *
 */
int esNumerica(char* cadena, int limite)
{
	int retorno = 1;
	int i;

	for(i = 0; i<limite && cadena[i] != '\0'; i++)
	{
		if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
		{
			continue;
		}

		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
        }
		//CONTINUE
	}
	//BREAK
	return retorno;
}

int esNumericaSinSigno(char* cadena, int limite)
{
	int retorno = 1;
	int i;

	for(i = 0; i < limite && cadena[i] != '\0'; i++)
	{
		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
        }
	}
	//BREAK

	return retorno;
}

int PedirEntero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	int retorno = -1;
	int bufferInt;

    if(pResultado != NULL && mensaje != NULL && mensajeError!= NULL && minimo <= maximo)
    {
        do
        {
            printf("%s", mensaje);

            if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo )
            {
                retorno = 0;
                *pResultado = bufferInt;
                break;
            }

            if(retorno != 0 && reintentos > 0)
            {
            	printf("%s", mensajeError);
            }

            reintentos--;

        }while(reintentos >= 0);
    }

	return retorno;
}


/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
 * \return Retorna 0 (EXITO) si se obtiene un numero flotante y -1 (ERROR) si no
 *
 */
static int getFloat(float* pResultado)
{
    int retorno = -1;
    char bufferString[50];

    if(	pResultado != NULL &&
    	getString(bufferString,sizeof(bufferString)) == 0 &&
    	esFlotante(bufferString,sizeof(bufferString)))
	{
		retorno = 0;
		*pResultado = atof(bufferString); //ATOF CONVIERTE UN STRING A FLOAT.
	}

    return retorno;
}

/**
 * \brief Verifica si la cadena ingresada es flotante
 * \param cadena Cadena de caracteres a ser analizada
 * \return Retorna 1 (vardadero) si la cadena es flotante y 0 (falso) si no lo es
 *
 */
int esFlotante(char* cadena, int limite)
{
	int retorno = 1;
	int i;
	int contadorPuntos = 0;

	if(cadena != NULL && limite > 0)
    {
        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
            if(i == 0 && (cadena[i] == '+' || cadena[i] == '-'))
            {
                continue;
            }

            if(cadena[i] > '9' || cadena[i] < '0')
            {
                if(cadena[i] == '.' && contadorPuntos == 0)
                {
                    contadorPuntos++;
                }else{
                    retorno = 0;
                    break;
                }
            }
            //CONTINUE
        }
        //BREAK
    }

	return retorno;
}

int PedirFlotante(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	int retorno = -1;
	float bufferFloat;

    if(pResultado != NULL && mensaje != NULL && mensajeError!= NULL && minimo <= maximo)
    {
        do
        {
            printf("%s", mensaje);

            if(getFloat(&bufferFloat) == 0 && bufferFloat >= minimo && bufferFloat <= maximo)
            {
                retorno = 0;
                *pResultado = bufferFloat;
                break;
            }

            if(retorno != 0 && reintentos > 0)
            {
            	printf("%s", mensajeError);
            }

            reintentos--;

        }while(reintentos >= 0);

    }

	return retorno;
}

static int getNombre(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer)) == 0 &&
    		esNombre(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer)) < longitud)
    	{
    		strncpy(pResultado,buffer,longitud);
			retorno = 0;
		}
    }

    return retorno;
}

int esNombre(char* cadena, int longitud)
{
	int i = 0;
	int retorno = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i = 0; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int PedirString(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;

	do
	{
		printf("%s", mensaje);

		if(getNombre(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) <= longitud)
		{
			strncpy(pResultado, bufferString, longitud);
			retorno = 0;
			break;
		}

		if(retorno != 0 && reintentos > 0)
		{
			printf("%s", mensajeError);
		}

		reintentos--;

	}while(reintentos >= 0);

	return retorno;
}

int GetConfirmCharacter(char* confirmC, char* mensaje, char* mensajeError, int reintentos)
{
	int rtnValue = -1;
	char confirmCharacter;

    do
    {
    	printf("%s", mensaje);
		fflush(stdin);
		scanf("%c", &confirmCharacter);
		confirmCharacter = toupper(confirmCharacter);

		if(confirmCharacter == 'S' || confirmCharacter == 'N')
		{
			*confirmC = confirmCharacter;
			rtnValue = 0;
			break;
		}

		if(rtnValue != 0 && reintentos > 0)
		{
			printf("%s", mensajeError);
		}

		reintentos--;

    }while(reintentos >= 0);

    return rtnValue;
}

static int getNumberAsString(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer)) == 0 &&
    		esNumericaSinSigno(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer)) < longitud)
    	{
    		strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int PedirNumeroComoCadena(char* pResultado, int longitud, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;

	if(pResultado != NULL && longitud > 0 && mensaje != NULL && mensajeError!= NULL)
	{
		do
		{
			printf("%s",mensaje);

			if(getNumberAsString(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud)
			{
				strncpy(pResultado, bufferString, longitud);
				retorno = 0;
				break;
			}

			if(retorno != 0 && reintentos > 0)
			{
				printf("%s", mensajeError);
			}

			reintentos--;

		}while(reintentos >= 0);
	}

	return retorno;
}

int PedirCUIT(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError!= NULL)
	{
		do
		{
			printf("%s",mensaje);

			//CUIT : 11 DIGITOS
			if(getNumberAsString(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) == 11)
			{
				strncpy(pResultado, bufferString, 11);
				FormatoCUIT(pResultado); //Transformamos la cadena a un formato de CUIT.
				retorno = 0;
				break;
			}

			if(retorno != 0 && reintentos > 0)
			{
				printf("%s", mensajeError);
			}

			reintentos--;

		}while(reintentos >= 0);
	}

	return retorno;
}

static void FormatoCUIT(char* pResultado)
{
	char bufferCUIT[14];

	bufferCUIT[0] = pResultado[0];
	bufferCUIT[1] = pResultado[1];
	bufferCUIT[2] = '-';
	bufferCUIT[3] = pResultado[2];
	bufferCUIT[4] = pResultado[3];
	bufferCUIT[5] = pResultado[4];
	bufferCUIT[6] = pResultado[5];
	bufferCUIT[7] = pResultado[6];
	bufferCUIT[8] = pResultado[7];
	bufferCUIT[9] = pResultado[8];
	bufferCUIT[10] = pResultado[9];
	bufferCUIT[11] = '-';
	bufferCUIT[12] = pResultado[10];

	strncpy(pResultado, bufferCUIT, 14);
}

int esDescripcion(char* cadena, int limite)
{
	int retorno = 1;
	int i;

	if(cadena != NULL && limite > 0)
    {
        for(i = 0; i < limite && cadena[i] != '\0'; i++)
        {
        	if(cadena[i] != '.' && cadena[i] != ' ' && (cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ) && (cadena[i] < '0' || cadena[i] > '9' ) )
			{
				retorno = 0;
				break;
			}
            //CONTINUE
        }
        //BREAK
    }

	return retorno;
}

static int getDescripcion(char* pResultado, int longitud)
{
    int retorno = -1;
    char buffer[4096];

    if(pResultado != NULL)
    {
    	if(	getString(buffer,sizeof(buffer)) == 0 &&
    		esDescripcion(buffer,sizeof(buffer)) &&
			strnlen(buffer,sizeof(buffer)) < longitud)
    	{
    		strncpy(pResultado, buffer, longitud);
			retorno = 0;
		}
    }
    return retorno;
}

int PedirDescripcion(char* pResultado, int longitud,char* mensaje, char* mensajeError, int reintentos)
{
	char bufferString[4096];
	int retorno = -1;

	if(pResultado != NULL && mensaje != NULL && mensajeError!= NULL)
	{
		do
		{
			printf("%s",mensaje);

			if(getDescripcion(bufferString,sizeof(bufferString)) == 0 && strnlen(bufferString,sizeof(bufferString)) < longitud)
			{
				strncpy(pResultado, bufferString, longitud);
				StringToUpper(pResultado, longitud);
				retorno = 0;
				break;
			}

			if(retorno != 0 && reintentos > 0)
			{
				printf("%s", mensajeError);
			}

			reintentos--;

		}while(reintentos >= 0);
	}

	return retorno;
}

int PedirDireccion(char* pResultado, int longitud, int reintentos)
{
	int retorno = -1;
	char bufferDirrecion[16];
	char bufferAltura[7];

	if(pResultado != NULL)
	{
		do
		{
			printf("\n**-DIRECCION-**");

			if(PedirDescripcion(bufferDirrecion, 16, "\n-Ingrese calle: ", "\n.ERROR! -> MAX: 15 Caracteres (incluyendo espacios).\n", 4) == 0
			&& PedirNumeroComoCadena(bufferAltura, 7, "\n-Ingrese la altura: ", "\n.ERROR! -> MAX: 6 Digitos / Solo Numeros.", 4) == 0)
			{
				//Armamos el formato de una dirrecion.
				strcpy(pResultado, bufferDirrecion);
				StringToUpper(pResultado, sizeof(bufferDirrecion));
				strcat(pResultado, " ");
				strcat(pResultado, bufferAltura);
				retorno = 0;
				break;
			}

			if(retorno != 0 && reintentos > 0)
			{
				printf("\n.ERROR! -> CALLE O ALTURA INVALIDA. Reingrese..");
			}

			reintentos--;

		}while(reintentos >= 0);
	}

	return retorno;
}

void StringToUpper(char* cadena, int limite)
{
	for(int i = 0; i < limite && cadena[i] != '\0'; i++)
	{
		cadena[i] = toupper(cadena[i]);
	}
}

void StringToLower(char* cadena, int limite)
{
	for(int i = 0; i < limite && cadena[i] != '\0'; i++)
	{
		cadena[i] = tolower(cadena[i]);
	}
}
