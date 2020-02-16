#include <iostream>
#include <fstream>
#include "Imovel.hpp"
#include "Apartamento.hpp"
#include "Casa.hpp"
#include "Terreno.hpp"
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

void salvar_arquivo(vector<Imovel*> imoveis)
{
    ofstream file;
    file.open("dados.txt");
    Endereco end;

    Apartamento* apto = new Apartamento();
    Casa* cs = new Casa();
    Terreno*ter = new Terreno();

    if (!file.is_open()) {
        cout << "Nao foi possivel abrir o arquivo para escrita" << endl;
        return ;
    }
    for (int i = 0; i < imoveis.size(); i++)
    {
        if(imoveis[i]->getTipoImovel() == 1)
        {

            file << 1 << endl;
            file << imoveis[i]->getValor() << endl;
            end = imoveis[i]->getEndereco();
            file << end.getLogradouro() <<endl;
            file << end.getBairro() << endl;
            file << end.getCidade() << endl;
            file << end.getNumero() << endl;
            file << end.getCep() << endl;
            file << imoveis[i]->getOferta() << endl;
            file << imoveis[i]->getDescricao() << endl;
            file << imoveis[i]->getAnuncio() << endl;
            apto = (Apartamento*)imoveis[i];
            file << apto->getposicao() << endl;
            file << apto->getnumQuartos() << endl;
            file << apto->getvagasGaragem() << endl;
            file << apto->getvalorCondomino() << endl;
            file << apto->getarea() << endl;
            file << apto->getAndar() << endl;

        }
        else if(imoveis[i]->getTipoImovel() == 2)
        {
            file << 2 << endl;
            file << imoveis[i]->getValor() << endl;
            end = imoveis[i]->getEndereco();
            file << end.getLogradouro() <<endl;
            file << end.getBairro() << endl;
            file << end.getCidade() << endl;
            file << end.getNumero() << endl;
            file << end.getCep() << endl;
            file << imoveis[i]->getOferta() << endl;
            file << imoveis[i]->getDescricao() << endl;
            file << imoveis[i]->getAnuncio() << endl;
            cs = (Casa*)imoveis[i];
            file << cs->getnumQuartos() << endl;
            file << cs->getareaConstruida() <<endl;
            file << cs->getareaTerreno() <<endl;
            file << cs->getnumPavimentos() << endl;
        }
        else
        {
            file << 3 << endl;
            file << imoveis[i]->getValor() << endl;
            end = imoveis[i]->getEndereco();
            file << end.getLogradouro() <<endl;
            file << end.getBairro() << endl;
            file << end.getCidade() << endl;
            file << end.getNumero() << endl;
            file << end.getCep() << endl;
            file << imoveis[i]->getOferta() << endl;
            file << imoveis[i]->getDescricao() << endl;
            file << imoveis[i]->getAnuncio() << endl;
            ter = (Terreno*)imoveis[i];
            file << ter->getArea() << endl;
        }
        
    }
    
}

