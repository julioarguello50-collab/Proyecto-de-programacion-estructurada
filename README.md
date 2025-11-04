<h1>Consumo de agua en hogares &#128167; </h1>
<h2>Cómo compilar/ejecutar</h2>

<p>
Para poder utilizar el código necesitamos descargar ya sea la carpeta o un archivo en específico. 
Para poder descargar la carpeta se hacen los siguientes pasos:
</p>

<ol>
  <li>En el proyecto de GitHub nos vamos al apartado de <strong>Code</strong> que se encuentra en la parte superior derecha del proyecto.</li>
  <li>En el apartado de <strong>Local</strong>, seleccionamos la opción <strong>Download ZIP</strong> para descargar la carpeta completa.</li>
  <li>Vamos a los archivos y descomprimimos la carpeta del proyecto.</li>
  <li>Damos clic en <strong>Extraer</strong>.</li>
  <li>Ya tenemos la carpeta completamente descargada para poder ser utilizada.</li>
</ol>

<p>
Una vez descargada la carpeta necesitamos un <strong>IDE (Entorno de Desarrollo Integrado)</strong> para poder ejecutar el código que en este caso está hecho en el lenguaje C. 
</p>

<p>Los IDE más populares para ejecutar código C son los siguientes:</p>

<ul>
  <li>Visual Studio Code (VS Code) </li>
  <li>Visual Studio</li>
  <li>Dev-C++</li>
</ul>

<p>También existen compiladores en línea que pueden ejecutar código C, algunos ejemplos son:</p>

<ul>
  <li>GDB Online Debugger</li>
  <li>myCompiler</li>
  <li>OneCompiler</li>
</ul>

<p>Para esta ocasión se usará <strong>Visual Studio Code</strong> ya que es el más popular para ejecutar código C.</p>


<h3>
Como ejecutar codigo C en vscode
</h3>
<p>
Para poder ejecutar nuestro proyecto es importante que la computadora que se utilice para compilar tenga el compilador de C ya que sin este el codigo no podra ser ejecutado por <strong>Vs code</strong> para esto tenemos que entrar a la terminal de la computadora. 
<p>
Para windows se utiliza la tecla windows + r 
Para mac con el atajo de teclado ⌘ + Espacio, escribir "Terminal" y presionar Enter. 
se ejecuta el comando gcc -version. 
Si no aparece la version es porque no tienes el compilador si es asi en el siguiente enlace es para un video en youtube para poder instalar el compilador
<a href="https://www.youtube.com/watch?v=GEZLjRSY_m8&t=306s">Instalar el compilador de para C/C++</a>

Una vez hecho esto basta con abrir la carpeta previamente descargada denominada <strong>Proyecto de programacion estructurada</strong> y abrir el archivo <strong>ConsumoAgua.C</strong>
Despues en el editor de codigo para compilar nos hiremos a la parte superior derecha y daremos clic en el triangulo para poder compilar y ejecutar el codigo. 

Finalmente se podra visualizar el programa ya compilado para poder ser usado.

</p>
</p>

