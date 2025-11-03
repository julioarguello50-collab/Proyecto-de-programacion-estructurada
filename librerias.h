#include<stdio.h>
#ifndef VARIABLES_H
#define VARIABLES_H
extern float consumo_agua[51][7],reduccion_agua, promedio_agua[51], mes, semana;
extern float suma, max[51], reduccion,reduccion2;
extern int repetir, opcion,semana_registro,entrada,Semana_extra,contador,j,i,semanas_imprimir;
extern int simular_ahorro,Consumo_excesivo,Consumo_global;
/*funcion para el menu principal*/
int menu() {
    do {
            printf("[1] --- Consumo por dia de agua\n[2] --- Reporte semanal\n[3] --- Reporte global\n[4] --- Simulacion de ahorro\n[5] --- salir\n");
            printf("Ingrese una opcion: \n");
            /*Compara la opcion que ingresa el usuario si ingresa un caracter, letra o un numero menor o igual a cero el programa se reinicia
            hasta que el usuario introduzca un valor numerico mayor a cero*/
        if(scanf("%d", &opcion) != 1 || opcion <=0) {
            printf("Error el programa no permite caracteres solo numeros mayores a 0\n");
            /*En caso de marcar el error limpia el scanf para que no guarde ese valor erroneo*/
            fflush(stdin);
            printf("\n");
            system("pause");
            system("cls");
        }
        /*El bucle termima hasta que el usuario introduzca un valor mayor a cero*/
    }while(opcion <= 0);
        printf("\n");
        system("cls");
    return opcion;
}
/*Funcion para registrar las semanas*/
int Registro_semana() {
    do {
        printf("Cuantas semanas va a registrar?\n");
        scanf("%d",&semana_registro);
        /*Si el usuario ingresa un valor erroneo se reinicia hasta que ponga un valor numero y que sea mayor a cero*/
        if(semana_registro <=0) 
        {
            printf("opcion invalida\nSolo acepta numeros mayores a 0\n");
        }
        }while(semana_registro <=0);
        return semana_registro;
}
/*funcion para registrar el consumo de agua por dia*/
float Registro_dia(int repetir, int contador, float consumo_agua[51][7]) {
        do {
            printf("Consumo del dia %d en litros: \n", repetir + 1);
            /*Compara si el usuario ingreso un numero o si ingreso un dato erroneo*/
            if (scanf("%f", &consumo_agua[contador][repetir]) != 1 || consumo_agua[contador][repetir] <= 0) 
            {
                printf("Error el programa no permite caracteres solo numeros mayores a 0\n");
                fflush(stdin);  
                consumo_agua[contador][repetir] = -1;
                }
                } while (consumo_agua[contador][repetir] <= 0);
                /*Retornamos el valor que ingresa el usuario y se guarda en el arrego bidimensional*/
                return consumo_agua[contador][repetir];
}
/*Maximo consumo de agua*/
float Maximo(int repetir, int contador, float consumo_agua[51][7],float max[51]) {
    /*Compara los valores ingresados por el usuario para calcular la mayor cantidad de agua consumida en un dia*/
    /*si el dato es el primero entonces sera nuestro maximo valor hasta que se encuentre un valor mayor*/
            if (repetir == 0) {
                    max[contador] = consumo_agua[contador][repetir];
                } 
                else {
                    /*El valor que entra al if se compara con el valor de max[contador] que se guardo anteriormente
                    si es mayor entonces sera el nuevo valor de max[contador] y esto se repitira un total de 7 veces*/
                    if(consumo_agua[contador][repetir] > max[contador]) {
                            max[contador] = consumo_agua[contador][repetir];
                                }
                        }
                return max[contador];
}
/*funcion para imprimir los datos de la semana del caso 2*/
void datos_semana(int j, float promedio_agua[51],float semana,int Consumo_excesivo,float max[51]) {
                printf("EL total de agua consumida en la semana es de %0.2f\n",promedio_agua[j]);
				printf("EL promedio de la semana es de %0.2f\n ",semana);
				printf("El porcentaje de dias que superaron el umbral en la semana es de %0.2f\n",((float)Consumo_excesivo/7)*100);
				printf("La mayor cantidad de agua consumo en un dia es de: %0.2f\n",max[j]);
				printf("\n");
}
/*funcion para todo el caso 2*/
void impresion_semana(int semanas_imprimir,int j, int i, float consumo_agua[51][7],int Consumo_excesivo,int Consumo_global,float promedio_agua[51],float semana,float mes,float suma) {
    printf("Cuantas semanas quieres imprimir?\n");
	scanf("%d",&semanas_imprimir);
        /*Comienza el bucle para imprimir las semanas*/
			for(j=0; j<semanas_imprimir ; j++) {
                if (j % 4 == 0) {
                    /*Si el valor de j es divisible entre 4 y su residuo da 0 entonces se ira imprimiendo la palabra 
                    Mes acompañado del numero al que corresponde*/
                    printf("Mes %d\n",(j/4)+1);
                }
                /*Empienza con semana 1 hasta termina con la impresion de las semanas*/
				printf("Semana %d\n",j+1); 
				for(i=0; i<7; i++) {
					semana = promedio_agua[j] /7;
					printf("Consumo del dia %d: %.2f \n",i+1,consumo_agua[j][i]); 
                    /*Si el valor que se imprime es mayor a 300 entran en la siguiente condicion para calcular el procentaje de dias 
                    que superaron el umbral*/
					if(consumo_agua[j][i] >= 300) {
						Consumo_excesivo = Consumo_excesivo +1; 
						Consumo_global = Consumo_global +1; 
					}
				}
                /*Se guardan en la variable suma para calcular la cantidad de agua consumida por la familia*/
				suma += promedio_agua[j];
                /*Mandamos a llamar la funcion datos_semana para imprimir el resumen de la semana*/
				datos_semana( j, promedio_agua, semana, Consumo_excesivo, max);
                Consumo_excesivo = 0;
				system("pause");
				system("cls");
			}
            /*la variable suma se divide entre las semanas impresas y se guarda en la nueva varible mes
            para calcular el porcentaje de agua consumida en todo el registro*/
            mes = suma / semanas_imprimir;
			printf("EL total de agua consumida en base a las semanas registradas es de: %.2f\n",suma);
			printf("El porcentaje de los dias que superaron el umbral de manera global es de: %.2f\n",((float)Consumo_global / (semanas_imprimir*7))*100);
			printf("EL promedio del total es de %.2f\n",mes);
            suma = 0; 
			Consumo_global = 0; 
			system("pause");
			system("cls");
}
/*para poder registrar una nueva semana*/
void nueva_semana(int Semana_extra,int *contador, int repetir, float consumo_agua[51][7],float max[51],float promedio_agua[51]) {
    /*Para agregar una semana mas a las que ya tenia registrada*/
    /*si escoge uno realiza lo siguente*/
    do{
    printf("quieres agregar una semana mas? \n1. si\n2. salir\n");
    scanf("%d",&Semana_extra);
        switch(Semana_extra) {
            case 1:
                if(*contador % 4 == 0) {
                printf("Mes %d\n",(*contador/4)+1);
            }
                printf("Semana %d\n",*contador+1);
            while (repetir < 7)
            {
                do {
                    printf("Consumo del dia %d en litros: \n", repetir + 1);
                    if (scanf("%f", &consumo_agua[*contador][repetir]) != 1 || consumo_agua[*contador][repetir] <= 0)
                    {
                        /*Si se ingresa un valor que no sea numero o menor a cero imprime el error y limpia el scanf*/
                        printf("Error el programa no permite caracteres solo numeros mayores a 0\n");
                        fflush(stdin);
                        consumo_agua[*contador][repetir] = -1;
                    }
                } while (consumo_agua[*contador][repetir] <= 0);
            /*Aqui se compara si la cantidad de agua que se introduce es mayor a 300 litros se lanza una alerta*/
            if (consumo_agua[*contador][repetir] >= 300)
            {
                printf("¡ALERTA! CONSUMO EXCESIVO DE AGUA O POSIBLE FUGA DE AGUA\n");
            }
            promedio_agua[*contador] +=  consumo_agua[*contador][repetir];
            /*Mandamos a llamar a la funcion Maximo para deducir la mayor cantidad de agua consumida en un dia*/
            max[*contador] = Maximo(repetir,*contador,consumo_agua,max);
            repetir ++;
                }
            (*contador) ++;
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
    }while(Semana_extra != 2);
    
}
/*funcion para el caso 3*/
void Reporte_global(int contador, int j,float promedio_agua[51]) {
    /*Esta funcion sirve para imprimir unicamente las semanas registradas mostrando unicamente 
    el total de agua consumida en cada semana*/
    for(j=0; j<contador;j++) 
    {
        if (j % 4 == 0) {
            printf("Mes %d\n",(j/4)+1);
        }
        printf("Semana %d\n",j+1);
        suma += promedio_agua[j];
        printf("El total de agua consumida en esta semana es de: %0.2f\n", promedio_agua[j]);
        printf("\n");
    }
}
/*funcion para hacer la simulacion de agua*/
void simular_reduccion(float reduccion, int semanas_imprimir, int simular_ahorro, float reduccion2, float consumo_agua[51][7],float reduccion_agua) {
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
}
#endif