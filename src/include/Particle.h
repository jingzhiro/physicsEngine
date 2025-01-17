#include <Core.h>

class Particle
{
protected:
    /**
     * More useful to have objects with infinite mass (immovable) than zero mass 
     * (unstable in numerical simulation)
     */
    real inverseMass;
public:
    Vector3 position, velocity, acceleration, forceAccum;

    /**
     *  Required to remove energy added through numerical instability in the integrator, 
     *  values near but less than 1 are optimal for no drag
     */
    real damping;

    void setPosition(real x, real y, real z) {
        (*this).position = Vector3(x, y, z);
    }
        
    void setVelocity(real x, real y, real z) {
        (*this).velocity = Vector3(x, y, z);
    }

    void setAcceleration(real x, real y, real z) {
        (*this).acceleration = Vector3(x, y, z);
    }

    void setDamping(real damping) {
        (*this).damping = damping;
    }
    
    void setInverseMass(real inverseMass) {
        (*this).inverseMass = inverseMass;
    }

    void setMass(real mass) {
        (*this).inverseMass = 1 / mass;
    }

    real getMass() {
        return (1 / inverseMass);
    }

    real getInverseMass() {
        return inverseMass;
    }

    Vector3 getPosition() {
        return position;
    }

    Vector3 getPosition(Vector3 *v) {
        *v = position;
    }

    Vector3 getVelocity() {
        return velocity;
    }

    Vector3 getVelocity(Vector3 *v) {
        *v = velocity;
    }

    bool hasFiniteMass() {
        return std::isfinite(inverseMass);
    }

    // Adds the given force to the particle, to be applied at the next iteration only
    void addForce(const Vector3 &force);

    // Uses the linearly approximate Newton-Euler integration method
    void integrate(real duration);

    // Clears the forces applied to the particle. Called automatically after each integration step
    void clearAccumulator();
};