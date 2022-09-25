#ifndef _MIDEA_H_
#define _MIDEA_H_

#include "include.h"

class Midea
{
private:

public:
    void sendMideaOpen(unsigned char A, unsigned char B, unsigned char C);
    void getcode(unsigned char A, unsigned char B, unsigned char C);
    void sendMeidi_CLOSE();
};

#ifdef __cplusplus
extern "C"
{
#endif

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
