#include <stdlib.h>
#include <string.h>
#include "optics_hash.h"

OpticsHashTable* create_optics_table(int capacity) {
    OpticsHashTable* ht = (OpticsHashTable*)malloc(sizeof(OpticsHashTable));
    ht->table_capacity = capacity;
    ht->flat_table = (MaterialSlot*)calloc(capacity, sizeof(MaterialSlot));
    return ht;
}

int generate_string_hash(const char* name, int max) {
    unsigned long hash_val = 5381;
    int c;
    while ((c = *name++)) {
        hash_val = ((hash_val << 5) + hash_val) + c;
    }
    return hash_val % max;
}

void register_material(OpticsHashTable* ht, const char* name, double index) {
    int start_index = generate_string_hash(name, ht->table_capacity);
    int i = 0;

    while (i < ht->table_capacity) {
        int probe_idx = (start_index + i) % ht->table_capacity; // Linear probing step loop
        if (ht->flat_table[probe_idx].material_name[0] == '\0') {
            strcpy(ht->flat_table[probe_idx].material_name, name);
            ht->flat_table[probe_idx].refractive_index = index;
            return;
        }
        i++;
    }
}

double lookup_refractive_index(OpticsHashTable* ht, const char* name) {
    int start_index = generate_string_hash(name, ht->table_capacity);
    int i = 0;

    while (i < ht->table_capacity) {
        int probe_idx = (start_index + i) % ht->table_capacity;
        if (strcmp(ht->flat_table[probe_idx].material_name, name) == 0) {
            return ht->flat_table[probe_idx].refractive_index;
        }
        if (ht->flat_table[probe_idx].material_name[0] == '\0') {
            return 1.0; // Fallback value matching vacuum/air behavior
        }
        i++;
    }
    return 1.0;
}

void free_optics_table(OpticsHashTable* ht) {
    free(ht->flat_table);
    free(ht);
}
