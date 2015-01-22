#ifndef _AES_H
#define _AES_H

#ifdef __cplusplus
extern "C" {
#endif

int aes_init(unsigned char *key, unsigned int key_len);

int aes_encrypt(unsigned char *src, unsigned int src_len, unsigned char *dest);

int aes_decrypt(unsigned char *src, unsigned int src_len, unsigned char *dest);

void aes_close();

#ifdef __cplusplus
}
#endif

#endif  //_AES_H