vector<Imovel*> ler_arquivo(int* indice) {
    vector<Imovel*> imoveis;
    ifstream file;
    string str;
    Endereco end;
    int inteiro, i=0;
    double pontoflutuante;
    bool of;

    
 
    file.open("dados.txt");

    if (!file.is_open())
    {
        cout << "Nao foi possivel abrir o arquivo para leitura" << endl;
        return imoveis;
    }
    while (true)
    {
        Apartamento* ap = new Apartamento();
        Casa* cs = new Casa();
        Terreno* ter = new Terreno();

        file >> inteiro;
        if (file.eof() || file.bad() || file.fail())
            break;
        switch (inteiro)
        {
        case 1:
            file >> pontoflutuante;
            file.ignore();
            ap->setValor(pontoflutuante);
            getline(file, str);
            end.setLogradouro(str);
            getline(file, str);
            end.setBairro(str);
            getline(file, str);
            end.setCidade(str);
            file >> inteiro;
            file.ignore();
            end.setNumero(inteiro);
            getline(file, str);
            end.setCep(str);
            ap->setEndereco(end);
            file >> of;
            file.ignore();
            ap->setOferta(of);
            getline(file, str);
            ap->setDescricao(str);
            getline(file, str);
            ap->setAnuncio(str);
            getline(file, str);
            imoveis.insert(imoveis.begin() + i, ap);
            ap = (Apartamento*)imoveis[i];
            ap->setposicao(str);
            file >> inteiro;
            ap->setnumQuartos(inteiro);
            file >> inteiro;
            ap->setvagasGaragem(inteiro);
            file >> pontoflutuante;
            ap->setvalorCondomino(pontoflutuante);
            file >> pontoflutuante;
            ap->setarea(pontoflutuante);
            file >> inteiro;
            ap->setAndar(inteiro);
            i++;
            break;

        case 2:
            file >> pontoflutuante;
            file.ignore();
            cs->setValor(pontoflutuante);
            getline(file, str);
            end.setLogradouro(str);
            getline(file, str);
            end.setBairro(str);
            getline(file, str);
            end.setCidade(str);
            file >> inteiro;
            file.ignore();
            end.setNumero(inteiro);
            getline(file, str);
            end.setCep(str);
            cs->setEndereco(end);
            file >> of;
            file.ignore();
            cs->setOferta(of);
            getline(file, str);
            cs->setDescricao(str);
            getline(file, str);
            cs->setAnuncio(str);
            file >> inteiro;
            imoveis.insert(imoveis.begin() + i, cs);
            cs = (Casa*)imoveis[i];
            cs->setnumQuartos(inteiro);
            file >> pontoflutuante;
            cs->setareaConstruida(pontoflutuante);
            file >> pontoflutuante; 
            cs->setareaTerreno(pontoflutuante);
            file >> inteiro;
            cs->setnumPavimentos(inteiro);
            i++;
            break;

        case 3:
            file >> pontoflutuante;
            file.ignore();
            ter->setValor(pontoflutuante);
            getline(file, str);
            end.setLogradouro(str);
            getline(file, str);
            end.setBairro(str);
            getline(file, str);
            end.setCidade(str);
            file >> inteiro;
            file.ignore();
            end.setNumero(inteiro);
            getline(file, str);
            end.setCep(str);
            ter->setEndereco(end);
            file >> of;
            file.ignore();
            ter->setOferta(of);
            getline(file, str);
            ter->setDescricao(str);
            getline(file, str);
            ter->setAnuncio(str);
            file >> inteiro;
            imoveis.insert(imoveis.begin() + i, ter);
            ter = (Terreno*)imoveis[i];
            file >> pontoflutuante;
            ter->setArea(pontoflutuante);
            i++;
            break;
        
        default:
            break;
        }
    }
    file.close();
    *indice = i;
    return imoveis;
}

void limpa_buffer()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
    
}

void limpa_tela()
{
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else defined(__linux__) || defined(__unix__)
        system("clear");
    #endif
}

void menu_principal()
{
    cout <<"==================================================================================================="<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    1 - CONSULTAR IMOVEIS                                          "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    2 - CADASTRAR IMOVEL                                           "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    3 - REMOVER IMOVEL                                             "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    4 - EDITAR IMOVEL                                              "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    5 - SAIR DO PROGRAMA                                           "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"==================================================================================================="<< endl;
    cout <<"--------------------------------------ESCOLHA UMA OPCAO--------------------------------------------"<< endl;
}

void submenu()
{
    cout <<"==================================================================================================="<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    1 - APARTAMENTO                                                "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    2 - CASA                                                       "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    3 - TERRENO                                                    "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    4 - VOLTAR AO MENU PRINCIPAL                                   "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"==================================================================================================="<< endl;
    cout <<"--------------------------------------ESCOLHA UMA OPCAO--------------------------------------------"<< endl;
}

void submenu_1_2()
{
    cout <<"==================================================================================================="<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    1 - TODOS                                                      "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    2 - POR CATEGORIA                                              "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    3 - VOLTAR AO MENU PRINCIPAL                                   "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"==================================================================================================="<< endl;
    cout <<"--------------------------------------ESCOLHA UMA OPCAO--------------------------------------------"<< endl;
}

