#include <iostream>
#include <string>
using namespace std;
string alm;
float ty = 0, ns = 0, hd = 0, alf = 0, bm = 0, op = 0, montoTotal = 0; // montos
double prty, prns, prhd, pralf, prbm;								   // promedios
int canty = 0, canns = 0, canhd = 0, canalf = 0, canbm = 0;			   // cantidades

string obtener_nombre_cliente(string cliente)
{
	cout << "Ingrese nombre del cliente" << endl;
	cin.ignore(); // Elimina cualquier caracter anterior sobrante(en este caso el de salto de linea)
	getline(cin, cliente);
	return cliente;
}

void seleccion_de_sucursal(int sucursal)
{
	do
	{ // Si Su no es valida repite y repite hasta que lo sea
		cout << "Seleccione una de las siguientes sucursales: \n"
			 << endl;
		cout << "1. San Miguelito, 2. San Francisco, 3. Arraijan, 4. Costa Verde \n";
		cin >> sucursal;
		switch (sucursal)
		{
		case 1:
			alm = "San Miguelito";
			break;
		case 2:
			alm = "San Francisco";
			break;
		case 3:
			alm = " Arraijan";
			break;
		case 4:
			alm = "Costa Verde";
			break;
		default:
			sucursal = 0;
			cout << "Sucursal no valida \n";
		}

	} while (sucursal == 0);
}

int retorno_marca_seleccionada(int numero_marca)
{
	cout << "Selecione una de las siguientes marcas: \n";
	cout << "1. Toyota, 2. Nissan, 3. Hyundai, 4. Alfa, 5. BMW \n";
	cin >> numero_marca;
	return numero_marca;
}

int retorno_cantidad_autos(int cantidadAutos)
{
	cout << "�Cuantos vehiculos de la marca desea alquilar?\n";
	cin >> cantidadAutos;
	return cantidadAutos;
}

int retorno_tiempo_alquiler()
{
	int diasAlquiler = 0;
	cout << "Tiempo de alquiler (dias) \n";
	cin >> diasAlquiler;
	cout << endl;
	return diasAlquiler;
}

void seleccion_de_marca(int numero_marca, int diasAlquiler, int totalDias, int cantidadAutos)
{
	do
	{
		if (numero_marca < 1 || numero_marca > 5)
		{
			cout << "Marca selecionada no valida, ingrese nuevamente\n"
				 << endl;
		}
	} while (numero_marca < 1 || numero_marca > 5);
}

void calculo_por_marca(int numeroMarca, int diasAlquiler, int cantidadAutos, int montoTotal)
{
	switch (numeroMarca)
	{
	case 1:
		op = (16.50 + 15.00) * diasAlquiler;
		ty = ty + op;			// Monto de toyota
		canty += cantidadAutos; // cantidad de autos
		prty = ty / canty;		// promedio de venta
		montoTotal += ty;
		break;
	case 2:
		op = (19.75 + 27.00) * diasAlquiler;
		ns += op;
		canns += cantidadAutos;
		prns = ns / canns;
		montoTotal += ns;
		break;
	case 3:
		op = (70.95 + 40.00) * diasAlquiler;
		hd += op;
		canhd += cantidadAutos;
		prhd = hd / canhd;
		montoTotal += hd;
		break;
	case 4:
		op = (75.00 + 55.00) * diasAlquiler;
		alf += op;
		canalf += cantidadAutos;
		pralf = alf / canalf;
		montoTotal += alf;
		break;
	case 5:
		op = (80.00 + 75.00) * diasAlquiler;
		bm += op;
		canbm += cantidadAutos;
		prbm = bm / canbm;
		montoTotal += bm;
		break;
	default:
		cout << "Error: marca de auto no valida.\n";
	}
}

int retorno_totalDias(int diasAlquiler, int totalDias)
{
	totalDias += diasAlquiler;
	return totalDias;
}