<h2>
DISTRIBUCION DE TAREAS
</h2>
<p>
A continuacion se presentan las variables que se utilizaron en la creacion del programa. 
En este proyectos se utilizaron variables de dos tipos. Enteros y flotantes, cada uno de estos tiene un proposito distinto mismo que se presenta a continuacion.
Es importante mencionar que para declarar todas las varibales es importante ponerlas antes de la funcion principal<strong> int main() </strong>para que el programa las tome como variables globales.
Las variables globales son utiles cuando queremos usar variables en dos archivos en nuestro fue necesario debido que se creo la carpeta de librerias. h la cual contenia funciones que utilizan las mismas variables que se utilizan en el programa principal. 
<p>
Para poder utilizarlas en librerias.h basta con poner la palabra extern al inicio de cada tipo de variable <strong>"exter int valor;"</strong> lo cual indica que las variables provienen de un codigo fuente.
Una vez entendido esto procedemos a explicar cada una de las variables utilizadas.
</p>
</p>
<h3>
Variables de tipo entero
</h3>
<p>
Las variables de tipo entero son aquellas que guardan numeros enteros exclusivamente, no se pueden guardar numeros decimales ni caracteres, solo numeros enteros. Las variables de tipo entero fueron utilizadas para contadores, registros, opciones que ingresa el usuario y para acumuladores.
<ol>
<li><strong>opcion:</strong>Es la primera variable en utilizarse ya que se utiliza para guarda la opcion que el usuario eliga dentro del menu principal del programa</li>
<li><strong>Repetir: </strong> Esta variable tiene como objetivo representar los 7 dias de la semanas. Esta variable se utiliza en los bucles donde se busca ya sea pedir los datos para 7 dias o para imprimir los datos de 7 dias</li>
<li><strong>semana_registro:</strong>Se utiliza para registrar la cantidad de semanas que el usuario  va a registrar</li>
<li><strong>entrada:</strong>Es empleado en el caso 1 del programa ya que si se ingresa por primera vez (entrada valdra 1) el programa preguntara cuantas semanas va a registrar, en caso de que el usuario vuelva a ingresar a la opcion 1 ahora le preguntara si quiere agregar una semana mas por lo que el valor de entrada sera 2 (entrada == 2)</li>
<li><strong>Semana_extra:</strong> Esta variable se utiliza cuando el usuario quiera agregar una semana mas se guarda en esa variable y repite el proceso de llenado de datos</li>
<li><strong>contador: </strong>Se utiliza para representar las semanas que el usuario registre dentro de los bucles</li>
<li><strong>J: </strong>Este contador tiene varias funcionalidades. Una de ellas sirve como contador para imprimir las semanas registradas con sus respectivos datos. Otra funcionalida esta en la impresion de las semanas, <strong>J</strong> se utiliza para representar las semanas a imprimir. </li>
<li><strong>i: </strong>Se utiliza para representar a los dias en la impresion de los dias para el caso 2 y caso 4, ademas que en el caso 4 el contador i se utiliza para calcular la reduccion de agua</li>
<li><strong>semanas_imprimir: </strong>Esta variable se utilizar guardar e imprimir las semanas que el usuario pida con sus respectivos datos de cada semana</li>
<li><strong>simular_ahorro: </strong>Se utiliza para guardar el porcentaje de reduccion que se desea aplicar a una semana</li>
<li><strong>Consumo_excesivo: </strong>Se utiliza para guardar la cantidad de dias que superaron el umbral de agua en una semana. El umbral establecido para el programa es de 300 litros al dia</li>
<li><strong>Consumo_global: </strong>Se utiliza para guardar la cantidad de dias que superaron el umbral de agua en todas las semanas registradas</li>
</ol>
<h3>
Variables de tipo flotante
</h3>
<p>
Las variables de tipo flotante pueden almacenar numeros enteros y decimales con el inconveniente que a la hora de imprimir los valores de tipo flotante es importante especificar cuantos decimales se ocupar mostrar en pantalla como por ejemplo <strong>"%.2f".</strong>. 
En este programa las variables de tipo flotante se utilizan para guardar los resultados de las operaciones que se realizen ademas para guardar datos que puedan ser introducidos en deciamales. Los arreglos utilizados son de tipo flotante que mas adelante se explica el porque de esta decision
</p>
<ol>
<li><strong>consumo_agua[51]]7]: </strong> Este arreglo se utiliza para registrar los litros que el usuario ingrese por dia y todas las semanas que el usuario registre. Este arreglo tiene como maximo 51 filas para semanas esto debido que son la cantidad de semanas que contiene un y 7 columnas que representas los 7 dias de la semana</li>

<li><strong>promedio_agua[51]: </strong>Este arreglo suma el consumo de agua de los 7 dias semanas registrados. Este arreglo contiene 51 espacios los cuales representan las semanas que contiene un año, esto quiere decir que guarda el consumo de agua de 51 semanas</li>
<li><strong>max[51]: </strong>Este arreglo es utilizado en el registro de agua de una semanas donde va comparando cada uno de los valores y guarda el valor mayor de los 7 dias. Este arreglo tiene 51 espacios lo que significa que puede guardar el mayor consumo de agua de 51 semanas</li>
<li><strong>suma_global: </strong>Guarda la cantidad de agua consumida en todas las semanas registradas</li>
<li><strong>reduccion_agua: </strong>Guarda e imprime la cantidad de agua a consumir si se hace una reduccion a su consumo original</li>
<li><strong>promedio_global: </strong>Calcula el promedio agua consumida en todas las semanas registradas para mostrar un promedio global</li>
<li><strong>promedio_semana: </strong>Calcula el promedio de agua consumida en una semana</li>
<li><strong>porcentaje_reduccion: </strong>convierte el numero que ingreso el usuario para la reduccion de agua en decimal para poder manejarlo en el calculo de reduccion de agua</li>
<li><strong>ahorro_agua: </strong>suma la cantidad de agua ahorrada de los 7 dias para obtener el total de agua ahorrada en la semana reducida</li>
</ol>

