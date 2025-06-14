// Copyright 2022 NNTU-CS
#include <cstdint>
#include "alg.h"



bool checkPrime(uint64_t value) {
  if (value < 2) return false;
  for (int i = 2; i * i <= value; i++) {
    if (value % i == 0) return false;
  }
  return true;
}

uint64_t nPrime(uint64_t n) {
  int s = 1;
  int num = 2;
  if (n == 1) return 2;
  while (s < n) {
    num++;
    if (checkPrime(num) == true) s++;
  }
  return num;
}

uint64_t nextPrime(uint64_t value) {
  value += 1;
  while (checkPrime(value) != true) {
    value++;
  }
  return value;
}

uint64_t sumPrime(uint64_t hbound) {
  uint64_t first = 2;
  uint64_t sum = 0;
  if (hbound <= 2) return 0;
  while (first < hbound) {
    sum += first;
    first = nextPrime(first);
  }
  return sum;
}

uint64_t twinPrimes(uint64_t lbound, uint64_t hbound) {
  int count = 0;
  for (int i = lbound; i < hbound; i++) {
    if ((checkPrime(i) == true) && (checkPrime(i+2) == true)) count++;
  }
  return count;
}
