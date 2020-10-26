#include <iostream>
#include "intkokoelma.h"
#include "intlista.h"

using namespace std;
using otecpp_intlista::IntLista;
using otecpp_intlista::IntSolmu;
using otecpp_intkokoelma::IntKokoelma;
using otecpp_intkokoelma::IntPino;
using otecpp_intkokoelma::IntJono;

namespace
{ // Tulostusoperaattori IntLista-listan alkioiden tulostamiseen.
ostream & operator<<(ostream &virta, const IntLista &lista)
{
  for(IntSolmu *s = lista.paa(); s != NULL; s = s->seur())
  {
    virta << " " << s->arvo();
  }
  return virta;
}
}

int main(int argc, char *argv[])
{
  IntLista lista;  // Voidaan käsitella IntKokoelma-, IntPino- ja IntJono-oliona
  IntKokoelma &kok = lista;  // IntKokoelma-viite yllä luotuun listaan.
  IntPino &pino = lista;     // IntPino-viite yllä luotuun listaan.
  IntJono &jono = lista;     // IntJono-viite yllä luotuun listaan.
  for(int i = 1; kok.koko() < 6; ++i)
  {
    pino.pinoon(i*5);        // Lisää pinon päälle (eli listan alkuun)
    jono.jonoon(-i*3);       // Lisää jonon perään (eli listan loppuun)
  }
  cout << "Lista:" << lista << endl;
  for(bool pariton = true; !kok.onTyhja(); pariton = !pariton)
  {
    if(pariton)  // Joka toinen kierros: poisto pinosta eli listan alusta.
    {
      cout << "pinosta: " << pino.pinosta() << "\nLista:" << lista << '\n';
    }
    else         // Joka toinen kierros: poisto jonosta eli listan alusta.
    {
      cout << "jonosta: " << jono.jonosta() << "\nLista:" << lista << '\n';
    }
  }
}