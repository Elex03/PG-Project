#include<iostream>
#include<irrKlang/irrKlang.h>

using namespace irrklang;
#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll
int main(int argc, const char** argv)
{
    // start the sound engine with default parameters
    ISoundEngine* engine = createIrrKlangDevice();

    if (!engine)
        return 0; // error starting up the engine
    // play some sound stream, looped

    engine->play2D("../../media/getout.ogg", true);
    std::cout << "\nHello World!\n";

    char i = 0;

    while (i != 'q')
    {
        std::cout << "Press any key to play some sound, press 'q' to quit.\n";

        // play a single sound
        engine->play2D("test1.wav");

        std::cin >> i; // wait for user to press some key
    }
}