#include <ParticleForceGenerator.h>

class ParticleBungee : public ParticleForceGenerator {
    Particle *other;
    real springConstant;
    real restLength;

    public:
        ParticleBungee(Particle *other, real springConstant, real restLength);

        virtual void updateForce(Particle *particle, real duration);
};