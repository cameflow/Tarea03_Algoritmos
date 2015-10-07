#include <iostream>

std::string obtenerSubsecuencia(const std::string primera, const std::string segunda);


int main()
{
  std::string A = "anitalavalatina";
  std::string B = "lavaderodetilatina";
  std::string C = "juan";

  std::cout << "Subsecuencia mas larga es: " << obtenerSubsecuencia(A,B) << std::endl;
  return 0;
}


std::string obtenerSubsecuencia(const std::string primera, const std::string segunda)
{
  int tamPrimera = primera.length();
  int tamSegunda = segunda.length();

  std::string subsecuenciaMasLarga = "";
  int tamSecuenciaMasLarga = 0;
  std::string temp = "";

  for(int i = 0; i<tamPrimera-1;i++)
  {
    int k = i;
    for (int j = 0; j < tamSegunda-1 ; j++)
    {
      temp = "";
      int l = j;
      while (primera[k] == segunda [l])
      {
        temp += primera[k];
        k++;
        l++;
      }
      if(temp.length() > tamSecuenciaMasLarga)
      {
        subsecuenciaMasLarga = temp;
        tamSecuenciaMasLarga = subsecuenciaMasLarga.length();
      }
    }
  }
  return subsecuenciaMasLarga;

}
