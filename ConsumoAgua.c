#include<stdio.h>
#include<stdlib.h>
#include"librerias.h"
/*integrantes:
Julio Cesar Arguello Palomeque
Juan jesus Magaña Palomeque
Luis Alberto Iturria Mendez
Felix Roberto Joo Cordero
Samuel de la cruz Lopez*/
float consumo_agua[51][7] = {0},reduccion_agua = 0.0, promedio_agua[51], promedio_global = 0, promedio_semana = 0;
float suma_global = 0, max[51], porcentaje_reduccion,ahorro_agua;
int dias = 0, opcion,semana_registro,entrada=1,Semana_extra,semana = 0,j,i,semanas_imprimir;
int simular_ahorro,Consumo_excesivo=0,Consumo_global=0,c;
int main(){
do{
/*Menu principal*/
menu();
/*Toma la opcion que ingreso el usuario y evalua en cual de los casos entra*/
switch (opcion)
{
case 1:
if(entrada == 1) {
    /*Registro de las semanas*/
        Registro_semana();
        
        while(semana<semana_registro) {
            if(semana % 4 == 0) {
                printf("\nMes %d\n",(semana/4)+1);
            }
        printf("Semana %d\n",semana +1);
        while (dias < 7)
                {
                        /*Mandamos a llamar a la funcion para registrar el consumo de agua en un dia*/
                        Registro_dia( dias,semana,consumo_agua);
                        /*Identificando el umbral*/
                        /*Aqui se compara si la cantidad de agua que se introduce es mayor a 300 litros se lanza una alerta*/
                        if (consumo_agua[semana][dias] >= 300)  
                        {
                            printf("¡ALERTA! CONSUMO EXCESIVO DE AGUA O POSIBLE FUGA DE AGUA\n");
                        }
                        promedio_agua[semana] +=  consumo_agua[semana][dias];
                        /*Maximo*/
                        max[semana] = Maximo(dias,semana,consumo_agua,max);
                        dias ++;
                }
        printf("\n");
        entrada = 2;
        dias = 0; 
        semana ++;
    }
    /*le dise al usuario si quiere agregar una nueva semana despues de registrar sus primeras semanas*/
        nueva_semana( Semana_extra, &semana, dias, consumo_agua, max, promedio_agua); 
}
else {
    /*si el usuario ingresa nuevamente a la opcion 1 el programa preguntara si quiere agregar una nueva semana*/
        nueva_semana( Semana_extra, &semana, dias, consumo_agua, max, promedio_agua); 
    
}
            break;
case 2: 
    /*Si el usuario seleccion la opcion 2 se pregunta cuantas semanas se van a imprimir e imprime cada una de las semanas
    mostrando la cantidad de agua consumida, el umbral, el promedio, el porcentaje del umbral en una semana*/
        impresion_semana(semanas_imprimir,i,j,consumo_agua,Consumo_excesivo,Consumo_global,promedio_agua,promedio_semana,promedio_global,suma_global);
            break;
case 3:/*Reporte global*/
    /*Se imprmien unicamente la semana sin los dias y el total de agua consumida en esa semana ademas del promedio de agua
    consumida en esa semana*/
        Reporte_global(semana,j,promedio_agua);
    
        promedio_global = suma_global / semana;
        printf("\n/===========================================================\\\n");
        printf("El total de agua consumida en todas las semanas es de: %0.2f \n", suma_global);
        printf("El promedio total de agua es de: %0.2f \n", promedio_global);
        printf("\\===========================================================/\n");
        promedio_global = 0;
        suma_global = 0;
        limpieza_codigo(c);
            break;
case 4:
        /*Simulador de reduccion de agua*/
        do{
        printf("\n/====================================\\ \n");
        printf("De cuanto quiere su reduccion de agua: \n");
        if(scanf("%d", &simular_ahorro) != 1 || simular_ahorro <=0) {
            printf("Error el programa no permite caracteres solo numeros mayores a 0\n");
            /*En caso de marcar el error limpia el scanf para que no guarde ese valor erroneo*/
            limpieza_codigo(c);
            simular_ahorro = 0;
        }
        }while(simular_ahorro <=0);
        /*Se pide la semana que quiere hacer la simulacion de ahorro*/
        do{
        printf("Que semana quiere reduccir: \n");
        if(scanf("%d", &semanas_imprimir) != 1 || semanas_imprimir <=0) {
            printf("Error el programa no permite caracteres solo numeros mayores a 0\n");
            /*En caso de marcar el error limpia el scanf para que no guarde ese valor erroneo*/
            limpieza_codigo( c);
            semanas_imprimir = 0;
        }
        }while(semanas_imprimir <= 0);
        /*Se obtiene el procentaje de la reduccion y despues se resta con el consumo_agua*/
        simular_reduccion(porcentaje_reduccion,semanas_imprimir,simular_ahorro, ahorro_agua,consumo_agua,reduccion_agua); 
        break;
case 5:
printf("Saliendo.....\n");
printf("Programa terminado\n");
break;
default: 
        printf("opcion no valida\n");
        break;

} }while (opcion != 5);

    return 0;
}