#include <ftxui/dom/elements.hpp>  //programa merecedor de 10.        Nombre: Lopez Andrade Roberto Gael
#include <ftxui/screen/screen.hpp> // 3-F mecatronica           //  Registro: 23310295.
#include <ftxui/screen/color.hpp>  //      Fecha: 01/11/24.
#include <ftxui/screen/terminal.hpp>
#include <iostream>
#include <thread>

using namespace std;
using namespace ftxui;

int main(int argc, char const *argv[])
{
    std::string reset_position; // String para guardar el texto original
    int frame = 0;

    auto ColorSupport = vbox({});
    // Definir el ancho del canvas y el ancho del carro esto para ejecutar el ciclo while principal
    const int canvas_horizontal = 200;
    const int carro_ancho = 52; // Ancho de la carrocería del carro

    while (true) // Bucle while principal
    {
        // Reiniciar el frame al inicio
        frame = 0;

        while (true) // Bucle while para mover el carro
        {
            Screen pantalla = Screen::Create(Dimension::Full(), Dimension::Full()); // Creación de pantalla
            auto can = Canvas(200, 500);                                            // Canvas donde se dibuja el carro

            // Calcular la posición de las ruedas en base a 'frame'
            int rueda1_x = 20 + frame; // Rueda 1
            int rueda2_x = 40 + frame; // Rueda 2
            if (rueda1_x > canvas_horizontal - carro_ancho)
            {
                break; // Si se alcanza el final, salir del bucle
            }

            // Dibujo de las ruedas del carro Formula 1
            can.DrawPointCircle(rueda1_x, 40, 5, Color::GrayLight); // Rueda 1
            can.DrawPointCircle(rueda2_x, 40, 5, Color::GrayLight); // Rueda 2

            // Dibujo del cuerpo del carro
            can.DrawPointLine(15 + frame, 35, 52 + frame, 35, Color::OrangeRed1); // Línea base de la carrocería
            can.DrawPointLine(15 + frame, 22, 45 + frame, 22, Color::OrangeRed1); // Techo del carro
            can.DrawPointLine(15 + frame, 35, 15 + frame, 22, Color::OrangeRed1); // Línea delantera
            can.DrawPointLine(45 + frame, 22, 45 + frame, 27, Color::OrangeRed1); // línea trasera
            can.DrawPointLine(45 + frame, 27, 52 + frame, 27, Color::OrangeRed1); // líneas frontales
            can.DrawPointLine(52 + frame, 35, 52 + frame, 28, Color::OrangeRed1); // líneas frontales
            can.DrawPointLine(1, 48, 200, 48, Color::Green1);                     // lineas pista
            can.DrawPointLine(1, 10, 200, 10, Color::Green1);                     // lineas pista

            Element lienzo = bgcolor(Color::BlueViolet, border(vbox(ColorSupport, canvas(&can))));
            Render(pantalla, lienzo);
            std::cout << reset_position;
            pantalla.Print();
            reset_position = pantalla.ResetPosition(true);

            // Controlador de la velocidad del carro(animacion)
            std::this_thread::sleep_for(0.1s);
            frame++; // Incrementar el frame para mover el carro
        }

        // Preguntar al usuario si quiere reiniciar
        char elegir;
        std::cout << "El carro ha llegado al final. ¿Quieres reiniciar? (s o S). ";
        std::cout << "De lo contrario presione cualquier otra tecla y presione ENTER: ";
        std::cin >> elegir;

        if (elegir != 's' && elegir != 'S')
        {
            break; // Salir del bucle si el usuario no quiere reiniciar
        }
    }

    return 0;
} // programa merecedor de 10