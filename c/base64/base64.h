#ifndef __BASE64_H__
#define __BASE64_H__

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern unsigned int base64Encode(const unsigned char *in, unsigned int inlen, char *out);
extern unsigned int base64Decode(const char *in, unsigned int inlen, unsigned char *out);

#endif /* __BASE64_H__ */
