#include "operaciones.h"

struct Terminos suma(struct Terminos term) {
    return term.i + term.j;
}

struct Terminos producto(struct Terminos term) {
    return term.i * term.j;
}

struct Terminos cociente(struct Terminos term) {
    return term.i / (float) term.j;
}