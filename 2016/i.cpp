#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
#include <algorithm>
using namespace std;
typedef long long ll;

const int plen = 1000;

struct Num {
  int f[2 * plen + 5];
  void clear() { fill(f, f + 2 * plen + 5, 0); }
} a, b, c;

char str[2005];
void get(Num& x) {
  x.clear();
  int dot = -1;
  scanf("%s", str);
  int len = strlen(str);
  for (int i = 0; i < len; i++) {
    if (str[i] == '.') {
      dot = i;
      break;
    }
  }
  if (dot == -1) {
    int p = plen;
    for (int i = len - 1; i >= 0; i--) {
      x.f[p] = str[i] - 'a';
      p++;
    }
  } else {
    int p = plen - 1;
    for (int i = dot + 1; str[i]; i++) {
      x.f[p] = str[i] - 'a';
      p--;
    }
    p = plen;
    for (int i = dot - 1; i >= 0; i--) {
      x.f[p] = str[i] - 'a';
      p++;
    }
  }
}

void add(Num& a, Num& b, Num& x) {
  x.clear();
  for (int i = 0; i < 2 * plen + 5; i++) {
    x.f[i] += a.f[i] + b.f[i];
    if (x.f[i] > 25) {
      x.f[i + 1] += x.f[i] / 26;
      x.f[i] %= 26;
    }
  }
}

void show(Num& x) {
  int nonZeros = plen, nonZeroe = plen;
  for (int i = 0; i < plen; i++) {
    if (x.f[i]) {
      nonZeros = i;
      break;
    }
  }
  for (int i = 2 * plen + 4; i >= plen; i--) {
    if (x.f[i]) {
      nonZeroe = i;
      break;
    }
  }
  int strp = 0;
  for (int i = nonZeroe; i >= plen; i--) {
    str[strp++] = x.f[i] + 'a';
  }
  if (nonZeros < plen) {
    str[strp++] = '.';
  }
  for (int i = plen - 1; i >= nonZeros; i--) {
    str[strp++] = x.f[i] + 'a';
  }
  str[strp] = 0;
  puts(str);
}

int main() {
  int T;
  for (scanf("%d", &T); T--;) {
    get(a);
    get(b);
    add(a, b, c);
    show(c);
  }
  return 0;
}
