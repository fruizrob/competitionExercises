//-------------------------//
//       Felipe Ruiz       //
//   felipe.ruizr@utem.cl  //
//       12/08/2017        //
//-------------------------//

#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int puntos_jp = 0, puntos_nelman = 0, mayor = 0, turno = 0, ganador = 0;
  vector<int> np;
  vector<int> ab;
  for(int i = 0; i < 2; i++){
    int aux;
    cin >> aux;
    np.push_back(aux);
  }
  for(int i = 0; i < 2; i++){
    int aux;
    cin >> aux;
    ab.push_back(aux);
  }

  while (mayor < np[0])
  {
    if (turno == 0)
    {
      if(np[1] == 1)
      {
        puntos_jp = ab[0];
        mayor = puntos_jp;
        ganador = 1;
        np[1] = 2;
      }
      else
      {
        if(np[1] == 2)
        {
          puntos_nelman = ab[1];
          mayor = puntos_nelman;
          ganador = 2;
          np[1] = 1;
        }
      }
    }
    else
    {
      if(np[1] == 1)
      {
        puntos_jp += (ab[0]+1);
        np[1] = 2;
        if (puntos_jp > mayor)
        {
          mayor = puntos_jp;
          ganador = 1;
        }
      }
      else
      {
        if(np[1] == 2)
        {
          puntos_nelman += (ab[1]+1);
          np[1] = 1;
          if (puntos_nelman > mayor)
          {
            mayor = puntos_nelman;
            ganador = 2;
          }
        }
      }
    }
    turno++;
  }
  cout << ganador << endl;
  return 0;
}
