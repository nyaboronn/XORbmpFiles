/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Ficheros;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

/**
 *
 * @author nyaboron
 */
public class ProcesaCosas {
    
    public String leerFicheroTexto(String ruta) {
        
        String texto = "";
        
        File archivo;
        FileReader fr = null;
        BufferedReader br;
        
        try {
           archivo = new File (ruta);
           fr = new FileReader (archivo);
           br = new BufferedReader(fr);
           
           String linea;
           while((linea=br.readLine())!=null) {
               texto += linea;
           }
        } catch(IOException e) {
        } finally {
           try{                    
              if( null != fr ){   
                 fr.close();     
              }                  
           }catch (IOException e2){
           }
        }
        
        return texto;
    }
 
    public String limpiarTexto(String texto) {
        return texto.replaceAll("[^a-zA-Z0-9]", "").toUpperCase();
    }
    
}
