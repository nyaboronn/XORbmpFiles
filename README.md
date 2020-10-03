# cosasRandomConBMP

Cada carpeta es un script indipendiente al resto.

## xor2bmp

| imagen1  | imagen2 | XOR |
| ------------- | ------------- | ------------- |
| ![mensaje limpio](https://github.com/nyaboronn/XORbmpFiles/blob/master/xor2bmp/examples/data.bmp) | ![data](https://github.com/nyaboronn/XORbmpFiles/blob/master/xor2bmp/examples/key.bmp) | ![clave](https://github.com/nyaboronn/XORbmpFiles/blob/master/xor2bmp/examples/encryptedData.bmp) |

Imágenes de ejemplo descargadas desde [fileformat.info](https://www.fileformat.info/format/bmp/sample/index.htm)

Calcula la operación XOR entre dos imágenes con formato BMP. La cabecera está establecida a 54 B y no se controlan imágenes de distinto número de Bytes.

```sh
$ gcc xorbmp.c -o xorbmp
$ ./xorbmp ./examples/data.bmp ./examples/key.bmp
```


## keyTobmp

| clave | imagen resultante |
| ------------- | ------------- |
| ea299fd8d676... | ![encriptado](https://github.com/nyaboronn/XORbmpFiles/blob/master/keyTobmp/examples/claveImagen.bmp) |

Dado un archivo de texto con una clave en formato hexadecimal, copia la clave en los pixeles
de una imagen para comprobar de forma visual la aleatoriedad de la clave. Esta se puede
generar con OpenSSL (openssl rand -hex 30000).

Si la imgen es 100 x 100px, cada pixel son 3B (RGB), por tanto la imagen estará formada
por 10000px * 3B = 30000B (sin contar la cabecera).

AL final el script lo que hace es copiar Bytes en un fichero, la imagen de origen puede solo ser la cabecera. No es necesario
que sea una imgen visible como la dada en los 'examples'

```sh
$ gcc keytobmp.cpp -o keytobmp
$ ./keytobmp examples/clave.txt examples/imagen.bmp 
```
