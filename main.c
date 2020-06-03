#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <stdarg.h>
#include "arbol_avl.h"
#include "tests.h"

void impresion(struct Rango rango) {
  printf(" [%lf, %lf]", rango.a, rango.b);
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

int main(int argc, char *argv[]) {
  if(argc == 2) {
    main_tests();

    return 0;
  }

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
}
