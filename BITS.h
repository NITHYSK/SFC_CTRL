/**
 * BITS.H
 */

#ifndef BIT_H
#define BIT_H

#define SetOf(no)((unsigned)1 << (no))

bool IsMemb(unsigned s, int n)
{
    return s & SetOf(n);
}

void Add(unsigned *s, int n)
{
    *s |= SetOf(n);
}

void Remove(unsigned *s, int n)
{
    *s &= !SetOf(n);
}

#endif  /* BITS_H */