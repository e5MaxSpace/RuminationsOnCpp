#include "vehiclesurrogate.h"

VehicleSurrogate::VehicleSurrogate() : vp(0)
{
}

VehicleSurrogate::VehicleSurrogate(const Vehicle &vehicle) : vp(vehicle.copy())
{

}

VehicleSurrogate::~VehicleSurrogate()
{
    delete vp;
    vp = 0;
}

VehicleSurrogate::VehicleSurrogate(const VehicleSurrogate &vs) : vp(vs.vp ? vp->copy() : 0)
{

}

VehicleSurrogate &VehicleSurrogate::operator=(const VehicleSurrogate &vs)
{
    if (this != &vs)
    {
        delete vp;
        vp = (vs.vp ? vs.vp->copy() : 0);
    }

    return *this;
}

double VehicleSurrogate::weihgt() const
{
    if (vp == 0)
        throw "null pointer error!";

    return vp->weihgt();
}

void VehicleSurrogate::start()
{
    if (vp == 0)
        throw "null pointer error!";

    vp->start();
}
