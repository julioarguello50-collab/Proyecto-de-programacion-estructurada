#include<stdio.h>
#include<stdlib.h>
#include"librerias.h"
/*integrantes:
Julio Cesar Arguello Palomeque
Juan jesus Magaña Palomeque
Luis Alberto Iturria Mendez
Felix Roberto Joo Cordero
Samuel de la cruz Lopez*/
float consumo_agua[51][7] = {0},reduccion_agua = 0.0, promedio_agua[51], mes = 0, semana = 0;
float suma = 0, max[51], reduccion,reduccion2;
int repetir = 0, opcion,semana_registro,entrada=1,Semana_extra,contador = 0,j,i,semanas_imprimir;
int simular_ahorro,Consumo_excesivo=0,Consumo_global=0;
int main(){
do{
/*Menu principal*/
menu();

switch (opcion)
{
case 1:
if(entrada == 1) {
    /*Registro de las semanas*/
         Registro_semana();
        
        while(contador<semana_registro) {
            if(contador % 4 == 0) {
                printf("Mes %d\n",(contador/4)+1);
            }
        printf("Semana %d\n",contador +1);
        while (repetir < 7)
                {
                        /*Registro de los dias consumiendo agua*/
                        Registro_dia( repetir,contador,consumo_agua);
                        /*Identificando el umbral*/
                        if (consumo_agua[contador][repetir] >= 300)  
                          {
                             printf("¡ALERTA! CONSUMO EXCESIVO DE AGUA O POSIBLE FUGA DE AGUA\n");
                          }
                        promedio_agua[contador] +=  consumo_agua[contador][repetir];
                        /*Maximo*/
                         max[contador] = Maximo(repetir,contador,consumo_agua,max);
                        repetir ++;
                }
        printf("\n");
        entrada = 2;
        repetir = 0; 
        contador ++;
    }
    /*le dise al usuario si quiere agregar una nueva semana despues de registrar sus primeras semanas*/
         nueva_semana( Semana_extra, &contador, repetir, consumo_agua, max, promedio_agua); 
}
 else {
    /*si el usuario ingresa nuevamente a la opcion 1 el programa preguntara si quiere agregar una nueva semana*/
        nueva_semana( Semana_extra, &contador, repetir, consumo_agua, max, promedio_agua); 
    
}
            break;
case 2: 
        impresion_semana(semanas_imprimir,i,j,consumo_agua,Consumo_excesivo,Consumo_global,promedio_agua,semana,mes,suma);
            break;
case 3:/*Reporte global*/
    /*Se imprmien unicamente la semana sin los dias y el total de agua consumida en esa semana ademas del promedio de agua
    consumida en esa semana*/
        Reporte_global(contador,j,promedio_agua);
    
        mes = suma / contador;
        printf("El total de agua consumida en todas las semanas es de: %0.2f \n", suma);
        printf("El promedio total de agua es de: %0.2f \n", mes);
        suma = 0;
        system("pause");
        system("cls");
            break;
case 4:
        /*Simulador de reduccion de agua*/
        printf("De cuanto quiere su reduccion de agua: \n");
        scanf("%d", &simular_ahorro);
        printf("\n");
        /*Se pide la semana que quiere hacer la simulacion de ahorro*/
        printf("Que semana quiere reduccir: \n");
        scanf("%d", &semanas_imprimir);
        /*Se obtiene el procentaje de la reduccion y despues se resta con el consumo_agua*/
       simular_reduccion(reduccion,semanas_imprimir,simular_ahorro, reduccion2,consumo_agua,reduccion_agua); 
        break;
case 5: 
printf("Programa terminado\n");
break;
default: 
        printf("opcion no valida\n");
        break;

    }
}while (opcion != 5);

    return 0;
}