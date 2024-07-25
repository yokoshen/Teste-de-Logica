#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>

/*
Dada a seguinte arvore binária de palavras, faça uma função que busque nessa 
arvore pela palavra-chave. O output da sua função deve ser o caminho até chegar no item procurado. 
Por exemplo, se o input de buscar for “goiaba” o output deve ser uma string “Maça -> morango -> Goiaba”.
*/

using namespace std;

class ArvoreDados {
public:
    string valor;
    ArvoreDados* esquerda;
    ArvoreDados* direita;

    ArvoreDados(string val) : valor(val), esquerda(nullptr), direita(nullptr) {}
};

string encontrar_caminho_para_palavra(ArvoreDados* root, const string& palavra_busca, vector<string> caminho_atual = {}) {
    if (root == nullptr) {
        return "";
    }

    caminho_atual.push_back(root->valor);

    if (root->valor == palavra_busca) {
        string caminho_resultante;
        for (const auto& passo : caminho_atual) {
            caminho_resultante += passo + " -> ";
        }
        caminho_resultante = caminho_resultante.substr(0, caminho_resultante.size() - 4); // Remover o último " -> "
        return caminho_resultante;
    }

    string caminho_esquerda = encontrar_caminho_para_palavra(root->esquerda, palavra_busca, caminho_atual);
    string caminho_direita = encontrar_caminho_para_palavra(root->direita, palavra_busca, caminho_atual);

    return !caminho_esquerda.empty() ? caminho_esquerda : caminho_direita;
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8);
    wcout.imbue(locale(""));

    ArvoreDados* raiz = new ArvoreDados("Maça");
    raiz->esquerda = new ArvoreDados("Morango");
    raiz->direita = new ArvoreDados("Pera");
    raiz->esquerda->esquerda = new ArvoreDados("Goiaba");
    raiz->esquerda->direita = new ArvoreDados("Limão");
    raiz->direita->direita = new ArvoreDados("Abacaxi");
    raiz->direita->direita->direita = new ArvoreDados("Laranja");
    raiz->direita->direita->direita->direita = new ArvoreDados("Cebola");
    raiz->direita->direita->direita->esquerda = new ArvoreDados("Banana");

    string palavra_busca;
    cout << "Digite a palavra que deseja buscar na árvore: ";
    cin >> palavra_busca;

    string caminho_resultante = encontrar_caminho_para_palavra(raiz, palavra_busca);

    if (!caminho_resultante.empty()) {
        cout << "Caminho para '" << palavra_busca << "': " << caminho_resultante << endl;
    }
    else {
        cout << "A palavra '" << palavra_busca << "' não foi encontrada na árvore." <<endl;
    }

    delete raiz->direita->direita->direita->direita;
    delete raiz->direita->direita->direita->esquerda;
    delete raiz->direita->direita->direita;
    delete raiz->direita->direita;
    delete raiz->direita;
    delete raiz->esquerda->direita;
    delete raiz->esquerda->esquerda;
    delete raiz->esquerda;
    delete raiz;

    return 0;
}