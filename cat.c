#include<stdio.h>

//Function cat, which concatenates the file chars to stdout
void cat(FILE * fp1,FILE *fp2){
int c;
while((c=getc(fp1))!=EOF){
putc(c,fp2);
}
}

//driver code
int main(int argc,char *argv[]){
FILE *fp;
char *p=argv[0];
if(argc==1){			//no agruments
cat(stdin,stdout);
}
else{
while(--argc>0){
if((fp=fopen(*++argv,"r"))==NULL){
fprintf(stderr,"%s: Can't open file %s\n",p,*argv);		// first %s points to program file and later one points to argv[1],i.e input file
}
else{
cat(fp,stdout);
fclose(fp);
}
}
}
return 0;
}
