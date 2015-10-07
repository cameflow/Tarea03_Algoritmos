#include <iostream>
#include <vector>


//-------------Declaración de las funciones--------------//

//Función que regresa un arreglo con las gasolineras en las que se debe de parar
std::vector<int> paradasPorHacer(int maxKilometers, std::vector<int> distances);

int main()
{
  std::vector<int> distances = {1000, 1500, 500, 700, 2000, 3000};
  int maxKilometers = 3000;
  std::vector<int> resultado = paradasPorHacer(maxKilometers, distances);
  for(int i=0; i<resultado.size(); i++)
  {
    std::cout << "El camión debe recargar gasolina en la parada " << resultado[i]+1 << std::endl;
  }
  return 0;
}


//-----------Implementación de funciones----------------//
std::vector<int>  paradasPorHacer(int maxKilometers, std::vector<int> distances)
{
  std::vector<int> gasolinerasAParar; //Arreglo que va a contener las gasolineras a parar
  int j = 0;
  int kmRestantes = 0; //Los km que le quedan por recorrer
  while(j != distances.size()-1)
  {
    if(kmRestantes + distances[j+1] > maxKilometers)
    {
     gasolinerasAParar.push_back(j);
     kmRestantes = 0;
    }
    else//si no es prometedor, saltárselo
    {
      j++;
      kmRestantes+=distances[j];
    }
 }
 return gasolinerasAParar;
}
