/*
 * 
 * Proyecto GStreamer - Aplicaciones Multimedia (2019-2020)
 * Universidad Carlos III de Madrid
 *
 * Equipo (TO DO: rellenar con los datos adecuados):
 * - Alumno 1 (nombre, apellidos y NIA)
 * - Alumno 2 (nombre, apellidos y NIA)
 *
 * Versión implementada (TO DO: eliminar las líneas que no procedan):
 * - versión básica
 * - intervalo 
 * - texto
 * - bordes
 */




  // ------------------------------------------------------------
  // Procesar argumentos
  // ------------------------------------------------------------
  
  // REF: https://www.gnu.org/software/libc/manual/html_node/Parsing-Program-Arguments.html#Parsing-Program-Arguments

  /* 
   * Argumentos del programa:
   * -h: presenta la ayuda y termina (con estado 0)
   * -i inicio: instante inicial a partir del cual reproducir y realizar la detección (en nanosegundos)
   * -f fin: instante final en el que detener la reproducción y detección (en nanosegundos)
   * -t: superpone un texto con el número de código de barras y su símbolo en la imagen visualizada
   * -b: aplica un borde de color rojo al vídeo para resaltar las imágenes en que aparece un código de barras
   * fichero_entrada: fichero de vídeo a analizar
   */


  int c;
  char *filename;
    
  opterr = 0;  // no es necesario declararla, la exporta getopt

  while ((c = getopt (argc, argv, "hi:f:tb")) != -1) {
    switch (c)
      {
      case 'h':
	// ayuda
	g_print("Funcionalidad ayuda no implementada\n");
        break;

      case 'i':
	// tiempo inicio intervalo de vídeo a procesar
	g_print("Funcionalidad intervalo no implementada\n");
        break;

      case 'f':
	// tiempo inicio intervalo de vídeo a procesar
	g_print("Funcionalidad intervalo no implementada\n");
        break;

      case 't':
	// Texto sobrescrito
	g_print("Funcionalidad efectos no implementada\n");
        break;

      case 'b':
	// Borde en la pantalla
	g_print("Funcionalidad efectos no implementada\n");
        break;

      case '?':
	// getopt devuelve '?' si encuentra una opción desconocida
	// o si falta el argumento para una opción que lo requiere
	// La opción conflictiva queda almacenada en optopt
        if ((optopt == 'i') ||(optopt == 'f') || (optopt == 'l') ||(optopt == 'g')) {
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

  filename = argv[optind];
  
  // getopt recoloca los argumentos no procesados al final
  // el primero será el nombre del fichero de entrada (es correcto)
  // si hay algún otro: error argumento desconocido
  for (int index = optind+1; index < argc; index++) {
    printf ("Error: argumento %s no válido\n", argv[index]);
    return 1;
  }



