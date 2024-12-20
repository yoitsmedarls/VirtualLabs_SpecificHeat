#ifndef THERMOMETER
#define THERMOMETER

namespace vl
{
    class Thermometer
    {
    private: // Class fields
    public:  // Special methods
        Thermometer();
        Thermometer(const Thermometer &copy);
        ~Thermometer();

    public: // Operator overloads
        Thermometer &operator=(const Thermometer &copy);

    public: // Getters and Setters
    public: // Other methods
    };

} // namespace vl

#endif