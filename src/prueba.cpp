#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ftxui/screen/color.hpp>
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position; // string para guardar el texto original
    int frame = 0;
    auto can = Canvas(150, 150);     // canvas es como lienzo
    can.DrawPointCircle(15, 10, 11); // mensaje que se le da al canvas
    can.DrawPointCircle(55, 10, 11);
   can.DrawPointCircle(35, 10, 11);




    auto ColorSupport = vbox({

    });
    while (true)
    {
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full()); // creacion de pantalla
        Element personaje = spinner(20, frame);
        Element lienzo = bgcolor(Color::Yellow, border(vbox(ColorSupport, personaje, canvas(&can))));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}