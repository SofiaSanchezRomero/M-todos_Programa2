#include <stdio.h>

int const Tam=101;

void PideDatos(int *Dim, float Mat[][Tam]);
void EscribeDatos(int Dim, float Mat[][Tam]);
void Cambio (int *Dim, float Mat[][Tam]); 
void CalcDet(int Dim, float Mat[][Tam]);
void SolSistema(int Dim, float Mat[][Tam]);


int main(void)
{
 int C,Dimension;
 float Matriz[Tam][Tam];
 PideDatos(&Dimension,Matriz);
 Cambio(&Dimension,Matriz);
 printf("\n\n\n MATRIZ FINAL: \n\n");
 EscribeDatos(Dimension,Matriz);
 printf("\n\n\n DETERMINANTE: \n\n");
 CalcDet(Dimension,Matriz);
 scanf("%d");
 return(0);
}


void PideDatos(int *Dim,float Mat[][Tam])
{
 int i,j,o;
 printf("\n\n |Metodo de Gauss|");
 printf("\n\n\n Introduce el tamaño de la matriz:");
 scanf("%d",&*Dim);
 printf("\n\n Introduce los valores de la matriz:");
 	for(i=1;i<=*Dim;i++) 
 		for(j=1;j<=*Dim;j++){
  printf("\n(%d,%d):",i,j); 
  scanf("%f",&Mat[i][j]);
  }
}
void Cambio(int *Dim, float Mat[][Tam]){
	int fila, columna,nuevo,o,i,j; 
	do{
	printf("\n Desea cambiar algun dato 1)Si 2)No \n");
    scanf ("%i", &o); 
        switch (o){
        	case 1: 
        	printf ("\nIngrese el valor de las coordenadas que quiere cambiar:\n");
        	printf ("Fila: \n"); 
        	scanf ("%d",&fila);
        	printf ("Columna: \n"); 
        	scanf ("%d",&columna);
        	printf ("\n Ingrese nuevo valor: \n"); 
        	scanf ("%d",&nuevo);
        	 Mat[fila][columna] = nuevo; 
      	
 		  }break; 	
    }while (o!=1);
}
void EscribeDatos(int Dim, float Mat[][Tam])
{
 int fila,columna;
    for(fila=1;fila<=Dim;fila++){
 		for(columna=1;columna<=Dim;columna++)
        printf(" %7.2f",Mat[fila][columna]);
        printf("\n");
    }
}

void CalcDet(int Dim, float Mat[][Tam])
{
 int difDC,Col,A1,A2,i,DifReg,Perm=0;
 float Pivote,Vec,Det=1;

 for(Col=1;Col<=Dim;Col++){
  difDC=0;i=Col;
  while((difDC==0)&&(i<=Dim))
  {
   if((Mat[i][Col]>0.0000001)||((Mat[i][Col]<-0.0000001)))
   {
    	difDC=1;}
   	else i++;}
  		if (i>Dim) DifReg=1;
  		if (i!=Col) Perm++;
  		Pivote=Mat[i][Col];
  for(A1=1;A1<=(Dim);A1++)
  {
   Vec=Mat[i][A1];
   Mat[i][A1]=Mat[Col][A1];
   Mat[Col][A1]=Vec;}
  	for(A2=Col+1;A2<=Dim;A2++)
	{
  		 Vec=Mat[A2][Col];
   		for(A1=Col;A1<=(Dim);A1++)
		{
    		Mat[A2][A1]=Mat[A2][A1]-((Vec/Pivote)*Mat[Col][A1]);
		}
	}
 }
    for(A2=1;A2<=Dim;A2++) Det=Det*Mat[A2][A2];
 i=Perm;
 	if ((i%2)==1) Det=-Det;
 	if (DifReg==1) Det=0;
    	printf("El determinante de la matriz es:   %f", Det);
    if (Det!= 0){
    	printf("\n----------------Solucion del sistema-------------\n");
    	
	}
}

	
	
	
	
