#include <iostream>
#include <fstream>
#include "Imovel.hpp"
#include "Apartamento.hpp"
#include "Casa.hpp"
#include "Terreno.hpp"
#include <vector>

using namespace std;

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
    cout <<"                                    3 - BUSCAR IMOVEL                                              "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    4 - REMOVER IMOVEL                                             "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    5 - EDITAR IMOVEL                                              "<< endl;
    cout <<"---------------------------------------------------------------------------------------------------"<< endl;
    cout <<"                                    6 - SAIR DO PROGRAMA                                           "<< endl;
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
    cout <<"                                    5 - VOLTAR AO MENU PRINCIPAL                                   "<< endl;
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

void consultar_imovel(vector<Imovel> imoveis, int indice)
{
    int tipo;
    int opcao;
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
            if(imoveis[i].getTipoImovel() == 1)
            {
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                imoveis[i].caracteristicas();
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
            }
        }
        cout <<"==================================================================================================="<< endl;
        cout <<"                                                CASAS                                              "<< endl;
        cout <<"==================================================================================================="<< endl;
        for (int i = 0; i < indice; i++)
        {
            if(imoveis[i].getTipoImovel() == 2)
            {
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                imoveis[i].caracteristicas();
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
            }
        }
        cout <<"==================================================================================================="<< endl;
        cout <<"                                               TERRENOS                                            "<< endl;
        cout <<"==================================================================================================="<< endl;
        for (int i = 0; i < indice; i++)
        {
            if(imoveis[i].getTipoImovel() == 3)
            {
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
                imoveis[i].caracteristicas();
                cout <<"---------------------------------------------------------------------------------------------------"<< endl;
            }
        }
        pressione();
        break;

    case 2:
        submenu_1();
        cin >> opcao;
        break;

    case 3:
        break;
    
    default:
        break;
    }

}

void cadastrar_imovel(vector<Imovel> imoveis, int *indice, int tipo)
{
    int inteiro;
    double pontoflutuante;
    string str;

    Apartamento apartamento = Apartamento();
    Casa casa = Casa();
    Terreno terreno = Terreno();
    Endereco endereco;

    switch (tipo)
    {
    case 1:
        cout << "Qual o valor do imóvel?" << endl;
        cin >> pontoflutuante;
        getchar();
        apartamento.setValor(pontoflutuante);

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

        apartamento.setEndereco(endereco);

        cout << "1 - Imóvel para venda\n2- Imóvel para alugar\n(Escolha uma opção)" << endl;
        cin >> inteiro;
        getchar();
        if(inteiro == 1)
        {
            apartamento.setOferta(true);
        }
        else
        {
            apartamento.setOferta(false);
        }

        cout << "Descrição:" << endl;
        getline(cin, str);
        apartamento.setDescricao(str);

        cout << "Anúncio:" <<endl;
        getline(cin, str);
        apartamento.setAnuncio(str);

        cout << "Qual a posição do imóvel?" << endl;
        getline(cin, str);
        apartamento.setposicao(str);

        cout << "Quantos quartos há no imóvel?" << endl;
        cin >> inteiro;
        apartamento.setnumQuartos(inteiro);

        cout << "Quantas vagas de garagem?" << endl;
        cin >> inteiro;
        apartamento.setvagasGaragem(inteiro);

        cout << "Qual o valor do condomínio?" << endl;
        cin >> pontoflutuante;
        apartamento.setvalorCondomino(pontoflutuante);

        cout << "Qual a área do imóvel?" << endl;
        cin >> pontoflutuante;
        apartamento.setarea(pontoflutuante);

        imoveis.push_back(apartamento);
        *indice++;
        
        break;

    case 2:
        cout << "Qual o valor do imóvel?" << endl;
        cin >> pontoflutuante;
        getchar();
        casa.setValor(pontoflutuante);

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

        casa.setEndereco(endereco);

        cout << "1 - Imóvel para venda\n2- Imóvel para alugar\n(Escolha uma opção)" << endl;
        cin >> inteiro;
        getchar();
        if(inteiro == 1)
        {
            casa.setOferta(true);
        }
        else
        {
            casa.setOferta(false);
        }

        cout << "Descrição:" << endl;
        getline(cin, str);
        casa.setDescricao(str);

        cout << "Anúncio:" <<endl;
        getline(cin, str);
        casa.setAnuncio(str);

        cout << "Quantos quartos há no imóvel?" << endl;
        cin >> inteiro;
        casa.setnumQuartos(inteiro);

        cout << "Qual a área do imóvel?" << endl;
        cin >> pontoflutuante;
        casa.setareaConstruida(pontoflutuante);

        cout << "Qual a área do terreno do imóvel?" << endl;
        cin >> pontoflutuante;
        casa.setareaTerreno(pontoflutuante);

        cout << "Quantos pavimentos há no imóvel?" << endl;
        cin >> inteiro;
        casa.setnumPavimentos(inteiro);

        imoveis.push_back(casa);
        *indice++;

        break;

    case 3:
        cout << "Qual o valor do imóvel?" << endl;
        cin >> pontoflutuante;
        getchar();
        terreno.setValor(pontoflutuante);

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

        terreno.setEndereco(endereco);

        cout << "1 - Imóvel para venda\n2- Imóvel para alugar\n(Escolha uma opção)" << endl;
        cin >> inteiro;
        getchar();
        if(inteiro == 1)
        {
            terreno.setOferta(true);
        }
        else
        {
            terreno.setOferta(false);
        }

        cout << "Descrição:" << endl;
        getline(cin, str);
        terreno.setDescricao(str);

        cout << "Anúncio:" <<endl;
        getline(cin, str);
        terreno.setAnuncio(str);

        cout << "Qual a área do imóvel?" << endl;
        cin >> pontoflutuante;
        terreno.setArea(pontoflutuante);

        imoveis.push_back(casa);
        *indice++;
        break;
    
    default:
        break;
    }
}

