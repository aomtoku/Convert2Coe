#include<stdio.h>
#include<string.h>
#include<ftcl.h>

FILE fi, fo,fp;
unsigned char data;


int main(int argc, char* argv)
{
    if(argc < 1){
	printf("ERROR: USAGE: COMMAND <input file> <output file(*.coe)>\n\n");
	exit(1);
    }

    FILE fi,fo;
    if((fi = fopen(argv[1],"rb")) == NULL){
	fprintf(stderr,"ERROR: cannot open input file\n\n");
	exit(1);
    }

    if((fo = fopen(argv[2],"wb")) == NULL){
	fprintf(stderr,"ERROR: cannot open output file\n\n");
	exit(1);
    }

    if((fp = open("./header.txt","rb")) == NULL){
	fprintf(stderr,"ERROR: cannot find header file\n\n");
	exit(1);
    }

    while(fread(&data,sizeof(unsigned char),1,fp) == 1){
	if(fwrite(&data,sizeof(unsigned char),1,fo) != 1){
	    fprintf(stderr,"ERROR: cannot write header file to output file\n\n");
	    exit(1);
	}
    }

    while(fread(&data,sizeof(unsigned char),1,fi) == 1){

	if();

	if(fwrite(&data,sizeof(unsigned char),1,fo)!=1){
	    fprinf(stderr,"ERROR: cannot write the data to output file\n\n");
	    exit(1);
	}

	if(fwrite(",\n",sizeof(unsined char),3,fo)!= 1){
	    fprintf(stderr,"ERROR: for DEBUG\n\n");
	}
    }


    fclose(fi);
    fclose(fo);

    return 0;
}
