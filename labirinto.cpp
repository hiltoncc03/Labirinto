#include <bits/stdc++.h>
using namespace std;

int main() {
    char caractere;
    FILE *file;
    int n=0;
    queue<pair<int,int>> coord;
    stack<pair<int,int>> menorCaminho;

    file = fopen("labirinto.txt","r");
    caractere = fgetc(file);
    //teste
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
    cout << "PRIMEIRA ETAPA" << endl;
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
    //SEGUNDA ETAPA
    coord.push({1,1});
    i=2;
    L[1][1]=1;
    while(!coord.empty()){//Loop que funciona enquanto a fila não estiver vazia; A fila armazena os valores das coordenadas, 1 por vez
        if(L[coord.front().first-1][coord.front().second]==0){//Analizando se a coordenada acima da atual é = 0
            coord.push({coord.front().first-1, coord.front().second});
            L[coord.front().first-1][coord.front().second] = L[coord.front().first][coord.front().second]+1;
        }
        if(L[coord.front().first+1][coord.front().second]==0){//Analizando se a coordenada abaixo da atual é = 0
            coord.push({coord.front().first+1, coord.front().second});
            L[coord.front().first+1][coord.front().second] = L[coord.front().first][coord.front().second]+1;
        }
        if(L[coord.front().first][coord.front().second-1]==0){//Analizando se a coordenada à esquerda da atual é = 0
            coord.push({coord.front().first, coord.front().second-1});
            L[coord.front().first][coord.front().second-1] = L[coord.front().first][coord.front().second]+1;
        }
        if(L[coord.front().first][coord.front().second+1]==0){//Analizando se a coordenada à direita da atual é = 0
            coord.push({coord.front().first, coord.front().second+1});
            L[coord.front().first][coord.front().second+1] = L[coord.front().first][coord.front().second]+1;
        }
        coord.pop();
        i++;
    }

    //Imprime o labirinto
    cout << endl << endl << endl << "SEGUNDA ETAPA" << endl;
    for(j=0;j<n;j++){
        for(i=0;i<n;i++){
            printf("%3d",L[i][j] );
        }
        cout << endl;
    }

    //TERCEIRA ETAPA
    menorCaminho.push({n-2,n-2});//Atribuí à pilha as cordenadas da posição final do labirinto
    while(L[menorCaminho.top().first][menorCaminho.top().second]!= 1){
        if(L[menorCaminho.top().first-1][menorCaminho.top().second]==L[menorCaminho.top().first][menorCaminho.top().second]-1){
            menorCaminho.push({menorCaminho.top().first-1,menorCaminho.top().second});//Analizando se a coordenada acima da atual é igual à ela mesma subtraída de 1
        }
        if(L[menorCaminho.top().first+1][menorCaminho.top().second]==L[menorCaminho.top().first][menorCaminho.top().second]-1){
            menorCaminho.push({menorCaminho.top().first+1,menorCaminho.top().second});//Analizando se a coordenada abaixo da atual é igual à ela mesma subtraída de 1
        }
        if(L[menorCaminho.top().first][menorCaminho.top().second-1]==L[menorCaminho.top().first][menorCaminho.top().second]-1){
            menorCaminho.push({menorCaminho.top().first,menorCaminho.top().second-1});//Analizando se a coordenada à esquerda da atual é igual à ela mesma subtraída de 1
        }
        if(L[menorCaminho.top().first][menorCaminho.top().second+1]==L[menorCaminho.top().first][menorCaminho.top().second]-1){
            menorCaminho.push({menorCaminho.top().first,menorCaminho.top().second+1});//Analizando se a coordenada à direita da atual é igual à ela mesma subtraída de 1
        }
    }

    //Imprime o labirinto, substituindo os valores antigos pelos caracteres solicitados na ETAPA 3
    cout << endl << endl << "TERCEIRA ETAPA" << endl;
    for(j=0;j<n;j++){
        for(i=0;i<n;i++){
            if(!menorCaminho.empty() && i==menorCaminho.top().first && j==menorCaminho.top().second){
                cout << "  x";
                menorCaminho.pop();
            }
            else if(L[i][j]== -1){
                cout << "  #";
            }
            else{
                cout << "   ";
            } 
        }
        cout << endl;
    }
    
    fclose(file);
    return 0;
}