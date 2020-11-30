#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>
#include <string>
#include <cstdlib>
#include <Functions.h>

int main()
{
    system("title CustomShutdownDialogueV03");
    checkfiles();
    SCG();
    StartLogo();
    pauseclear();
    prompt();
    while(true){
        chooseprompt();
    }

}
