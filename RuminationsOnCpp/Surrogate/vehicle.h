#ifndef VEHICLE_H
#define VEHICLE_H

class Vehicle
{
public:
    Vehicle();
    // �������������Ա�֧����ȷ�Ķ�̬ɾ��
    virtual ~Vehicle() {}

    virtual double weihgt() const = 0;

    virtual void start() = 0;

    // �� clone() ��¡������GOFԭ��ģʽ
    virtual Vehicle *copy() const = 0;
};

#endif // VEHICLE_H
