// -*- mode: c++; c-basic-offset: 2; indent-tabs-mode: nil; -*-
// Classic pinout before July 2015. Consider upgrading to the new pinout.
#define RGB_PARALLEL_CHAINS 3
union IoBits {
  struct {
    // This bitset reflects the GPIO mapping. The naming of the
    // pins of type 'p0_r1' means 'first parallel chain, red-bit one'
#ifdef PI_REV1_RGB_PINOUT
    // TODO(hzeller): Maybe break out this rev1 mapping. I don't have a
    // Rev1 Pi to test though, so this is it for now.
#  undef RGB_PARALLEL_CHAINS
#  define RGB_PARALLEL_CHAINS 1
    // The Revision1 and Revision2 boards have different GPIO mappings
    // on the pins 2 and 3. Just use both interpretations.
    // To keep the I2C pins free, we don't use these anymore.
    unsigned int output_enable_rev1 : 1;  // 0      (RPi 1, Revision 1)
    unsigned int clock_rev1         : 1;  // 1      (RPi 1, Revision 1)
    unsigned int output_enable_rev2 : 1;  // 2      (Pi1.Rev2; masks: I2C SDA)
    unsigned int clock_rev2         : 1;  // 3      (Pi1.Rev2; masks: I2C SCL)
#else
    unsigned int unused_0_1         : 2;  // 0..1   (only on RPi 1, Revision 1)
    unsigned int p2_g1              : 1;  // 2      (masks SDA when parallel=3)
    unsigned int p2_b1              : 1;  // 3      (masks SCL when parallel=3)
#endif
    unsigned int strobe             : 1;  // 4
    unsigned int p1_g1              : 1;  // 5      (only on A+/B+/Pi2)
    unsigned int p1_b1              : 1;  // 6      (only on A+/B+/Pi2)
    // row: 7..10, but separated as seprate bits to make it easier to shuffle
    // bits if needed.
    unsigned int a                  : 1;  // 7      (masks: SPI0_CE1)
    unsigned int b                  : 1;  // 8      (masks: SPI0_CE0)
    unsigned int c                  : 1;  // 9      (masks: SPI0_MISO)
    unsigned int d                  : 1;  // 10     (masks: SPI0_MOSI)
    unsigned int clock              : 1;  // 11     (masks: SPI0_SCKL)
    unsigned int p1_r1              : 1;  // 12     (only on A+/B+/Pi2)
    unsigned int p1_g2              : 1;  // 13     (only on A+/B+/Pi2)
    unsigned int p2_r1              : 1;  // 14     (masks TxD when parallel=3)
    unsigned int p2_r2              : 1;  // 15     (masks RxD when parallel=3)
    unsigned int e                  : 1;  // 16     (only on A+/B+/Pi2)
    unsigned int p0_r1              : 1;  // 17
    unsigned int p0_g1              : 1;  // 18
    unsigned int p1_r2              : 1;  // 19     (only on A+/B+/Pi2)
    unsigned int p1_b2              : 1;  // 20     (only on A+/B+/Pi2)
    unsigned int p2_b2              : 1;  // 21     (only on A+/B+/Pi2)
    unsigned int p0_b1              : 1;  // 22
    unsigned int p0_r2              : 1;  // 23
    unsigned int p0_g2              : 1;  // 24
    unsigned int p0_b2              : 1;  // 25
    unsigned int p2_g2              : 1;  // 26     (only on A+/B+/Pi2)
    unsigned int output_enable      : 1;  // 27     (Not on RPi1, Rev1)
  } bits;
  uint32_t raw;
  IoBits() : raw(0) {}
};
