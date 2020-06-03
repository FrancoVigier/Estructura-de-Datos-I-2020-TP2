#ifndef ESTRUCTURA_DE_DATOS_I_2020_TP2_DEQUE_H
#define ESTRUCTURA_DE_DATOS_I_2020_TP2_DEQUE_H

#include <malloc.h>
#include "arbol_avl.h"

//INICIO <-> <-> <-> FINAL
struct RangoDequeNode {
  struct Rango rango;
  struct RangoDequeNode* siguente;
  struct RangoDequeNode* anterior;
};

struct RangoDeque {
  struct RangoDequeNode* primerNodo;
  struct RangoDequeNode* ultimoNodo;
};

struct RangoDeque* deque_crear();

void deque_destruir(struct RangoDeque* deque);

bool deque_vacio(struct RangoDeque *deque);

void deque_push_front(struct RangoDeque* deque, struct Rango rango);

struct Rango deque_pop_front(struct RangoDeque* deque);

struct Rango deque_pop_back(struct RangoDeque* deque);

#endif //ESTRUCTURA_DE_DATOS_I_2020_TP2_DEQUE_H
