#include <ParticleForceGenerator.h>
#include "ParticleForceGenerator.h"

/**
 * Force generator for gravitational force
 */

class ParticleGravity : public ParticleForceGenerator {
    // Holds the acceleration due to gravity
    Vector3 gravity;

    public:

    ParticleGravity(Vector3 &gravity);
    
    // Applies the gravitational force to the given particle
    virtual void updateForce(Particle *particle, real duration);
};