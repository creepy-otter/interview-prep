#include <iostream>

int main() {
  /* An object of empty class allocates 1 byte by the compiler for its unique
   * address identification. */

  class EmptyClass {
  } emptyClass;
  std::cout << "Size of empty class: " << sizeof(emptyClass) << std::endl;

  /* The offset of the starting address of the variable relative to the starting
   * address of the structure must be a multiple of the number of bytes occupied
   * by the type of the variable. */

  /* To ensure that the size of the structure is a multiple of the number of
   * bytes occupied by the type that has the largest space in structure, the
   * vacant space will be filled after applying for space for the last member
   * variable.
   */

  /* Type, sizeof
   * char, 1
   * int, 4
   * short int, 2
   * float, 4
   * double, 8
   * pointer, 8 (64-bit)
   */

  /* 1 (char) + 1 (padding for short int) + 2 (short int) = 4 */
  struct CharAndShort {
    char c;
    short int i;
  } cas;
  std::cout << "Size of struct char and short: " << sizeof(cas) << std::endl;

  /* 2 (short int) + 1 (char) + 1 (aligned with largest type -> short int) = 4
   */
  struct ShortAndChar {
    short int i;
    char c;
  } sac;
  std::cout << "Size of struct short and char: " << sizeof(sac) << std::endl;

  /* 1 (char) + 7 (padding for double) + 8 (double) + 4 (int) + 4 (aligned with
   * largest type -> double) = 24 */
  struct ComplexStruct {
    char c;
    double d;
    int i;
  } cs;
  std::cout << "Size of struct char, double and int: " << sizeof(cs)
            << std::endl;

  return 0;
}