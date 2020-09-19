#include "hamm.h"

/*Hamm::Hamm()
{

}*/
QByteArray Hamm::InHamm(const QByteArray mess)
{
    QByteArray messHamm;
    messHamm.resize(mess.size()*2);
    PBYTE byteHamm = new BYTE[2];
    for(int i = 0; i < mess.size(); i++)
    {
        memset(byteHamm, 0, 2);
        SetBit0(byteHamm, 0);
        SetBit0(byteHamm, 1);
        SetBit(byteHamm, (PBYTE)(mess.data() + sizeof(BYTE)*i), 2, 0);
        SetBit0(byteHamm, 3);
        SetBit(byteHamm, (PBYTE)(mess.data() + sizeof(BYTE)*i), 4, 1);
        SetBit(byteHamm, (PBYTE)(mess.data() + sizeof(BYTE)*i), 5, 2);
        SetBit(byteHamm, (PBYTE)(mess.data() + sizeof(BYTE)*i), 6, 3);
        SetBit0(byteHamm, 7);
        SetBit(byteHamm, (PBYTE)(mess.data() + sizeof(BYTE)*i), 8, 4);
        SetBit(byteHamm, (PBYTE)(mess.data() + sizeof(BYTE)*i), 9, 5);
        SetBit(byteHamm, (PBYTE)(mess.data() + sizeof(BYTE)*i), 10, 6);
        SetBit(byteHamm, (PBYTE)(mess.data() + sizeof(BYTE)*i), 11, 7);
        SetBit0(byteHamm, 12);
        SetBit0(byteHamm, 13);
        SetBit0(byteHamm, 14);
        SetBit0(byteHamm, 15);

        //check bit computation
        int sum = 0;
        //computation of the first check bit
        for(int j = 0; j < 16; j += 2)
        {
            if(GetBit(byteHamm, (WORD)j) == 1)
                sum++;
        }
        if (sum % 2 == 0)
        {
            SetBit1(byteHamm, 0);
        }

        //computation of the second check bit
        sum = 0;
        for(int j = 1; j < 16; j += 3)
        {
            if(GetBit(byteHamm, (WORD)j) == 1)
                sum++;
            j++;
            if(j >= 16) break;
            if(GetBit(byteHamm, (WORD)j) == 1)
                sum++;
        }
        if (sum % 2 == 0)
        {
            SetBit1(byteHamm, 1);
        }

        //computation of the third check bit
        sum = 0;
        for(int j = 3; j < 16; j += 4)
        {
            for(int k = 0; k < 4; k++)
            {
                if(GetBit(byteHamm, (WORD)j) == 1)
                    sum++;
                j++;
                if(j >= 16) break;
            }
        }
        if (sum % 2 == 0)
        {
            SetBit1(byteHamm, 3);
        }

        //calculating the fourth check bit
        sum = 0;
        for(int j = 7; j < 16; j += 8)
        {
            for(int k = 0; k < 8; k++)
            {
                if(GetBit(byteHamm, (WORD)j) == 1)
                    sum++;
                j++;
                if(j >= 16) break;
            }
        }
        if (sum % 2 == 0)
        {
            SetBit1(byteHamm, 7);
        }
        memcpy(messHamm.data() + i*2, byteHamm, 2);
    }
    delete []byteHamm;
    return messHamm;
}
QByteArray Hamm::FromHamm(const QByteArray messHamm)
{
    QByteArray mess;
    mess.resize(messHamm.size()/2);
    PBYTE byteHamm = new BYTE[2];
    PBYTE byteHammCmp = new BYTE[2];
    BYTE byteMess = 0;
    for(int i = 0; i < messHamm.size(); i+=2)
    {
        memset(byteHamm, 0, 2);
        memset(byteHammCmp, 0, 2);
        memcpy(byteHamm, messHamm.data() + i, 2);
        memcpy(byteHammCmp, messHamm.data() + i, 2);

        SetBit0(byteHamm, 0);
        SetBit0(byteHamm, 1);
        SetBit0(byteHamm, 3);
        SetBit0(byteHamm, 7);
        SetBit0(byteHamm, 12);
        SetBit0(byteHamm, 13);
        SetBit0(byteHamm, 14);
        SetBit0(byteHamm, 15);

        //check bit computation
        int sum = 0;
        //computation of the first check bit
        for(int j = 0; j < 16; j += 2)
        {
            if(GetBit(byteHamm, (WORD)j) == 1)
                sum++;
        }
        if (sum % 2 == 0)
        {
            SetBit1(byteHamm, 0);
        }

        //computation of the second check bit
        sum = 0;
        for(int j = 1; j < 16; j += 3)
        {
            if(GetBit(byteHamm, (WORD)j) == 1)
                sum++;
            j++;
            if(j >= 16) break;
            if(GetBit(byteHamm, (WORD)j) == 1)
                sum++;
        }
        if (sum % 2 == 0)
        {
            SetBit1(byteHamm, 1);
        }

        //computation of the third check bit
        sum = 0;
        for(int j = 3; j < 16; j += 4)
        {
            for(int k = 0; k < 4; k++)
            {
                if(GetBit(byteHamm, (WORD)j) == 1)
                    sum++;
                j++;
                if(j >= 16) break;
            }
        }
        if (sum % 2 == 0)
        {
            SetBit1(byteHamm, 3);
        }

        //calculating the fourth check bit
        sum = 0;
        for(int j = 7; j < 16; j += 8)
        {
            for(int k = 0; k < 8; k++)
            {
                if(GetBit(byteHamm, (WORD)j) == 1)
                    sum++;
                j++;
                if(j >= 16) break;
            }
        }
        if (sum % 2 == 0)
        {
            SetBit1(byteHamm, 7);
        }
        sum = 0;
        if(GetBit(byteHamm, 0) != GetBit(byteHammCmp, 0))
            sum ++;
        if(GetBit(byteHamm, 1) != GetBit(byteHammCmp, 1))
            sum += 2;
        if(GetBit(byteHamm, 3) != GetBit(byteHammCmp, 3))
            sum += 4;
        if(GetBit(byteHamm, 7) != GetBit(byteHammCmp, 7))
            sum += 8;

        if(sum != 0)
        {
            if (GetBit(byteHammCmp, (sum - 1)) == 0)
                SetBit1(byteHammCmp, sum - 1);
            else SetBit0(byteHammCmp, sum - 1);
        }
        SetBit(&byteMess, byteHammCmp, 0, 2);
        SetBit(&byteMess, byteHammCmp, 1, 4);
        SetBit(&byteMess, byteHammCmp, 2, 5);
        SetBit(&byteMess, byteHammCmp, 3, 6);
        SetBit(&byteMess, byteHammCmp, 4, 8);
        SetBit(&byteMess, byteHammCmp, 5, 9);
        SetBit(&byteMess, byteHammCmp, 6, 10);
        SetBit(&byteMess, byteHammCmp, 7, 11);
        mess.data()[i/2] = byteMess;
    }
    delete []byteHamm;
    delete []byteHammCmp;
    return mess;
}
void Hamm::SetBit1(PBYTE pMem, WORD dwNumBit)
{
    const BYTE BM[] =            // running unit
      {1,2,4,8,16,32,64,128};
    pMem[dwNumBit>>3] |= BM[dwNumBit & 7];
}

// Установить ноль
void Hamm::SetBit0(PBYTE pMem, WORD dwNumBit)
{
    const BYTE BM[] =            // running unit
      {1,2,4,8,16,32,64,128};
    pMem[dwNumBit>>3] &= (BYTE)~BM[dwNumBit & 7];
}
BYTE Hamm::GetBit(PBYTE pMem, WORD dwNumBit)
{
    const BYTE BM[] =            // running unit
      {1,2,4,8,16,32,64,128};
    return (BYTE)((pMem[dwNumBit >> 3] & BM[dwNumBit & 7]) ? 1 : 0);
}

void Hamm::SetBit(PBYTE m1, PBYTE m2, WORD num1, WORD num2) //checking the bit num2 in the message
{                                                           //and insert into m1 num1
    if(GetBit(m2, num2) == 1)
    {
        SetBit1(m1, num1);
    }
    else if (GetBit(m2, num2) == 0)
    {
        SetBit0(m1, num1);
    }
}

