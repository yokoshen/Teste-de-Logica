#include <iostream>

/*
Dado o array de números inteiros [1, 15, 2, 7, 2, 5, 7, 1, 4] crie uma função que recebe um argumento X e 
retorne true ou false caso haja no array uma combinação de soma entre dois números que resulte no input X. 
Exemplo: Se X=2, a função deve retornar true pois existem dois números 1 dentro do array 1+1 = 2. Caso X=1231 a 
função deve retornar false pois não existe uma combina de dois números capazes de somar 1231.

*/
#define ARRAY_MAX 9

using namespace std;

int Array_base[ARRAY_MAX] = {1, 15, 2, 7, 2, 5, 7, 1, 4};

bool Busca(int valor)
{
    for (int loop1 = 0; loop1 < ARRAY_MAX; loop1++)
    {
        for (int loop2 = 0; loop2 < ARRAY_MAX; loop2++)
        {
            for (int loop3 = 0; loop3 < ARRAY_MAX; loop3++)
            {
                if (loop3 == loop2)
                    continue;

                if (Array_base[loop3] + Array_base[loop2] == valor)
                    return true;
            }
        }
    }

    return false;
}

int main()
{
    int valor = 0;

    cout << "informe um valor em decimal:";
    cin >> valor;

    if (Busca(valor) == true)
        cout << "\nSucesso valor de soma encontrada na array [" << valor <<"]\n";
    else
        cout << "\nErro valor de soma nao encontrada na array [" << valor << "]\n";

    system("pause");
    return 0;
}