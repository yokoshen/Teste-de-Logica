#include <iostream>
#include <Windows.h>

/*
Dada a seguinte arvore binária de palavras, faça uma função que busque nessa 
arvore pela palavra-chave. O output da sua função deve ser o caminho até chegar no item procurado. 
Por exemplo, se o input de buscar for “goiaba” o output deve ser uma string “Maça -> morango -> Goiaba”.
*/

using namespace std;

struct Struct_Goiaba
{
    string info1 = "Maça";
    string info2 = "morango";
    string info3 = "Goiaba";
};

struct Struct_Laranja
{
    string info1 = "Limão";
    string info2 = "Pessego";
    string info3 = "Laranja";
};

struct Frutas
{
    Struct_Goiaba Goiaba;
    Struct_Laranja Laranja;
};

bool Check(string imput)
{
    if (imput == "goiaba")
    {
        Frutas FrutasInfo;

        cout << "\n" << FrutasInfo.Goiaba.info1 << " -> " << FrutasInfo.Goiaba.info2 << " -> " << FrutasInfo.Goiaba.info3;
        return true;
    }

    if (imput == "laranja")
    {
        Frutas FrutasInfo;

        cout << "\n" << FrutasInfo.Laranja.info1 << " -> " << FrutasInfo.Laranja.info2 << " -> " << FrutasInfo.Laranja.info3;
        return true;
    }

    return false;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    wcout.imbue(locale(""));

    inicio:
    string Text;
    cout << "informe o nome da fruta para continuarmos a busca:";
    cin >> Text;

    if (Check(Text) == false)
    {
        system("cls");
        cout << "\n" << "Não foi encontrado informação sobre:[" << Text << "] em nossa base de dados\n";
        goto inicio;
    }

    return 0;
}