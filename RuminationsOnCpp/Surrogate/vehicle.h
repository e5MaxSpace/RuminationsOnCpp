#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
public:
    Vehicle();
    // 虚析构函数，以便支持正确的多态删除
    virtual ~Vehicle() {}

    virtual double weihgt() const = 0;

    virtual void start() = 0;

    // 即 clone() 克隆函数，GOF原型模式
    virtual Vehicle *copy() const = 0;
};

#endif // VEHICLE_H
