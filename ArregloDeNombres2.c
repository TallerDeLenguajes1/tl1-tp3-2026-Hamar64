#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void mostrarPersonas(char *nombres[]);
void buscarNombre(char *nombres[]);

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

    mostrarPersonas(Nombres);

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

void buscarNombre(char *nombres[]){
    int num;
    printf("Ingrese el número (entero positivo) del nombre que desea buscar:\n");
    scanf("%d", &num);
    if(num<1 || num>5){
        printf("No se encontró el valor buscado");
    } else {
        printf("Nombre número %d: %s", num, nombres[num-1]);
    }
}