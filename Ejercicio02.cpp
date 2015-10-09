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
    int tamaniolinea;  //Tamaño máximo de la linea
    int b;    //Tamañode los espacios de la linea
    int espaciosOcupados;
    vector<int> palabras; //Las palabras que están en la linea
  public:
    //Constructor de la liena
    linea(int tamaniolinea,int b)
    {
      this->tamaniolinea = tamaniolinea;
      this->b = b;
      espaciosOcupados = 0;
    }

    //Función para insertar una palabra
    bool insertarPalabra(int palabra)
    {
      if(getLongitud()+palabra+b > tamaniolinea)
      {
        if(!saltarLinea(palabra))
        {
          while(b>=2)
          {
            b--;
            if (getLongitud()+palabra <= tamaniolinea)
            {
              palabras.push_back(palabra);
              espaciosOcupados += palabra;
              return true;
            }
          }
        }
        else
        {
          while(getLongitud() != tamaniolinea)
          {
            b++;
          }
          return false;
        }
      }
      else
      {
        palabras.push_back(palabra);
        espaciosOcupados += palabra;
        return true;
      }
      return false;
    }

    //Función para saber si la palabra se debe de pasar a la siguiente linea
    bool saltarLinea(int palabra)
    {
      int original = b;
      unsigned long costoReducir = 0;
      unsigned long costoAmpliar = 0;
      bool cabe = false;
      while(b>=2)
      {
        b--;
        costoReducir++;
      }
      if (getLongitud()+palabra <= tamaniolinea)
      {
        cabe = true;
      }
      b = original;
      while(getLongitud() != tamaniolinea)
      {
        b++;
        costoAmpliar++;
      }
      costoReducir = palabras.size()* costoReducir;
      costoAmpliar = (palabras.size()-1)* costoAmpliar;
      b = original;
      if (cabe == true)
      {
        return costoReducir > costoAmpliar;
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
      return espaciosOcupados+(b*(palabras.size()-1));
    }

    //Función para limpiar la linea
    void clear()
    {
      espaciosOcupados = 0;
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


int main()
{
    int tamLinea = 22;
    int b = 2;
    std::vector<std::string> texto = {"Pablito", "Clavo", "un", "clavito", "en", "la", "calva"};
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
