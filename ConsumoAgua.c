#include<stdio.h>
#include<stdlib.h>
/*integrantes:
Julio Cesar Arguello Palomeque
Juan jesus Magaña Palomeque
Luis Alberto Iturria Mendez
Felix Roberto Joo Cordero
Samuel de la cruz Lopez*/
int main(){
float consumo_agua[51][7] = {0},reduccion_agua = 0.0, promedio_agua[51], mes = 0, semana = 0;
float suma = 0, max[51], reduccion,reduccion2;
int repetir = 0, opcion,semana_registro,entrada=1,Semana_extra,contador = 0,j,i,semanas_imprimir;
int simular_ahorro,Consumo_excesivo=0,Consumo_global=0;
do{
/*Menu principal*/
printf("[1] --- Consumo por dia de agua\n[2] --- Reporte semanal\n[3] --- Reporte global\n[4] --- Simulacion de ahorro\n[5] --- salir\n");
printf("Ingrese una opcion: \n");
scanf("%d", &opcion);
printf("\n");
system("cls");

switch (opcion)
{
case 1:
if(entrada == 1) {
    /*Registro de las semanas*/
    do {
          printf("Cuantas semanas va a registrar?");
          scanf("%d",&semana_registro);
         if(semana_registro <=0) {
         printf("opcion invalida\nSolo acepta numeros mayores a 0\n");
            }
        }while(semana_registro <=0);
        
        while(contador<semana_registro) {
        printf("Semana %d\n",contador +1);
        while (repetir < 7)
                {
                        /*Registro de los dias consumiendo agua*/
                        printf("Consumo del dia %d en litros: \n", repetir + 1);
                        scanf("%f", &consumo_agua[contador][repetir]);
                        /*Identificando el umbral*/
                        if (consumo_agua[contador][repetir] >= 300)  
                          {
                             printf("¡ALERTA! CONSUMO EXCESIVO DE AGUA O POSIBLE FUGA DE AGUA\n");
                          }
                        promedio_agua[contador] +=  consumo_agua[contador][repetir];
                        /*Maximo*/
            if(repetir==0) {
                max[contador] = consumo_agua[contador][repetir];
            } else {
                if(consumo_agua[contador][repetir] > max[contador]) max[contador] = consumo_agua[contador][repetir];
            }
                repetir ++;
                }
        printf("\n");
        entrada = 2;
        repetir = 0; 
        contador ++;
    }
} else {
    /*Para agregar una semana mas a las que ya tenia registrada*/
    /*si escoge uno realiza lo siguente*/
    printf("quieres agregar una semana mas? \n1. si\n2. salir\n");
    scanf("%d",&Semana_extra);
    switch(Semana_extra) {
            case 1:
            printf("Semana %d\n",contador+1);
            while (repetir < 7)
        {
            printf("Consumo del dia %d en litros: \n", repetir + 1);
            scanf("%f", &consumo_agua[contador][repetir]);
            /*Aqui se compara si la cantidad de agua que se introduce es mayor a 300 litros se lanza una alerta*/
            if (consumo_agua[contador][repetir] >= 300)
            {
                printf("¡ALERTA! CONSUMO EXCESIVO DE AGUA O POSIBLE FUGA DE AGUA\n");
            }
            promedio_agua[contador] +=  consumo_agua[contador][repetir];/*Aqui se suma en la variable para obtener el total de agua consumida en la semana*/
            /*Se compara en el if para ver si la cantidad de agua que se ingrese es la primero o ya es la segunda
            si es la primero entonces sera el valor de max[contador]*/
            if(repetir==0) {
                max[contador] = consumo_agua[contador][repetir];
            }
            /*Como ya no es el primer dato que se introduce se compara la nueva cantidad que se introdujo
            con la anterior y si es mayor que la cantidad anterior entonces la nueva cantidad pasara a ser 
            el nuevo valor de max[contador] y se repetira que termine de registrar una semana para comenzar 
            el ciclo con otra*/ 
            else {
                if(consumo_agua[contador][repetir] > max[contador]) max[contador] = consumo_agua[contador][repetir];
            }
            repetir ++;
        }
            contador ++;
            printf("\n");
            repetir = 0;
            break;
            /*si escoge dos entonces termina esta parte del programa*/
            case 2: 
            break;
            default: 
            printf("opcion no valida\n");
            break; 
    }
    
}

            break;
case 2: /*Reporte semamanal*/
/*se pregunta cuantas semanas quiere el usuario imprimir, por ejemplo 
si en total registro 8 pero solo quiere ver dos entonces el codigo solo le imprimira dos*/
printf("Cuantas semanas quieres imprimir?\n");
scanf("%d",&semanas_imprimir);
        for(j=0; j<semanas_imprimir;j++) { /*se incia el bucle primero inciandouna semana*/
        printf("Semana %d\n",j+1); /*va imprimiendo los dias de la primera semana*/
        for ( i = 0; i < 7; i++)
        {
            semana = promedio_agua[j] / 7;
            printf("Consumo del dia %d: %.2f \n", i + 1, consumo_agua[j][i]);
            /*si el dia que se imprime tiene un valor mayor o igual a 300
            se considera como consumo excesivo y se guarda en una variable 
            para tener el control de cuantos dias fueron de consumo excesivo*/
            if (consumo_agua[j][i] >= 300)
            {
                Consumo_excesivo = Consumo_excesivo + 1;
                Consumo_global = Consumo_global + 1;
            }
        }
        /*En esta parte se suman todos los valores de todos los dias registrados*/
        suma += promedio_agua[j];
        /*Se imprime el total de litros consumidos en la sema*/
        printf("El total de agua consumida en la semana es de %0.2f\n", promedio_agua[j]);
        /*Se calcula el promedio de agua de la semana*/
        printf("El promedio de la semana es de %0.2f\n", semana);
        /*Se calcula e imprime el procentaje de dias que superaron el umbral de la semana*/
        printf("El procentaje de los dias que superaron el umbral en la semana es de: %.2f\n",((float) Consumo_excesivo/7) * 100);
        /*Se imprime la mayor de cantidad de agua consumida en un dia*/
        printf("La mayor cantidad de agua consumida en un dia es de: %0.2f", max[j]);
        printf("\n");
        Consumo_excesivo = 0;
         system("pause");
         system("cls");
    }
    mes = suma / semanas_imprimir;
    /*Se imprime el total de agua consumida en todas las semanas registradas*/
    printf("El total de agua consumida en base a las semanas registradas es de: %0.2f \n", suma);
    /*Se calcula e imprime los dias que superaron el umbral de todas las semanas registradas*/
    printf("El porcentaje de los dias que superaron el umbral de manera global es de: %.2f\n", ((float)Consumo_global / (semanas_imprimir * 7)) *100);
    /*Se imprime el promedio de agua consumida por todas las semanas*/
    printf("El promedio total es de %0.2f \n", mes);
    suma = 0;
    Consumo_global = 0;
    system("pause");
    system("cls");
            break;
case 3:/*Reporte global*/
    /*Se imprmien unicamente la semana sin los dias y el total de agua consumida en esa semana ademas del promedio de agua
    consumida en esa semana*/
        for(j=0; j<contador;j++) {
        printf("Semana %d\n",j+1);
        for ( i = 0; i < 7; i++)
        {
            semana = promedio_agua[j] / 7;
        }
        suma += promedio_agua[j];
        printf("El total de agua consumida en esta semana es de: %0.2f\n", promedio_agua[j]);
        printf("\n");
        }
    
        mes = suma / contador;
        printf("El total de agua consumida en todas las semanas es de: %0.2f \n", suma);
        printf("El promedio total de agua es de: %0.2f \n", mes);
        suma = 0;
        system("pause");
        system("cls");
            break;
case 4:
        /*Simulador de reduccion de agua*/
        printf("De cuanto quiere su reduccion de agua: ");
        scanf("%d", &simular_ahorro);
        printf("\n");
        /*Se pide la semana que quiere hacer la simulacion de ahorro*/
        printf("Que semana quiere reduccir: ");
        scanf("%d", &semanas_imprimir);
        /*Se obtiene el procentaje de la reduccion y despues se resta con el consumo_agua*/
        reduccion = (float)simular_ahorro / 100;
        printf("Semana %d\n",semanas_imprimir);
        for ( i = 0; i < 7; i++)
        {
            reduccion_agua += consumo_agua[semanas_imprimir - 1][i] - (consumo_agua[semanas_imprimir - 1][i]*reduccion);
            reduccion2 += consumo_agua[semanas_imprimir - 1][i]; 
            /*se repite la accion para los 7 dias de la semana que se esta reduciendo*/
        }
        /*Por ultimo se imprime el resultado de la simulacion del ahorro*/
            printf("Si se reduce en %d%% a su consumo total se estaria ahorrando %.2f litros por lo que usted estaria consumiendo %.2f \n\n", simular_ahorro, reduccion2*reduccion ,reduccion_agua);
            reduccion_agua = 0.0;
        break;
    }

}while (opcion != 5);

    return 0;
}