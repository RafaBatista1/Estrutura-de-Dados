#include <iostream>
#include <vector>

using namespace std;

class Lista {
private:
    vector<int> dados; // criacao da lista sequencial
public:
    Lista() { // Esvazia a lista 
        dados.clear();
    }

    bool VerificaVazia() { // Verifica se a lista está vazia
        return dados.empty(); // empty em c++ retorna positivo caso o vetor esteja vazio
    }

    bool VerificaCheia() { // Verificar se a lista está cheia
        return false; // Como estamos usando um vetor que cresce na medida que os dados sao inseridos, ele nunca estará cheio
        
        /*caso seja definido em uma variavel global um tamanho limite para o vetor a implementacao seria essa

        if(tamAtual == tamMax){
            return true;
        }
        else{   
            return false;
        }

    */

    }

    int VerificaTamanho() { // Retorna o tamanho da lista
        return dados.size(); // size em c++ retorna a quantidade de elementos atual do vetor
    }

    int Elemento(int pos) { // Retorna o valor de um elemento de uma determinada posicao na lista
        if(pos > dados.size()){
            return false;
        }
        else
            return dados[pos];
    }

    void Insere(int x, int pos) { // Insere um elemento em uma determinada posicao apos dado o valor a ser inserido e a posicao a ser alterada
        dados.insert(dados.begin() + pos, x);
    }

    void Apaga(int pos) { // Retirar um elemento de uma determinada posição
        dados.erase(dados.begin() + pos);
    }
};

int main() {
    Lista ListaSeq;
    int elementos, valor, posicao, opcao;

    cout << "Tamanho atual da lista: " << ListaSeq.VerificaTamanho() << endl;
    cout << "A lista esta vazia? " << (ListaSeq.VerificaVazia() ? "Sim" : "Nao") << endl << endl;

    cout << "Insira quantos elementos voce quer adicionar na sua lista" << endl;

    cin >> elementos;

    for(int i = 0; i < elementos; i++){
        cout << "Insira o valor, e em seguida sua posicao na lista" << endl;

        cin >> valor;
        cin >> posicao;

        ListaSeq.Insere(valor, posicao);
    }

    cout << "Tamanho atual da lista: " << ListaSeq.VerificaTamanho() << endl;
    cout << "A lista esta vazia? " << (ListaSeq.VerificaVazia() ? "Sim" : "Nao") << endl << endl;

    while(1){
        cout << "Caso queria verificar o valor de um elemento dado sua posicao digite 1\nCaso queira apagar um elemento digite 2\nCaso queria encerrar o programa digite 3" << endl;

        cin >> opcao;

        if(opcao == 1){
            cout << "Digite a posicao do elemento: " << endl;
            cin >> posicao;

            cout << "O elemento na posicao " << posicao <<  " e: " << ListaSeq.Elemento(posicao) << endl << endl;
        }
        else if(opcao == 2){
            cout << "Digite a posicao do elemento: ";
            cin >> posicao;
            ListaSeq.Apaga(posicao);

            cout << "Tamanho da lista: " << ListaSeq.VerificaTamanho() << endl;
        }
        
        else if(opcao == 3){
            break;
        }
        
        else{
            cout << "Opcao invalida, digite uma opcao valida!" << endl;
        }
    }

    cout << "Tamanho da lista: " << ListaSeq.VerificaTamanho() << endl;

    return 0;
}