#include <ParticleForceRegistry.h>
#include <algorithm>

void ParticleForceRegistry::add(Particle *particle, ParticleForceGenerator *fg) {
    registrations.push_back({particle, fg});
}

void ParticleForceRegistry::remove(Particle *particle, ParticleForceGenerator *fg) {
    ParticleForceRegistration target{particle, fg};

    std::vector<ParticleForceRegistration>::iterator position = find(registrations.begin(), registrations.end(), target);

    if (position != registrations.end())
        registrations.erase(position);
}

void ParticleForceRegistry::clear() {
    registrations.clear();
}

void ParticleForceRegistry::updateForces(real duration) {
    Registry::iterator i = registrations.begin();
    for (; i != registrations.end(); i++) {
        i->fg->updateForce(i->particle, duration);
    }
}