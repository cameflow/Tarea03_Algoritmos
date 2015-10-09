#include <iostream>
#include <string>
#include <vector>

//--------------- Declaración de las funciones -----------------//

bool prefiere(std::vector<std::vector<int>>, int, int, int, int);
void crearParejas(std::vector<std::vector<int>>,  int);

int main()
{
  //Número de hombres y mujeres
  int n = 4;

  //Vector que contiene vectores de ints.
  //Es una matriz que las primeras 4 filas son los hombres, las últimas 4 filas son las mujeres
  //Cada hombre o mujer tiene acomodados a los hombres o mujeres en el orden de su preferencia
	std::vector<std::vector<int>> matrizPreferencias(2 * n, std::vector<int>(n));
	matrizPreferencias = { { 6, 5, 4, 7 },{ 5, 7, 4, 6 },{ 6, 4, 7, 5 },{ 4, 5, 6, 7 },{ 0, 2, 1, 3 },{ 2, 3, 1, 0 },{ 1, 2, 3, 0 },{ 3, 1, 0, 2 } };

	parejas(matrizPreferencias, n);

}

//----------------- Implementación de las funciones ---------------- //

//Recibe la matriz con todas las preferencias y la cantidad de hombres y mujeres que hay
void crearParejas(std::vector<std::vector<int>> matrizPreferencias, int n)
{

	std::vector<int> parejaDeMujeres; //Lista con las mujeres que están disponibles
	std::vector<bool> hombresLibres; //Vector que tiene el valor de si los hombres están asignados
  int hombresSinPareja = n; //Cantidad de hombres libres

  //Llenado de los vectores, uno con puros -1 y otro con puros falsos ya que todos los hombres están solos
	for (int i = 0; i < n; i++)
	{
		parejaDeMujeres.push_back(-1);
		hombresLibres.push_back(false);
	}

  //Mientras haya hombres disponibles ejecutar el algoritmo
	while (hombresSinPareja > 0)
	{
		int hombreQuePide;
    //Se le asigna un hombre soltero a la variable hombre
		for (int i = 0; i < n; i++)
		{
			if (hombresLibres[i] == false)
			{
				hombreQuePide = i;
				i = n;
			}
		}

		for (int i = 0; i < n && hombresLibres[hombreQuePide] == false; i++)
		{
			int mujer = matrizPreferencias[hombreQuePide][i]; //Variable mujer que se le asigna la primera preferencia del hombre
			if (parejaDeMujeres[mujer - n] == -1) //Se checa si la mujer está disponible
			{
				parejaDeMujeres[mujer - n] = hombreQuePide; //Se le asigna el hombre
				hombresLibres[hombreQuePide] = true;  //El hombre se pone como que ya no está libre
				hombresSinPareja--;  //Se reduce en 1 el número de hombres libres
			}
			else //En caso de que la mujer no este disponible
			{
				int hombreActual = parejaDeMujeres[mujer - n]; //Se le asigna a una variable el hombre con el que está la mujer
				if (prefiere(matrizPreferencias, hombreQuePide, mujer, hombreActual, n) == false) //Se llama a la función para saber si prefiere a el hombre actual sobre el que el pide
				{
					parejaDeMujeres[mujer - n] = hombreQuePide; //En caso de que prefiera al nuevo se lo asigna a la mujer
					hombresLibres[hombreQuePide] = true; //Al nuevo hombre se le pone que está asignado
					hombresLibres[hombreActual] = false; //Al hombre viejo que se pone que ya está libre
				}
			}
		}
	}

	std::cout << "Mujer   Hombre" << std::endl;
	for (int i = 0; i < n; i++)
	{
		std::cout << " " << i + n << "\t" << parejaDeMujeres[i] << std::endl;
	}

}

//Checa si una mujer prefiere a un hombre sobre otro
bool prefiere(std::vector<std::vector<int>> preferencias, int hombreQuePide, int mujer, int hombreActual, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (preferencias[mujer][i] == hombreActual) //Si se encuentra primero al hombre acutal regresa true
		{
			return true;
		}
		if (preferencias[mujer][i] == hombreQuePide) //Si se encuenetra primero al hombre nuevo regresa false
		{
			return false;
		}
	}
  return false;
}
