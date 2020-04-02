#include <iostream>

#include <algorithm>

using namespace std;



int N, M;



int main()

{

  ios_base::sync_with_stdio(false);

  cin.tie(0);



  cin >> N >> M;

  if (N == 1)

    cout << 1 << "\n";

  else if (N == 2)

    cout << min(4,(M-1)/2 + 1) << "\n";

  else

  {

    if (M >= 7)

      cout << M - 2 << "\n";

    else

      cout << min(4, M) << "\n";

  }

  return 0;

}