// GLIBC and Endianness checker v1.0 ..feel free to improve @unixfreaxjp, 2020
// for GNU base linux
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <gnu/libc-version.h>
enum {  ENDIAN_UNKNOWN,  // wakewakaran
        ENDIAN_BIG, ENDIAN_LITTLE,
        ENDIAN_BIG_WORD,   // Middle-type/honeywell-316
        ENDIAN_LITTLE_WORD // Middle-type/pdp-11
};
int get_endianness(void)
  { union
    { uint32_t value;
      uint8_t data[sizeof(uint32_t)];
  } number;
  number.data[0] = 0x00;  number.data[1] = 0x01; number.data[2] = 0x02;  number.data[3] = 0x03;
  switch (number.value)
  { case UINT32_C(0x00010203):if(ENDIAN_BIG){printf("Checked Endian: %s\n","BigEndian");exit(EXIT_SUCCESS);}
    case UINT32_C(0x03020100):if(ENDIAN_LITTLE){printf("Checked Endian: %s\n","LittleEndian");exit(EXIT_SUCCESS);}
    case UINT32_C(0x02030001):if(ENDIAN_BIG_WORD){printf("Checked Endian: %s\n","BigWordEndian");exit(EXIT_SUCCESS);}
    case UINT32_C(0x01000302):if(ENDIAN_LITTLE_WORD){printf("Checked Endian: %s\n","LittleWordEndian");exit(EXIT_SUCCESS);}
    default:if(ENDIAN_UNKNOWN){printf("Endian: %s\n","WakewakaranEndian");exit(EXIT_SUCCESS);}
  }
}
int main(int argc, char *argv[]) {
  printf("Checked Glibc ver: %s\n", gnu_get_libc_version());
  get_endianness();
  printf("Error: %s\n","Error happened in endianness checking..");exit(1);
}
