#include <ParticleBungee.h>

ParticleBungee::ParticleBungee(Particle *other, real springConstant, real restLength) : other(other), springConstant(springConstant), restLength(restLength) {}

void ParticleBungee::updateForce(Particle *particle, real duration) {
    Vector3 force;
    particle->getPosition(&force);
    force -= other->getPosition();

    // Checks if bungee is compressed
    real magnitude = force.magnitude();
    if (magnitude <= restLength) return;

    magnitude = springConstant * (restLength - magnitude);

    force.normalise();
    force *= -magnitude;
    particle->addForce(force);
}
