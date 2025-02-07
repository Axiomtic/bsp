#ifndef BSP_CRC32_H
#define BSP_CRC32_H
//#include "struct_typedef.h"
#include "stm32f4xx_hal.h"
extern uint32_t get_crc32_check_sum(uint32_t *data, uint32_t len);
extern unsigned char  verify_crc32_check_sum(uint32_t *data, uint32_t len);
extern void append_crc32_check_sum(uint32_t *data, uint32_t len);

#endif
