#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	puts("** LWC PROGRAM **");

	//conteo
	int caracteres = 0;
	int palabras = 0;
	int lineas = 0;

	//Toma un argumento de la LINEA DE COMANDOS
	if(argc < 2){
		puts("No input file");
		return 1;
	}
	
	//lee un archivo
	FILE* fp;

	if((fp = fopen(argv[1], "r")) != NULL){

		//lee caracter por caracter
		int actual = 0;
		char anterior = 0;

		//caracteres especiales
		char espacio = ' ';
		char tabulador = '\t';
		char fin = '\n';
	
		while ((actual = fgetc(fp)) != EOF){

			if(actual == fin)
				lineas++;

			if(actual > 0 && (actual == espacio || actual == tabulador || actual == fin)){
				if(anterior != espacio && anterior != tabulador && anterior != fin && anterior > 0)
					palabras++;
			}

			anterior = actual;
			caracteres++;
		}

		if(anterior > 0 && anterior != espacio && anterior != tabulador && anterior != fin){
			palabras++;
		}

		//Cerramos el archivo
		fclose(fp);
	}else{
		perror("Error de archivo");
		return 1;
	}

	//VISUALIZAR
	printf("%d\t%d\t%d\n", lineas, palabras, caracteres);

	return 0;
}
