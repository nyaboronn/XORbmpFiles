

#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] )
{
  if ( argc != 3 ) {
    puts( "Faltan argumentos (clave, imagen)" );
    exit(1);
  }
  
  char* FICHEROCLAVE = argv[ 1 ];
  char* FICHEROIMAGEN = argv[ 2 ];
  char FICHEROSALIDA[] = "claveImagen.bmp";
  
  FILE* pClave; 
  FILE* pImagen;

  size_t claveSize;

  pClave = fopen(FICHEROCLAVE, "r");
  // abrir como lectura para obtener la cabecera
  pImagen = fopen(FICHEROIMAGEN, "rb");

  if (pClave == NULL) {
    puts("Error leer clave");
    return -1;
  }
	
  if (pImagen == NULL) {
    puts("Error leer imagen");
    return -1;
  }
	
  // size en B del archivo de la clave
  fseek(pClave, 0, SEEK_END);
  claveSize = ftell(pClave);
  rewind(pClave);

  /*
    openssl rand -hex 30000
    Cada letra se forma por 1B por ejemplo 0xFE, por ello el tipo es unsigned char
    Al estar 0xFE separado en los caracteres 'F' y 'E' (por poner un ejemplo) la cantidad
    de B ocupados al obtener su valor es la mitad.
  */
  unsigned char* bufferClave = (unsigned char*)malloc(claveSize / 2);
	
  /*
    Lee caracteres de dos en dos y de ellos se obtiene el valor numerico.
  */
  int c;
  size_t i = 0;
  char hex[2];
  while (((c = fgetc(pClave)) != EOF)) {
    hex[0] = c;
    hex[1] = fgetc(pClave);
    bufferClave[i++] = (unsigned char)strtol(hex, NULL, 16);
  }

  // guardar la cabecera
  unsigned char cabecera[54] = { 0 };
  fread(cabecera, 1, 54, pImagen);

  fclose(pClave);
  fclose(pImagen);

  // guardar el resultado en un archivo nuevo
  FILE* resultado;
  resultado = fopen(FICHEROSALIDA, "wb");

  fwrite(cabecera, sizeof(unsigned char), 54, resultado);
  fwrite(bufferClave, sizeof(unsigned char), (claveSize / 2), resultado);

  fclose(resultado);

  return 0;
}
