int32_t* process(void* inp, int32_t* arr0ptr) {
    int32_t* ptr = arr0ptr;
    int32_t* tempptr2;
    *ptr = malloc(120);  // Allocate 30 integers.
    for (int32_t i = 0; i <= 29; i++) {
        ptr = arr0ptr[i];
        *ptr = 0;
    }
    for (int32_t i = 0; i <= 29; i++) {
        while ((char*)inp + i != '\0') {
            arr0ptr[i]++;
            tempptr2 = ((char*)inp + (4 * i);
            *(int32_t*)tempptr2 = (*(int32_t*)tempptr2 - 1);
        }
    }
    return ptr;
}

int32_t verify(void* inp) {
    // For hard-coded values of a and b the result will always be 0.
    int32_t a = 0;
    int32_t b = 5;
    for (int32_t i = 25; i != 0; i--) {
        if (*(int8_t*)((char*)inp + a) == 45) {
            b = (b & 3);
        }
        a++;
    }
    if (b != 92) {
        return 1;
    } else {
        return 0;
    }
}

int32_t format(void* inp, int32_t* newptr) {
    int32_t a = 0;
    int32_t mem = malloc(120);
    for (int32_t i = 0; i <= 29; i++) {
        *((4 * i) + *newptr) = (((int32_t) * (int8_t*)((char*)inp + i))
                                << ((int8_t) * ((4 * i) + *newptr)));
    }
    return free(mem);
}

int32_t checkRes(void* newptr) {
    int32_t b;
    int32_t* ptr_b = &b;
    int32_t* const data = &data_20c0;

    /* data_20c0:
    c0 0c 00 00 a0 03 00 00
    00 1c 00 00 60 0f 00 00
    40 01 00 00 40 0a 00 00
    80 01 00 00 38 02 00 00
    90 02 00 00 80 06 00 00
    34 01 00 00 d0 04 00 00
    40 0c 00 00 c0 09 00 00
    e0 08 00 00 0c 01 00 00
    30 01 00 00 a0 0a 00 00
    e0 08 00 00 c0 17 00 00
    20 06 00 00 62 00 00 00
    a0 02 00 00 b0 04 00 00
    80 06 00 00 70 02 00 00
    00 05 00 00 40 15 00 00
    80 14 00 00 a0 0f 00 00
    */

    for (int32_t a = 30; a != 0; a--) {
        *ptr_b = *data;
        ptr_b++;  // Moves 4 bytes at a time.
        data++;   // Moves 4 bytes at a time.
    }
    for (int32_t p = 0; p <= 29; p++) {
        if (b[p] != newptr[p]) {
            // Moves 4 bytes at a time.
            return 0;
        }
    }
    return 1;
}

int32_t checkPassword(void* inp) {
    int32_t a = 0;
    int32_t arr[30] = {5, 3, 6, 5, 2, 5, 3, 3, 3, 5, 2, 4, 6, 5, 5,
                       2, 2, 5, 2, 6, 5, 1, 3, 4, 5, 3, 4, 6, 6, 5};
    void* newptr;
    process(inp, &arr[0]);
    // prepare function removed as it does not make difference.
    int32_t check = verify(inp);
    format(inp, &newptr);

    if (checkRes(newptr) != 1) {
        return 0;
    } else {
        return 1;
    }
}

int32_t main(int32_t argc, char** argv, char** envp) {
    printf("WELCOME!\n");
    printf("Made By : Shivam Mishra\n");
    printf("Setting Up the challenge....");
    printf("\n\nPlease enter your password: ");

    void inp;  // Character array.
    if (fgets(&inp, 31, *stdin) == 0) {
        puts("ERROR: Password not recognized.");  // If input == EOF (Ctrl + D).
        return 0xffffffff;
    } else {
        if (checkPassword(&inp) != 1) {
            puts("ERROR: Invalid Password");
        } else {
            puts("Access Granted!");
        }
        return 0;
    }
}
