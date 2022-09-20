#ifndef SU8_UTF8_H
#define SU8_UTF8_H
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

uint8_t su8_enc_cp_to_bytes(uint32_t codepoint, char *dest);
uint8_t su8_dec_bytes_to_cp(const char src[4], uint32_t *codepoint);

#endif // SU8_UTF8_H
