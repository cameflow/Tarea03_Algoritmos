/*
*/
#include <iostream>

//----------------------Declaración de funciones---------------------//
std::string obtenerSubsecuencia(const std::string primera, const std::string segunda);


int main()
{
  std::string A = "aaa";
  std::string B = "aba";
  std::string C = "juan";

  std::cout << "Subsecuencia mas larga es: " << obtenerSubsecuencia(A,B) << std::endl;
  return 0;
}


//--------------------Implementación de funciones------------------//

//Función que obtiene la subsecuencia
//Recibe dos strings i empieza a comparar el caracter por carater del primero con todos los del segundo
//En caso de que sean iguales se entra a otro ciclo donde se revisa si los siguientes si son iguales
//Cuando dejan de ser iguales se guarda este substring y se compara si es mayor o menor al substring original
//Si es mayor este se pone como la posible solución hasta que se encuentre otro mayor
std::string obtenerSubsecuencia(const std::string primera, const std::string segunda)
{
  int tamPrimera = primera.length(); //Longitud primer palabra
  int tamSegunda = segunda.length(); //Longitud segunda palabra

  std::string subsecuenciaMasLarga = ""; //String resultado
  int tamSecuenciaMasLarga = 0; //Tamaño string resultado
  std::string temp = ""; //String temporal

  for(int i = 0; i<tamPrimera-1;i++)
  {
    int k = i;
    for (int j = 0; j < tamSegunda-1 ; j++)
    {
      temp = ""; //Se vacía el string temporal
      int l = j;
      while (primera[k] == segunda [l]) //Se compara si las letras son iguales
      {
        temp += primera[k]; //se agrega esa letra al string emporal
        k++;
        l++;
      }
      if(temp.length() > tamSecuenciaMasLarga) //Si el string temporal es mayor en cuanto a tamaño este se convierte en el rsutlado
      {
        //Se actualizan los valores del resultado y de su tamaño
        subsecuenciaMasLarga = temp;
        tamSecuenciaMasLarga = subsecuenciaMasLarga.length();
      }
    }
  }
  return subsecuenciaMasLarga;

}
