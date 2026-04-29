#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mostrarPersonas(char *nombres[]);
void buscarNombrePorId(char *nombres[]);
int buscarNombrePorPalabra(char * Nombres[]);

int main() {
    char *Nombres[5];
    char Buff[50];  
    int tama;
    for(int i=0; i<5; i++){
        printf ("Ingrese el nombre numero %d:\n", i+1);
        scanf("%s", Buff);
        tama = strlen(Buff);
        Nombres[i] = (char *) malloc(tama * sizeof(char)+1);
        strcpy(Nombres[i], Buff);
    }
    int busq;
        printf("Cómo desea buscar nombres?\n 1. Buscar por ID\n 2. Buscar por palabra\n");
        scanf("%d", &busq);
        if(busq==1){
            buscarNombrePorId(Nombres);
        } else if (busq==2) {
            int indice = buscarNombrePorPalabra(Nombres);
            printf("Nombre encontrado: %s", Nombres[indice]);
        }
    
    for(int i=0;i<5;i++){
        free(Nombres[i]);
    }

    return 0;
}

void mostrarPersonas(char *nombres[]){
    for(int i=0;i<5;i++){
        printf("Nombre %d: %s\n", i+1, nombres[i]);
    }
}

int buscarNombrePorPalabra(char * Nombres[]){
    char Buff[50];  
    printf ("Ingrese el nombre a buscar:\n");
    scanf("%s", Buff);
    for(int i=0;i<5;i++){
        if(strstr(Nombres[i], Buff)!=NULL){
            return i;
        }
    }
    return -1;
}

void buscarNombrePorId(char *nombres[]){
    int num;
    printf("Ingrese el número (entero positivo) del nombre que desea buscar:\n");
    scanf("%d", &num);
    if(num<1 || num>5){
        printf("No se encontró el valor buscado");
    } else {
        printf("Nombre número %d: %s", num, nombres[num-1]);
    }
}
