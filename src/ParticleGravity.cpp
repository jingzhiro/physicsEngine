#include <ParticleGravity.h>

ParticleGravity::ParticleGravity(Vector3 &gravity) : gravity(gravity) {}

void ParticleGravity::updateForce(Particle *particle, real duration)
{
    if (!particle->hasFiniteMass()) return;
    particle->addForce(gravity * particle->getMass());
}