#include<stdio.h>
#include<stdlib.h>

int main(){
float consumo_agua[51][7] = {0},reduccion_agua = 0.0, promedio_agua[51], mes = 0, semana = 0, suma = 0, max[51], reduccion;
int repetir = 0, opcion,semana_registro,entrada=1,luis,contador = 0,j,i,semanas_imprimir, simular_ahorro;
do{

printf("[1] --- Consumo por dia de agua\n[2] --- Reporte semanal\n[3] --- Reporte global\n[4] --- Simulacion de ahorro\n[5] --- salir\n");
printf("Ingrese una opcion: \n");
scanf("%d", &opcion);
printf("\n");
system("cls");

switch (opcion)
{
case 1:
if(entrada == 1) {
 printf("Cuantas semanas va a registrar?");
scanf("%d",&semana_registro);
while(contador<semana_registro) {
    while (repetir < 7)
    {
        printf("Consumo del dia %d en litros: \n", repetir + 1);
        scanf("%f", &consumo_agua[contador][repetir]);
        if (consumo_agua[contador][repetir] > 300)
        {
            printf("¡ALERTA! CONSUMO EXCESIVO DE AGUA\n");
        }
        
        promedio_agua[contador] +=  consumo_agua[contador][repetir];
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
    printf("quieres agregar una semana mas? \n1. si\n2. salir\n");
    scanf("%d",&luis);
    switch(luis) {
        case 1:
        while (repetir < 7)
    {
        printf("Consumo del dia %d en litros: \n", repetir + 1);
        scanf("%f", &consumo_agua[contador][repetir]);
         if (consumo_agua[contador][repetir] > 300)
        {
            printf("¡ALERTA! CONSUMO EXCESIVO DE AGUA o POSIBLE FUGA DE AGUA\n");
        }
        promedio_agua[contador] +=  consumo_agua[contador][repetir];
        if(repetir==0) {
            max[contador] = consumo_agua[contador][repetir];
        } else {
             if(consumo_agua[contador][repetir] > max[contador]) max[contador] = consumo_agua[contador][repetir];
        }
        repetir ++;
    }
            contador ++;
        printf("\n");
        repetir = 0;
        break;
        case 2: 
        break;
        default: 
        printf("opcion no valida\n");
        break; 
    }
    
}
        break;
case 2:  ///// Imprimir semanas
printf("Cuantas semanas quieres imprimir?\n");
scanf("%d",&semanas_imprimir);
for(j=0; j<semanas_imprimir;j++) {
    printf("Semana %d\n",j+1);
     for ( i = 0; i < 7; i++)
    {
    	semana = promedio_agua[j] / 7;
        printf("Consumo del dia %d: %.2f \n", i + 1, consumo_agua[j][i]);
    }
    suma += promedio_agua[j];
    printf("La suma de la semanal es de %0.2f\n", promedio_agua[j]);
    printf("El promedio semanal es de %0.2f\n", semana);
    printf("El maximo %0.2f", max[j]);
    printf("\n");
}
mes = suma / semanas_imprimir;
printf("La suma total es de %0.2f \n", suma);
printf("El promedio total es de %0.2f \n", mes);
suma = 0;
    break;
case 3:
    //pendiente (Miercoles preguntar)
    break;
case 4:
    printf("De cuanto quiere su reduccion de agua: ");
    scanf("%d", &simular_ahorro);
    printf("\n");
    reduccion = (float)simular_ahorro/100;
    
    printf("Que semana quiere reduccir: ");
    scanf("%d", &semanas_imprimir);

    
    printf("Semana %d\n",semanas_imprimir);
     for ( i = 0; i < 7; i++)
    {
        reduccion_agua += consumo_agua[semanas_imprimir - 1][i] - (consumo_agua[semanas_imprimir - 1][i]*reduccion);
        
    }
        printf("El total de la semana %d con el %d%%: %.2f \n\n", semanas_imprimir, simular_ahorro,reduccion_agua);
        reduccion_agua = 0.0;
    break;
}

}while (opcion != 5);

    return 0;
}