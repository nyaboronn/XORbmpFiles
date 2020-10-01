# XORbmpFiles

Calcula la operación XOR entre dos imágenes con formato BMP. 
La cabecera está establecida a 54 B y no se controlan imágenes de distinto número de Bytes.

| imagen1  | imagen2 | XOR |
| ------------- | ------------- | ------------- |
| ![mensaje limpio](https://github.com/nyaboronn/XORbmpFiles/blob/master/examples/data.bmp?raw=true) | ![clave](https://github.com/nyaboronn/XORbmpFiles/blob/master/examples/key.bmp?raw=true) | ![mensaje limpio](https://github.com/nyaboronn/XORbmpFiles/blob/master/examples/encryptedData.bmp?raw=true) |

## Archivos

Imágenes de ejemplo descargadas desde [fileformat.info](https://www.fileformat.info/format/bmp/sample/index.htm)

## Uso

```sh
$ gcc xorbmp.c -o xorbmp
$ ./xorbmp ./examples/data.bmp ./examples/key.bmp
```
