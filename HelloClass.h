#ifndef HELLOCLASS_H
#define HELLOCLASS_H

class HelloClass
{
public:
    HelloClass(int target);
    ~HelloClass();
    
    void countToTarget();
private:
    int target;
};

#endif // HELLOCLASS_H