void submenu_1()
{
    cout <<"==================================================================================================="<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    1 - POR TIPO DE CONTRATO                                       "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    2 - POR BAIRRO                                                 "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    3 - POR TITULO                                                 "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    4 - POR VALOR                                                  "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    5 - POR CIDADE                                                 "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    6 - VOLTAR AO MENU PRINCIPAL                                   "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"==================================================================================================="<< endl;
    cout <<"--------------------------------------ESCOLHA UMA OPCAO--------------------------------------------"<< endl;
}

void submenu_1_1()
{
    cout <<"==================================================================================================="<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    1 - VENDA                                                      "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    2 - ALUGUEL                                                    "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    3 - VOLTAR AO MENU PRINCIPAL                                   "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"==================================================================================================="<< endl;
    cout <<"--------------------------------------ESCOLHA UMA OPCAO--------------------------------------------"<< endl;
}

void pressione()
{
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"Pressione enter para sair dessa tela..."<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    limpa_buffer();
    getchar();
    system("clear");
}

int main();

void consultar_imovel(vector<Imovel*> imoveis, int indice)
{
    int tipo;
    int opcao;
    bool contrato;
    double valor;
    string str, str2;
    Endereco end;
    submenu_1_2();
    cin >> opcao;
    limpa_tela();
    switch (opcao)
    {
    case 1:
        cout <<"==================================================================================================="<< endl;
        cout <<"                                             APARTAMENTOS                                          "<< endl;
        cout <<"==================================================================================================="<< endl;
        for (int i = 0; i < indice; i++)
        {
            if(imoveis[i]->getTipoImovel() == 1)
            {
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                cout <<"                                       Posição:"<< i << endl;
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;

                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                imoveis[i]->caracteristicas();
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
            }
        }
        cout <<"==================================================================================================="<< endl;
        cout <<"                                                CASAS                                              "<< endl;
        cout <<"==================================================================================================="<< endl;
        for (int i = 0; i < indice; i++)
        {
            if(imoveis[i]->getTipoImovel() == 2)
            {
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                cout <<"                                       Posição:"<< i << endl;
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                imoveis[i]->caracteristicas();
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
            }
        }
        cout <<"==================================================================================================="<< endl;
        cout <<"                                               TERRENOS                                            "<< endl;
        cout <<"==================================================================================================="<< endl;
        for (int i = 0; i < indice; i++)
        {
            if(imoveis[i]->getTipoImovel() == 3)
            {
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                cout <<"                                       Posição:"<< i << endl;
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                imoveis[i]->caracteristicas();
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
            }
        }
        pressione();
        break;

    case 2:
        submenu_1();
        cin >> opcao;
        limpa_tela();
        switch (opcao)
        {
        case 2:
            cout << "Qual o bairro que deseja pesquisar?" << endl;
            cin >> str;
            transform(str.begin(),str.end(), str.begin(), ::tolower);
            limpa_tela();
            if (opcao == 1)
            {
                contrato = true;
            }
            else
            {
                contrato = false;
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                             APARTAMENTOS                                          "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                end = imoveis[i]->getEndereco();
                str2 = end.getBairro();
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if(imoveis[i]->getTipoImovel() == 1 && str2.find(str) != string::npos)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                                CASAS                                              "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                end = imoveis[i]->getEndereco();
                str2 = end.getBairro();
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if(imoveis[i]->getTipoImovel() == 2 && str2.find(str) != string::npos)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                               TERRENOS                                            "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                end = imoveis[i]->getEndereco();
                str2 = end.getBairro();
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if(imoveis[i]->getTipoImovel() == 3 && str2.find(str) != string::npos)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            pressione();
            break;
        case 1:
            cout << "Qual o tipo de contrato? (1 - Venda) (2 - Aluguel)" << endl;
            cin >> opcao;
            limpa_tela();
            if (opcao == 1)
            {
                contrato = true;
            }
            else
            {
                contrato = false;
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                             APARTAMENTOS                                          "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                if(imoveis[i]->getTipoImovel() == 1 && imoveis[i]->getOferta() == contrato)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                                CASAS                                              "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                if(imoveis[i]->getTipoImovel() == 2 && imoveis[i]->getOferta() == contrato)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                               TERRENOS                                            "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                if(imoveis[i]->getTipoImovel() == 3 && imoveis[i]->getOferta() == contrato)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            pressione();
            break;
        case 3:
            cout << "Qual o anúncio que deseja pesquisar?" << endl;
            cin >> str;
            transform(str.begin(),str.end(), str.begin(), ::tolower);
            limpa_tela();
            cout <<"==================================================================================================="<< endl;
            cout <<"                                             APARTAMENTOS                                          "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                str2 = imoveis[i]->getAnuncio();
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if(imoveis[i]->getTipoImovel() == 1 && str2.find(str) != string::npos)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                                CASAS                                              "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                str2 = imoveis[i]->getAnuncio();
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if(imoveis[i]->getTipoImovel() == 2 && str2.find(str) != string::npos)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                               TERRENOS                                            "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                str2 = imoveis[i]->getAnuncio();
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if(imoveis[i]->getTipoImovel() == 3 && str2.find(str) != string::npos)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            pressione();
            break;
        case 4:
            cout << "Qual o tipo de contrato? (1 - Venda) (2 - Aluguel)" << endl;
            cin >> opcao;
            limpa_tela();
            if (opcao == 1)
            {
                contrato = true;
            }
            else
            {
                contrato = false;
            }
            cout << "Qual o valor máximo que pretende gastar?" << endl;
            cin >> valor;
            limpa_tela();
            cout <<"==================================================================================================="<< endl;
            cout <<"                                             APARTAMENTOS                                          "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                if(imoveis[i]->getTipoImovel() == 1 && imoveis[i]->getOferta() == contrato && imoveis[i]->getValor() <= valor)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                                CASAS                                              "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                if(imoveis[i]->getTipoImovel() == 2 && imoveis[i]->getOferta() == contrato && imoveis[i]->getValor() <= valor)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                               TERRENOS                                            "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                if(imoveis[i]->getTipoImovel() == 3 && imoveis[i]->getOferta() == contrato && imoveis[i]->getValor() <= valor)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            pressione();
            break;
        case 5:
            cout << "Em qual cidade deseja pesquisar?" << endl;
            cin >> str;
            transform(str.begin(),str.end(), str.begin(), ::tolower);
            limpa_tela();
            cout <<"==================================================================================================="<< endl;
            cout <<"                                             APARTAMENTOS                                          "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                end = imoveis[i]->getEndereco();
                str2 = end.getCidade();
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if(imoveis[i]->getTipoImovel() == 1 && str2.find(str) != string::npos)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                                CASAS                                              "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                end = imoveis[i]->getEndereco();
                str2 = end.getCidade();
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if(imoveis[i]->getTipoImovel() == 2 && str2.find(str) != string::npos)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            cout <<"==================================================================================================="<< endl;
            cout <<"                                               TERRENOS                                            "<< endl;
            cout <<"==================================================================================================="<< endl;
            for (int i = 0; i < indice; i++)
            {
                end = imoveis[i]->getEndereco();
                str2 = end.getCidade();
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if(imoveis[i]->getTipoImovel() == 3 && str2.find(str) != string::npos)
                {
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"                                       Posição:"<< i << endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                    imoveis[i]->caracteristicas();
                    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                }
            }
            pressione();

            break;
        
        default:
            break;
        }
        break;
    }

}

vector<Imovel*> cadastrar_imovel(vector<Imovel*> imoveis, int indice, int tipo)
{
    int inteiro;
    double pontoflutuante;
    string str;

    Apartamento* apartamento = new Apartamento();
    Casa* casa = new Casa();
    Terreno* terreno = new Terreno();
    Endereco endereco;

    switch (tipo)
    {
    case 1:
        cout << "Qual o valor do imóvel?" << endl;
        cin >> pontoflutuante;
        getchar();
        apartamento->setValor(pontoflutuante);

        cout << "Qual o logradouro?" << endl;
        getline(cin, str);
        endereco.setLogradouro(str);

        cout << "Qual o bairro do imóvel?" << endl;
        getline(cin, str);
        endereco.setBairro(str);

        cout << "Qual a cidade do imóvel?" << endl;
        getline(cin, str);
        endereco.setCidade(str);

        cout << "Qual o numero do imóvel?" << endl;
        cin >> inteiro;
        getchar();
        endereco.setNumero(inteiro);

        cout << "Qual o CEP do imóvel?" << endl;
        getline(cin, str);
        endereco.setCep(str);

        apartamento->setEndereco(endereco);

        cout << "1 - Imóvel para venda\n2- Imóvel para alugar\n(Escolha uma opção)" << endl;
        cin >> inteiro;
        getchar();
        if(inteiro == 1)
        {
            apartamento->setOferta(true);
        }
        else
        {
            apartamento->setOferta(false);
        }

        cout << "Descrição:" << endl;
        getline(cin, str);
        apartamento->setDescricao(str);

        cout << "Anúncio:" <<endl;
        getline(cin, str);
        apartamento->setAnuncio(str);

        imoveis.insert(imoveis.begin() + indice, apartamento);

        apartamento = (Apartamento*)imoveis.at(indice);

        cout << "Qual a posição do imóvel?" << endl;
        getline(cin, str);
        apartamento->setposicao(str);

        cout << "Quantos quartos há no imóvel?" << endl;
        cin >> inteiro;
        apartamento->setnumQuartos(inteiro);

        cout << "Quantas vagas de garagem?" << endl;
        cin >> inteiro;
        apartamento->setvagasGaragem(inteiro);

        cout << "Qual o valor do condomínio?" << endl;
        cin >> pontoflutuante;
        apartamento->setvalorCondomino(pontoflutuante);

        cout << "Qual a área do imóvel?" << endl;
        cin >> pontoflutuante;
        apartamento->setarea(pontoflutuante);

        cout << "Qual o andar do imóvel?" << endl;
        cin >> inteiro;
        apartamento->setAndar(inteiro);
        
        break;

    case 2:
        cout << "Qual o valor do imóvel?" << endl;
        cin >> pontoflutuante;
        getchar();
        casa->setValor(pontoflutuante);

        cout << "Qual o logradouro?" << endl;
        getline(cin, str);
        endereco.setLogradouro(str);

        cout << "Qual o bairro do imóvel?" << endl;
        getline(cin, str);
        endereco.setBairro(str);

        cout << "Qual a cidade do imóvel?" << endl;
        getline(cin, str);
        endereco.setCidade(str);

        cout << "Qual o numero do imóvel?" << endl;
        cin >> inteiro;
        getchar();
        endereco.setNumero(inteiro);

        cout << "Qual o CEP do imóvel?" << endl;
        getline(cin, str);
        endereco.setCep(str);

        casa->setEndereco(endereco);

        cout << "1 - Imóvel para venda\n2- Imóvel para alugar\n(Escolha uma opção)" << endl;
        cin >> inteiro;
        getchar();
        if(inteiro == 1)
        {
            casa->setOferta(true);
        }
        else
        {
            casa->setOferta(false);
        }

        cout << "Descrição:" << endl;
        getline(cin, str);
        casa->setDescricao(str);

        cout << "Anúncio:" <<endl;
        getline(cin, str);
        casa->setAnuncio(str);

        imoveis.insert(imoveis.begin() + indice, casa);

        casa = (Casa*)imoveis.at(indice);

        cout << "Quantos quartos há no imóvel?" << endl;
        cin >> inteiro;
        casa->setnumQuartos(inteiro);

        cout << "Qual a área do imóvel?" << endl;
        cin >> pontoflutuante;
        casa->setareaConstruida(pontoflutuante);

        cout << "Qual a área do terreno do imóvel?" << endl;
        cin >> pontoflutuante;
        casa->setareaTerreno(pontoflutuante);

        cout << "Quantos pavimentos há no imóvel?" << endl;
        cin >> inteiro;
        casa->setnumPavimentos(inteiro);

        break;

    case 3:
        cout << "Qual o valor do imóvel?" << endl;
        cin >> pontoflutuante;
        getchar();
        terreno->setValor(pontoflutuante);

        cout << "Qual o logradouro?" << endl;
        getline(cin, str);
        endereco.setLogradouro(str);

        cout << "Qual o bairro do imóvel?" << endl;
        getline(cin, str);
        endereco.setBairro(str);

        cout << "Qual a cidade do imóvel?" << endl;
        getline(cin, str);
        endereco.setCidade(str);

        cout << "Qual o numero do imóvel?" << endl;
        cin >> inteiro;
        getchar();
        endereco.setNumero(inteiro);

        cout << "Qual o CEP do imóvel?" << endl;
        getline(cin, str);
        endereco.setCep(str);

        terreno->setEndereco(endereco);

        cout << "1 - Imóvel para venda\n2- Imóvel para alugar\n(Escolha uma opção)" << endl;
        cin >> inteiro;
        getchar();
        if(inteiro == 1)
        {
            terreno->setOferta(true);
        }
        else
        {
            terreno->setOferta(false);
        }

        cout << "Descrição:" << endl;
        getline(cin, str);
        terreno->setDescricao(str);

        cout << "Anúncio:" <<endl;
        getline(cin, str);
        terreno->setAnuncio(str);

        imoveis.insert(imoveis.begin() + indice, terreno);

        terreno = (Terreno*)imoveis.at(indice);

        cout << "Qual a área do imóvel?" << endl;
        cin >> pontoflutuante;
        terreno->setArea(pontoflutuante);

        break;
    }
    return imoveis;
}

vector<Imovel*> editar_imovel(vector<Imovel*> imoveis, int indice)
{
    int posicao, tipo;
    consultar_imovel(imoveis, indice);
    limpa_tela();
    cout <<"Qual tipo de imóvel você deseja editar? (1-Apartamento) (2-Casa) (3-Terreno)?" <<endl;
    cin >> tipo;
    cout <<"Escolha uma posição para editar:"<< endl;
    cin >> posicao;
    return cadastrar_imovel(imoveis, posicao, tipo);
}

vector<Imovel*> remover_imovel(vector<Imovel*> imoveis, int indice)
{
    int posicao;
    consultar_imovel(imoveis, indice);
    limpa_tela();
    cout <<"Escolha uma posição para remover:"<< endl;
    cin >> posicao;

    imoveis.erase(imoveis.begin() + posicao);

    return imoveis;
}

int main()
{
    int opcao, subopcao;

    int indice = 0;

    int tipo;

    vector<Imovel*> imoveis;

    imoveis = ler_arquivo(&indice);

    while (true)
    {
        menuprincipal:
            limpa_tela();
            menu_principal();
            cin >> opcao;
            switch (opcao)
            {
            case 1:
                limpa_tela();
                consultar_imovel(imoveis, indice);
                goto menuprincipal;
            
            case 2:
                limpa_tela();
                submenu();
                cin >> subopcao;
                switch (subopcao)
                {
                case 1:
                    limpa_tela();
                    tipo = 1;
                    imoveis = cadastrar_imovel(imoveis, indice, tipo);
                    indice++;
                    pressione();
                    goto menuprincipal;
                    break;
                case 2:
                    limpa_tela();
                    tipo = 2;
                    imoveis = cadastrar_imovel(imoveis, indice, tipo);
                    indice++;
                    pressione();
                    goto menuprincipal;
                    break;
                case 3:
                    limpa_tela();
                    tipo = 3;
                    imoveis = cadastrar_imovel(imoveis, indice, tipo);
                    indice++;
                    pressione();
                    goto menuprincipal;
                    break;
                
                default:
                    limpa_tela();
                    goto menuprincipal;
                    break;
                }
                break;
            case 3:
                limpa_tela();
                imoveis = remover_imovel(imoveis, indice);
                indice--;
                cout << "Imóvel removido com sucesso"<< endl;
                pressione();
                goto menuprincipal;
                break;
            
            case 4:
                limpa_tela();
                imoveis = editar_imovel(imoveis, indice);
                cout << "Imóvel editado com sucesso!" <<endl;
                pressione();
                goto menuprincipal;
                break;
            
            default:
                limpa_tela();
                cout << "---------------------------OBRIGADO POR USAR NOSSO PROGRAMA! ATÉ MAIS!-----------------------------" << endl;
                cout << "------------------------------------FEITO POR ANDRE HUGO (P2)!-------------------------------------" << endl;
                break;
            }
            break;
    }
    salvar_arquivo(imoveis); 
    return 0;
}