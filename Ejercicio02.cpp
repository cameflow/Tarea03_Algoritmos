/*
  Problema sobre la justificación del texto
  Este problema es un algoritmo ávido ya que decide lo mejor que hacer en el momento
  Decide por linea si es mejor reducir o amunter dependiendo de cual tendría menor costo en el momento
  No toma en cuenta el costo final, solo del momento.

  La complejidad sería O(n)
*/
#include <iostream>
#include <vector>
using namespace std;

//------------------Declaración e implementación de la clase linea --------------//
class linea
{
    int maxTam;  //Tamaño máximo de la linea
    int b;    //Tamañode los espacios de la linea
    int total; n
    vector<int> palabras; //Las palabras que están en la linea
  public:
    //Constructor de la liena
    linea(int maxTam,int b)
    {
      this->maxTam = maxTam;
      this->b = b;
      total = 0;
    }

    //Función para insertar una palabra
    bool insertarPalabra(int palabra)
    {
      if(getLongitud()+palabra+b > maxTam)
      {
        if(!pasarSiguiente(palabra))
        {
          while(b>=2)
          {
            b--;
            if (getLongitud()+palabra <= maxTam)
            {
              palabras.push_back(palabra);
              total += palabra;
              return true;
            }
          }
        }
        else
        {
          while(getLongitud() != maxTam)
          {
            b++;
          }
          return false;
        }
      }
      else
      {
        palabras.push_back(palabra);
        total += palabra;
        return true;
      }
      return false;
    }

    //Función para saber si la palabra se debe de pasar a la siguiente linea
    bool pasarSiguiente(int palabra)
    {
      int original = b;
      unsigned long costoAchicar = 0;
      unsigned long costoPasarSiguiente = 0;
      bool cabe = false;
      while(b>=2)
      {
        b--;
        costoAchicar++;
      }
      if (getLongitud()+palabra <= maxTam)
      {
        cabe = true;
      }
      b = original;
      while(getLongitud() != maxTam)
      {
        b++;
        costoPasarSiguiente++;
      }
      costoAchicar = palabras.size()* costoAchicar;
      costoPasarSiguiente = (palabras.size()-1)* costoPasarSiguiente;
      b = original;
      if (cabe == true)
      {
        return costoAchicar > costoPasarSiguiente;
      }
      else
      {
        return true;
      }
    }

    //Función para asignar un nuevo valor al espacio
    void setB(int b)
    {
      this->b = b;
    }
    //Función para obtener el valor del espacio de la linea
    int getB()
    {
      return b;
    }
    //Función para obtener la longitud de la linea
    unsigned long getLongitud()
    {
      return total+(b*(palabras.size()-1));
    }

    //Función para limpiar la linea
    void clear()
    {
      total = 0;
      palabras.clear();
    }

    //Función para imprimir la linea
    void print()
    {
      for(int i = 0; i < palabras.size();i++)
      {
        cout << palabras[i] << " ";
      }
    }
};

//-------------Declaración de funciones ---------------//
std::vector<int> sacarLongitudes(std::vector<std::string> words);


int main(int argc, const char * argv[])
{
    int tamLinea = 26;
    int b = 2;
    std::vector<std::string> texto = {"Castillote", "Castillote", "alex", "Castillo", "Castillote", "Castillotote", "Castillotote"};
    std::vector<int> longitudes = sacarLongitudes(texto);

    vector<linea> parrafo;
    linea nueva(tamLinea,b);
    int i = 0;
    while(i<longitudes.size())
    {
      if(nueva.insertarPalabra(longitudes[i]))
      {
        i++;
      }
      else
      {
        parrafo.push_back(nueva);
        nueva.clear();
        nueva.setB(b);
      }
    }
    parrafo.push_back(nueva);

    for(int j = 0; j < parrafo.size();j++)
    {
      parrafo[j].print();
      cout << " con b: " << parrafo[j].getB() <<endl;
    }
}
//---------------------- Implementación de las funciones --------------------//
std::vector<int> sacarLongitudes(std::vector<std::string> words)
{
  std::vector<int> tamanios;
  for(int i = 0 ; i < words.size() ; i++)
  {
    tamanios.push_back(words[i].size());
  }
  return tamanios;
}
