#include <Core.h>
#include <Particle.h>
#include <vector>

class ParticleForceGenerator {
    public:
        /**
         * Overload this in implementations of the interface to calculate
         * and update the force applied to the given particle.
         */
        virtual void updateForce(Particle *particle, real duration) = 0;
};