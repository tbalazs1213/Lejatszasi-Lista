#include <iostream>

using namespace std;

struct Szam
{
  string eloado;
  string cim;
	Szam *kov;
};

void kiir(Szam *horgony)
{
	
  if(horgony != NULL)
  {
		int szamlalo = 1;
		Szam *akt = horgony;
    while(akt != NULL)
    {
      cout << szamlalo << ". " << horgony->eloado << "-" << horgony->cim << endl;
    }
  }
  else
  {
    cout << "A lejatszasi lista ures." << endl;
  }
}

int kilepes(Szam *horgony)
{
  if(horgony != NULL)
  {
    while(horgony != NULL)
    {
			Szam *tmp = horgony;
      horgony = horgony->kov;
      delete tmp;
    }
  }
  cout << "Viszlat!";
  return 0;
}

void hozzaadas(Szam *horgony)
{
  string eloado, cim;
  cout << "Eloado: ";
  cin.ignore();
  getline(cin, eloado);
  cout << "Cim: ";
  getline(cin, cim);
	Szam *uj = new Szam;
	uj->eloado = eloado;
	uj->cim = cim;
	uj->kov = NULL;
	if(horgony == NULL)
	{
    horgony = uj;
	}
	else
	{
		Szam *akt = horgony;
		while(akt->kov != NULL)
		{
			akt = akt->kov;
		}
		akt->kov = uj;
	}
}

void eltavolitas(Szam *horgony)
{
  int elem, szamlalo = 1;
  Szam *akt = horgony;
  Szam *elozo = NULL;
  cout << "Hanyadik szamot szeretned torolni?" << endl;
  cin >> elem;
  kiir(horgony);
  while(szamlalo != elem)
  {
    akt = akt->kov;
    szamlalo++;
		if(szamlalo != elem)
    {
      elozo = akt;
    }
  }
  elozo->kov = akt->kov;
  delete akt;
}

int main()
{
  Szam *horgony = NULL;
  string parancs;
  cout << "Lejatszasi lista szerkeszto" << endl;
  kiir(horgony);
  cout << "Valasszon menupontot:" << endl << "1 - Kilepes" << endl << "2 - Hozzaadas" << endl << "3 - Eltavolitas" << endl;
  do
  {
    cout << "Parancs: ";
		cin >> parancs;
    if(parancs == "1")
    {
      kilepes(horgony);
    }
    else if(parancs == "2")
    {
      hozzaadas(horgony);
      kiir(horgony);
    }
    else if(parancs == "3")
    {
      eltavolitas(horgony);
      kiir(horgony);
    }
    else
    {
      cout << "Nem letezo parancs!" << endl;
    }
  }while(parancs != "1");
  return 0;
}
