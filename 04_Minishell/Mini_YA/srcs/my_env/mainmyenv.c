int main() {
    char *env[] = {
        "USER=john",
        "HOME=/home/john",
        "SHELL=/bin/bash",
        NULL // Le tableau se termine par NULL
    };

    t_env *myenv;
    dupenv(&myenv, env);
    t_env *A = myenv;
    while (A != NULL) {
        printf("Variable: %s, Value: %s\n", A->variable, A->value);
        A = A->next;
    }
    return 0;
}
