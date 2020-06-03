#include <assert.h>
#include "tests.h"
#include "deque.h"

void test_deque_pila() {
  struct ArbolAvlDeque* deque = deque_crear();

  deque_push_front(deque, 1);
  deque_push_front(deque, 2);
  deque_push_front(deque, 3);
  deque_push_front(deque, 4);

  assert(deque_pop_front(deque) == 4);
  assert(deque_pop_front(deque) == 3);
  assert(deque_pop_front(deque) == 2);
  deque_push_front(deque, 4);
  assert(deque_pop_front(deque) == 4);
  assert(deque_pop_front(deque) == 1);

  assert(deque_vacio(deque));

  deque_destruir(deque);
}

void test_deque_cola() {
  struct ArbolAvlDeque* deque = deque_crear();

  deque_push_front(deque, 1);
  deque_push_front(deque, 2);
  deque_push_front(deque, 3);
  deque_push_front(deque, 4);

  assert(deque_pop_back(deque) == 1);
  assert(deque_pop_back(deque) == 2);
  assert(deque_pop_back(deque) == 3);
  deque_push_front(deque, 1);
  assert(deque_pop_back(deque) == 4);
  assert(deque_pop_back(deque) == 1);

  assert(deque_vacio(deque));

  deque_destruir(deque);
}

void main_tests() {
  test_deque_pila();
  test_deque_cola();
}
