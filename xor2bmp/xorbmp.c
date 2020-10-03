

#include <stdio.h>
#include <stdlib.h>

// Size en B de la cabecera bmp
#define CABECERASIZE 54

int main( int argc, char* argv[] ) {

  if ( argc != 3 ) {
    puts( "Falta argumentos (file1, file2)" );
    exit(1);
  }

  char* NOMBREMENSAJE = argv[ 1 ];
  char* NOMBRECLAVE = argv[ 2 ];
  
  long lSize;
  size_t readedBytes;
  size_t imagen1Size;
  
  FILE* fImagen1;
  FILE* fImagen2;
  unsigned char cabecera[ CABECERASIZE ] = { 0 };
  unsigned char* pixelsImagen1;
  unsigned char* pixelsImagen2;

  
  puts( "*** Imagen1 ***" );

  // abrir imagen1
  fImagen1 = fopen( NOMBREMENSAJE, "rb" );

  if ( fImagen1 == NULL ) {
    puts( "error el leer imagen1" );
    exit(1);
  }

  // size del archivo
  fseek( fImagen1 , 0 , SEEK_END );
  imagen1Size = lSize = ftell( fImagen1 );
  rewind( fImagen1 );

  printf( "size de la imagen: %zu\n", lSize );

  // obtener cabecera
  readedBytes = fread( cabecera, 1, CABECERASIZE, fImagen1 );

  printf( "cabecera bytes leidos: %zu\n", readedBytes );

  for ( size_t i = 0;  i < sizeof(cabecera); ++i ) {
    printf( "%X ", cabecera[ i ] );
  }

  puts( "" );

  // obtener pixels
  size_t lSizePixels = lSize - CABECERASIZE;
  pixelsImagen1 = (unsigned char*) malloc( lSizePixels );
  readedBytes = fread( pixelsImagen1, 1, lSizePixels, fImagen1 );

  printf( "pixels bytes leidos: %zu\n", readedBytes );

  for ( size_t i = 0; i < 20; ++i ) {
    printf( "%02X ", pixelsImagen1[ i ] );
  }

  puts( "...");

  // cerrar file
  fclose( fImagen1 );
  

  puts( "\n*** Imagen2 ***" );

  // abrir imagen2
  fImagen2 = fopen( NOMBRECLAVE, "rb" );

  if ( fImagen2 == NULL ) {
    puts( "error el leer imagen2" );
    exit(1);
  }

  // size del archivo
  fseek( fImagen2 , 0 , SEEK_END );
  lSize = ftell( fImagen2 );
  rewind( fImagen2 );

  printf( "size de la imagen: %zu\n", lSize );
  
  // saltar cabecera (usar la de la primera imagen)
  fseek( fImagen2, 54, SEEK_SET );

  // obtener pixels
  lSizePixels = lSize - CABECERASIZE;
  pixelsImagen2 = (unsigned char*) malloc( lSizePixels );
  readedBytes = fread( pixelsImagen2, 1, lSizePixels, fImagen2 );

  printf( "pixels bytes leidos: %zu\n", readedBytes );

  for ( size_t i = 0; i < 20; ++i ) {
    printf( "%02X ", pixelsImagen2[ i ] );
  }

  puts( "...");  // obtener pixels
  

  /*
    calcular xor
    iterar sobre la imagen de menos pixels
   */

  puts( "\n*** XOR ***" );
  
  size_t numPixelsCalcular;

  numPixelsCalcular = imagen1Size - CABECERASIZE;

  for ( size_t i = 0; i < numPixelsCalcular; ++i ) {
    pixelsImagen1[ i ] = (unsigned char)(pixelsImagen1[ i ] ^ pixelsImagen2[ i ]);
  } 
  
  for ( size_t i = 0; i < 20; ++i ) {
    printf( "%02X ", pixelsImagen1[ i ] );
  }

  puts( "..." );
  
  fclose( fImagen2 );

  /*
    guardar resultado en un archivo distinto
   */

  FILE* resultado;

  resultado = fopen( "ouput.bmp", "wb+" );

  fwrite( cabecera, sizeof(unsigned char), CABECERASIZE, resultado );
  fwrite( pixelsImagen1, sizeof( unsigned char), (imagen1Size - CABECERASIZE), resultado );
  fclose( resultado );
  
}
