#ifndef HAMM_H
#define HAMM_H

#include <QByteArray>

typedef unsigned char            BYTE;
typedef unsigned short int       WORD;
typedef unsigned       int       DWORD;
typedef unsigned char          * PBYTE;

class Hamm
{
public:
    Hamm() {};
    static QByteArray InHamm(const QByteArray mess);
    static QByteArray FromHamm(const QByteArray mess);
    static void SetBit1(PBYTE pMem, WORD dwNumBit);
    static void SetBit0(PBYTE pMem, WORD dwNumBit);
    static BYTE GetBit(PBYTE pMem, WORD dwNumBit);
    static void SetBit(PBYTE m1, PBYTE m2, WORD num1, WORD num2);
};

#endif // HAMM_H
