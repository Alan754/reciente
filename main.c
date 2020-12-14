#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char procesador[20];
    char marca[20];
    float precio;
} eNotebook;

int ordenarXMarcaYPrecio(eNotebook lista[], int tam);
float calcularIVA(float precio);

int main()
{
    printf("PUNTO 3\n\n");
 eNotebook listado[5]= {{20, "Intel", "Samsumg", 1000}, {21, "AMD", "HP", 1500}, {22, "Intel", "Lenovo", 1008.5}, {23, "AMD", "HP", 1000.8}, {24, "Intel", "Asus", 1800}};

    printf("ID\tPROCESADOR\tMARCA\tPRECIO\n\n");
    printf("-------------------------------\n");
    printf("LISTA DESORDENADA \n");
    printf("-------------------------------\n");
    for(int i=0; i<5; i++)
    {
        printf("%d\t%s\t       %s\t%.2f\n", listado[i].id, listado[i].procesador, listado[i].marca, listado[i].precio);
    }
    printf("\n\nLISTA ORDENADA POR MARCA ( A, A LA Z) Y PRECIO (MENOR A MAYOR)\n");
    printf("-------------------------------\n");
    if(!ordenarXMarcaYPrecio(listado, 5))
    {
        printf("ID\tPROCESADOR\tMARCA\tPRECIO\n\n");
        for(int i=0; i<5; i++)
        {
            printf("%d\t%s\t       %s\t%.2f\n", listado[i].id, listado[i].procesador, listado[i].marca, listado[i].precio);
        }
    }
    printf("\n\n");
    printf("------------------------------------------------------------------\n\n");
    printf("PUNTO 1\n\n");
    //PUNTO !

    float precio=100;
    float descontado = calcularIVA(precio);
    printf("Precio: %.2f\nPrecio con IVA: %.2f\n", precio, descontado);

    return 0;
}

int ordenarXMarcaYPrecio(eNotebook lista[], int tam)
{
    int error=1;
    eNotebook auxNotebook;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam - 1; i++)
        {
            for(int j=i+1; j<tam; j++)
            {
                if(strcmp(lista[i].marca, lista[j].marca)>0 || (strcmp(lista[i].marca, lista[j].marca)==0 && lista[i].precio>lista[j].precio))
                {
                    auxNotebook=lista[i];
                    lista[i]=lista[j];
                    lista[j]=auxNotebook;
                }
            }
        }
        error=0;
    }
    return error;
}

float calcularIVA(float precio)
{
    float descontado;

    descontado= precio+(precio*100/21);

    return descontado;
}
