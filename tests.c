#include <assert.h>
#include "tests.h"
#include "deque.h"

void test_deque_pila() {
  struct RangoDeque* deque = deque_crear();

  deque_push_front(deque, (struct Rango) {.a = 1, .b = 1});
  deque_push_front(deque, (struct Rango) {.a = 2, .b = 2});
  deque_push_front(deque, (struct Rango) {.a = 3, .b = 3});
  deque_push_front(deque, (struct Rango) {.a = 4, .b = 4});

  assert(deque_pop_front(deque).a == 4);
  assert(deque_pop_front(deque).a == 3);
  assert(deque_pop_front(deque).a == 2);
  deque_push_front(deque, (struct Rango) {.a = 4, .b = 4});
  assert(deque_pop_front(deque).a == 4);
  assert(deque_pop_front(deque).a == 1);

  assert(deque_vacio(deque));

  deque_destruir(deque);
}

void test_deque_cola() {
  struct RangoDeque* deque = deque_crear();

  deque_push_front(deque, (struct Rango) {.a = 1, .b = 1});
  deque_push_front(deque, (struct Rango) {.a = 2, .b = 2});
  deque_push_front(deque, (struct Rango) {.a = 3, .b = 3});
  deque_push_front(deque, (struct Rango) {.a = 4, .b = 4});

  assert(deque_pop_back(deque).a == 1);
  assert(deque_pop_back(deque).a == 2);
  assert(deque_pop_back(deque).a == 3);
  deque_push_front(deque, (struct Rango) {.a = 1, .b = 1});
  assert(deque_pop_back(deque).a == 4);
  assert(deque_pop_back(deque).a == 1);

  assert(deque_vacio(deque));

  deque_destruir(deque);
}

void main_tests() {
  test_deque_pila();
  test_deque_cola();
}
