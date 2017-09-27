#include "console.h"
#include "morse.h""
#include "exercise11.h"


//func prototypes


//general
void exercise11() {
    Morse m;
    string l = m.getMorseCodeLetter(".-");
    std::cout << m.getMorseCodeLetter(".-") << std::endl;
    std::cout << m.getMorseCodeLetter("-...") << std::endl;
    std::cout << m.getMorseCodeLetter("-.") << std::endl;
    std::cout << m.getMorseCodeLetter("--a.") << std::endl;
}





