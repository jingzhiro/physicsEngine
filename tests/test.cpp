#include "../src/include/Particle.h"
#include "../src/include/ParticleDrag.h"
#include "../src/include/ParticleGravity.h"
#include "../src/include/ParticleSpring.h"
#include "../src/include/ParticleForceRegistry.h"

int main() {
    Particle a, b;
    ParticleForceRegistry registry;

    ParticleSpring ps(&b, 1.0f, 2.0f);
    registry.add(&a, &ps);
}