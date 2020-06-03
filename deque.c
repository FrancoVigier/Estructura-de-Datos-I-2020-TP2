#include "deque.h"

struct RangoDeque *deque_crear() {
  return calloc(1, sizeof(struct RangoDeque));
}

void deque_destruir(struct RangoDeque *deque) {
  while (deque->primerNodo != NULL) {
    struct RangoDequeNode* siguente = deque->primerNodo->siguente;
    free(deque->primerNodo);
    deque->primerNodo = siguente;
  }

  free(deque);
}

struct Rango deque_pop_back(struct RangoDeque *deque) {
  struct RangoDequeNode* tmp = deque->ultimoNodo;

  struct Rango elemento = deque->ultimoNodo->rango;
  deque->ultimoNodo = deque->ultimoNodo->anterior;

  free(tmp);
  return elemento;
}

struct Rango deque_pop_front(struct RangoDeque *deque) {
  struct RangoDequeNode* tmp = deque->primerNodo;

  struct Rango elemento = deque->primerNodo->rango;
  deque->primerNodo = deque->primerNodo->siguente;

  free(tmp);
  return elemento;
}

void deque_push_front(struct RangoDeque *deque, struct Rango rango) {
  struct RangoDequeNode* node = malloc(sizeof(struct RangoDequeNode));
  node->rango = rango;
  node->siguente = deque->primerNodo;

  deque->primerNodo->anterior = node;

  deque->primerNodo = node;
}