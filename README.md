# tieto_cstring
Plik cstring.c zawiera implementację struktury CString oraz jej API. Plik test.c zawiera testy jednostkowe: test podstawowej funkcjonalności (zwracanie char*) oraz funkcji zwracającej długość, znak na danej pozycji, zamieniającej znak, a także blokady na modyfikację po pobraniu zawartości. W katalogu projektu znajduje się również plik nagłówkowy cstring.h ze specyfikacją API.

Kompilacja na systemie Linux przy pomocy polecenia ```make``` i uruchomienie ```./test``` lub ```gcc cstring.c test.c``` i uruchomienie ```./a.out```.

Uruchomienie testów powinno wyświetlić jedynie komunikat o uruchomieniu oraz wiadomość "OK", świadczącą o pomyślnym przejściu testów (asercje spełnione). 
