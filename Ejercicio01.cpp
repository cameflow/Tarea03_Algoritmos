#include <iostream>
#include <vector>


//-------------Declaración de las funciones--------------//

//Función que regresa un arreglo con las gasolineras en las que se debe de parar
std::vector<int> paradasPorHacer(int maxKm, std::vector<int> gasolineras);

int main()
{
  std::vector<int> gasolineras = {1000, 1500, 500, 700, 2000, 3000};
  int maxKm = 3000;
  std::vector<int> resultado = paradasPorHacer(maxKm, gasolineras);
  for(int i=0; i<resultado.size(); i++)
  {
    std::cout << "El camión debe recargar gasolina en la parada " << resultado[i]+1 << std::endl;
  }
  return 0;
}


//-----------Implementación de funciones----------------//

//El algoritmo lo que hace es que revisa si con la distancia que le queda por recorrer podría saltarse
//una gasolinera y llegar a la que sigue.
//En caso de que no llegue detiene en la gasolinera acutal.
//En caso de que si llegue se revisa con la que sigue de esá y así hasta encontrar a la cual no se llegaría.
//Se necesita saber la cantidad de km máximos que puede recorrer el camionero y se asume que siempre carga tanque lleno.
std::vector<int>  paradasPorHacer(int maxKm, std::vector<int> gasolineras)
{
  std::vector<int> gasolinerasAParar; //Arreglo que va a contener las gasolineras a parar
  int j = 0;
  int kmRestantes = 0; //Los km que le quedan por recorrer
  while(j != gasolineras.size()-1)
  {
    if(kmRestantes + gasolineras[j+1] > maxKm)
    {
     gasolinerasAParar.push_back(j);
     kmRestantes = 0;
    }
    else
    {
      j++;
      kmRestantes+=gasolineras[j];
    }
 }
 return gasolinerasAParar;
}
