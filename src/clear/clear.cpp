#include "clear/clear.hpp"
#include <cstdlib>
#include <iostream>

void clearTerminal() {
#ifdef _WIN32
    system("cls"); // Windows
#else
    [[maybe_unused]] int _ =  system("clear"); // Unix/Linux/Mac
#endif
}

void clearTerminalWithWait(bool waitForEnter) {
    if (waitForEnter) {
        std::cout << "Pressione Enter para limpar o terminal...";
        std::cin.get();  // Espera o usuário pressionar Enter
    }

    clearTerminal();  // Chama a versão sem parâmetros para limpar o terminal
}