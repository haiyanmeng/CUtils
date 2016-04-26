#ifndef BIT_UTILS_H
#define BIT_UTILS_H

/* net_value returns the negative value of a through bit operations */
int neg_value(int a);

/* count_one counts the number of 1 bits in the binary representation of a */
int count_one(unsigned long a);

/* swap_bits swaps the ath bit and the bth bit of x
 * 0 <= a,b <= 63
 */
unsigned long swap_bits(unsigned long x, int a, int b);

/* print_bits prints an unsigned long in binary format */
void print_bits(unsigned long x);
#endif

