#include <iostream>
using namespace std;
 
int main() {
    char caractere;
    FILE *file;
    int n=0;

    file = fopen("labirinto.txt","r");
    caractere = fgetc(file);
    
    //Conta o número de caracteres em uma linha
    while (caractere != '\n'){
        n++;
        caractere = fgetc(file);
    }
    
    int L[n][n], i=0, j=0;
    
    //Reinicia a leitura do arquivo
    fclose(file);
    file = fopen("labirinto.txt","r");
    caractere = fgetc(file);

    // Algoritmo que inicia o vetor L com o labirinto, já com a substituição feita e imprime o labirinto presente no arquivo .txt
    while (caractere != EOF){
        if(caractere == '#'){
            cout << caractere << ' ';
            L[i][j] = -1;
            i++;
        }
        if(caractere == '.'){
            cout << caractere << ' ';
            L[i][j] = 0;
            i++;
        }
        if(caractere == '\n'){
            cout << endl;
            j++;
            i=0;
        }
        caractere = fgetc(file);
    }
    
    //Imprime o labirinto
    cout << endl << endl << endl;
    for(j=0;j<n;j++){
        for(i=0;i<n;i++){
            if(L[i][j]== -1){
                cout << L[i][j] << ' ';
            }
            else{
               cout << ' ' << L[i][j] << ' '; 
            }
        }
        cout << endl;
    }
    
    fclose(file);
    return 0;
}