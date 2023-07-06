#include <iostream>
#include <string>
using namespace std;
float ty = 0, ns = 0, hd = 0, alf = 0, bm = 0; // montos
double prty, prns, prhd, pralf, prbm;		   // promedios
int canty = 0, canns = 0, canhd = 0, canalf = 0, canbm = 0;

string getClientName()
{
	string cli;
	cout << "Ingrese nombre del cliente" << endl;
	cin.ignore(); // Elimina cualquier caracter anterior sobrante(en este caso el de salto de linea
	getline(cin, cli);
	return cli;
}

string getSucursalName()
{
	int su;
	string alm;
	do
	{ // Si Su no es valida repite y repite hasta que lo sea
		cout << "Seleccione una de las siguientes sucursales: \n"
			 << endl;
		cout << "1. San Miguelito, 2. San Francisco, 3. Arraijan, 4. Costa Verde \n";
		cin >> su;
		switch (su)
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
			su = 0;
			cout << "Sucursal no valida \n";
		}
	} while (su == 0);
	return alm;
}

int getBrandNumber()
{
	int brandNumber = 0;
	do
	{
		cout << "Selecione una de las siguientes marcas: \n";
		cout << "1. Toyota, 2. Nissan, 3. Hyundai, 4. Alfa, 5. BMW \n";
		cin >> brandNumber;
		if (brandNumber < 1 || brandNumber > 5)
		{
			cout << "Marca selecionada no valida, ingrese nuevamente\n"
				 << endl;
		}
	} while (brandNumber < 1 || brandNumber > 5);
	return brandNumber;
}

int getBrandQuantity()
{
	int cantidad = 0;
	cout << "�Cuantos vehiculos de la marca desea alquilar?\n";
	cin >> cantidad;
	return cantidad;
}

int getRentalTime()
{
	int dias = 0;
	cout << "Tiempo de alquiler (dias) \n";
	cin >> dias;
	return dias;
}

int selectAnotherBrand()
{
	int res = 1;
	cout << "Desea seleccionar otra marca de auto?\n";
	cout << "Para Si ingresar 1, Para No ingresar 2\n";
	cin >> res;
	return res;
}

int sumDays(int totalDias, int dias)
{
	totalDias += dias;
	return totalDias;
}

int sumTotalAmount(int &totalAmount, int amount)
{
	totalAmount += amount;
	return totalAmount;
}

void calculo_marca(int brandNumber, int dias, int cantidad, int &totalAmount)
{ // usa cantidades
	float op = 0;
	switch (brandNumber)
	{
	case 1:
		// toyota
		break;
	case 2:
		op = (19.75 + 27.00) * dias;
		ns += op;
		canns += cantidad;
		prns = ns / canns;
		sumTotalAmount(totalAmount, ns);
		break;
	case 3:
		op = (70.95 + 40.00) * dias;
		hd += op;
		canhd += cantidad;
		prhd = hd / canhd;
		sumTotalAmount(totalAmount, hd);
		break;
	case 4:
		op = (75.00 + 55.00) * dias;
		alf += op;
		canalf += cantidad;
		pralf = alf / canalf;
		sumTotalAmount(totalAmount, alf);
		break;
	case 5:
		op = (80.00 + 75.00) * dias;
		bm += op;
		canbm += cantidad;
		prbm = bm / canbm;
		sumTotalAmount(totalAmount, bm);
		break;
	default:
		cout << "Error: marca de auto no valida.\n";
	}
}

void bucle_marca(int brandNumber, int &totalDias, int &dias, int &cantidad, int &totalAmount)
{
	int res = 1;
	do
	{
		brandNumber = getBrandNumber();
		cantidad = getBrandQuantity();
		dias = getRentalTime();
		totalDias = sumDays(totalDias, dias);
		calculo_marca(brandNumber, dias, cantidad, totalAmount); // usa cantidades
		cout << "TotalAmount en bucle: " << totalAmount << "\n";
		res = selectAnotherBrand();
	} while (brandNumber < 1 || brandNumber > 5 || res != 2);
}

void impresion_toyota()
{
	if (ty > 0.0001)
	{
		cout << "Marca: Toyota\n";
		cout << "Monto: " << ty << "\n";
		cout << "Pro. Alq./Auto: " << prty << "\n";
		cout << "Cantidad de autos: " << canty << "\n"
			 << endl;
	}
}

void impresion_nissan()
{
	if (ns > 0.0001)
	{
		cout << "Marca: Nissan\n";
		cout << "Monto: " << ns << "\n";
		cout << "Pro. Alq./Auto: " << prns << "\n";
		cout << "Cantidad de autos: " << canns << "\n"
			 << endl;
	}
}

void impresion_hyundai()
{
	if (hd > 0.0001)
	{
		cout << "Marca: Hyundai\n";
		cout << "Monto: " << hd << "\n";
		cout << "Pro. Alq./Auto: " << prhd << "\n";
		cout << "Cantidad de autos: " << canhd << "\n"
			 << endl;
	}
}

void impresionAlfa()
{
	if (alf > 0.0001)
	{
		cout << "Marca: Alfa\n";
		cout << "Monto: " << alf << "\n";
		cout << "Pro. Alq./Auto: " << pralf << "\n";
		cout << "Cantidad de autos: " << canalf << "\n"
			 << endl;
	}
}

void impresionBmw()
{
	if (bm > 0.0001)
	{
		cout << "Marca: BMW\n";
		cout << "Monto: " << bm << "\n";
		cout << "Pro. Alq./Auto: " << prbm << "\n";
		cout << "Cantidad de autos: " << canbm << "\n"
			 << endl;
	}
}

void impresionGeneral(string cli, string alm, int totalDias, int totalAmount)
{
	cout << "CIA De Alquiler De Autos \n";
	cout << "RENT A CAR" << endl
		 << "\n";
	cout << "Surcursal: " << alm << "\n";
	cout << "Contrato: " << 3 * 21 * 0.0056 << "_efrr32"
		 << "\n";
	cout << "Cliente: " << cli << "\n";
	cout << "Tiempo/Alquiler: " << totalDias << " Dias"
		 << "\n";
	cout << "Monto: " << totalAmount << endl
		 << endl;
	cout << "Total por marca: " << endl
		 << endl;
}

int askForSucursalChange()
{
	int res = 0;
	cout << "Desea cambiar de sucursal? \n";
	cout << "Para Si ingresar 1, Para No ingresar 2\n";
	cin >> res;
	return res;
}

int main()
{
	string cli, alm;
	int brandNumber = 0, sucursalChange, totalDias = 0, dias = 0, cantidad = 0;
	int totalAmount = 0;
	do
	{ // Para sucursal
		alm = getSucursalName();
		cli = getClientName();
		bucle_marca(brandNumber, totalDias, dias, cantidad, totalAmount);
		impresionGeneral(cli, alm, totalDias, totalAmount);
		impresion_nissan();
		impresion_hyundai();
		impresion_toyota();
		impresionAlfa();
		impresionBmw();
		sucursalChange = askForSucursalChange();
		if (sucursalChange == 1)
		{
			ty = 0;
			ns = 0;
			hd = 0;
			alf = 0;
			bm = 0;
			totalDias = 0;
			totalAmount = 0;
			canty = 0;
			canns = 0;
			canhd = 0;
			canalf = 0;
			canbm = 0;
			brandNumber = 0;
			dias = 0;
			cli = "";
		}
	} while (sucursalChange != 2);

	return 0;
}