int main()
{
    int opcao, subopcao;

    int indice = 0;

    int tipo;

    vector<Imovel> imoveis = {};

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
                    cadastrar_imovel(imoveis, &indice, tipo);
                    pressione();
                    goto menuprincipal;
                    break;
                case 2:
                    limpa_tela();
                    tipo = 2;
                    cadastrar_imovel(imoveis, &indice, tipo);
                    pressione();
                    goto menuprincipal;
                    break;
                case 3:
                    limpa_tela();
                    tipo = 3;
                    cadastrar_imovel(imoveis, &indice, tipo);
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
                submenu();
                cin >> subopcao;
                switch (subopcao)
                {
                case 1:
                    limpa_tela();
                    cout << "Busca de Apartamentos";
                    pressione();
                    goto menuprincipal;
                    break;
                case 2:
                    limpa_tela();
                    cout << "Busca de Casas";
                    pressione();
                    goto menuprincipal;
                    break;
                case 3:
                    limpa_tela();
                    cout << "Busca de Terrenos";
                    pressione();
                    goto menuprincipal;
                    break;
                
                default:
                    limpa_tela();
                    goto menuprincipal;
                    break;
                }
                break;
            
            case 4:
                limpa_tela();
                submenu();
                cin >> subopcao;
                switch (subopcao)
                {
                case 1:
                    limpa_tela();
                    cout << "Remover de Apartamentos";
                    pressione();
                    goto menuprincipal;
                    break;
                case 2:
                    limpa_tela();
                    cout << "Remover de Casas";
                    pressione();
                    goto menuprincipal;
                    break;
                case 3:
                    limpa_tela();
                    cout << "Remover de Terrenos";
                    pressione();
                    goto menuprincipal;
                    break;
                
                default:
                    limpa_tela();
                    goto menuprincipal;
                    break;
                }
                break;
            
            case 5:
                limpa_tela();
                submenu();
                cin >> subopcao;
                switch (subopcao)
                {
                case 1:
                    limpa_tela();
                    cout << "Editar de Apartamentos";
                    pressione();
                    goto menuprincipal;
                    break;
                case 2:
                    limpa_tela();
                    cout << "Editar de Casas";
                    pressione();
                    goto menuprincipal;
                    break;
                case 3:
                    limpa_tela();
                    cout << "Editar de Terrenos";
                    pressione();
                    goto menuprincipal;
                    break;
                
                default:
                    limpa_tela();
                    goto menuprincipal;
                    break;
                }
                break;
            
            default:
                limpa_tela();
                cout << "---------------------------OBRIGADO POR USAR NOSSO PROGRAMA! ATÉ MAIS!-----------------------------" << endl;
                cout << "------------------------------------FEITO POR ANDRE HUGO (P2)!-------------------------------------" << endl;
                break;
            }
            break;
    }
    
    return 0;
}