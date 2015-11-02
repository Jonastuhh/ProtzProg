/**
 * Prozedurale Programmierung WS 15/16
 *
 * Integer Arithmetik
 */

#include <stdio.h>
#include <stdint.h>

int main() {
  int16_t a_16, b_16, c_16;	// short int
  int64_t a_64, b_64, c_64;	// long int
  uint16_t a_u16, b_u16, c_u16;	// unsigned short int

  b_16 = a_16 = 22222;
  b_64 = a_64 = 22222;

  c_64 = a_64 + b_64;
  c_16 = a_16 + b_16;
  printf("a_64 + b_64 = %lld + %lld = %lld\n\n", a_64, b_64, c_64);    //Alle Zahlen im 64 bit Raum, somit kann das Ergebnins korrekt dargestellt werden.
  printf("a_16 + b_16 = %hd + %hd = %hd\n\n", a_16, b_16, c_16);       //Das Ergebnis ist größer als 2^15-1, Stellen werden abgeschnitten, dadurch wird bei -2^15 weitergerechnet

  a_u16 = a_16 + c_64;
  printf("a_16 + c_64 = %hd + %lld = %hu\n\n", a_16, c_64, a_u16);     //Das Ergebnis ist größer als 2^15-1, Stellen werden abgeschnitten, dadurch wird bei -2^15 weitergerechnet,
                                                                       //Ergebnis kann nur potiv sein, da a_u16

  a_u16 = 2222;
  b_u16 = -222;
  c_u16 = a_u16 + b_u16;
  printf("a_u16 + b_u16 = %hu(=%hd) + %hu(=%hd) = %hu(=%hd)\n\n", a_u16,    //-222 wird in eine positive Zahl umgewandelt (65314), Ergebnis überschreitet um 2000 den Wertebereich,
	 a_u16, b_u16, b_u16, c_u16, c_u16);                                    //die Differenz von 65314 bis 2^16 ist genau die Zahl die abgezogen wird, daher stimmt das Ergebnis dennoch

  a_64 = 555;
  b_64 = 1001;
  c_16 = c_64 = a_64 * b_64;
  printf("c_16 = c_64 = a_64 * b_64\n");                                //555*1001 ist zu groß für c_16 und wird in 16 bit konvertiert, aber nicht zu groß für c_64, Ergebnis ist richtig
  printf("%hd = %lld = %lld * %lld\n\n", c_16, c_64, a_64, b_64);
  c_64 = c_16 = a_64 * b_64;
  printf("c_64 = c_16 = a_64 * b_64\n");                                //555*1001 ist zu groß für c_16 und wird in 16 bit konvertiert, c_64 übernimmt den Wert von c_16
  printf("%lld = %hd = %lld * %lld\n\n", c_64, c_16, a_64, b_64);

  return 0;
}
