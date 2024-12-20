#ifndef COMPONENT
#define COMPONENT

#include <iostream>

namespace vl
{
    class IComponent
    {
    private: // Class fields
    public:  // Special methods
        IComponent();
        IComponent(const IComponent &copy);
        virtual ~IComponent() {};

    public: // Operator overloads
        IComponent &operator=(const IComponent &copy);

    public: // Other methods
        virtual void renderComponent() {};
    };
}
#endif