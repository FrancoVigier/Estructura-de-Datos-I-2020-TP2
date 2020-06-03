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

bool deque_vacio(struct RangoDeque *deque) {
  return deque->ultimoNodo == NULL;
}

struct Rango deque_pop_back(struct RangoDeque *deque) {
  struct RangoDequeNode* tmp = deque->ultimoNodo;

  struct Rango elemento = deque->ultimoNodo->rango;
  deque->ultimoNodo = deque->ultimoNodo->anterior;

  if(deque->ultimoNodo != NULL) {
    deque->ultimoNodo->siguente = NULL;
  } else {
    deque->primerNodo = NULL;
  }

  free(tmp);
  return elemento;
}

struct Rango deque_pop_front(struct RangoDeque *deque) {
  struct RangoDequeNode* tmp = deque->primerNodo;

  struct Rango elemento = deque->primerNodo->rango;
  deque->primerNodo = deque->primerNodo->siguente;

  if(deque->primerNodo != NULL) {
    deque->primerNodo->anterior = NULL;
  } else {
    deque->ultimoNodo = NULL;
  }

  free(tmp);
  return elemento;
}

void deque_push_front(struct RangoDeque *deque, struct Rango rango) {
  struct RangoDequeNode* node = malloc(sizeof(struct RangoDequeNode));
  node->rango = rango;
  node->siguente = deque->primerNodo;
  node->anterior = NULL;

  if(deque->primerNodo == NULL) {
    deque->primerNodo = node;
    deque->ultimoNodo = node;
  } else {
    deque->primerNodo->anterior = node;

    deque->primerNodo = node;
  }
}