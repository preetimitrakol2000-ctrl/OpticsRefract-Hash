#include <stdio.h>
#include "optics_hash.h"

extern double calculate_refraction_angle(double n1, double n2, double incident_angle_deg);

int main() {
    printf("👓 Instantiating OpticsRefract-Hash Open-Probing System Core...\n\n");

    OpticsHashTable* optics_db = create_optics_table(11);
    register_material(optics_db, "Glass", 1.52);
    register_material(optics_db, "Diamond", 2.42);

    // Retrieve material parameters from the custom hash table map
    double n_air = 1.0;
    double n_glass = lookup_refractive_index(optics_db, "Glass");

    double incident_angle = 30.0;
    double output_angle = calculate_refraction_angle(n_air, n_glass, incident_angle);

    printf("📥 Light Ray Ray-Tracing Traversal: Air ---> Glass\n");
    printf("   • Input Strike Incident Angle Boundary: %.1f°\n", incident_angle);
    printf("   • Calculated Exit Refraction Angle Result: %.2f°\n", output_angle);

    free_optics_table(optics_db);
    return 0;
}
