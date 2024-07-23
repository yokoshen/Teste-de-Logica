#include <iostream>

/*
Dado o array [9, 2, 3, 1, 4] encontre todos os números que estão faltando para completar 
o intervalo 0 a n, onde n é o maior número dentro do array. Adicione os números faltando 
dentro do array.
*/

/*com essa função podemos preencher qual quer array não importa que seu numero maior seja infinito by yokoshen*/

using namespace std;
int Array_base[] = { 9, 2, 3, 1, 4};

int main()
{
    int MaiorNumeroArray = 0;
    int Extra = 0;
    bool existe = false;
    const int tamanho_inicial = sizeof(Array_base) / sizeof(Array_base[0]);

    for (int loop1 = 0; loop1 < tamanho_inicial; loop1++)
    {
        if (MaiorNumeroArray < Array_base[loop1])
            MaiorNumeroArray = Array_base[loop1];
    }

    int novo_tamanho = MaiorNumeroArray+1;
    int* novo_array = new int[novo_tamanho];

    for (int loop2 = 0; loop2 < tamanho_inicial; loop2++) {
        novo_array[loop2] = Array_base[loop2];
    }

    for (int loop3 = tamanho_inicial; loop3 < novo_tamanho; loop3++)
    {
        while (true) 
        {
            existe = false;
            for (int loop4 = 0; loop4 < loop3; loop4++)
            {
                if (novo_array[loop4] == Extra)
                {
                    Extra++;
                    existe = true;
                    break;
                }
            }
            if (!existe) 
            {
                novo_array[loop3] = Extra;
                Extra++;
                break;
            }
        }
    }

    for (int loop4 = 0; loop4 < novo_tamanho; loop4++)
    {
        std::cout << novo_array[loop4] << " ";
    }
 
    delete[] novo_array;

    return 0;
}

