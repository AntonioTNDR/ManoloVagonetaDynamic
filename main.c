#include <stdio.h>






int dynamical(int rows,int columns,int matrix[rows][columns], int elements[],int selected[]){ //El array selected para guardar los pesos de los elementos seleccionados
    int totalWeight = 0; //Para ir sumando los pesos cuando seleccionemos los items
//We initialize the first row
    for (int j=0;j<columns;j++){
        matrix[0][j]=0;
    }
//Crear tabla
    for (int i=1;i<=rows;i++){
        for (int j=0;j<columns;j++){
            if(elements[i-1]>j){matrix[i][j]=matrix[i-1][j];continue;}
            matrix[i][j]= (matrix[i - 1][j] > matrix[i][j-elements[i-1]]+elements[i-1]) ? (matrix[i - 1][j]) : (matrix[i - 1][j-elements[i-1]]+ elements[i-1]);
        }
    }
    //Aqui todo el proceso de seleccionar



    return totalWeight*6; //precio en euros
}












int main() {
    int list[20];
    int selected[100];
    int value;
    int i=0;
    while(1){
        scanf("%d",&value);
        if(value==-1) break;
        list[i]=value;
        i++;

    }
    int matrix[i][15];
    int rows=i+1;
    int columns=15;
    int price=dynamical(rows,columns,matrix,list,selected);
    for (int j=0;j<rows;j++){
        for (int k=0;k<columns;k++){
            printf("%d ",matrix[j][k]);
        }
        printf("\n");
    }
    printf("%d",price);
}
