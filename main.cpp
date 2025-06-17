#include <iostream>
#include "empresa.h"
#include "escola.h"

using namespace std;

void funEmpresa(){
Restaurante r;
    Prato P;
    string nomePrato;
    double precoPrato;

    int opcao = 1;
    while(opcao != 0){
        cout << "Bem vindo ao restaurante\n";
        cout << "Escolha uma opcao:\n";
        cout << "0 - Sair do programa\n";
        cout << "1 - Ver menu\n";
        cout << "2 - Criar prato\n";
        cout << "3 - Excluir prato\n";
        cin >> opcao;

        if(opcao == 1){
            r.imprimirPratos();
        }else if (opcao == 2){
            cout << "Digite o nome do prato: \n";
            cin >> nomePrato;
            cout << "Digite o preco do prato: \n";
            cin >> precoPrato;
            P.setNome(nomePrato);
            P.setPreco(precoPrato);
            r.push_back(P);
        }
    }

}

void funcEscola(){

    Data data;
    data.setDia(12);
    data.setMes(1);
    data.setAno(2005);
    cin >> data;
    cout << data;


}

int main()
{
    //funEmpresa();
    funcEscola();


    return 0;
}
