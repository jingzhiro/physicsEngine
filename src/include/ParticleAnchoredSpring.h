#include <ParticleForceGenerator.h>

class ParticleAnchoredSpring : public ParticleForceGenerator {
    Vector3 *anchor;
    real springConstant;
    real restLength;

    public:
        ParticleAnchoredSpring(Vector3 *anchor, real springConstant, real restLength);

        virtual void updateForce(Particle *particle, real duration);
};