#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "myvalidations.h"

int GetNombre(char* pCadena, char* mensaje, char* mensajeError)
{
    int retorno;
    int i;
    char bufferString[16];

    do
    {
        retorno = 1;

        printf("%s", mensaje);
        fflush(stdin);
        scanf("%[^\n]", bufferString);

        if(strlen(bufferString) > sizeof(bufferString))
        {
            retorno = 0;
        }
        else
        {
            for(i=0; i<strlen(bufferString); i++)
            {
                //EXCLUI TODA LA TABLA DEL CODIGO ASCII, MENOS LOS VALORES DE LAS LETRAS MAYUSCULAS Y MINUSCULAS . TAMBIEN NO QUIERO ESPACIOS , ASI QUE SOLO ACEPTA UN NOMBRE.
                if(!((bufferString[i] >= 65 && bufferString[i] <= 90) || (bufferString[i] >= 97 && bufferString[i] <= 122)) || bufferString[i] == ' ')
                {
                    retorno = 0;
                    break;
                }
            }

        }

        if(retorno == 0)
        {
            printf("%s", mensajeError);
        }

    }while(retorno != 1);

    //Una vez obtenido un nombre valido, lo transformo a minusculas, y convierto la primer letra en mayuscula.
    strlwr(bufferString);

    bufferString[0] = toupper(bufferString[0]);

    strcpy(pCadena, bufferString);

    return retorno;
}

char GetConfirmCharacter(char mensaje[], char mensajeError[])
{
    char confirmCharacter;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &confirmCharacter);
    confirmCharacter = toupper(confirmCharacter);

    while(confirmCharacter != 'S' && confirmCharacter != 'N')
    {
        printf("%s", mensajeError);
        printf("%s", mensaje);
        fflush(stdin);
        scanf("%c", &confirmCharacter);
        confirmCharacter = toupper(confirmCharacter);
    }

    return confirmCharacter;
}
