#include <Core.h>
#include <Particle.h>
#include <ParticleForceGenerator.h>
#include <vector>

/**
 * Interface to add a force to one or more particles
 */
class ParticleForceRegistry {
    protected:
        // Keeps track of one force generator and the particle it applies to
        struct ParticleForceRegistration {
            Particle *particle;
            ParticleForceGenerator *fg;
        };

        // Holds the list of registrations
        typedef std::vector<ParticleForceRegistration> Registry;
        Registry registrations;

    public:
        /**
         * Registers/removes the given force generator to apply to the given particle
         */
        void add(Particle *particle, ParticleForceGenerator *fg);
        void remove(Particle *particle, ParticleForceGenerator *fg);
        
        // Clears registry. Does not delete the particles or the force generators, just the record
        void clear();

        // Calls all the force generators to update the forces of their corresponding particles
        void updateForces(real duration);
};