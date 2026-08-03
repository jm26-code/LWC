#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char* argv[]){
	puts("** LWC PROGRAM **");

	//Values to be found
	int characters = 0;
	int words = 0;
	int lines = 0;

	//Takes a command-line argument
	if(argc < 2){
		puts("No input file");
		return 1;
	}
	
	//File
	FILE* fp;

	if((fp = fopen(argv[1], "r")) != NULL){

		//Chars values
		int current = 0;
		char previous = 0;

		//End of the line
		char endLine = '\n';
		
		//Read file
		while ((current = fgetc(fp)) != EOF){

			//Line by line
			if(current == endLine)
				lines++;

			//Every word
			if(isspace(current)){
				if(!isspace(previous) && previous > 0)
					words++;
			}
			previous = current;

			//Character count
			characters++; 
		}

		//Word without a line break
		if(previous > 0 && !isspace(previous)){
			words++;
		}

		//Close file
		fclose(fp);
	}else{
		perror("File");
		return 1;
	}

	//Values found
	printf("%d\t%d\t%d\n", lines, words, characters);

	return 0;
}
