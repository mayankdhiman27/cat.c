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
if(argc==1){
cat(stdin,stdout);
}
else{
while(--argc>0){
if((fp=fopen(*++argv,"r"))==NULL){
printf("Can't open file");
}
else{
cat(fp,stdout);
fclose(fp);
}
}
}
return 0;
}
