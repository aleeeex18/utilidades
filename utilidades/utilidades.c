////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE IMPORTACIÓN: FICHEROS NECESARIOS A INCLUIR
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

#include "utilidades.h"   // Mi propia colección de subprogramas útiles.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE MACROS, CONSTANTES Y VARIABLES GLOBALES: PARA USO GLOBAL.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////

char MSJxERROR[] = "¡VALOR NO VÁLIDO!";
char MSJxPAUSA[] = "Pulse INTRO para continuar... ";

int codigoError; // VARIABLE GLOBAL: Visible por todos los subprogramas.



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
//
// ZONA DE CÓDIGO: CUERPOS DE LOS SUBPROGRAMAS DECLARADOS ANTES.
//
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarINTRO (void);
//
//  USO:
//
//    Programa que produce una espera hasta que se pulse INTRO.
//
//  DETALLES:
//
//    Es un envoltorio de la función vaciarBuffer(), a la cual delega todo el
//    trabajo. Es una manera de crear "sinónimos" de acciones, es decir, de
//    tener disponibles varios nombres para hacer lo mismo.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Se delega toda la carga de trabajo a esta función.
//
////////////////////////////////////////////////////////////////////////////////

void esperarINTRO (void)
{
  vaciarBuffer();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void descartarEntrada (void);
//
//  USO:
//
//    Descarta todo lo que haya en el buffer de teclado sin esperar acción
//    del usuario. Es un sinónimo de esperarINTRO() con nombre más descriptivo.
//
//  DETALLES:
//
//    Es otro envoltorio de vaciarBuffer(). Permite usar un nombre diferente
//    según el contexto: cuando lo que interesa es desechar datos incorrectos
//    o sobrantes del teclado, este nombre resulta más claro.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    vaciarBuffer()
//
//      Realiza el vaciado real del buffer de teclado.
//
////////////////////////////////////////////////////////////////////////////////

void descartarEntrada (void)
{
  vaciarBuffer();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void vaciarBuffer (void);
//
//  USO:
//
//    Programa que espera que el usuario pulse teclas a la espera de INTRO.
//
//  DETALLES:
//
//    Se basa en un bucle que va pidiendo letras del buffer de teclado y no
//    termina hasta que detecta que ha encontrado un "INTRO" (0x10). Cualquier
//    otro código ASCII introducido por el usuario se descarta. Se produce ECO
//    de cualquier tecla pulsada.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      comunicarse con el sistema operativo y con el hardware del teclado.
//
////////////////////////////////////////////////////////////////////////////////

void vaciarBuffer (void)
{
  // ENTER CREADO EN DEFINE = ASCII(10) = 0x0A
  
  // MEDIANTE BUCLE DO-WHILE:
  char letra;
  do
  {
    letra = getchar();
  } while (letra != ENTER);
  
  // MEDIANTE BUBLE WHILE:
  // while (getchar() != '\n')   ; // Bucle vacío
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void borrarPantalla (void);
//
//  USO:
//
//    Borra completamente el contenido visible de la pantalla. Es un sinónimo
//    de limpiarPantalla() con un nombre alternativo.
//
//  DETALLES:
//
//    Delega todo el trabajo a limpiarPantalla(). Permite disponer de dos
//    nombres distintos para la misma acción, eligiendo el más intuitivo
//    según el contexto del programa que la llame.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    limpiarPantalla()
//
//      Realiza el borrado efectivo de la pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void borrarPantalla (void)
{
  limpiarPantalla();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void limpiarPantalla (void);
//
//  USO:
//
//    Borra completamente el contenido visible de la pantalla usando el comando
//    del sistema operativo correspondiente.
//
//  DETALLES:
//
//    Llama a system() con la macro BORRAR, que está definida en el fichero de
//    cabecera según el sistema operativo (cls en Windows, clear en Linux/Mac).
//    Así el código funciona en distintas plataformas sin modificarse.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    system()
//
//      Función estándar de C que ejecuta un comando del sistema operativo.
//
////////////////////////////////////////////////////////////////////////////////

void limpiarPantalla (void)
{
  system(BORRAR);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void bajar (int nlineas);
//
//  USO:
//
//    Permite bajar el cursor en la pantalla, tantas líneas como se le indique.
//
//  DETALLES:
//
//    Crea tantas líneas en blanco como se le suministre como dato. No ubica el
//    cursor de texto en ninguna coordenada concreta, sino que genera contenido
//    en blanco en la pantalla, desplazando el punto donde se escribirá texto en
//    acciones posteriores. Utiliza para ello un bucle en cuyo interior se llama
//    a printf() con el código ASCII de salto de línea '\n' ó 0x10.
//
//  PARÁMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      emitir por pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void bajar (int nlineas)
{
  while(nlineas>0)
  {
    printf("\n");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
    
    nlineas--;
  }
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void abajo (int nfils);
//
//  USO:
//
//    Desplaza el cursor hacia abajo el número de filas indicado. Es un
//    sinónimo de bajar() con nombre alternativo.
//
//  DETALLES:
//
//    Envoltorio directo de bajar(). Permite elegir el nombre que resulte más
//    natural en el código del programa principal.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera con el número de filas que se desea bajar el cursor.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Realiza el desplazamiento vertical real en pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void abajo (int nfils)
{
  bajar(nfils);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void saltar (int nfils);
//
//  USO:
//
//    Desplaza el cursor hacia abajo el número de filas indicado. Es otro
//    sinónimo de bajar() con nombre alternativo.
//
//  DETALLES:
//
//    Envoltorio directo de bajar(). Útil cuando en el contexto del programa
//    el término "saltar" resulta más expresivo que "bajar".
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera con el número de filas que se desea saltar.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Realiza el desplazamiento vertical real en pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void saltar (int nfils)
{
  bajar(nfils);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarFils (int nfils);
//
//  USO:
//
//    Desplaza el cursor verticalmente el número de filas indicado. Sinónimo
//    de bajar() con nombre explícito sobre el eje de desplazamiento.
//
//  DETALLES:
//
//    Envoltorio directo de bajar(). El nombre deja claro que el desplazamiento
//    es en el eje de filas (vertical), útil en contextos donde se trabaja con
//    coordenadas de pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera con el número de filas a desplazar hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Realiza el desplazamiento vertical real en pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarFils (int nfils)
{
  bajar(nfils);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarV (int nfils);
//
//  USO:
//
//    Desplaza el cursor verticalmente el número de filas indicado. Sinónimo
//    de bajar() usando la letra "V" de "vertical".
//
//  DETALLES:
//
//    Envoltorio directo de bajar(). El nombre abreviado "V" indica el eje
//    vertical, facilitando la comprensión cuando se trabaja con sistemas de
//    coordenadas X/Y o H/V.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera con el número de filas a desplazar hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Realiza el desplazamiento vertical real en pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarV (int nfils)
{
  bajar(nfils);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarY (int nfils);
//
//  USO:
//
//    Desplaza el cursor verticalmente el número de filas indicado. Sinónimo
//    de bajar() usando la letra "Y" del eje de coordenadas.
//
//  DETALLES:
//
//    Envoltorio directo de bajar(). El nombre "Y" hace referencia al eje
//    vertical en un sistema de coordenadas cartesianas, siendo natural en
//    contextos donde se manejan posiciones (X, Y) en pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera con el número de filas a desplazar hacia abajo.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Realiza el desplazamiento vertical real en pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarY (int nfils)
{
  bajar(nfils);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void indentar (int ncolumnas);
//
//  USO:
//
//    Desplaza el cursor hacia la derecha imprimiendo espacios en blanco,
//    tantos como se indique.
//
//  DETALLES:
//
//    Utiliza un bucle for que imprime un espacio en blanco por cada iteración.
//    No puede usar mostrar() internamente porque eso crearía una llamada
//    circular (bucle infinito de llamadas entre funciones).
//
//  PARÁMETROS DE ENTRADA:
//
//    ncolumnas
//
//      Variable entera con el número de espacios en blanco a imprimir, es
//      decir, el número de columnas a desplazar el cursor hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    printf()
//
//      Función estándar usada para imprimir cada espacio en blanco.
//
////////////////////////////////////////////////////////////////////////////////

void indentar (int ncolumnas)
{
  for(int i=0; i<ncolumnas; i++)
  {
    printf(" ");   // No se puede usar "mostrar()" porque crearíamos un bucle de llamadas.
  }
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void derecha (int ncols);
//
//  USO:
//
//    Desplaza el cursor hacia la derecha el número de columnas indicado.
//    Sinónimo de indentar() con nombre más intuitivo.
//
//  DETALLES:
//
//    Envoltorio directo de indentar(). El nombre "derecha" resulta más
//    natural cuando simplemente se quiere mover el cursor a la derecha sin
//    implicaciones de formato de código fuente.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
//      Realiza el desplazamiento horizontal real imprimiendo espacios.
//
////////////////////////////////////////////////////////////////////////////////

void derecha (int ncols)
{
  indentar(ncols);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void tabular (int ncols);
//
//  USO:
//
//    Desplaza el cursor hacia la derecha el número de columnas indicado.
//    Sinónimo de indentar() con nombre que evoca el tabulador.
//
//  DETALLES:
//
//    Envoltorio directo de indentar(). El nombre "tabular" sugiere la acción
//    de pulsar el tabulador para alinear texto, muy reconocible en el contexto
//    del aula.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
//      Realiza el desplazamiento horizontal real imprimiendo espacios.
//
////////////////////////////////////////////////////////////////////////////////

void tabular (int ncols)
{
  indentar(ncols);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarCols (int ncols);
//
//  USO:
//
//    Desplaza el cursor horizontalmente el número de columnas indicado.
//    Sinónimo de indentar() con nombre explícito sobre el eje de movimiento.
//
//  DETALLES:
//
//    Envoltorio directo de indentar(). El nombre deja claro que el
//    desplazamiento es en el eje de columnas (horizontal).
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
//      Realiza el desplazamiento horizontal real imprimiendo espacios.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarCols (int ncols)
{
  indentar(ncols);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarX (int ncols);
//
//  USO:
//
//    Desplaza el cursor horizontalmente el número de columnas indicado.
//    Sinónimo de indentar() usando la letra "X" del eje de coordenadas.
//
//  DETALLES:
//
//    Envoltorio directo de indentar(). El nombre "X" hace referencia al eje
//    horizontal en un sistema de coordenadas cartesianas, siendo coherente
//    con desplazarY() para el eje vertical.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
//      Realiza el desplazamiento horizontal real imprimiendo espacios.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarX (int ncols)
{
  indentar(ncols);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarH (int ncols);
//
//  USO:
//
//    Desplaza el cursor horizontalmente el número de columnas indicado.
//    Sinónimo de indentar() usando la letra "H" de "horizontal".
//
//  DETALLES:
//
//    Envoltorio directo de indentar(). El nombre abreviado "H" indica el eje
//    horizontal, siendo la pareja natural de desplazarV() para el eje vertical.
//
//  PARÁMETROS DE ENTRADA:
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    indentar()
//
//      Realiza el desplazamiento horizontal real imprimiendo espacios.
//
////////////////////////////////////////////////////////////////////////////////

void desplazarH (int ncols)
{
  indentar(ncols);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void posicionar (int nfils, int ncols);
//
//  USO:
//
//    Mueve el cursor a una posición de pantalla indicada por un número de
//    filas hacia abajo y un número de columnas hacia la derecha.
//
//  DETALLES:
//
//    Combina bajar() y tabular() para lograr un desplazamiento en dos ejes
//    con una sola llamada. No posiciona en coordenadas absolutas sino
//    relativas al punto actual del cursor en pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera con el número de filas a bajar desde la posición actual.
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    bajar()
//
//      Realiza el desplazamiento vertical.
//
//    tabular()
//
//      Realiza el desplazamiento horizontal.
//
////////////////////////////////////////////////////////////////////////////////

void posicionar (int nfils, int ncols)
{
  bajar(nfils);
  tabular(ncols);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazar (int nfils, int ncols);
//
//  USO:
//
//    Mueve el cursor en pantalla según las filas y columnas indicadas.
//    Sinónimo de posicionar() con nombre más genérico.
//
//  DETALLES:
//
//    Envoltorio directo de posicionar(). Permite usar un nombre más corto
//    o más intuitivo según el contexto del programa que lo utilice.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera con el número de filas a bajar.
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar a la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//
//      Realiza el desplazamiento combinado (filas + columnas).
//
////////////////////////////////////////////////////////////////////////////////

void desplazar (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void desplazarXY (int nfils, int ncols);
//
//  USO:
//
//    Mueve el cursor en pantalla según las filas (Y) y columnas (X) indicadas.
//    Sinónimo de posicionar() con nombre basado en ejes de coordenadas.
//
//  DETALLES:
//
//    Envoltorio directo de posicionar(). El nombre "XY" hace referencia al
//    sistema de coordenadas cartesianas, siendo coherente con las funciones
//    desplazarX() y desplazarY() del resto de la librería.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera con el número de filas a bajar (eje Y).
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar a la derecha (eje X).
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    posicionar()
//
//      Realiza el desplazamiento combinado (filas + columnas).
//
////////////////////////////////////////////////////////////////////////////////

void desplazarXY (int nfils, int ncols)
{
  posicionar(nfils, ncols);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoSegundos (int segundosmax);
//
//  USO:
//
//    Produce una espera activa de aproximadamente el número de segundos
//    indicado, sin usar funciones del sistema operativo.
//
//  DETALLES:
//
//    Implementa la espera mediante bucles anidados vacíos. El número de
//    iteraciones está ajustado para aproximar el tiempo real, aunque el
//    resultado puede variar según la velocidad del procesador. No bloquea
//    el sistema, simplemente mantiene ocupada la CPU durante el tiempo.
//
//  PARÁMETROS DE ENTRADA:
//
//    segundosmax
//
//      Variable entera con el número de segundos de espera deseados.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Ninguna (bucles vacíos internos).
//
////////////////////////////////////////////////////////////////////////////////

void retardoSegundos (int segundosmax)
{
  // POSIBILIDAD: Poner en función de la que usa milisegundos.
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for(int nseg=0; nseg < segundosmax ; nseg++)
  {
    for(int j=0; j<100; j++)
      for(int j=0; j<1000; j++)
        for(int k=0; k<1000; k++)   ;
  }
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retardoMilisegundos (int milisegundosmax);
//
//  USO:
//
//    Produce una espera activa de aproximadamente el número de milisegundos
//    indicado, mediante bucles vacíos sin usar el sistema operativo.
//
//  DETALLES:
//
//    Funciona igual que retardoSegundos() pero con granularidad de
//    milisegundos. Los bucles internos están calibrados para aproximar
//    el tiempo real, aunque depende de la velocidad del procesador.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundosmax
//
//      Variable entera con el número de milisegundos de espera deseados.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Ninguna (bucles vacíos internos).
//
////////////////////////////////////////////////////////////////////////////////

void retardoMilisegundos (int milisegundosmax)
{
  int i, j;
  
  // AJUSTAR CEROS DE LOS BUCLES PARA APROXIMAR EL PERIODO.

  for (int nmiliseg=0; nmiliseg<milisegundosmax ; nmiliseg++)
    for (i=0; i<100; i++)
      for (j=0; j<1000; j++)   ;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void retrasoMilisegundos (int milisegundos);
//
//  USO:
//
//    Produce una espera precisa de exactamente el número de milisegundos
//    indicado, usando el reloj interno del sistema para medir el tiempo real.
//
//  DETALLES:
//
//    A diferencia de retardoMilisegundos(), esta versión es más precisa porque
//    consulta el reloj del sistema (clock()) en un bucle do-while hasta que
//    haya transcurrido el tiempo pedido. El tipo clock_t almacena el número
//    de "ticks" del reloj, y CLOCKS_PER_SEC lo convierte a segundos.
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Variable entera con el número de milisegundos de espera deseados.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    clock()
//
//      Función estándar de <time.h> que devuelve el tiempo transcurrido
//      desde el inicio del programa en unidades de CLOCKS_PER_SEC.
//
////////////////////////////////////////////////////////////////////////////////

void retrasoMilisegundos (int milisegundos)
{
  double e = 0;

  clock_t t0 = clock();   // clock_t es un tipo interno equivalente a UINT32.
  
  do
  {
    
    e = 1000*(double)(clock()-t0)/CLOCKS_PER_SEC;

  } while (e<milisegundos);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarSegundos (int segundos);
//
//  USO:
//
//    Detiene la ejecución del programa durante el número de segundos indicado
//    usando la función de espera del sistema operativo.
//
//  DETALLES:
//
//    Usa compilación condicional (#ifdef) para elegir la función correcta
//    según el sistema operativo: Sleep() en Windows (con milisegundos) y
//    sleep() en Linux/Mac (con segundos directamente). Así el mismo código
//    funciona en distintas plataformas.
//
//  PARÁMETROS DE ENTRADA:
//
//    segundos
//
//      Variable entera con el número de segundos que debe durar la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep()   [Windows]
//
//      Función de Windows que espera el número de milisegundos indicado.
//
//    sleep()   [Linux/Mac]
//
//      Función estándar POSIX que espera el número de segundos indicado.
//
////////////////////////////////////////////////////////////////////////////////

void esperarSegundos (int segundos)
{
  #ifdef SO_WINDOWS
    Sleep(segundos*1000);
  #else
    sleep(segundos);
  #endif
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void esperarMilisegundos (int milisegundos);
//
//  USO:
//
//    Detiene la ejecución del programa durante el número de milisegundos
//    indicado usando la función de espera del sistema operativo.
//
//  DETALLES:
//
//    Usa compilación condicional (#ifdef) para elegir la función correcta
//    según el sistema operativo: Sleep() en Windows y usleep() en Linux/Mac
//    (que trabaja con microsegundos, por lo que se multiplica por 1000).
//
//  PARÁMETROS DE ENTRADA:
//
//    milisegundos
//
//      Variable entera con el número de milisegundos que debe durar la espera.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    Sleep()    [Windows]
//
//      Función de Windows que espera el número de milisegundos indicado.
//
//    usleep()   [Linux/Mac]
//
//      Función POSIX que espera en microsegundos (1 ms = 1000 µs).
//
////////////////////////////////////////////////////////////////////////////////

void esperarMilisegundos (int milisegundos)
{
  #ifdef SO_WINDOWS
    Sleep(milisegundos);
  #else
    usleep(milisegundos*1000);   // Alternativa: nanosleep() de "time.h".
  #endif
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausa (void);
//
//  USO:
//
//    Muestra el mensaje estándar de "Pulse INTRO para continuar" y espera
//    a que el usuario lo pulse. Versión simplificada sin parámetros.
//
//  DETALLES:
//
//    Llama a pausaEstandar() con valores predeterminados de posición (1 fila
//    abajo, 2 columnas a la derecha). Es la forma más cómoda de hacer una
//    pausa sin preocuparse por la posición del mensaje en pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaEstandar()
//
//      Muestra el mensaje de pausa en la posición indicada y espera INTRO.
//
////////////////////////////////////////////////////////////////////////////////

void pausa (void)
{
  pausaEstandar(1, 2);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaEstandar (int nfils, int ncols);
//
//  USO:
//
//    Muestra el mensaje estándar de "Pulse INTRO para continuar" en la
//    posición de pantalla indicada y espera a que el usuario pulse INTRO.
//
//  DETALLES:
//
//    Usa el texto predefinido en la constante global MSJxPAUSA. Delega la
//    visualización y la espera a pausaGenerica(), pasando FALSE para que
//    no añada una línea nueva al final del mensaje.
//
//  PARÁMETROS DE ENTRADA:
//
//    nfils
//
//      Variable entera con el número de filas a bajar antes de mostrar el mensaje.
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    pausaGenerica()
//
//      Muestra cualquier mensaje en pantalla y espera a que se pulse INTRO.
//
////////////////////////////////////////////////////////////////////////////////

void pausaEstandar (int nfils, int ncols)
{
  pausaGenerica(MSJxPAUSA, nfils, ncols, FALSE);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
//  USO:
//
//    Muestra en pantalla el mensaje indicado en la posición deseada y espera
//    a que el usuario pulse INTRO. Versión totalmente configurable de pausa.
//
//  DETALLES:
//
//    Es la función base de la familia de pausas. Permite personalizar el texto
//    mostrado, la posición en pantalla y si se añade salto de línea al final.
//    Primero llama a mensaje_x_y() para mostrar el texto y luego a
//    esperarINTRO() para aguardar la pulsación del usuario.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar antes de esperar.
//
//    nfils
//
//      Variable entera con el número de filas a bajar antes del mensaje.
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//    nuevalinea
//
//      Valor booleano: si es TRUE, añade un salto de línea tras el mensaje.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Muestra el mensaje en la posición indicada.
//
//    esperarINTRO()
//
//      Espera hasta que el usuario pulse INTRO.
//
////////////////////////////////////////////////////////////////////////////////

void pausaGenerica (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  mensaje_x_y(msjtxt, nfils, ncols, nuevalinea);

  esperarINTRO();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void texto (char msjtxt[]);
//
//  USO:
//
//    Muestra una cadena de texto en pantalla seguida de un salto de línea
//    automático. Sinónimo simplificado de puts().
//
//  DETALLES:
//
//    Usa directamente la función estándar puts(), que a diferencia de printf()
//    añade automáticamente un salto de línea al final. Es útil para mostrar
//    mensajes completos como líneas de texto.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar. Debe estar terminado en '\0'.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    puts()
//
//      Función estándar de C que imprime una cadena y añade salto de línea.
//
////////////////////////////////////////////////////////////////////////////////

void texto (char msjtxt[])
{
  puts(msjtxt);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void separar (void);
//
//  USO:
//
//    Imprime una línea en blanco en pantalla para separar visualmente bloques
//    de texto o menús. Versión sin parámetros de nuevaLinea().
//
//  DETALLES:
//
//    Llama a mostrar() con el carácter de salto de línea '\n'. Es equivalente
//    a imprimir una línea vacía, útil para dar espaciado visual entre secciones
//    del programa.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mostrar()
//
//      Imprime el texto indicado por pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void separar()
{
  mostrar("\n");
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void nuevaLinea (void);
//
//  USO:
//
//    Baja el cursor una línea en pantalla. Versión sin parámetros equivalente
//    a saltar(1).
//
//  DETALLES:
//
//    Envoltorio de saltar() con el valor fijo 1. Permite escribir código más
//    legible cuando simplemente se quiere pasar a la línea siguiente sin
//    necesidad de pasar ningún número como argumento.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar()
//
//      Realiza el desplazamiento vertical de líneas en pantalla.
//
////////////////////////////////////////////////////////////////////////////////

void nuevaLinea (void)
{
  saltar(1);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar (char msjtxt[]);
//
//  USO:
//
//    Muestra en pantalla el texto indicado, sin salto de línea ni desplazamiento.
//    Es la forma más directa y limpia de imprimir un mensaje.
//
//  DETALLES:
//
//    Envoltorio de mostrar_x_y() con 0 filas y 0 columnas de desplazamiento.
//    Es el punto de entrada habitual para mostrar mensajes simples sin
//    preocuparse por la posición en pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar. Debe estar terminado en '\0'.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mostrar_x_y()
//
//      Versión con posición configurable que realiza el trabajo real.
//
////////////////////////////////////////////////////////////////////////////////

void mostrar (char msjtxt[])
{
  mostrar_x_y (msjtxt, 0, 0);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mostrar_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Muestra en pantalla el texto indicado desplazado un número de filas y
//    columnas desde la posición actual del cursor.
//
//  DETALLES:
//
//    Envoltorio de mensaje_x_y() con nuevalinea fijado a FALSE. Permite
//    situar el texto en una posición relativa de pantalla sin añadir salto
//    de línea al final del mensaje.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar. Debe estar terminado en '\0'.
//
//    nfils
//
//      Variable entera con el número de filas a bajar antes de mostrar el texto.
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Función base que realiza el posicionamiento y la impresión del texto.
//
////////////////////////////////////////////////////////////////////////////////

void mostrar_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void escribir (char msjtxt[]);
//
//  USO:
//
//    Muestra en pantalla el texto indicado sin desplazamiento ni salto de línea.
//    Sinónimo de mostrar() con nombre alternativo.
//
//  DETALLES:
//
//    Envoltorio de escribir_x_y() con 0 filas y 0 columnas. Permite usar un
//    nombre diferente al de mostrar() cuando el contexto del programa lo
//    hace más claro o expresivo.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar. Debe estar terminado en '\0'.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    escribir_x_y()
//
//      Versión con posición configurable que realiza el trabajo real.
//
////////////////////////////////////////////////////////////////////////////////

void escribir (char msjtxt[])
{
  escribir_x_y (msjtxt, 0, 0);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void escribir_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Muestra en pantalla el texto indicado desplazado un número de filas y
//    columnas. Sinónimo de mostrar_x_y() con nombre alternativo.
//
//  DETALLES:
//
//    Envoltorio directo de mensaje_x_y() con nuevalinea fijado a FALSE.
//    Funciona de forma idéntica a mostrar_x_y(), ofreciendo otra denominación
//    para la misma operación.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar. Debe estar terminado en '\0'.
//
//    nfils
//
//      Variable entera con el número de filas a bajar antes de mostrar el texto.
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Función base que realiza el posicionamiento y la impresión del texto.
//
////////////////////////////////////////////////////////////////////////////////

void escribir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void imprimir (char msjtxt[]);
//
//  USO:
//
//    Muestra en pantalla el texto indicado sin desplazamiento ni salto de línea.
//    Sinónimo de mostrar() y escribir() con un tercer nombre alternativo.
//
//  DETALLES:
//
//    Envoltorio de imprimir_x_y() con 0 filas y 0 columnas. Amplía la familia
//    de sinónimos para mostrar texto, permitiendo al programador elegir el
//    nombre más expresivo en cada contexto.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar. Debe estar terminado en '\0'.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    imprimir_x_y()
//
//      Versión con posición configurable que realiza el trabajo real.
//
////////////////////////////////////////////////////////////////////////////////

void imprimir (char msjtxt[])
{
  imprimir_x_y (msjtxt, 0, 0);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void imprimir_x_y (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Muestra en pantalla el texto indicado desplazado un número de filas y
//    columnas. Sinónimo de mostrar_x_y() y escribir_x_y() con nombre alternativo.
//
//  DETALLES:
//
//    Envoltorio directo de mensaje_x_y() con nuevalinea fijado a FALSE.
//    Completa la familia de sinónimos para mostrar texto con desplazamiento.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar. Debe estar terminado en '\0'.
//
//    nfils
//
//      Variable entera con el número de filas a bajar antes de mostrar el texto.
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Función base que realiza el posicionamiento y la impresión del texto.
//
////////////////////////////////////////////////////////////////////////////////

void imprimir_x_y (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje (char msjtxt[], int nfils, int ncols);
//
//  USO:
//
//    Muestra en pantalla el texto indicado desplazado un número de filas y
//    columnas, sin salto de línea al final.
//
//  DETALLES:
//
//    Envoltorio de mensaje_x_y() con nuevalinea fijado a FALSE. Es el nombre
//    más semántico de la familia: deja claro que se está mostrando un mensaje
//    en una posición relativa de pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar. Debe estar terminado en '\0'.
//
//    nfils
//
//      Variable entera con el número de filas a bajar antes de mostrar el texto.
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje_x_y()
//
//      Función base que realiza el posicionamiento y la impresión del texto.
//
////////////////////////////////////////////////////////////////////////////////

void mensaje (char msjtxt[], int nfils, int ncols)
{
  mensaje_x_y (msjtxt, nfils, ncols, FALSE);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea);
//
//  USO:
//
//    Función base para mostrar texto en pantalla con control total de posición
//    y salto de línea. Todas las funciones de mostrar texto la usan internamente.
//
//  DETALLES:
//
//    Baja primero el número de filas indicado, luego desplaza a la derecha el
//    número de columnas dado, e imprime el texto con printf(). Si nuevalinea
//    es TRUE, añade un '\n' al final. Es la función de más bajo nivel de toda
//    la familia de funciones de texto.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar. Debe estar terminado en '\0'.
//
//    nfils
//
//      Variable entera con el número de filas a bajar antes de mostrar el texto.
//
//    ncols
//
//      Variable entera con el número de columnas a desplazar hacia la derecha.
//
//    nuevalinea
//
//      Valor booleano: si es TRUE, añade un salto de línea al final del texto.
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    saltar()
//
//      Realiza el desplazamiento vertical (filas).
//
//    tabular()
//
//      Realiza el desplazamiento horizontal (columnas).
//
//    printf()
//
//      Función estándar que imprime el texto y el posible salto de línea.
//
////////////////////////////////////////////////////////////////////////////////

void mensaje_x_y (char msjtxt[], int nfils, int ncols, boolean nuevalinea)
{
  saltar(nfils);
  tabular(ncols);
  printf("%s", msjtxt);
  
  if (nuevalinea)   printf("\n");   // ALTERNATIVA: if (nuevalinea)   putchar(ENTER);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    void iniciaAleatorizador (void);
//
//  USO:
//
//    Inicializa el generador de números aleatorios usando la hora actual como
//    semilla, para que cada ejecución del programa genere secuencias distintas.
//
//  DETALLES:
//
//    Llama a srand() con el valor de time(NULL), que devuelve el número de
//    segundos transcurridos desde el 1 de enero de 1970. Así la semilla cambia
//    en cada ejecución y los números generados con rand() no se repiten.
//    Debe llamarse una sola vez al inicio del programa, antes de usar
//    generaAleatorioEntero().
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    No devuelve ningún valor.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    srand()
//
//      Función estándar de <stdlib.h> que establece la semilla del generador.
//
//    time()
//
//      Función estándar de <time.h> que devuelve la hora actual del sistema.
//
////////////////////////////////////////////////////////////////////////////////

void iniciaAleatorizador (void)
{
  srand(time(NULL));
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int generaAleatorioEntero (int limite);
//
//  USO:
//
//    Genera y devuelve un número entero aleatorio entre 0 y limite-1 (sin
//    incluir limite). Útil para simular dados, sorteos, posiciones, etc.
//
//  DETALLES:
//
//    Usa el operador módulo (%) sobre el valor devuelto por rand() para
//    acotar el resultado al rango [0, limite-1]. Para que los números sean
//    verdaderamente aleatorios hay que haber llamado antes a iniciaAleatorizador().
//
//  PARÁMETROS DE ENTRADA:
//
//    limite
//
//      Variable entera que marca el tope exclusivo del rango. Por ejemplo,
//      con limite=6 se generan valores entre 0 y 5.
//
//  VALOR DE SALIDA:
//
//    Devuelve un entero aleatorio en el rango [0, limite-1].
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    rand()
//
//      Función estándar de <stdlib.h> que genera el número pseudoaleatorio.
//
////////////////////////////////////////////////////////////////////////////////

int generaAleatorioEntero (int limite)
{
  // Generará un número entre 0 y limite - 1, nunca llega a limite.
  return (rand() % limite);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int obtenerEntero (void);
//
//  USO:
//
//    Sustitución mejorada de scanf() que impide que queden letras almacenadas
//    en el buffer de teclado para posteriores operaciones de entrada de datos.
//
//  DETALLES:
//
//    La función scanf() no retira el código ASCII de la letra INTRO del buffer
//    de teclado ni posibles letras después de un texto que se pueda convertir
//    en una cantidad. Nos ayudamos de otra función creada en esta librería,
//    vaciarBuffer() para ello. No muestra ningún mensaje por pantalla.
//
//  PARÁMETROS DE ENTRADA:
//
//    nlineas
//
//      Variable entera que recibirá del exterior el número de líneas en blanco
//      que se va a desplazar el cursor hacia abajo.
//
//  VALOR DE SALIDA:
//
//    Devuelve al exterior el valor entero que a su vez ha recibido en la
//    variable "valor" de la función scanf(), mediante paso por referencia.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    scanf()
//
//      Es el programa estándar ("prefabricado") que hace la logística de
//      leer caracteres del teclado y convertirlos en la cantidad entera.
//
////////////////////////////////////////////////////////////////////////////////

int obtenerEntero (void)
{
  int valor;
  
  scanf("%d", &valor);
  vaciarBuffer();

  return valor;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerCaracterASCII (void);
//
//  USO:
//
//    Lee un carácter del teclado y lo devuelve. Sinónimo de obtenerLetra()
//    con nombre que enfatiza que se trabaja con el código ASCII del carácter.
//
//  DETALLES:
//
//    Envoltorio directo de obtenerLetra(). El nombre alternativo resulta más
//    descriptivo en contextos donde se quiere remarcar que el dato recibido
//    es un código ASCII, no necesariamente una letra del alfabeto.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter ASCII leído del teclado, o '\0' si no era ASCII válido.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    obtenerLetra()
//
//      Realiza la lectura real del teclado con validación ASCII.
//
////////////////////////////////////////////////////////////////////////////////

char obtenerCaracterASCII()
{
  return obtenerLetra();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerLetra (void);
//
//  USO:
//
//    Lee un carácter del teclado y lo devuelve, garantizando que sea un
//    carácter ASCII válido (código menor de 128) y vaciando el buffer.
//
//  DETALLES:
//
//    Lee un carácter con getchar(). Si su código ASCII es menor de 128 lo
//    considera válido y lo devuelve; si no, devuelve '\0' (carácter nulo).
//    Además, si el carácter leído no es INTRO, llama a vaciarBuffer() para
//    eliminar posibles caracteres sobrantes en el buffer de teclado.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter leído si es ASCII válido, o '\0' en caso contrario.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    getchar()
//
//      Función estándar que lee un carácter del buffer de teclado.
//
//    vaciarBuffer()
//
//      Elimina posibles caracteres sobrantes del buffer de teclado.
//
////////////////////////////////////////////////////////////////////////////////

char obtenerLetra (void)   // Sólo ASCII VÁLIDO.
{
  char letra, valida;
  
  letra = getchar();
  
  if (letra < 128)
    valida = letra; // Devolveremos la letra
  else
    valida = '\0';  // Devolveremos la letra nula.
  
  // VACIAMOS POSIBLES CÓDIGOS EN EL BUFFER.
  //   Se incluye el INTRO EXTRA y una posible escritura de múltiples letras.
  if (letra != ENTER)   vaciarBuffer();

  return valida;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEntero (char msjtxt[], int ncols);
//
//  USO:
//
//    Muestra un mensaje en pantalla para pedir un dato entero al usuario. El
//    mensaje es configurable y desplazable un número de caracteres desde la
//    izquierda de la pantalla.
//
//  DETALLES:
//
//    Es como un printf() más un scanf(), mejorados. Puede desplazarse el texto
//    recibido mediante un segundo dato entero. También impide problemas del
//    buffer de teclado con scanf(). Para ello, delega el emitir el mensaje por
//    pantalla a las funciones msj() y mostrar(), y la toma del dato entero a la
//    función obtenerEntero().
//
//  PARÁMETROS DE ENTRADA:
//
//    mensaje
//
//      Variable de tipo vector de caracteres donde se recibirá el texto que se
//      debe mostrar, que debe ser una cadena terminada en '\0'.
//
//    tabs
//
//      Variable entera donde se recibirá del exterior el número de espacios en
//      blanco a añadir antes del mensaje.
//
//  VALOR DE SALIDA:
//
//    Devuelve al programa donde se invoque, un valor entero que a su vez esta
//    función ha recibido desde la función obtenerEntero().
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    msj()
//
//      Se encarga efectivamente de mostrar el mensaje.
//
//    mostrar()
//
//      Usada para añadir en pantalla un texto adicional después del mensaje.
//
//    obtenerEntero()
//
//      Es la función que se encarga en la práctica de obtener la cantidad.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEntero (char msjtxt[], int ncols)
{
  mensaje(msjtxt, 0, ncols);
  mostrar(": ");
  
  return obtenerEntero();
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror);
//
//  USO:
//
//    Pide al usuario un número entero positivo (mayor o igual a cero) y no
//    acepta el valor hasta que se introduzca uno válido.
//
//  DETALLES:
//
//    Utiliza un bucle do-while que repite la petición mientras el número
//    introducido sea negativo. Si mostrarerror es TRUE, muestra el mensaje
//    de error global MSJxERROR cuando el valor no es válido. El mensaje de
//    error aparece indentado dos posiciones más que el mensaje principal.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar al pedir el dato.
//
//    ncols
//
//      Variable entera con el número de columnas de indentación del mensaje.
//
//    mostrarerror
//
//      Valor booleano: si es TRUE muestra el mensaje de error cuando el
//      valor introducido no es positivo.
//
//  VALOR DE SALIDA:
//
//    Devuelve el número entero positivo introducido por el usuario.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()
//
//      Muestra el texto de petición en pantalla.
//
//    mostrar()
//
//      Añade el separador ": " tras el mensaje.
//
//    obtenerEntero()
//
//      Lee el número entero introducido por el usuario.
//
//    nuevaLinea()
//
//      Añade saltos de línea para separar el mensaje de error.
//
//    mensaje_x_y()
//
//      Muestra el mensaje de error en la posición indicada.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEnteroPositivo (char msjtxt[], int ncols, boolean mostrarerror)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < 0)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < 0);
  
  return num;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror,
//                              int min, int max);
//
//  USO:
//
//    Pide al usuario un número entero dentro del intervalo cerrado [min, max]
//    y no acepta el valor hasta que se introduzca uno que esté en ese rango.
//
//  DETALLES:
//
//    Muestra el rango permitido [min, max] junto al mensaje de petición.
//    Usa un bucle do-while que repite la petición mientras el valor quede
//    fuera del intervalo. Si mostrarerror es TRUE, muestra el mensaje de
//    error global MSJxERROR cuando el valor no es válido.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar al pedir el dato.
//
//    ncols
//
//      Variable entera con el número de columnas de indentación del mensaje.
//
//    mostrarerror
//
//      Valor booleano: si es TRUE muestra el mensaje de error cuando el
//      valor queda fuera del intervalo permitido.
//
//    min
//
//      Variable entera con el valor mínimo permitido (incluido en el rango).
//
//    max
//
//      Variable entera con el valor máximo permitido (incluido en el rango).
//
//  VALOR DE SALIDA:
//
//    Devuelve el número entero introducido, garantizado dentro de [min, max].
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()
//
//      Muestra el texto de petición en pantalla.
//
//    printf()
//
//      Añade el intervalo [min, max] visible al usuario.
//
//    obtenerEntero()
//
//      Lee el número entero introducido por el usuario.
//
//    nuevaLinea()
//
//      Añade saltos de línea para separar el mensaje de error.
//
//    mensaje_x_y()
//
//      Muestra el mensaje de error en la posición indicada.
//
////////////////////////////////////////////////////////////////////////////////

int pedirEnteroIntervalo (char msjtxt[], int ncols, boolean mostrarerror, int min, int max)
{
  int num;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%d,%d]: ", min, max);
    
    num = obtenerEntero();
    
    if (mostrarerror)
    {
      if (num < min || num > max)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (num < min || num > max);
  
  return num;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra);
//
//  USO:
//
//    Pide al usuario que introduzca una letra concreta y no continúa hasta
//    que la introduzca correctamente (sin distinguir mayúsculas/minúsculas).
//
//  DETALLES:
//
//    Convierte tanto la letra esperada como la introducida a mayúsculas antes
//    de compararlas, de modo que la comprobación no distingue entre mayúsculas
//    y minúsculas. Usa un bucle do-while que repite la petición hasta que
//    ambas letras coincidan.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar al pedir el dato.
//
//    ncols
//
//      Variable entera con el número de columnas de indentación del mensaje.
//
//    mostrarerror
//
//      Valor booleano: si es TRUE muestra el mensaje de error cuando la
//      letra introducida no coincide con la esperada.
//
//    letra
//
//      Carácter que se espera que introduzca el usuario.
//
//  VALOR DE SALIDA:
//
//    Devuelve la letra introducida convertida a mayúsculas.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()
//
//      Muestra el texto de petición en pantalla.
//
//    mostrar()
//
//      Añade el separador ": " tras el mensaje.
//
//    obtenerLetra()
//
//      Lee el carácter introducido por el usuario.
//
//    toupper()
//
//      Convierte un carácter a mayúsculas para la comparación.
//
//    nuevaLinea() y mensaje_x_y()
//
//      Muestran el mensaje de error cuando el valor no es válido.
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetra (char msjtxt[], int ncols, boolean mostrarerror, char letra)
{
  char pedida;
  
  letra = toupper(letra);
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(": ");
    
    pedida = obtenerLetra();
    pedida = toupper(pedida);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != pedida)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != pedida);
  
  return pedida;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror);
//
//  USO:
//
//    Pide al usuario que confirme o rechace una acción introduciendo S (sí)
//    o N (no), y no acepta otra respuesta. Muestra las opciones disponibles.
//
//  DETALLES:
//
//    Muestra las opciones [S/N] junto al mensaje. Convierte la respuesta a
//    mayúsculas para no distinguir entre s/S y n/N. Usa un bucle do-while
//    que repite la petición hasta recibir una de las dos letras válidas.
//    Los valores SI y NO están definidos como constantes en el fichero de cabecera.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto de la pregunta a confirmar.
//
//    ncols
//
//      Variable entera con el número de columnas de indentación del mensaje.
//
//    mostrarerror
//
//      Valor booleano: si es TRUE muestra el mensaje de error cuando la
//      respuesta introducida no es S ni N.
//
//  VALOR DE SALIDA:
//
//    Devuelve el carácter SI o NO (en mayúsculas) introducido por el usuario.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    mensaje()
//
//      Muestra el texto de la pregunta en pantalla.
//
//    printf()
//
//      Añade las opciones [S/N] visibles al usuario.
//
//    obtenerLetra()
//
//      Lee el carácter introducido por el usuario.
//
//    toupper()
//
//      Convierte la respuesta a mayúsculas para la comparación.
//
//    nuevaLinea() y mensaje_x_y()
//
//      Muestran el mensaje de error cuando el valor no es válido.
//
////////////////////////////////////////////////////////////////////////////////

int pedirConfirmacion (char msjtxt[], int ncols, boolean mostrarerror)
{
  char letra;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    printf(" [%c/%c]: ", SI, NO);
    
    letra = obtenerLetra();
    letra = toupper(letra);   // Convertimos a mayúsculas para simplificar casos.
    
    if (mostrarerror)
    {
      if (letra != SI && letra != NO)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
    
  } while (letra != SI && letra != NO);
  
  return letra;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas);
//
//  USO:
//
//    Comprueba si dos caracteres son iguales, con la opción de ignorar la
//    diferencia entre mayúsculas y minúsculas.
//
//  DETALLES:
//
//    Si sensibleamayusculas es FALSE, convierte ambos caracteres a mayúsculas
//    antes de compararlos, de modo que 'a' y 'A' se consideran iguales.
//    Devuelve TRUE si los caracteres coinciden y FALSE si no.
//
//  PARÁMETROS DE ENTRADA:
//
//    original
//
//      Carácter que se usa como referencia (el esperado).
//
//    dada
//
//      Carácter que se quiere comprobar (el introducido por el usuario).
//
//    sensibleamayusculas
//
//      Valor booleano: si es TRUE distingue mayúsculas de minúsculas;
//      si es FALSE las trata como equivalentes.
//
//  VALOR DE SALIDA:
//
//    Devuelve TRUE si los caracteres coinciden, FALSE si no coinciden.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    toupper()
//
//      Convierte caracteres a mayúsculas cuando no se distingue entre ellas.
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraUnica (char original, char dada, boolean sensibleamayusculas)
{
  if (!sensibleamayusculas)
  {
    original = toupper(original);
      dada   = toupper(dada);
  }
  
  return (original == dada);
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    boolean validarLetraConjunto (char letra, char seleccion[],
//                                  boolean sensibleamayusculas);
//
//  USO:
//
//    Comprueba si un carácter dado pertenece a un conjunto de caracteres
//    válidos definido por una cadena, con opción de ignorar mayúsculas.
//
//  DETALLES:
//
//    Recorre uno a uno los caracteres de la cadena seleccion[] y compara
//    cada uno con letra usando validarLetraUnica(). En cuanto encuentra una
//    coincidencia, devuelve TRUE y detiene la búsqueda. Si recorre toda la
//    cadena sin encontrar coincidencia, devuelve FALSE.
//
//  PARÁMETROS DE ENTRADA:
//
//    letra
//
//      Carácter que se quiere comprobar (el introducido por el usuario).
//
//    seleccion[]
//
//      Cadena de caracteres que contiene todas las letras válidas permitidas.
//
//    sensibleamayusculas
//
//      Valor booleano: si es TRUE distingue mayúsculas de minúsculas;
//      si es FALSE las trata como equivalentes.
//
//  VALOR DE SALIDA:
//
//    Devuelve TRUE si la letra está en el conjunto, FALSE si no lo está.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen()
//
//      Calcula la longitud de la cadena de caracteres válidos.
//
//    validarLetraUnica()
//
//      Realiza la comparación individual de cada carácter.
//
////////////////////////////////////////////////////////////////////////////////

boolean validarLetraConjunto (char letra, char seleccion[], boolean sensibleamayusculas)
{
  boolean resultado = FALSE;
  int largo = strlen(seleccion);
  
  for(int i = 0; i < largo ; i++)
  {
    if (validarLetraUnica(letra, seleccion[i], sensibleamayusculas))
    {
      resultado = TRUE;
      break;
    }
  }
  
  return resultado;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char *cadenaOpcionesDisponibles (char entrada[]);
//
//  USO:
//
//    Transforma una cadena de letras válidas en una cadena con las letras
//    separadas por '/', lista para mostrar al usuario las opciones disponibles.
//    Por ejemplo: "ABC" → "A/B/C".
//
//  DETALLES:
//
//    Reserva memoria dinámica con malloc() para construir la nueva cadena.
//    La cadena resultante tiene el doble de caracteres que la original menos
//    uno (cada letra va seguida de '/' excepto la última, que lleva '\0').
//    Si la entrada es NULL o vacía, gestiona esos casos devolviendo NULL o
//    cadena vacía respectivamente. Es importante liberar la memoria con
//    free() cuando ya no se necesite la cadena devuelta.
//
//  PARÁMETROS DE ENTRADA:
//
//    entrada[]
//
//      Cadena de caracteres con las letras válidas juntas (sin separadores).
//
//  VALOR DE SALIDA:
//
//    Devuelve un puntero a la nueva cadena con las letras separadas por '/'.
//    Devuelve NULL si la entrada es NULL.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    strlen()
//
//      Calcula la longitud de la cadena de entrada.
//
//    malloc()
//
//      Reserva la memoria necesaria para la cadena de salida.
//
////////////////////////////////////////////////////////////////////////////////

char *cadenaOpcionesDisponibles (char entrada[])
{
  if (entrada == NULL) return NULL;   // Si no dan nada, petas máximus ...
  
  char *textoinicial, *textofinal;
  
  textoinicial = entrada;
  
  int largoinicial, largofinal;
  
  largoinicial = strlen(textoinicial);

  if (largoinicial == 0)
  {
    // Nos dan cadena vacía, así que generamos vacía. Pero consideramos el '\0'.
    largofinal = 1;
    textofinal = (char *) malloc(1*sizeof(char));
    textofinal[0] = '\0';
  }
  else
  {
    // CASO 1: "A" -> "A" => largo 2 = 1 (letra) + 1 ('\0')
    // CASO 2: "ABC" -> "A/B/C" => largo 6 = 3 (letras) + 2 (sepadores) +1 ('\0'); 
    largofinal = 2 * largoinicial;
    textofinal = (char *) malloc(largofinal*sizeof(char));
    
    if (textofinal != NULL)
    {
      int j = 0;
      for (int i = 0; i < largoinicial; i++, j++)
      {
        textofinal[j] = textoinicial[i];
        j++;
        textofinal[j] = '/';
      }
      
      // Sustituimos la última '/' por un ' 0'.
      j--;
      textofinal[j] = '\0';
    }
  }

  return textofinal;
}


////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror,
//                             char seleccion[], boolean sensibleamayusculas);
//
//  USO:
//
//    Pide al usuario que elija una letra entre un conjunto de opciones válidas
//    definido por una cadena, mostrando las opciones disponibles separadas por '/'.
//
//  DETALLES:
//
//    Usa cadenaOpcionesDisponibles() para construir la cadena de opciones
//    visible (por ejemplo "A/B/C") y la muestra entre corchetes. Valida la
//    letra introducida con validarLetraConjunto(). Si no es válida y
//    mostrarerror es TRUE, muestra el mensaje de error. Al terminar, libera
//    la memoria reservada por cadenaOpcionesDisponibles() con free().
//    Si sensibleamayusculas es FALSE, siempre devuelve la letra en mayúsculas.
//
//  PARÁMETROS DE ENTRADA:
//
//    msjtxt
//
//      Vector de caracteres con el texto a mostrar al pedir la opción.
//
//    ncols
//
//      Variable entera con el número de columnas de indentación del mensaje.
//
//    mostrarerror
//
//      Valor booleano: si es TRUE muestra el mensaje de error cuando la
//      letra introducida no pertenece al conjunto de opciones válidas.
//
//    seleccion[]
//
//      Cadena con las letras válidas juntas (por ejemplo "SN" para S y N).
//
//    sensibleamayusculas
//
//      Valor booleano: si es FALSE, trata mayúsculas y minúsculas como iguales
//      y siempre devuelve la letra en mayúsculas.
//
//  VALOR DE SALIDA:
//
//    Devuelve la letra válida introducida por el usuario (en mayúsculas si
//    sensibleamayusculas es FALSE).
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    cadenaOpcionesDisponibles()
//
//      Construye la cadena de opciones con separadores para mostrar al usuario.
//
//    mensaje()
//
//      Muestra el texto de petición en pantalla.
//
//    mostrar() y printf()
//
//      Muestran las opciones disponibles entre corchetes.
//
//    obtenerLetra()
//
//      Lee el carácter introducido por el usuario.
//
//    validarLetraConjunto()
//
//      Comprueba si la letra introducida pertenece al conjunto válido.
//
//    nuevaLinea() y mensaje_x_y()
//
//      Muestran el mensaje de error cuando el valor no es válido.
//
//    free()
//
//      Libera la memoria reservada dinámicamente para la cadena de opciones.
//
//    toupper()
//
//      Convierte la letra a mayúsculas cuando no se distingue entre ellas.
//
////////////////////////////////////////////////////////////////////////////////

int pedirLetraSeleccion (char msjtxt[], int ncols, boolean mostrarerror, char seleccion[], boolean sensibleamayusculas)
{
  // HACER: Evitar que falle con «seleccion» a valor NULL.
  
  // Usar «cadenaOpcionesDisponibles()» implica luego liberar memoria con «free()».
  char *editada = cadenaOpcionesDisponibles(seleccion);
  
  char letra;
  
  boolean validada;
  
  do
  {
    mensaje(msjtxt, 0, ncols);
    mostrar(" [");
    printf("%s", editada);
    mostrar("]: ");
    
    letra = obtenerLetra();

    validada = validarLetraConjunto(letra, seleccion, sensibleamayusculas);
    
    if (mostrarerror)
    {
      if (!validada)
      {
        nuevaLinea();
        mensaje_x_y(MSJxERROR, 0, ncols+2, TRUE);
        nuevaLinea();
      }
    }
  } while (!validada);
  
  // Liberamos la memoria para cadena modificada.
  free(editada);
  
  // Si no era sensible a mayúsculas, siempre la devolvemos mayúscula.
  if (!sensibleamayusculas)   letra = toupper(letra);
  
  return letra;
}



#ifdef SO_WINDOWS

#include <conio.h>

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    char obtenerTeclaInteractiva (void);   [versión Windows]
//
//  USO:
//
//    Lee una tecla del teclado de forma interactiva, sin necesidad de pulsar
//    INTRO, y devuelve un código identificador de la tecla pulsada.
//
//  DETALLES:
//
//    En Windows usa _getch() de <conio.h>, que es bloqueante por defecto.
//    Las teclas especiales (flechas, etc.) generan dos códigos consecutivos:
//    el primero es 0 o 224, y el segundo identifica la tecla concreta.
//    Las flechas se convierten a las constantes TECLA_ARRIBA, TECLA_ABAJO,
//    TECLA_IZQUIERDA y TECLA_DERECHA. Las teclas no reconocidas devuelven
//    TECLA_NULA. También normaliza ENTER y RETROCESO a sus constantes.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    Devuelve un carácter o código identificador de la tecla pulsada:
//    TECLA_ARRIBA, TECLA_ABAJO, TECLA_IZQUIERDA, TECLA_DERECHA,
//    TECLA_ENTER, TECLA_RETROCESO o TECLA_NULA.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    _getch()   [<conio.h>, solo Windows]
//
//      Lee un carácter del teclado sin eco y sin esperar INTRO.
//
////////////////////////////////////////////////////////////////////////////////

char obtenerTeclaInteractiva(void)
{
  int caracter = _getch();   // En Windows, getch() ya es bloqueante por defecto.

  if (caracter == 0 || caracter == 224)
  {
    // Tecla especial, depende de un segundo código. Lo leemos.
    caracter = _getch();
    
    switch(caracter)
    {
      case 72: caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
      case 80: caracter = TECLA_ABAJO;     break;   // Flecha Abajo
      case 75: caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
      case 77: caracter = TECLA_DERECHA;   break;   // Flecha Derecha
      default: caracter = TECLA_NULA;               // Tecla nula.
    }
    else
    {
      // Normalización de teclas conflictivas no estándar.
      switch(caracter)
      {
        case 13: caracter = TECLA_ENTER;
        case 8:  caracter = TECLA_RETROCESO;
      }
    }
    
    return (char)caracter;
}

#else

#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

////////////////////////////////////////////////////////////////////////////////
//
//  FUNCIÓN:
//
//    int obtenerTeclaInteractiva (void);   [versión Linux/Mac]
//
//  USO:
//
//    Lee una tecla del teclado de forma interactiva, sin necesidad de pulsar
//    INTRO, y devuelve un código identificador de la tecla pulsada.
//
//  DETALLES:
//
//    En Linux/Mac no existe _getch(), así que esta versión reconfigura la
//    terminal manualmente: desactiva el modo canónico (que requiere INTRO) y
//    el eco (que muestra la tecla en pantalla) usando tcsetattr(). Las teclas
//    de flecha envían tres caracteres: ESC (27), '[' (91) y una letra (A/B/C/D).
//    Tras leer ESC, cambia a modo no bloqueante para detectar si hay más
//    caracteres. Al terminar, restaura siempre la configuración original de
//    la terminal.
//
//  PARÁMETROS DE ENTRADA:
//
//    Ninguno
//
//  VALOR DE SALIDA:
//
//    Devuelve un entero con el código identificador de la tecla pulsada:
//    TECLA_ARRIBA, TECLA_ABAJO, TECLA_IZQUIERDA, TECLA_DERECHA,
//    TECLA_ESCAPE o TECLA_NULA para teclas no reconocidas.
//
//  FUNCIONES DE LAS QUE DEPENDE:
//
//    tcgetattr() y tcsetattr()   [<termios.h>]
//
//      Leen y modifican la configuración de la terminal del sistema.
//
//    getchar()
//
//      Lee caracteres del teclado una vez reconfigurada la terminal.
//
//    fcntl()   [<fcntl.h>]
//
//      Cambia la terminal entre modo bloqueante y no bloqueante.
//
////////////////////////////////////////////////////////////////////////////////

int obtenerTeclaInteractiva(void)
{
  struct termios terminaloriginal, terminalnueva;
  int caracter;

  // 1. Obtenemos la configuración actual de la terminal.
  tcgetattr(STDIN_FILENO, &terminaloriginal);
  terminalnueva = terminaloriginal;

  // 2. Desactivamos el modo canónico (espera de INTRO) y el ECO (ver la tecla al pulsar).
  terminalnueva.c_lflag &= ~(ICANON | ECHO); // Quitamos espera de INTRO y eco
  tcsetattr(STDIN_FILENO, TCSANOW, &terminalnueva);
  
  // 3. El programa se detiene aquí hasta recibir un carácter.
  // Las flechas envían una secuencia de escape: 27 (ESC), 91 ('['), y una letra.
  caracter = getchar();
  
  if (caracter == ESCAPE)
  {
    // Cambiamos a NO BLOQUEANTE un instante para ver si hay bytes extra
    int flags = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);
    
    // Pedimos a ver si hay otro caracter.
    int siguiente = getchar();
    
    // ¿Es '[' (91)?
    if (siguiente == '[')
    {
      // Lo desechamos simplemente no usando "siguiente".

      // Pedimos el tercer código de caracter generado.
      caracter = getchar();
      
      while ((siguiente = getchar()) != EOF && siguiente != -1);

      switch(caracter)
      {
        case 'A': caracter = TECLA_ARRIBA;    break;   // Flecha Arriba
        case 'B': caracter = TECLA_ABAJO;     break;   // Flecha Abajo
        case 'D': caracter = TECLA_IZQUIERDA; break;   // Flecha Izquierda
        case 'C': caracter = TECLA_DERECHA;   break;   // Flecha Derecha
        default:  caracter = TECLA_NULA;      break;
      }
    }
    else
    {
      if (siguiente == EOF || siguiente == -1)
      {
        // Era sólo la tecla ESCAPE.
        caracter = TECLA_ESCAPE;
      }
      else
      {
        // Era una secuencia no contemplada.
        caracter = TECLA_NULA;
      }
    }

    // Restauramos el modo BLOQUEANTE de la terminal.
    fcntl(STDIN_FILENO, F_SETFL, flags);
  }

  // 4. Restauramos la configuración original antes de salir.
  tcsetattr(STDIN_FILENO, TCSANOW, &terminaloriginal);
  
  return caracter;
}

#endif
