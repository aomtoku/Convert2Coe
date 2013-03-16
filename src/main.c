#include<stdio.h>
#include<string.h>
#include<stdlib.h>

FILE *fi, *fo,*fp,*ft;
unsigned char data;
unsigned char buf[256];

int main(int argc, char** argv)
{
    /* local valiable */
    int i,index;
    char *p,foo[]="\n";

    /* Initialize */
    index = 0;
    i = 0;
    
    /* Initialize with Error Check */
    if(argc < 1){
	printf("ERROR: USAGE: COMMAND <input file> <output file(*.coe)>\n\n");
	exit(1);
    }

    if((fi = fopen(argv[1],"rb")) == NULL){
	fprintf(stderr,"ERROR: cannot open input file\n\n");
	exit(1);
    }

    if((fp = fopen("/Users/toku1938/Work/Convert2Coe/src/header.txt","rb")) == NULL){
	fprintf(stderr,"ERROR: cannot find header file\n\n");
	exit(1);
    }

    if((ft = fopen("test.coe","wb")) == NULL){
	fprintf(stderr,"ERROR: cannot open input file\n\n");
	exit(1);
    }

    /* header file reading */
    while(i= fread(buf,sizeof(unsigned char),1,fi) != 0){
	p = buf;
	do{
	    printf("%02x", *p & 0xff);
	    if(memcmp(p,foo,1)==0) index++;
	    *p++;
	} while(--i);
	if(index==3)break;
    }
    
    /* corefile header */
    while(fread(&data,sizeof(unsigned char),1,fp) == 1){

	if(fwrite(&data,sizeof(unsigned char),1,ft) != 1){
	    fprintf(stderr,"ERROR: cannot write header file to output file\n\n");
	    exit(1);
	}
    }

    fclose(fp);
    
    /* Make a file */
    while(fread(&data,sizeof(unsigned char),1,fi) == 1){
	 char a[4];
	 sprintf(a,"%02x",data);
	if(fwrite(&a,sizeof(char)*2,1,ft)!=1){
	    fprintf(stderr,"ERROR: cannot write the data to output file\n\n");
	    exit(1);
	}
	fputs(",\n",ft);
    }

    fseek(ft,-6L,SEEK_END);
    fputs(";\n",ft);
    int loc = ftell(ft);

    fclose(ft);

    if((ft = fopen("test.coe","rb")) == NULL){
	fprintf(stderr,"ERROR: cannot open output file\n\n");
	exit(1);
    }

    if((fo = fopen(argv[2],"wb")) == NULL){
	fprintf(stderr,"ERROR: cannot open output file\n\n");
	exit(1);
    }

    while(fread(&data,sizeof(unsigned char),1,ft) == 1){
	int loc_t;
	 
	if(fwrite(&data,sizeof(unsigned char),1,fo)!=1){
	    fprintf(stderr,"ERROR: cannot write the data to output file\n\n");
	    exit(1);
	}
	if((loc_t=ftell(fo)) == loc) break;
    }


    fclose(fi);
    fclose(ft);
    remove("test.coe");
    fclose(fo);
    return 0;
}
