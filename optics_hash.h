#ifndef OPTICS_HASH_H
#define OPTICS_HASH_H

typedef struct {
    char material_name[20];
    double refractive_index;
} MaterialSlot;

typedef struct {
    MaterialSlot* flat_table;
    int table_capacity;
} OpticsHashTable;

OpticsHashTable* create_optics_table(int capacity);
void register_material(OpticsHashTable* ht, const char* name, double index);
double lookup_refractive_index(OpticsHashTable* ht, const char* name);
void free_optics_table(OpticsHashTable* ht);

#endif
