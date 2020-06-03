#include "deque.h"

struct ArbolAvlDeque *deque_crear() {
  return calloc(1, sizeof(struct ArbolAvlDeque));
}

void deque_destruir(struct ArbolAvlDeque *deque) {
  while (deque->primerNodo != NULL) {
    struct ArbolAvlDequeNode* siguente = deque->primerNodo->siguente;
    free(deque->primerNodo);
    deque->primerNodo = siguente;
  }

  free(deque);
}

bool deque_vacio(struct ArbolAvlDeque *deque) {
  return deque->ultimoNodo == NULL;
}

struct ArbolAvl* deque_pop_back(struct ArbolAvlDeque *deque) {
  struct ArbolAvlDequeNode* tmp = deque->ultimoNodo;

  struct ArbolAvl* elemento = deque->ultimoNodo->arbolAvl;
  deque->ultimoNodo = deque->ultimoNodo->anterior;

  if(deque->ultimoNodo != NULL) {
    deque->ultimoNodo->siguente = NULL;
  } else {
    deque->primerNodo = NULL;
  }

  free(tmp);
  return elemento;
}

struct ArbolAvl* deque_pop_front(struct ArbolAvlDeque *deque) {
  struct ArbolAvlDequeNode* tmp = deque->primerNodo;

  struct ArbolAvl* elemento = deque->primerNodo->arbolAvl;
  deque->primerNodo = deque->primerNodo->siguente;

  if(deque->primerNodo != NULL) {
    deque->primerNodo->anterior = NULL;
  } else {
    deque->ultimoNodo = NULL;
  }

  free(tmp);
  return elemento;
}

void deque_push_front(struct ArbolAvlDeque *deque, struct ArbolAvl* arbolAvl) {
  struct ArbolAvlDequeNode* node = malloc(sizeof(struct ArbolAvlDequeNode));
  node->arbolAvl = arbolAvl;
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