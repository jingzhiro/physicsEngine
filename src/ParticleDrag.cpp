#include <ParticleDrag.h>

ParticleDrag::ParticleDrag(real k1, real k2)
{
}

void ParticleDrag::updateForce(Particle *particle, real duration)
{
    Vector3 force;
    particle->getVelocity(&force);

    real dragCoeff = force.magnitude();
    dragCoeff = k1 * dragCoeff + k2 * dragCoeff * dragCoeff;

    force.normalise();
    force *= -dragCoeff;
    particle->addForce(force);
}