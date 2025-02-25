/* ProszÄ™ dopisaÄ‡ kod, dodaÄ‡ nowe pliki, tak aby program siÄ™ wykonywaĹ‚
   a wynik jego dziaĹ‚ania byĹ‚ taki sam, jak podany na koĹ„cu tego pliku.

   Celem zadania jest napisanie kilku klas zwiÄ…zanych relacjÄ…
   dziedziczenia.  Klasy te opisujÄ… elementarne ksztaĹ‚ty. KaĹĽdy ksztaĹ‚t
   ma jakieĹ› polimorficzne metody i koniecznÄ… infrastrukturÄ™.

   UWAGA: Przed rozpoczeciem zadania proszÄ™ przeanalizowaÄ‡ kod programu do koĹ„ca.
   WskazĂłwka: Wzor na pole trojkata: sqrt(x(x-a)(x-b)(x-c))
   gdzie "x" to poĹ‚owa obwodu trĂłjkata.

 * ProszÄ™ pamietaÄ‡ o dokumentacji kodu.
 * Skonfiguruj plik konfiguracyjny cmake albo napisz Makefile tak, aby:
   - plikiem wynikowym byĹ‚ main
   - program kompilowaĹ‚ siÄ™ z flagami -Wall -g - pedantic.
   - byĹ‚y zdefiniowane cele uĹĽytkownika run, clean, check oraz all (main+run)
 */

#include "circle.h"
#include "rectangle.h"
#include "triangle.h"
int main() {
	
	Rectangle r(4, 2);
	Triangle t(3, 2, 4);
	Circle c(3);
	Shape::print(r); // Prostokat o bokach: 4 2
	Shape::print(t); // Trojkat o bokach: 3 2 4
	Shape::print(c); // Kolo o promieniu: 3

	Shape* b = new Rectangle(7, 2);
	Shape::print(*b);
	delete b;

	b = new Circle(7);
	Shape::print(*b);
	delete b;
	const Shape* all[] = { &r, &r, &c, &t, &c }; // obiekty powtorzone celowo
	for (unsigned idx = 0; idx < sizeof(all) / sizeof(Shape*); ++idx) {
		const Shape* k = all[idx];
		k->print(std::cout);
		double area = k->area();
		std::cout << area << std::endl;
	}
}
/* Oczekiwany wynik ./main
Prostokat o bokach: 4 2
Trojkat o bokach: 3 2 4
Kolo o promieniu: 3
Prostokat o bokach: 7 2
Kolo o promieniu: 7
Prostokat o bokach: 4 2
8
Prostokat o bokach: 4 2
8
Kolo o promieniu: 3
28.2743
Trojkat o bokach: 3 2 4
2.90474
Kolo o promieniu: 3
28.2743

 */