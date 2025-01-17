#include <assert.h>
#include <particle.h>

void Particle::integrate(real duration) {
    assert(duration > 0.0);

    // s = s_0 + v * t
    position.addScaledVector(velocity, duration);

    // v' = v * d^t + a * t
    Vector3 resultingAcc = acceleration;
    resultingAcc.addScaledVector(forceAccum, inverseMass);

    // Update linear velocity from 
    velocity.addScaledVector(resultingAcc, duration);

    // Impose drag
    velocity *= real_pow(damping, duration);

    clearAccumulator();
}

void Particle::clearAccumulator() {
    forceAccum = Vector3(0, 0, 0);
}

void Particle::addForce(const Vector3 &force) {
    forceAccum += force;
}