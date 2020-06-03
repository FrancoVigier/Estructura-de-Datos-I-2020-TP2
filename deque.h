#ifndef ESTRUCTURA_DE_DATOS_I_2020_TP2_DEQUE_H
#define ESTRUCTURA_DE_DATOS_I_2020_TP2_DEQUE_H

#include <malloc.h>
#include "arbol_avl.h"

//INICIO <-> <-> <-> FINAL
struct ArbolAvlDequeNode {
  struct ArbolAvl* arbolAvl;
  struct ArbolAvlDequeNode* siguente;
  struct ArbolAvlDequeNode* anterior;
};

struct ArbolAvlDeque {
  struct ArbolAvlDequeNode* primerNodo;
  struct ArbolAvlDequeNode* ultimoNodo;
};

struct ArbolAvlDeque* deque_crear();

void deque_destruir(struct ArbolAvlDeque* deque);

bool deque_vacio(struct ArbolAvlDeque *deque);

void deque_push_front(struct ArbolAvlDeque* deque, struct ArbolAvl* arbolAvl);

struct ArbolAvl* deque_pop_front(struct ArbolAvlDeque* deque);

struct ArbolAvl* deque_pop_back(struct ArbolAvlDeque* deque);

#endif //ESTRUCTURA_DE_DATOS_I_2020_TP2_DEQUE_H
