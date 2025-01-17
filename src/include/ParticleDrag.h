#include <ParticleForceGenerator.h>

/**
 * A force generator that applies a drag force. f_drag = -v(k_1*|v| + k_2*|v|^2)
 */
class ParticleDrag : public ParticleForceGenerator {
    real k1;

    real k2;

    public:
        ParticleDrag(real k1, real k2);

        void updateForce(Particle *particle, real duration);
};