#include <ParticleForceGenerator.h>

class ParticleSpring : public ParticleForceGenerator {
    // The particle at the other end of the spring
    Particle *other;

    real springConstant;
    real restLength;

    public:
        ParticleSpring(Particle *other, real springConstant, real restLength);
        virtual void updateForce(Particle *particle, real duration);
};
