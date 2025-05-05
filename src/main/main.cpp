#include <iostream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <limits>
#include "set/Set.hpp"
#include "clear/clear.hpp"

int main() {
    std::unordered_map<std::string, Set> conjuntos;
    std::string nome;
    int escolha;
    
    while (true) {
        clearTerminalWithWait(true);
        std::cout << "\n--- MENU ---\n"
                  << "1. Criar novo conjunto\n"
                  << "2. Inserir elemento\n"
                  << "3. Mostrar conjunto\n"
                  << "4. União\n"
                  << "5. Interseção\n"
                  << "6. Diferença\n"
                  << "7. Máximo e mínimo elemento\n"
                  << "8. Tamanho do conjunto\n"
                  << "9. Sucessor e predecessor\n"
                  << "10. Remover elemento\n"
                  << "11. Verificar se elemento está contido\n"
                  << "12. Trocar conteúdo de dois conjuntos\n"
                  << "13. Apagar todos os elementos de um conjunto\n"
                  << "14. Sair\n\n"
                  << "Escolha: ";

        std::string entrada;
        std::getline(std::cin, entrada);
        std::istringstream iss(entrada);
        if (!(iss >> escolha)) {
            std::cout << "Entrada inválida. Digite um número de 1 a 13.\n";
            continue;
        }

        switch (escolha) {
            case 1: {
                std::cout << "Digite o nome do novo conjunto: ";
                std::getline(std::cin, nome);
                conjuntos[nome] = Set();
                std::cout << "Conjunto '" << nome << "' criado.\n";
                break;
            }
            case 2: {
                std::cout << "Selecione o conjunto: \n";
                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }

                std::cout << "Nome do conjunto: ";
                std::getline(std::cin, nome);
                if (conjuntos.count(nome) == 0) {
                    std::cout << "Conjunto inexistente.\n";
                    break;
                }

                std::cout << "Digite o(s) valor(es) separado(s) por espaço: ";
                std::string linha;
                std::getline(std::cin, linha);
                std::istringstream iss(linha);
                int val;
                while (iss >> val) {
                    conjuntos[nome].insert(val);
                }
                break;
            }
            case 3: {
                std::cout << "Selecione o conjunto: \n";
                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }

                std::cout << "Nome do conjunto: ";
                std::getline(std::cin, nome);
                if (conjuntos.count(nome)) conjuntos[nome].print();
                else std::cout << "Conjunto inexistente.\n";
                break;
            }   
            case 4: {

                if (conjuntos.empty()) {
                    std::cout << "Nenhum conjunto criado.\n";
                    break;
                }

                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }
                std::cout << "Digite os nomes dos conjuntos para união (ex: A B C): ";
                std::string linha, novo_nome;
                std::getline(std::cin, linha);
                std::istringstream iss(linha);
                std::vector<std::string> nomes;
                std::string temp;
            
                while (iss >> temp)
                    nomes.push_back(temp);
            
                Set resultado;
                bool erro = false;
            
                for (const auto& n : nomes) {
                    if (conjuntos.count(n)) {
                        resultado = resultado.unionSet(conjuntos[n]);
                    } else {
                        std::cout << "Conjunto '" << n << "' não existe.\n";
                        erro = true;
                        break;
                    }
                }
            
                if (!erro) {
                    std::cout << "Digite o nome para o novo conjunto resultado: ";
                    std::getline(std::cin, novo_nome);
                    if (conjuntos.count(novo_nome)) {
                        std::cout << "Já existe um conjunto com esse nome. Deseja sobrescrever? (s/n): ";
                        char resp;
                        std::cin >> resp;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        if (resp != 's' && resp != 'S') {
                            std::cout << "Operação cancelada.\n";
                            break;
                        }
                    }
                    conjuntos[novo_nome] = resultado;
                    std::cout << "União armazenada em '" << novo_nome << "': ";
                    conjuntos[novo_nome].print();
                }
            
                break;
            }            
            case 5: {
                if (conjuntos.empty()) {
                    std::cout << "Nenhum conjunto criado.\n";
                    break;
                }

                std::cout << "Selecione o conjunto: \n";
                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }
                std::cout << "Digite os nomes dos conjuntos para interseção (ex: A B C): ";
                std::string linha, novo_nome;
                std::getline(std::cin, linha);
                std::istringstream iss(linha);
                std::vector<std::string> nomes;
                std::string temp;
            
                while (iss >> temp)
                    nomes.push_back(temp);
            
                if (nomes.empty()) {
                    std::cout << "Nenhum conjunto informado.\n";
                    break;
                }
            
                if (!conjuntos.count(nomes[0])) {
                    std::cout << "Conjunto '" << nomes[0] << "' não existe.\n";
                    break;
                }
            
                Set resultado = conjuntos[nomes[0]];
                bool erro = false;
            
                for (size_t i = 1; i < nomes.size(); ++i) {
                    if (conjuntos.count(nomes[i])) {
                        resultado = resultado.intersection(conjuntos[nomes[i]]);
                    } else {
                        std::cout << "Conjunto '" << nomes[i] << "' não existe.\n";
                        erro = true;
                        break;
                    }
                }
            
                if (!erro) {
                    std::cout << "Digite o nome para o novo conjunto resultado: ";
                    std::getline(std::cin, novo_nome);
                    if (conjuntos.count(novo_nome)) {
                        std::cout << "Já existe um conjunto com esse nome. Deseja sobrescrever? (s/n): ";
                        char resp;
                        std::cin >> resp;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        if (resp != 's' && resp != 'S') {
                            std::cout << "Operação cancelada.\n";
                            break;
                        }
                    }
                    conjuntos[novo_nome] = resultado;
                    std::cout << "Interseção armazenada em '" << novo_nome << "': ";
                    conjuntos[novo_nome].print();
                }
            
                break;
            }
            case 6: {
                if (conjuntos.empty()) {
                    std::cout << "Nenhum conjunto criado.\n";
                    break;
                }

                std::cout << "Selecione o conjunto: \n";
                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }

                std::cout << "Digite os nomes dos conjuntos para diferença (ex: A B C) -> fará A - B - C: ";
                std::string linha, novo_nome;
                std::getline(std::cin, linha);
                std::istringstream iss(linha);
                std::vector<std::string> nomes;
                std::string temp;
            
                while (iss >> temp)
                    nomes.push_back(temp);
            
                if (nomes.empty()) {
                    std::cout << "Nenhum conjunto informado.\n";
                    break;
                }
            
                if (!conjuntos.count(nomes[0])) {
                    std::cout << "Conjunto '" << nomes[0] << "' não existe.\n";
                    break;
                }
            
                Set resultado = conjuntos[nomes[0]];
                bool erro = false;
            
                for (size_t i = 1; i < nomes.size(); ++i) {
                    if (conjuntos.count(nomes[i])) {
                        resultado = resultado.difference(conjuntos[nomes[i]]);
                    } else {
                        std::cout << "Conjunto '" << nomes[i] << "' não existe.\n";
                        erro = true;
                        break;
                    }
                }
            
                if (!erro) {
                    std::cout << "Digite o nome para o novo conjunto resultado: ";
                    std::getline(std::cin, novo_nome);
                    if (conjuntos.count(novo_nome)) {
                        std::cout << "Já existe um conjunto com esse nome. Deseja sobrescrever? (s/n): ";
                        char resp;
                        std::cin >> resp;
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        if (resp != 's' && resp != 'S') {
                            std::cout << "Operação cancelada.\n";
                            break;
                        }
                    }
                    conjuntos[novo_nome] = resultado;
                    std::cout << "Diferença armazenada em '" << novo_nome << "': ";
                    conjuntos[novo_nome].print();
                }
            
                break;
            }            
            case 7: {
                if (conjuntos.empty()) {
                    std::cout << "Nenhum conjunto criado.\n";
                    break;
                }

                std::cout << "Selecione o conjunto: \n";
                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }

                std::cout << "Nome do conjunto a ser analisado: ";
                std::getline(std::cin, nome);
                if (!conjuntos.count(nome)) {
                    std::cout << "Conjunto inexistente.\n";
                    break;
                }

                try {
                    int menor = conjuntos[nome].minimum();
                    int maior = conjuntos[nome].maximum();
                    std::cout << "Menor: " << menor << ", Maior: " << maior << '\n';
                } catch (const std::runtime_error& e) {
                    std::cout << "Erro: " << e.what() << '\n';
                }

                break;
            }
            case 8: {
                if (conjuntos.empty()) {
                    std::cout << "Nenhum conjunto criado.\n";
                    break;
                }

                std::cout << "Selecione o conjunto: \n";
                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }

                std::cout << "Nome do conjunto: ";
                std::getline(std::cin, nome);
                if (conjuntos.count(nome)) std::cout << "Tamanho: " << conjuntos[nome].size() << '\n';
                else std::cout << "Conjunto inexistente.\n";
                break;
            }
            case 9: {
                if (conjuntos.empty()) {
                    std::cout << "Nenhum conjunto criado.\n";
                    break;
                }
                
                std::cout << "Selecione o conjunto: \n";
                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }
                
                std::cout << "Nome do conjunto: ";
                std::getline(std::cin, nome);
                int elem;
                std::cout << "Elemento: ";
                std::cin >> elem;
                std::cin.ignore();
                
                if (!conjuntos.count(nome) || !conjuntos[nome].contains(elem)) {
                    std::cout << "Conjunto ou elemento inexistente.\n";
                    break;
                }
                
                int pred = -1, suc = -1;
                
                bool erroPred = false, erroSuc = false; 
                
                try {
                    pred = conjuntos[nome].predecessor(elem);
                } catch (const std::runtime_error& e) {
                    std::cout << "Erro ao calcular predecessor: " << e.what() << '\n';
                    erroPred = true; 
                }
                
                try {
                    suc = conjuntos[nome].successor(elem);
                } catch (const std::runtime_error& e) {
                    std::cout << "Erro ao calcular sucessor: " << e.what() << '\n';
                    erroSuc = true; 
                }
                
                if (!erroPred) {
                    std::cout << "Predecessor: " << pred << '\n';
                } 
                
                if (!erroSuc) {
                    std::cout << "Sucessor: " << suc << '\n';
                }
                
                break;
            }
            case 10: {
                if (conjuntos.empty()) {
                    std::cout << "Nenhum conjunto criado.\n";
                    break;
                }

                std::cout << "Selecione o conjunto: \n";
                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }

                std::cout << "Nome do conjunto: ";
                std::getline(std::cin, nome);
                int elem;
                std::cout << "Elemento: ";
                std::cin >> elem;
                std::cin.ignore();
                if (conjuntos.count(nome) && conjuntos[nome].contains(elem)) {
                    conjuntos[nome].erase(elem);
                    std::cout << "Removido.\n";
                } else {
                    std::cout << "Conjunto ou elemento inexistente.\n";
                }
                break;
            }
            case 11: {
                if (conjuntos.empty()) {
                    std::cout << "Nenhum conjunto criado.\n";
                    break;
                }

                std::cout << "Selecione o conjunto: \n";
                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }

                std::cout << "Nome do conjunto: ";
                std::getline(std::cin, nome);
                int elem;
                std::cout << "Elemento: ";
                std::cin >> elem;
                std::cin.ignore();
                if (conjuntos.count(nome)) {
                    std::cout << (conjuntos[nome].contains(elem) ? "Contido\n" : "Nao contido\n");
                } else {
                    std::cout << "Conjunto inexistente.\n";
                }
                break;
            }
            case 12: {
                if (conjuntos.empty()) {
                    std::cout << "Nenhum conjunto criado.\n";
                    break;
                }
                
                std::cout << "Selecione o conjunto: \n";
                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }

                std::string a, b;
                std::cout << "Nomes dos conjuntos (ex: A B): ";
                std::cin >> a >> b;
                std::cin.ignore();
                if (conjuntos.count(a) && conjuntos.count(b)) {
                    conjuntos[a].swap(conjuntos[b]);
                    std::cout << "Troca realizada.\n";
                } else {
                    std::cout << "Conjunto(s) inexistente(s).\n";
                }
                break;
            }
            case 13:{

                std:: cout << "Selecione o conjunto: \n";
                for (const auto& par : conjuntos) {
                    std::cout << "- " << par.first << '\n';
                }
                std::cout << "Nome do conjunto: ";
                std::getline(std::cin, nome);
                if (conjuntos.count(nome)) {
                    if (conjuntos[nome].empty()) {
                        std::cout << "Conjunto já está vazio.\n";
                        break;
                    } 
                    conjuntos[nome].clear();
                    std::cout << "Conjunto '" << nome << "' limpo.\n";
                } else {
                    std::cout << "Conjunto inexistente.\n";
                }

                break;
            }
            case 14:
                std::cout << "Saindo...\n";
                return 0;
            default:
                std::cout << "Escolha invalida.\n";
                break;
        }
    }
}