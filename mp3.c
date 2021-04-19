/*
 * 
 * Proyecto GStreamer - Aplicaciones Multimedia (2020-2021)
 * Universidad Carlos III de Madrid
 *
 * Equipo (TO DO: rellenar con los datos adecuados):
 * - Alumno 1 (nombre, apellidos y NIA)
 * - Alumno 2 (nombre, apellidos y NIA)
 *
 * Versión implementada (TO DO: eliminar las líneas que no procedan):
 * - pipeline
 * - reproducción mp3 visualmente (goom)
 * - conversión mp3 a ogg
 *  - manejar eventos de teclado (mostrar tiempo)
 */

  // ------------------------------------------------------------
  // Procesar argumentos
  // ------------------------------------------------------------
  
  // REF: https://www.gnu.org/software/libc/manual/html_node/Parsing-Program-Arguments.html#Parsing-Program-Arguments

  /* 
   * Argumentos del programa:
   * -h: presenta la ayuda y termina (con estado 0).
   * -f fichero_mp3: nombre del fichero del audio de entrada en formato MP3.   
   * -o fichero_ogg: nombre del fichero del audio que se va a generar en formato OGG.
   * -t: responde al evento de teclado para poner el instante de tiempo enla imagen visualizada.
   */
#include <gst/gst.h>
#include <glib.h>
#include <stdio.h>
#include <string.h>

#include <ctype.h>
#include <stdlib.h>
#include <unistd.h>

int main (int   argc, char *argv[])
{

  int c;
    
  opterr = 0;  // no es necesario declararla, la exporta getopt

  while ((c = getopt (argc, argv, "hto:f:")) != -1) {
    switch (c)
      {
      case 'h':
	// ayuda
	g_print("Funcionalidad ayuda no implementada\n");
		
        return 0;

      case 'f':
	// fichero_ogg: nombre del fichero del audio de entrada (MP3).
		g_print("Funcionalidad leer fichero mp3 y mostrar goom no implementada\n");
        break;
		
      case 'o':
	// fichero_ogg: nombre del fichero del audio que se va a generar en formato OGG.
	g_print("Funcionalidad convertir fichero mp3 a ogg\n");
		    
        break;

      case 't':
	// superpone un texto con el instante en la imagen visualizada.
	g_print("Funcionalidad un texto con el instante en la imagen no implementada\n");
        break;

      case '?':
	// getopt devuelve '?' si encuentra una opción desconocida
	// o si falta el argumento para una opción que lo requiere
	// La opción conflictiva queda almacenada en optopt
        if ((optopt == 'o') ) {
	  // falta argumento para opción que lo requiere
          fprintf (stderr, "Error: la opción -%c requiere un argumento\n", optopt);
		}
		// error: opción desconocida
        else if (isprint (optopt))
          fprintf (stderr, "Error: argumento `-%c' no válido\n", optopt);
        else
          fprintf (stderr, "Error: argumento `\\x%x' no válido.\n", optopt);
        return 1;
	
      default:
        fprintf (stderr,
                 "Error: argumento %d no válido\n", optind);
        
        return 1;
      }
  }
  
   // getopt recoloca los argumentos no procesados al final
  // el primero será el nombre del fichero de entrada (es correcto)
  // si hay algún otro: error argumento desconocido
  for (int index = optind+1; index < argc; index++) {
    printf ("Error: argumento %s no válido\n", argv[index]);
    return 1;
  }

}


