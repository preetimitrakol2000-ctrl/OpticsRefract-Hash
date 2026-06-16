#include <math.h>
#include "optics_hash.h"

double calculate_refraction_angle(double n1, double n2, double incident_angle_deg) {
    double rad = incident_angle_deg * (3.14159265 / 180.0);
    double sin_theta2 = (n1 / n2) * sin(rad);
    if (sin_theta2 > 1.0) return -1.0; // Total Internal Reflection match state indicator
    return asin(sin_theta2) * (180.0 / 3.14159265);
}
