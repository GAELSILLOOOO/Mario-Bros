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
    std::string reset_position;//string para guardar el texto original
    int frame = 0;
    auto can = Canvas(50,50);//canvas es como lienzo 
    can.DrawPointCircle(10,10,10);//mensaje que se le da al canvas
    can.DrawPointLine(0,0,10,10);
    auto ColorSupport = vbox({
                            Terminal::ColorSupport() >= Terminal::Color::Palette16
                                ? text(" 16 color palette support : Yes")//signo de pregunta es el if en linea "?" ":"es el else
                                : text(" 16 color palette support : No"),
                            Terminal::ColorSupport() >= Terminal::Color::Palette256
                                ? text("256 color palette support : Yes")
                                : text("256 color palette support : No"),
                            Terminal::ColorSupport() >= Terminal::Color::TrueColor
                                ? text("       True color support : Yes")
                                : text("       True color support : No"),
                        });
    while (true)
    {
        Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full());//creacion de pantalla
        Element personaje = spinner(20, frame);
        Element lienzo = bgcolor(Color::Red, border(vbox(ColorSupport,personaje,canvas(&can))));
        Render(pantalla, lienzo);
        std::cout << reset_position;
        pantalla.Print();
        reset_position = pantalla.ResetPosition(true);
        this_thread::sleep_for(0.1s);
        frame++;
    }

    return 0;
}