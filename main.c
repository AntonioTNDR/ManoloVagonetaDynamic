#include <stdio.h>






int dynamical(int rows,int columns,int matrix[rows][columns], int elements[],int selected[],int * nElements){ //El array selected para guardar los pesos de los elementos seleccionados
    int totalWeight = 0; //Para ir sumando los pesos cuando seleccionemos los items
//We initialize the first row
    for (int j=0;j<columns;j++){
        matrix[0][j]=0;
    }
//Crear tabla
    for (int i=1;i<=rows;i++) {
        for (int j = 0; j < columns; j++) {
            if (elements[i - 1] > j) { matrix[i][j] = matrix[i - 1][j]; }
            else {
                if (matrix[i-1][j]>(matrix[i-1][j-elements[i-1]]+elements[i-1])) matrix[i][j]=matrix[i-1][j];
                else{matrix[i][j]=matrix[i-1][j-elements[i-1]]+elements[i-1];}
            }
        }
    }
    //Aqui todo el proceso de seleccionar

    int n=0;
    int j=columns-1;
    *nElements=0;
   for(int i=rows;i>0;i--){
      if(matrix[i][j]!=matrix[i-1][j]){
        selected[n]=elements[i-1];
        *nElements=*nElements+1;
        totalWeight+=elements[i-1];
        j=j-elements[i-1];
        n++;
      }
   }


    return totalWeight*6; //precio en euros
}












int main() {
    int list[20];
    int selected[100];
    int value;
    int i=0;
    int  nElements=0;
    while(1){
        scanf("%d",&value);
        if(value==-1) break;
        list[i]=value;
        i++;

    }
    int matrix[i+1][15];
    int rows=i+1;
    int columns=15;
    int price=dynamical(rows,columns,matrix,list,selected,&nElements);
    for (int j=0;j<rows;j++){
        for (int k=0;k<columns;k++){
            printf("%d\t",matrix[j][k]);
        }
    }
    printf("Selected elements:\n");
    for (int x=0;x<nElements;x++){
        if(x==nElements-1){printf("%d",selected[x]);}
        else printf("%d,",selected[x]);

    }

    printf("\n%d",price);
}