void bucle_marca(int totalDias, int numeroMarca)
{
	int cantidadAutos = 0;
	int diasAlquiler = 0;
	int res = 1;
	do
	{
		numeroMarca = retorno_marca_seleccionada(numeroMarca);
		if (res == 1)
		{
			seleccion_de_marca(numeroMarca, diasAlquiler, totalDias, cantidadAutos);
			cantidadAutos = retorno_cantidad_autos(cantidadAutos);
			diasAlquiler = retorno_tiempo_alquiler(); // retorno dias ingresados por el user
			totalDias = retorno_totalDias(diasAlquiler, totalDias);
			cout << "Aqui esta dias alquiler, dentro del bucle" << diasAlquiler;
			calculo_por_marca(numeroMarca, diasAlquiler, cantidadAutos, montoTotal);
		}
		cout << "Desea seleccionar otra marca de auto?\n";
		cout << "Para Si ingresar 1, Para No ingresar 2\n";
		cin >> res;
	} while (numeroMarca < 1 || numeroMarca > 5 || res != 2);
}

void impresion_por_marca()
{
	if (ty > 0.0001)
	{
		cout << "Marca: Toyota\n";
		cout << "Monto: " << ty << "\n";
		cout << "Pro. Alq./Auto: " << prty << "\n";
		cout << "Cantidad de autos: " << canty << "\n"
			 << endl;
	}

	if (ns > 0.0001)
	{
		cout << "Marca: Nissan\n";
		cout << "Monto: " << ns << "\n";
		cout << "Pro. Alq./Auto: " << prns << "\n";
		cout << "Cantidad de autos: " << canns << "\n"
			 << endl;
	}

	if (hd > 0.0001)
	{
		cout << "Marca: Hyundai\n";
		cout << "Monto: " << hd << "\n";
		cout << "Pro. Alq./Auto: " << prhd << "\n";
		cout << "Cantidad de autos: " << canhd << "\n"
			 << endl;
	}
	if (alf > 0.0001)
	{
		cout << "Marca: Alfa\n";
		cout << "Monto: " << alf << "\n";
		cout << "Pro. Alq./Auto: " << pralf << "\n";
		cout << "Cantidad de autos: " << canalf << "\n"
			 << endl;
	}
	if (bm > 0.0001)
	{
		cout << "Marca: BMW\n";
		cout << "Monto: " << bm << "\n";
		cout << "Pro. Alq./Auto: " << prbm << "\n";
		cout << "Cantidad de autos: " << canbm << "\n"
			 << endl;
	}
}

void impresion(int sucursal, string nombre_cliente, int numeroMarca, int totalDias)
{ // montoTotal, alm
	cout << "CIA De Alquiler De Autos \n";
	cout << "RENT A CAR" << endl
		 << "\n";
	cout << "Surcursal: " << alm << "\n";
	cout << "Contrato: " << sucursal * numeroMarca * 0.0056 << "_efrr32"
		 << "\n";
	cout << "Cliente: " << nombre_cliente << "\n";
	cout << "Tiempo/Alquiler: " << totalDias << " Dias"
		 << "\n";
	cout << "Monto: " << montoTotal << endl
		 << endl;
	cout << "Total por marca: " << endl
		 << endl;
	impresion_por_marca();
}

int retorno_cambio_sucursal(int cambiarSu)
{
	cout << "Desea cambiar de sucursal?"
		 << "\n";
	cout << "1. Si, 2. No \n";
	cout << endl;
	cin >> cambiarSu;
	return cambiarSu;
}

void cambio_de_sucursal(string cliente, int totalDias, int diasAlquiler, int numeroMarca, int cambiarSu)
{
	if (cambiarSu == 1)
	{
		ty = 0;
		ns = 0;
		hd = 0;
		alf = 0;
		bm = 0;
		totalDias = 0;
		montoTotal = 0;
		canty = 0;
		canns = 0;
		canhd = 0;
		canalf = 0;
		canbm = 0;
		numeroMarca = 0;
		diasAlquiler = 0;
		cliente = "";
	}
}

int main(int argc, char **argv)
{
	int su = 0, numeroMarca = 0, totalDias = 0, diasAlquiler = 0, cambiarSu = 1;
	string cliente;
	do
	{ // Para sucursal
		seleccion_de_sucursal(su);
		cliente = obtener_nombre_cliente(cliente);
		bucle_marca(totalDias, numeroMarca);
		impresion(su, cliente, numeroMarca, totalDias);
		cambiarSu = retorno_cambio_sucursal(cambiarSu);
		cambio_de_sucursal(cliente, totalDias, diasAlquiler, numeroMarca, cambiarSu);
	} while (cambiarSu != 2);
	return 0;
}
