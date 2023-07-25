#ifndef MY_STRING_S21_S21_DEFINE_H
#define MY_STRING_S21_S21_DEFINE_H

#define FLOAT_MIN 1e-28
#define FLOAT_ROUND 7

#define INFin 1.0 / 0.0
#define mINFin -1.0 / 0.0

#define UNSINT 1u
#define MAXSTP 16
#define MINFLT 23
#define MAXEXP 28
#define MAXDEC 29
#define SHFbit 32
#define SHFBIT 64
#define BITVAL 96
#define MAXSTR 100
#define MAXBIT 127
#define MAXSTRs 200

#define MAXBITS 4294967295U
#define INT_MAX 2147483647
#define INT_MIN -2147483647

#define SIGN_DECIMAL_MASK 0x80000000
#define EXP1 0b00000000000000010000000000000000
#define MINUS 0b10000000000000000000000000000000
#define PLUS 0b00000000000000000000000000000000

#define MAXINT 2147483647
#define MAXLEN ".123456789"
#define MAXFLT "%.29f"
#define DEC_MAX "79228162514264337593543950335"
#define STR_0                                                                  \
  "00000000000000000000000000000000000000000000000000000000000000000000000000" \
  "0000000000000000000000000"

#define DECIMAL_ZERO \
  (s21_decimal) {    \
    { 0, 0, 0, 0 }   \
  }

typedef struct {
  int bits[4];
} s21_decimal;

enum error { ok, error };
enum sign { plus, minus };
enum bits { LOW, MIDDLE, HIGH, SCALE };
enum NumBit { OK, INF, NEGATIVE_INF, s21_NAN };
enum False_or_True { FALSE, TRUE };

#endif  // MY_STRING_S21_S21_DEFINE_H