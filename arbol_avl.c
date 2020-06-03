#include <malloc.h>
#include "arbol_avl.h"
#include "deque.h"

struct ArbolAvl *itree_crear() {
  struct ArbolAvl* avl = malloc(sizeof(struct ArbolAvl));

  return avl;
}

void itree_destruir(struct ArbolAvl *tree) {
  free(tree);
}

void itree_eliminar(struct ArbolAvl *tree, struct Rango rango) {

}

void itree_insertar(struct ArbolAvl *tree, struct Rango rango) {

}

bool itree_intersectar(struct ArbolAvl *tree, struct Rango rango) {
 return true;
}

typedef struct Rango (Popper(struct ArbolAvlDeque*)) ;

void itree_recorrer_dfs(struct ArbolAvl *arbol, Impresion impresion) {

}

void itree_recorrer_bfs(struct ArbolAvl *arbol, Impresion impresion) {

}

void itree_recorrer_fs(
  struct ArbolAvl *arbol,
  Impresion impresion,
  Popper pop
  ) {

  struct Deque* deque = deque_crear();

  deque_push_front(deque, arbol);



}