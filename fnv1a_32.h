struct fnv1a_32 {
    uint32_t sum32a;
};

struct fnv1a_32* FNV1a32_New() {
    struct fnv1a_32* fnv = (struct fnv1a_32*)malloc(sizeof(struct fnv1a_32));
    if (fnv)
        fnv->sum32a = 0x811c9dc5;
    return fnv;
}

void FNV1a32_Free(struct fnv1a_32* fnv32a) {
    free(fnv32a);
}

void FNV1a32_Write(struct fnv1a_32* fnv, const char* data, size_t len) {
    uint32_t hash = fnv->sum32a;
    for (size_t i = 0; i < len; i++) {
        hash ^= (uint8_t)data[i];
        hash *= 0x01000193;
    }
    fnv->sum32a = hash;
}

uint32_t FNV1a32_Sum(struct fnv1a_32* fnv) {
    return fnv->sum32a;
}