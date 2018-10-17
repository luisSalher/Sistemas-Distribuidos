struct Terminos{
    double a;
    double b;
    double resultado;
};

program OPERACIONES_PROG {
    version OPERACIONES_VERS {
        struct Terminos SUMA(struct Terminos) = 1;
        struct Terminos PRODUCTO(struct Terminos) = 2;
        struct Terminos COCIENTE(struct Terminos) = 3;
    } = 1;
} = 0x31111111;
