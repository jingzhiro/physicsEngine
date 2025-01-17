#include <ParticleAnchoredSpring.h>

ParticleAnchoredSpring::ParticleAnchoredSpring(Vector3 *anchor, real springConstant, real restLength) : anchor(anchor), springConstant(springConstant), restLength(restLength) {}

void ParticleAnchoredSpring::updateForce(Particle *particle, real duration)
{
    Vector3 force;
    particle->getPosition(&force);
    force -= *anchor;

    real magnitude = force.magnitude();
    magnitude = real_abs(magnitude - restLength);
    magnitude *= springConstant;

    force.normalise();
    force *= -magnitude;
    particle->addForce(force);
}