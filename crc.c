#include<stdio.h>
#include<string.h>
#include<stdint.h>


uint32_t crc_table[256];
 
/* Run this function previously */
void make_crc_table(void) {
    uint32_t i;
    for (i = 0; i < 256; i++) {
        uint32_t c = i;
        int j;
        for (j = 0; j < 8; j++) {
            c = (c & 1) ? (0xEDB88320 ^ (c >> 1)) : (c >> 1);
        }
        crc_table[i] = c;
    }
}
 
uint32_t crc32(uint8_t *buf, size_t len) {
    uint32_t c = 0xFFFFFFFF;
    size_t i;
    for (i = 0; i < len; i++) {
        c = crc_table[(c ^ buf[i]) & 0xFF] ^ (c >> 8);
    }
    return c ^ 0xFFFFFFFF;
}



