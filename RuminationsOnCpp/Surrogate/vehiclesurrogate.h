#ifndef VEHICLESURROGATE_H
#define VEHICLESURROGATE_H

#include "vehicle.h"

// GOF代理模式(Proxy)
class VehicleSurrogate
{
public:
    VehicleSurrogate();
    VehicleSurrogate(const Vehicle &vehicle);
    ~VehicleSurrogate();

    VehicleSurrogate(const VehicleSurrogate &vs);
    VehicleSurrogate &operator=(const VehicleSurrogate &vs);

    double weihgt() const;
    void start();

private:
    Vehicle *vp;
};

#endif // VEHICLESURROGATE_H
