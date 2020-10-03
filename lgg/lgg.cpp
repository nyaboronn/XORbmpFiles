
#include <iostream>

int main()
{
    int cantidad;
    int x0;
    int a;
    int b;
    int m;

    std::cout << "a: ";
    std::cin >> a;
    
    std::cout << "b: ";
    std::cin >> b;
    
    std::cout << "m: ";
    std::cin >> m;

    std::cout << "X0: ";
    std::cin >> x0;

    std::cout << "cantidad a generar: ";
    std::cin >> cantidad;


    int estadoActual = x0;

    std::cout << "** valores generados **\n";
    for (auto i = 0; i < cantidad; ++i) {
        estadoActual = ( a * estadoActual ) % m;
        std::cout << "Valor" << i << ": " << estadoActual << '\n';
    }
}