#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdarg.h>
#include "arbol_avl.h"

void impresion(const unsigned int n, ...) {
  va_list args;
  va_start(args, n);
  for (int i = 0; i < n; i++) {
    struct Rango rango = va_arg(args, struct Rango);
    printf("[%lf, %lf]", rango.a, rango.b);
  }
  va_end(args);
}

struct Rango escanearRango(char* entrada) {
  double a, b;
  sscanf(entrada, "[%lf, %lf]", &a, &b);
  return (struct Rango) {.a =  a, .b =  b};
}

bool procesar(char* entrada, struct ArbolAvl* arbol) {
  char c;
  sscanf(entrada, "%c", &c);

  switch (c) {
    case 'i': {
      struct Rango rango = escanearRango(entrada);
      itree_insertar(arbol, rango);
    }
      break;
    case 'e':{
      struct Rango rango = escanearRango(entrada);
      itree_eliminar(arbol, rango);
    }
      break;
    case '?':{
      struct Rango rango = escanearRango(entrada);
      bool intersecta = itree_intersectar(arbol, rango);
      printf(intersecta? "Si":"No");
    }
      break;
    case 'b':
      itree_recorrer_bfs(arbol, impresion);
      break;
    case 'd':
      itree_recorrer_dfs(arbol, impresion);
      break;
    case 's':
      return true;
  }
  return false;
}

int main() {
  struct ArbolAvl* arbol = itree_crear();
  bool sigue = true;

  while (sigue) {
    char *entrada = malloc(1024 * sizeof(char));
    entrada = fgets(entrada, 1024, stdin);
    if (entrada != NULL) {
      sigue = !procesar(entrada, arbol);
      free(entrada);
    }
  }

	return 0;
}
