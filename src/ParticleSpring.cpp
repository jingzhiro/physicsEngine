#include <ParticleForceGenerator.h>
#include "ParticleSpring.h"

ParticleSpring::ParticleSpring(Particle *other, real springConstant, real restLength)
    : other(other), springConstant(springConstant), restLength(restLength)
{
}

void ParticleSpring::updateForce(Particle *particle, real duration)
{
    Vector3 force;
    particle->getPosition(&force);
    force -= other->getPosition();

    real magnitude = force.magnitude();
    magnitude = real_abs(magnitude - restLength);
    magnitude *= springConstant;

    force.normalise();
    force *= -magnitude;
    particle->addForce(force);
}